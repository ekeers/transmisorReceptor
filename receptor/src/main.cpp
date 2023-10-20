#include <Arduino.h>
#include <LiquidCrystal.h>

#define dataPin 13

int sincTime = 10;
int pulseTime = 100;
int data[6];
int total;

int x = 0;
int y = 0;

char index[37] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
//generamos un indice comun para que los dos programas tengan un codigo comun

const int rs = 9, en = 8, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(dataPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  while(digitalRead(dataPin) == LOW){}
  while(digitalRead(dataPin) == HIGH){}
  delay(sincTime);
  for(int i = 5; i > -1;i--){
    delay(pulseTime);
    data[i] = digitalRead(dataPin);
    Serial.print(data[i]);
  }

  total =data[5]*32 + data[4]*16 + data[3]*8 + data[2]*4 + data[1]*2 + data[0]*1;
  Serial.print(index[total]);
  Serial.println();
 
  if(x == 16){
    x=0;
    y++;
  }
  if(y == 2){
    y=0;
    
  }
  lcd.setCursor(x,y);
  lcd.print(index[total]);
  x++;
}