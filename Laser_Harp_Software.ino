#define btnUP     1
#define btnDOWN   2
#define btnSELECT 4
#define SDA_PIN 1 
#define SDA_PORT PORTD 
#define SCL_PIN 0
#define SCL_PORT PORTD

#include "SoftI2CMaster.h"
#include <LiquidCrystal.h>
#include "Fluxamasynth.h"
#include <TimerOne.h>

struct menuItems{  
  char up;
  char down;
  char sel;
  char *name;
};

const char tuning[]={
  60,62,64,65,67,69,71,72};
  //36,40,43,48,52,55,60,64};
  
  
const struct menuItems Menu[]={
  {  
    7,  1,  8,"Channel Options"            }
  ,//0   Main Menu Block
  {  
    0,  2,-99,"Effects Units  "            }
  ,
  {  
    1,  3,-99,"Arpeggiator    "            }
  ,
  {  
    2,  4,-99,"Master Volume  "            }
  ,
  {  
    3,  5,-99,"Master Tempo   "            }
  ,
  {  
    4,  6,-99,"Clear Settings "            }
  ,
  {  
    5,  7,-99,"Save Settings  "            }
  ,
  {  
    6,  0,-99,"Reload Save    "            }
  ,

  {
    12, 9,13,"Channel One"            }
  ,//8   Channel Options Block
  { 
    8,10,19,"Channel Two"            }
  ,
  { 
    9,11,25,"Channel Three"            }
  ,
  {
    10,12,31,"Channel Four"            }
  ,
  {
    11, 8, 0,"Exit"            }
  ,

  {
    18,14,-1,"Patch"            }
  ,//13   Channel 1 Block
  {
    13,15,-2,"Channel Volume"            }
  ,
  {
    14,16,-3,"Reverb Send"            }
  ,
  {
    15,17,-4,"Chorus Send"            }
  ,
  {
    16,18,-5,"Portamento"            }
  ,
  {
    17,13, 0,"Exit"            }
  ,

  {
    24,20,-6,"Patch"            }
  ,//19   Channel 2 Block
  {
    19,21,-7,"Channel Volume"            }
  ,
  {
    20,22,-8,"Reverb Send"            }
  ,
  {
    21,23,-9,"Chorus Send"            }
  ,
  {
    22,24,-10,"Portamento"            }
  ,
  {
    23,19, 0,"Exit"            }
  ,

  {
    30,26,-11,"Patch"            }
  ,//25   Channel 3 Block
  {
    25,27,-12,"Channel Volume"            }
  ,
  {
    26,28,-13,"Reverb Send"            }
  ,
  {
    27,29,-14,"Chorus Send"            }
  ,
  {
    28,30,-15,"Portamento"            }
  ,
  {
    29,25, 0,"Exit"            }
  ,

  {
    36,32,-16,"Patch"            }
  ,//31   Channel 4 Block
  {
    31,33,-17,"Channel Volume"            }
  ,
  {
    32,34,-18,"Reverb Send"            }
  ,
  {
    33,35,-19,"Chorus Send"            }
  ,
  {
    34,36,-20,"Portamento"            }
  ,
  {
    35,31, 0,"Exit"            }
  ,
};


// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


Fluxamasynth synth;

char portAVal=0;
char oldPortAVal = 0;

char portBVal=0;
char oldPortBVal = 0;

char currentItem= 0;

short scrollCounter = 8000;

char menuItem[5];

char menuDepth=0;

unsigned char contVals[24];

char scrollHighSpeed=0;

unsigned long nextTick = 0;

void updateMenu(){
  lcd.clear();
  lcd.setCursor(0,0);
  if(menuDepth==0){
    lcd.print("Main Menu"); 
  }
  else{
    lcd.print(Menu[menuItem[menuDepth-1]].name);
  }
  lcd.setCursor(0,1);
  lcd.print("\176");
  if(currentItem >= 0){
    lcd.print(Menu[currentItem].name);
  }
  else{
    lcd.print((int)contVals[-currentItem-1]);
  }
}

