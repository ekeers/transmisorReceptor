#include <Arduino.h>

#define dataPin 4
#define clockPin 5


int bA;             //los 5 bits que se usan para comunicar el caracter, guardados en variables diferentes bA siendo el dijito de mallor importancia
int bB;
int bC;
int bD;
int bE;

int total;

char index[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//generamos un indice comun para que los dos programas tengan un codigo comun

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(clockPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(clockPin) == HIGH){      //se recibe el rimer pulso
    bA = digitalRead(dataPin);            //guardamos el bit A
    while(clockPin == HIGH){
    }                                     //Pausa asta que se reciba otro pulso de reloj
    while(clockPin == LOW){
    }
    bB = digitalRead(dataPin);            //guardamos el bit B
    while(clockPin == HIGH){
    }                                     //Pausa asta que se reciba otro pulso de reloj
    while(clockPin == LOW){
    }
    bC = digitalRead(dataPin);            //guardamos el bit C
    while(clockPin == HIGH){
    }                                     //Pausa asta que se reciba otro pulso de reloj
    while(clockPin == LOW){
    }
    bD = digitalRead(dataPin);            //guardamos el bit D
    while(clockPin == HIGH){
    }                                     //Pausa asta que se reciba otro pulso de reloj
    while(clockPin == LOW){
    }
    bE = digitalRead(dataPin);            //guardamos el bit E
    while(clockPin == HIGH){
    }
    while(clockPin == LOW){
    }
    total = bA*16 + bB*8 + bC*4 + bD*2 + bE*1;          //sumamos todos los digitos para sacar el valor
    Serial.print(index[total]);                         //imprimimos el caracter atraves del indice
  }
}
