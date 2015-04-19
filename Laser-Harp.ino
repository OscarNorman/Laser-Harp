#include "Wire.h"
#include "LCD_I2C.h"
#include "Fluxamasynth.h"
#include <TimerOne.h>
#include "Menu.h"
#include "Abbrv_Names.h"


const char maxVals[]={
  1,
  127,
  127,
  23,
  7,
  7,
  127,
  2,
  2,
  2
};


const char tuning[]={
  59,60,62,64,65,67,69,71,72,74,76,77,79,81,83,84,96,98,100,101,103,105,107,108};
//36,40,43,48,52,55,60,64};

Fluxamasynth synth;

unsigned char portAVal=0;
unsigned char oldPortAVal = 0;

unsigned char portBVal=0;
unsigned char oldPortBVal = 0;

unsigned char portAVal2=0;
unsigned char oldPortAVal2 = 0;

unsigned char portBVal2=0;
unsigned char oldPortBVal2 = 0;

// This is the current menu item
short currentItem= 0;

// This is set to '1' when a control is being edited. Set to '0' when navigating the menu
unsigned char editingControl = 0;

unsigned short scrollCounter = 8000;

unsigned char menuItem[5];

unsigned char menuDepth=0;

unsigned char scrollHighSpeed=0;

unsigned long nextTick = 0;


/* Control/action definitions */
/* Array of control values */
char controls[149];

/* -------------------------- TEMPLATE FUNCTIONS -------------------------------*/


static void updateControlC1En() {
};

static void updateControlC1Vol() {
  synth.setChannelVolume(0, controls[CTRL_C1_VOL]);
};

static void updateControlC1Pan() {
};

static void updateControlC1Patch() {
  synth.programChange(0,0,controls[CTRL_C1_PATCH]);
};

static void updateControlC1RevSend() {
};

static void updateControlC1ChoSend() {
};

static void updateControlC1Ft() {
};

static void updateControlC1VibRate() {
};

static void updateControlC1VibDepth() {
};

static void updateControlC1VibDelay() {
};

static void updateControlC1FilterCutoff() {
};

static void updateControlC1FilterRes() {
};

static void updateControlC1EnvAttack() {
};

static void updateControlC1EnvDecay() {
};

static void updateControlC1EnvRelease() {
};

static void updateControlC1ModBendPitch() {
};

static void updateControlC1ModBendFilter() {
};

static void updateControlC1ModBendAmp() {
};

static void updateControlC1ModBendLfoPitch() {
};

static void updateControlC1ModBendLfoFilter() {
};

static void updateControlC1ModBendLfoAmp() {
};

static void updateControlC1ModWheelPitch() {
};

static void updateControlC1ModWheelFilter() {
};

static void updateControlC1ModWheelAmp() {
};

static void updateControlC1ModWheelLfoPitch() {
};

static void updateControlC1ModWheelLfoFilter() {
};

static void updateControlC1ModWheelLfoAmp() {
};

static void updateControlC1ModCc1Pitch() {
};

static void updateControlC1ModCc1Filter() {
};

static void updateControlC1ModCc1Amp() {
};

static void updateControlC1ModCc1LfoPitch() {
};

static void updateControlC1ModCc1LfoFilter() {
};

static void updateControlC1ModCc1LfoAmp() {
};

static void updateControlC1ModCc2Pitch() {
};

static void updateControlC1ModCc2Filter() {
};

static void updateControlC1ModCc2Amp() {
};

static void updateControlC1ModCc2LfoPitch() {
};

static void updateControlC1ModCc2LfoFilter() {
};

static void updateControlC1ModCc2LfoAmp() {
};

static void updateControlC1KeyLower() {
};

static void updateControlC1KeyUpper() {
};

static void updateControlC2En() {
};

static void updateControlC2Vol() {
  synth.setChannelVolume(1, controls[CTRL_C2_VOL]);
};

static void updateControlC2Pan() {
};

static void updateControlC2Patch() {
  synth.programChange(0,1,controls[CTRL_C2_PATCH]);
};

static void updateControlC2RevSend() {
};

static void updateControlC2ChoSend() {
};

