#include <Arduino.h>

#define dataPin 4
#define clockPin 5

char index[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//generamos un indice comun para que los dos programas tengan un codigo comun

int data[5];      //los bits son guardados en un array envez de variables apaartes para optimizar i facilitar la expansion

char caracter;    //el caracter que escribiremos al puerto serie
int numeroLetra;  //el el numero que se le asignara al caracter para hacer la conversion a binaria

int delayDataClock = 100; //la pausa que habra al mandar el pulso de reloj despues de que el bit de data se coloque
int delayClockData = 100; //la pausa que habra despues del pulso para cambiar el bit de data
int pulsetime = 10;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {                            //la conversion del caracter a un numero decimal
  if (Serial.available() > 0){
    caracter = Serial.read();
    for(int i=0; i<27; i++){
      if(caracter == index[i]){
        numeroLetra = i;
      }

    }                                   //la conversion de el numero del caracter a binario para mandar los pulsos
    if(numeroLetra >= 16){
      data[5] = 1;
    }else{
      data[5] = 0;
    }
    if(numeroLetra >= 16 * data[5] + 8){
      data[4] = 1;
    }else{
      data[4] = 0;
    }
    if(numeroLetra >= 16 * data[5] + 8 * data[4] + 4){
      data[3] = 1;
    }else{
      data[3] = 0;
    }
    if(numeroLetra >= 16 * data[5] + 8 * data[4] + 4 * data[3] + 2){
      data[2] = 1;
    }else{
      data[2] = 0;
    }
    if(numeroLetra >= 16 * data[5] + 8 * data[4] + 4 * data[3] + 2 * data[2] + 1){
      data[1] = 1;
    }else{
      data[1] = 0;
    }
    Serial.print(caracter);
    Serial.print('_');

                                          //se mandan los 5 pulsos corectos
    for(int i = 5; i >= 1; i = i-1) {
      digitalWrite(dataPin, data[i]);
      Serial.print(data[i]);
      delay(delayDataClock);
      digitalWrite(clockPin, HIGH);
      delay(pulsetime);
      digitalWrite(clockPin, LOW);
      delay(delayClockData);
    }
    digitalWrite(dataPin, LOW);                                     
     Serial.println();

  }
}

