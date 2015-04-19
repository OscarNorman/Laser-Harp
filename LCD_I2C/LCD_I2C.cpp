#include <LCD_I2C.h>
#include <Wire.h>
#include <Arduino.h>

//command bytes for LCD
#define CMD_CLR 0x01
#define CMD_HOME 0x02

#define BIT_RS    0x01
#define BIT_RW    0x02
#define BIT_E     0x04
#define BIT_LIGHT 0x08

#define DATA_SHIFT 4

#define I2C_ADDRESS 0x27

// ---------------- HELPER FUNCTIONS ----------------

static void SendToLCD(unsigned char d)
{
 Wire.beginTransmission(I2C_ADDRESS);
 Wire.write(d | BIT_LIGHT);
 Wire.endTransmission();
 delayMicroseconds(1);

 Wire.beginTransmission(I2C_ADDRESS);
 Wire.write(d | BIT_E | BIT_LIGHT);
 Wire.endTransmission();
 delayMicroseconds(1);

 Wire.beginTransmission(I2C_ADDRESS);
 Wire.write(d | BIT_LIGHT);
 Wire.endTransmission();
 delayMicroseconds(1);
}


static void commandWrite( int c ) 
{
 SendToLCD((c >> 4) << DATA_SHIFT);
 SendToLCD((c & 0x0F) << DATA_SHIFT);
}

static void outputChar( unsigned char c )
{
 SendToLCD(((c >> 4) << DATA_SHIFT) | BIT_RS);
 SendToLCD(((c & 0x0F) << DATA_SHIFT) | BIT_RS);
 delayMicroseconds(40);
}

// --------------- CLASS METHODS -------------------

void LCDI2C::init( void )
{
 // From the Hitachi databook - initialization diagram page 46
 delay(50);
 SendToLCD(0x03 << DATA_SHIFT);
 delay(5);
 SendToLCD(0x03 << DATA_SHIFT);
 delayMicroseconds(100);
 SendToLCD(0x03 << DATA_SHIFT);
 delay(5);
 SendToLCD(0x02 << DATA_SHIFT);
 delay(5);

 // Set interface length and font
 commandWrite(0x28);
 delayMicroseconds(40);

 // Set display on
 commandWrite(0x0C);
 delayMicroseconds(40);
}


void LCDI2C::print(const char value[] )
{
 for (const char *p = value; *p != 0; p++ ) outputChar(*p);
}

void LCDI2C::print(unsigned char n){
  static char buf[8];
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  do {
    unsigned char m = n;
    n /= 10;
    char c = m - 10 * n;
    *--str = c + '0';
  } while(n);

  return print(str);
}

void LCDI2C::clear()
{
 commandWrite(CMD_CLR);
 delay(5);
}

void LCDI2C::cursorToLine(unsigned char y)
{
 commandWrite(0x80 + (y * 0x40));
 delay(2);
}