static void updateControlC2Ft() {
};

static void updateControlC2VibRate() {
};

static void updateControlC2VibDepth() {
};

static void updateControlC2VibDelay() {
};

static void updateControlC2FilterCutoff() {
};

static void updateControlC2FilterRes() {
};

static void updateControlC2EnvAttack() {
};

static void updateControlC2EnvDecay() {
};

static void updateControlC2EnvRelease() {
};

static void updateControlC2ModBendPitch() {
};

static void updateControlC2ModBendFilter() {
};

static void updateControlC2ModBendAmp() {
};

static void updateControlC2ModBendLfoPitch() {
};

static void updateControlC2ModBendLfoFilter() {
};

static void updateControlC2ModBendLfoAmp() {
};

static void updateControlC2ModWheelPitch() {
};

static void updateControlC2ModWheelFilter() {
};

static void updateControlC2ModWheelAmp() {
};

static void updateControlC2ModWheelLfoPitch() {
};

static void updateControlC2ModWheelLfoFilter() {
};

static void updateControlC2ModWheelLfoAmp() {
};

static void updateControlC2ModCc1Pitch() {
};

static void updateControlC2ModCc1Filter() {
};

static void updateControlC2ModCc1Amp() {
};

static void updateControlC2ModCc1LfoPitch() {
};

static void updateControlC2ModCc1LfoFilter() {
};

static void updateControlC2ModCc1LfoAmp() {
};

static void updateControlC2ModCc2Pitch() {
};

static void updateControlC2ModCc2Filter() {
};

static void updateControlC2ModCc2Amp() {
};

static void updateControlC2ModCc2LfoPitch() {
};

static void updateControlC2ModCc2LfoFilter() {
};

static void updateControlC2ModCc2LfoAmp() {
};

static void updateControlC2KeyLower() {
};

static void updateControlC2KeyUpper() {
};

static void updateControlC3En() {
};

static void updateControlC3Vol() {
  synth.setChannelVolume(2, controls[CTRL_C3_VOL]);
};

static void updateControlC3Pan() {
};

static void updateControlC3Patch() {
  synth.programChange(0,2,controls[CTRL_C3_PATCH]);
};

static void updateControlC3RevSend() {
};

static void updateControlC3ChoSend() {
};

static void updateControlC3Ft() {
};

static void updateControlC3VibRate() {
};

static void updateControlC3VibDepth() {
};

static void updateControlC3VibDelay() {
};

static void updateControlC3FilterCutoff() {
};

static void updateControlC3FilterRes() {
};

static void updateControlC3EnvAttack() {
};

static void updateControlC3EnvDecay() {
};

static void updateControlC3EnvRelease() {
};

static void updateControlC3ModBendPitch() {
};

static void updateControlC3ModBendFilter() {
};

static void updateControlC3ModBendAmp() {
};

static void updateControlC3ModBendLfoPitch() {
};

static void updateControlC3ModBendLfoFilter() {
};

static void updateControlC3ModBendLfoAmp() {
};

static void updateControlC3ModWheelPitch() {
};

static void updateControlC3ModWheelFilter() {
};

static void updateControlC3ModWheelAmp() {
};

static void updateControlC3ModWheelLfoPitch() {
};

static void updateControlC3ModWheelLfoFilter() {
};

static void updateControlC3ModWheelLfoAmp() {
};

static void updateControlC3ModCc1Pitch() {
};

static void updateControlC3ModCc1Filter() {
};

static void updateControlC3ModCc1Amp() {
};

static void updateControlC3ModCc1LfoPitch() {
};

static void updateControlC3ModCc1LfoFilter() {
};

static void updateControlC3ModCc1LfoAmp() {
};

static void updateControlC3ModCc2Pitch() {
};

static void updateControlC3ModCc2Filter() {
};

static void updateControlC3ModCc2Amp() {
};

static void updateControlC3ModCc2LfoPitch() {
};

static void updateControlC3ModCc2LfoFilter() {
};

static void updateControlC3ModCc2LfoAmp() {
};

static void updateControlC3KeyLower() {
};

static void updateControlC3KeyUpper() {
};

