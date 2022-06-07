#define relay1Pin 2
#define relay2Pin 3
#include <Wire.h>
#include <LiquidCrystal_IC2.h>

FaBoLCD-PCF8574 lcd;

//impulse arası değişken tanımı  

const int coin = 2;
boolean insert = false;
volatile int pulse = 0;
unsigned long toplam;


void setup() {
  //Put your setup code here, to run once:
  pinMode(relay1Pin ,OUTPUT);
  pinMode(relay2Pin ,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), coinInterrupt, RISING);
  delay(1000);  

  lcd.begin(16,2);
  lcd.clear();
  delay(1000);
  lcd.print("Hoşgeldiniz! Lütfen Para Atınız!");
}
}

void loop() {
  //Put your main code here, to run repeatedly:
  if (insert) {
    insert = false;
    //Serial.println("coin detected!");
    toplam+=1;
    
    lcd.clear();

    lcd.setCursor(0,0);
    Serial.println("toplam : "+(String)toplam);
    delay(1000);
}
}

//interrupt
void coinInterrupt() {
  pulse++ ;
  insert = true;
}