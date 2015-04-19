#ifndef __LCD_I2C__H_
#define __LCD_I2C__H_

namespace LCDI2C
{
  void init(void);
  void clear();
  void cursorToLine(unsigned char y);
  void print(const char value[]);
  void print(unsigned char);
};


#endif