static void updateControlRevType() {
  synth.setReverb(0,controls[CTRL_REV_TYPE],controls[CTRL_REV_VOL],controls[CTRL_REV_TYPE]);
};

static void updateControlRevVol() {
  synth.setReverb(0,controls[CTRL_REV_TYPE],controls[CTRL_REV_VOL],controls[CTRL_REV_TYPE]);
};

static void updateControlRevTime() {
};

static void updateControlRevFb() {
  synth.setReverb(0,controls[CTRL_REV_TYPE],controls[CTRL_REV_VOL],controls[CTRL_REV_TYPE]);
};

static void updateControlChoType() {
  synth.setChorus(0, controls[CTRL_CHO_TYPE], controls[CTRL_CHO_VOL], controls[CTRL_CHO_FB], controls[CTRL_CHO_DEL]);
};

static void updateControlChoVol() {
  synth.setChorus(0, controls[CTRL_CHO_TYPE], controls[CTRL_CHO_VOL], controls[CTRL_CHO_FB], controls[CTRL_CHO_DEL]);
};

static void updateControlChoDel() {
  synth.setChorus(0, controls[CTRL_CHO_TYPE], controls[CTRL_CHO_VOL], controls[CTRL_CHO_FB], controls[CTRL_CHO_DEL]);
};

static void updateControlChoFb() {
  synth.setChorus(0, controls[CTRL_CHO_TYPE], controls[CTRL_CHO_VOL], controls[CTRL_CHO_FB], controls[CTRL_CHO_DEL]);
};

static void updateControlChoRate() {
};

static void updateControlChoDepth() {
};

static void updateControlMstrVol() {
  synth.setMasterVolume(255);
};

static void updateControlMstrTempo() {
};

static void updateControlMstrQuant() {
};

static void updateControlModLfoRate() {
};

static void updateControlMstrTuning() {
};

static void updateControlMstrScale() {
};

static void updateControlDrumEn() {
};

static void updateControlDrumKit() {
};

static void updateControlDrumPat0() {
};

static void updateControlDrumPat1() {
};

static void updateControlDrumPat2() {
};

static void updateControlDrumPat3() {
};

static void updateControlDrumChoSend() {
};

static void updateControlDrumRevSend() {
};

static void updateControlArpEn() {
};

static void updateControlArpPat() {
};

