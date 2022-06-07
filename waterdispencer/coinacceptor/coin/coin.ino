#include <Wire.h>
#include <FaBoLCD_PCF8574.h>
#include <arduino.h>
#include <EEPROM.h>

#define
#define

// variable use to measuer the intervals inbetween impulses
int i=0;
// Number of impulses detected
int impulsCount=0;
// Sum of all the coins inseted
float total_amount=0;

void setup() {
  // pinMode(2, INPUT_PULLUP);
 Serial.begin(9600);
  display.setBrightness(0x0f);
 // Interrupt connected to PIN D2 executing IncomingImpuls function when signal goes from HIGH to LOW
 attachInterrupt(0,incomingImpuls, FALLING);
 EEPROM.get(0, total_amount);
 display.clear();

}


void incomingImpuls()
{
  impulsCount=impulsCount+1;
  i=0;
}

void loop() {
 i=i+1;

  Serial.print("i=");
  Serial.print(i);
  Serial.print(" Impulses:");
  Serial.print(impulsCount);
  Serial.print(" Total:");
  Serial.println(total_amount);
 
  if (i>=30 and impulsCount==1){
    total_amount=total_amount+2;
    impulsCount=0;
    EEPROM.put(0, total_amount);
  }
   if (i>=30 and impulsCount==2){
    total_amount=total_amount+1;
    impulsCount=0;
    EEPROM.put(0, total_amount);
  }
   if (i>=30 and impulsCount==3){
    total_amount=total_amount+0.5;
    impulsCount=0;
    EEPROM.put(0, total_amount);
  }
   if (i>=30 and impulsCount==4){
    total_amount=total_amount+0.2;
    impulsCount=0;
    EEPROM.put(0, total_amount);
  }
   if (i>=30 and impulsCount==5){
    total_amount=total_amount+0.1;
    impulsCount=0;
    EEPROM.put(0, total_amount);
  }

 if(total_amount<10) display.showNumberDecEx(total_amount*10, 0b10000000, true, 2, 2); 
  else
  display.showNumberDecEx(total_amount*10, 0b00100000, false, 4, 0);
}