void setUpPortExpander(){
  int r = i2c_init();
  i2c_start(0x40); //IO-A
  i2c_write(0x00);
  i2c_write(0xff);
  i2c_stop();

  i2c_start(0x40); //IO-B
  i2c_write(0x01);
  i2c_write(0xff);
  i2c_stop();

  i2c_start(0x40);//pull-up B
  i2c_write(0x0D);
  i2c_write(0xff);
  i2c_stop();

  i2c_start(0x40);//pull-up A
  i2c_write(0x0C);
  i2c_write(0xff);
  i2c_stop();

  i2c_start(0x40);//Polarity B
  i2c_write(0x03);
  i2c_write(0xff);
  i2c_stop();

  i2c_start(0x40);//Polarity A
  i2c_write(0x02);
  i2c_write(0xff);
  i2c_stop(); 
}

void doMenu(){
  if(oldPortBVal==portBVal&&portBVal!=0){ 
    scrollCounter-=1;
  }
  else{
    scrollCounter=8000;
    scrollHighSpeed=0; 
  }
  if((portBVal == 0&&oldPortBVal!=0)||(scrollCounter==0)){

    if(oldPortBVal & 0x01)
    {
      if(currentItem>=0){
        currentItem=Menu[currentItem].up;
      }
      else{
        if(contVals[-currentItem-1]<100){
          contVals[-currentItem-1]++;
        }
      }
      updateMenu();
    }
    else if(oldPortBVal & 0x02)
    {
      if(currentItem>=0){
        currentItem=Menu[currentItem].down;
      }
      else{
        if(contVals[-currentItem-1]>0){
          contVals[-currentItem-1]--;
        }
      }
      updateMenu(); 
    }
    else if(oldPortBVal & 0x08)
    {
      if(Menu[currentItem].sel == 0||currentItem < 0){
        menuDepth--; 
        currentItem=menuItem[menuDepth];
      }
      else if(Menu[currentItem].sel == -99){
        //do nothing
      }
      else if(Menu[currentItem].sel <0){
        menuItem[menuDepth]=currentItem;
        menuDepth++;
        currentItem=Menu[currentItem].sel; 
      }

      else{
        menuItem[menuDepth]=currentItem;
        menuDepth++;
        currentItem=Menu[currentItem].sel; 
      }
      updateMenu(); 

    }
    if(scrollHighSpeed>=10){
      scrollCounter=1000; 
    }
    else{
      scrollCounter=2000;
      scrollHighSpeed++;
    }
  }
  oldPortBVal = portBVal;

}

void doSynth(){
    char b=1;
    for(char i=0;i<8;i++){
      if((portAVal & b) != (oldPortAVal&b)){
        if((portAVal&b) == 0){
          synth.noteOn(0, tuning[i], 127);
          synth.noteOn(1, tuning[i], 127);
          synth.noteOn(2, tuning[i], 127);    // play a note
        }
        else{
          synth.noteOff(0, tuning[i]);
          synth.noteOff(1, tuning[i]);
          synth.noteOff(2, tuning[i]);
        }
      }
      b=b<<1;    
    }    
  oldPortAVal=portAVal;
}

void readI2C(){
  i2c_start(0x40);//Read GPIO-A
  i2c_write(0x12);
  i2c_rep_start(0x41);
  portAVal = i2c_read(true);
  i2c_stop();

  i2c_start(0x40);//Read GPIO-B
  i2c_write(0x13);
  i2c_rep_start(0x41);
  portBVal = i2c_read(true);
  i2c_stop(); 
}

void setup()
{
  lcd.begin(16, 2);              // start the library
  updateMenu();
  setUpPortExpander();

  Serial.begin(31250);		//  Set MIDI baud rate:

  synth.midiReset();            // Do a complete MIDI reset

  synth.setReverb(1,7,255,120); // A Plate Reverb with maximum effect level
  synth.setReverb(2,4,255,120); // A Plate Reverb with maximum effect level
  
  synth.setChannelVolume(0, 70); // max. channel volume
  synth.setMasterVolume(255);	// max. master volume

  synth.programChange(0,0,101);
  synth.programChange(0,1,26);
  synth.programChange(0,2,14);

  Timer1.initialize(1000000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
}


void loop()
{
  readI2C();     
  doSynth();
 // doMenu();


}