static void (*updateControlFns[149])() = {
  updateControlC1En,
  updateControlC1Vol,
  updateControlC1Pan,
  updateControlC1Patch,
  updateControlC1RevSend,
  updateControlC1ChoSend,
  updateControlC1Ft,
  updateControlC1VibRate,
  updateControlC1VibDepth,
  updateControlC1VibDelay,
  updateControlC1FilterCutoff,
  updateControlC1FilterRes,
  updateControlC1EnvAttack,
  updateControlC1EnvDecay,
  updateControlC1EnvRelease,
  updateControlC1ModBendPitch,
  updateControlC1ModBendFilter,
  updateControlC1ModBendAmp,
  updateControlC1ModBendLfoPitch,
  updateControlC1ModBendLfoFilter,
  updateControlC1ModBendLfoAmp,
  updateControlC1ModWheelPitch,
  updateControlC1ModWheelFilter,
  updateControlC1ModWheelAmp,
  updateControlC1ModWheelLfoPitch,
  updateControlC1ModWheelLfoFilter,
  updateControlC1ModWheelLfoAmp,
  updateControlC1ModCc1Pitch,
  updateControlC1ModCc1Filter,
  updateControlC1ModCc1Amp,
  updateControlC1ModCc1LfoPitch,
  updateControlC1ModCc1LfoFilter,
  updateControlC1ModCc1LfoAmp,
  updateControlC1ModCc2Pitch,
  updateControlC1ModCc2Filter,
  updateControlC1ModCc2Amp,
  updateControlC1ModCc2LfoPitch,
  updateControlC1ModCc2LfoFilter,
  updateControlC1ModCc2LfoAmp,
  updateControlC1KeyLower,
  updateControlC1KeyUpper,
  updateControlC2En,
  updateControlC2Vol,
  updateControlC2Pan,
  updateControlC2Patch,
  updateControlC2RevSend,
  updateControlC2ChoSend,
  updateControlC2Ft,
  updateControlC2VibRate,
  updateControlC2VibDepth,
  updateControlC2VibDelay,
  updateControlC2FilterCutoff,
  updateControlC2FilterRes,
  updateControlC2EnvAttack,
  updateControlC2EnvDecay,
  updateControlC2EnvRelease,
  updateControlC2ModBendPitch,
  updateControlC2ModBendFilter,
  updateControlC2ModBendAmp,
  updateControlC2ModBendLfoPitch,
  updateControlC2ModBendLfoFilter,
  updateControlC2ModBendLfoAmp,
  updateControlC2ModWheelPitch,
  updateControlC2ModWheelFilter,
  updateControlC2ModWheelAmp,
  updateControlC2ModWheelLfoPitch,
  updateControlC2ModWheelLfoFilter,
  updateControlC2ModWheelLfoAmp,
  updateControlC2ModCc1Pitch,
  updateControlC2ModCc1Filter,
  updateControlC2ModCc1Amp,
  updateControlC2ModCc1LfoPitch,
  updateControlC2ModCc1LfoFilter,
  updateControlC2ModCc1LfoAmp,
  updateControlC2ModCc2Pitch,
  updateControlC2ModCc2Filter,
  updateControlC2ModCc2Amp,
  updateControlC2ModCc2LfoPitch,
  updateControlC2ModCc2LfoFilter,
  updateControlC2ModCc2LfoAmp,
  updateControlC2KeyLower,
  updateControlC2KeyUpper,
  updateControlC3En,
  updateControlC3Vol,
  updateControlC3Pan,
  updateControlC3Patch,
  updateControlC3RevSend,
  updateControlC3ChoSend,
  updateControlC3Ft,
  updateControlC3VibRate,
  updateControlC3VibDepth,
  updateControlC3VibDelay,
  updateControlC3FilterCutoff,
  updateControlC3FilterRes,
  updateControlC3EnvAttack,
  updateControlC3EnvDecay,
  updateControlC3EnvRelease,
  updateControlC3ModBendPitch,
  updateControlC3ModBendFilter,
  updateControlC3ModBendAmp,
  updateControlC3ModBendLfoPitch,
  updateControlC3ModBendLfoFilter,
  updateControlC3ModBendLfoAmp,
  updateControlC3ModWheelPitch,
  updateControlC3ModWheelFilter,
  updateControlC3ModWheelAmp,
  updateControlC3ModWheelLfoPitch,
  updateControlC3ModWheelLfoFilter,
  updateControlC3ModWheelLfoAmp,
  updateControlC3ModCc1Pitch,
  updateControlC3ModCc1Filter,
  updateControlC3ModCc1Amp,
  updateControlC3ModCc1LfoPitch,
  updateControlC3ModCc1LfoFilter,
  updateControlC3ModCc1LfoAmp,
  updateControlC3ModCc2Pitch,
  updateControlC3ModCc2Filter,
  updateControlC3ModCc2Amp,
  updateControlC3ModCc2LfoPitch,
  updateControlC3ModCc2LfoFilter,
  updateControlC3ModCc2LfoAmp,
  updateControlC3KeyLower,
  updateControlC3KeyUpper,
  updateControlRevType,
  updateControlRevVol,
  updateControlRevTime,
  updateControlRevFb,
  updateControlChoType,
  updateControlChoVol,
  updateControlChoDel,
  updateControlChoFb,
  updateControlChoRate,
  updateControlChoDepth,
  updateControlMstrVol,
  updateControlMstrTempo,
  updateControlMstrQuant,
  updateControlModLfoRate,
  updateControlMstrTuning,
  updateControlMstrScale,
  updateControlDrumEn,
  updateControlDrumKit,
  updateControlDrumPat0,
  updateControlDrumPat1,
  updateControlDrumPat2,
  updateControlDrumPat3,
  updateControlDrumChoSend,
  updateControlDrumRevSend,
  updateControlArpEn,
  updateControlArpPat,
};


static void updateControl(unsigned int c) {
  updateControlFns[c]();
};


static void updateAllControls() {
  unsigned int c;
  for (c=0; c<149; c++) {
    updateControl(c);
  }
}


/* -------------------------------------------------------------------------------*/

/* Control types:
 0 = enable/disable
 1 = full range number
 2 = instrument patch
 3 = key range
 4 = reverb type
 5 = chorus type
 6 = quantize type
 7 = scale type
 8 = drum kit
 9 = drum pattern
 10 = arpegiator pattern*/

void updateMenuVal(){
  unsigned char ctrl=menu_ctrl[currentItem];
  unsigned char val=controls[ctrl];

  switch(control_types[ctrl]){
  case 0:
    if(val==0){
      LCDI2C::print("Off");
    }
    else{
      LCDI2C::print("On");
    }
    break;

  case 1:
    LCDI2C::print(val);
    break;

  case 2:
    LCDI2C::print(patchNames[val]);
    break;

  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
    LCDI2C::print(val);
    break;
  }
}

void updateMenu(){
  LCDI2C::clear();
  LCDI2C::cursorToLine(0);
  if(menuDepth==0){
    LCDI2C::print("Main Menu"); 
  }
  else{
    LCDI2C::print(menu_str[menuItem[menuDepth-1]]);
  }
  LCDI2C::cursorToLine(1);
  LCDI2C::print("\176");
  if(editingControl == 0){
    LCDI2C::print(menu_str[currentItem]);
  }
  else{
    updateMenuVal();
  }
}

void increaseControl(unsigned char control_num) {
  char maxval=maxVals[control_types[menu_ctrl[currentItem]]];

  if (controls[control_num] < maxval) {
    controls[control_num] += 1;
  }
  updateControl(control_num);
}

void decreaseControl(unsigned char control_num) {
  if (controls[control_num] > 0) {
    controls[control_num] -= 1;
  }
  updateControl(control_num);
}


void setUpPortExpander(){
  Wire.beginTransmission(0x20); //IO-A
  Wire.write(0x00);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x20); //IO-B
  Wire.write(0x01);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x20);//pull-up B
  Wire.write(0x0D);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x20);//pull-up A
  Wire.write(0x0C);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x20);//Polarity B
  Wire.write(0x03);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x20);//Polarity A
  Wire.write(0x02);
  Wire.write(0xff);
  Wire.endTransmission(); 

  //port expander 2

  Wire.beginTransmission(0x21); //IO-A2
  Wire.write(0x00);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x21); //IO-B2
  Wire.write(0x01);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);//pull-up B2
  Wire.write(0x0D);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);//pull-up A2
  Wire.write(0x0C);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);//Polarity B2
  Wire.write(0x03);
  Wire.write(0xff);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);//Polarity A2
  Wire.write(0x02);
  Wire.write(0xff);
  Wire.endTransmission(); 
}

void doMenu(){
  if(oldPortAVal2==portAVal2&&portAVal2!=0){ 
    scrollCounter-=1;
  }
  else{
    scrollCounter=8000;
    scrollHighSpeed=0; 
  }
  if((portAVal2 == 0&&oldPortAVal2!=0)||(scrollCounter==0)){

    // Down key
    if(oldPortAVal2 & 0x01)
    {
      if(editingControl == 0){
        if (menu_dir[currentItem] == -1 || menu_dir[currentItem] < currentItem) {
          currentItem -= 1;
        } 
        else {
          currentItem = menu_dir[currentItem];
        }
      }
      else{
        increaseControl(menu_ctrl[currentItem]);
      }
      updateMenu();
    }

    // Up key
    else if(oldPortAVal2 & 0x02)
    {
      if (editingControl == 0) {
        if (menu_dir[currentItem] == -1 || menu_dir[currentItem] > currentItem) {
          currentItem += 1;
        } 
        else {
          currentItem = menu_dir[currentItem];
        }
      }
      else{
        decreaseControl(menu_ctrl[currentItem]);
      }
      updateMenu(); 
    }
    else if(oldPortAVal2 & 0x08)
    {
      if(editingControl == 1) {
        editingControl = 0;
      }
      else if(menu_sel[currentItem] == -3) {
        // 'Back' selected OR select when editing a control
        menuDepth--; 
        currentItem=menuItem[menuDepth];
      }
      else if(menu_sel[currentItem] == -2) {
        // Action selected
      }
      else if (menu_sel[currentItem] == -1) {
        // Control selected
        editingControl = 1;
      }
      else{
        menuItem[menuDepth]=currentItem;
        menuDepth++;
        currentItem=menu_sel[currentItem]; 
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
  oldPortAVal2 = portAVal2;

}

void doSynth(){
  char b=1;
  for(char i=0;i<8;i++){
    if((portBVal & b) != (oldPortBVal&b)){
      if((portBVal&b) == 0){
        if(controls[CTRL_C1_EN]){
          synth.noteOn(0, tuning[i], 127);
        }
        if(controls[CTRL_C2_EN]){
          synth.noteOn(1, tuning[i], 127);
        }
        if(controls[CTRL_C3_EN]){
          synth.noteOn(2, tuning[i], 127);    // play a note
        }
      }
      else{
        synth.noteOff(0, tuning[i]);
        synth.noteOff(1, tuning[i]);
        synth.noteOff(2, tuning[i]);
      }
    }
    if((portBVal2 & b) != (oldPortBVal2&b)){
      if((portBVal2&b) == 0){
        if(controls[CTRL_C1_EN]){
          synth.noteOn(0, tuning[i+8], 127);
        }
        if(controls[CTRL_C2_EN]){
          synth.noteOn(1, tuning[i+8], 127);
        }
        if(controls[CTRL_C3_EN]){
          synth.noteOn(2, tuning[i+8], 127);    // play a note
        }
      }
      else{
        synth.noteOff(0, tuning[i+8]);
        synth.noteOff(1, tuning[i+8]);
        synth.noteOff(2, tuning[i+8]);
      }
    }
    if((portAVal & b) != (oldPortAVal&b)){
      if((portAVal&b) == 0){
        if(controls[CTRL_C1_EN]){
          synth.noteOn(0, tuning[i+8], 127);
        }
        if(controls[CTRL_C2_EN]){
          synth.noteOn(1, tuning[i+8], 127);
        }
        if(controls[CTRL_C3_EN]){
          synth.noteOn(2, tuning[i+8], 127);    // play a note
        }
      }
      else{
        synth.noteOff(0, tuning[i+8]);
        synth.noteOff(1, tuning[i+8]);
        synth.noteOff(2, tuning[i+8]);
      }
    }
    b=b<<1;    
  }
  oldPortAVal=portAVal;  
  oldPortBVal=portBVal;
  oldPortBVal2=portBVal2;
}

void readI2C(){
  Wire.beginTransmission(0x20);//Read GPIO-A
  Wire.write(0x12);
  Wire.endTransmission();
  Wire.requestFrom(0x20,1);
  portAVal = Wire.read();
  Wire.endTransmission();

  Wire.beginTransmission(0x20);//Read GPIO-B
  Wire.write(0x13);
  Wire.endTransmission();
  Wire.requestFrom(0x20,1);
  portBVal = Wire.read();
  Wire.endTransmission(); 

  //port expander 2

  Wire.beginTransmission(0x21);//Read GPIO-A
  Wire.write(0x12);
  Wire.endTransmission();
  Wire.requestFrom(0x21,1);
  portAVal2 = Wire.read();
  Wire.endTransmission();

  Wire.beginTransmission(0x21);//Read GPIO-B
  Wire.write(0x13);
  Wire.endTransmission();
  Wire.requestFrom(0x21,1);
  portBVal2 = Wire.read();
  Wire.endTransmission(); 
}

void setup()
{
  Wire.begin();
  LCDI2C::init();              // start the library
  updateMenu();
  setUpPortExpander();

  Serial.begin(31250);		//  Set MIDI baud rate:

  for(int i=0;i<149;i++){
    controls[i]=control_defaults[i]; 
  }

  synth.midiReset();            // Do a complete MIDI reset

    updateAllControls();

  Timer1.initialize(1000000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
}


void loop()
{
  readI2C();     
  doSynth();
  doMenu();


}









