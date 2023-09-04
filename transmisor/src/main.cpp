#include <Arduino.h>

#define dataPin 4
#define clockPin 5

char index[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//generamos un indice comun para que los dos programas tengan un codigo comun

int bA;           //los 5 bits que se usan para comunicar el caracter, guardados en variables diferentes bA siendo el dijito de mallor importancia
int bB;
int bC;
int bD;
int bE;

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
      bA = 1;
    }else{
      bA = 0;
    }
    if(numeroLetra >= 16 * bA + 8){
      bB = 1;
    }else{
      bB = 0;
    }
    if(numeroLetra >= 16 * bA + 8 * bB + 4){
      bC = 1;
    }else{
      bC = 0;
    }
    if(numeroLetra >= 16 * bA + 8 * bB + 4 * bC + 2){
      bD = 1;
    }else{
      bD = 0;
    }
    if(numeroLetra >= 16 * bA + 8 * bB + 4 * bC + 2 * bD + 1){
      bE = 1;
    }else{
      bE = 0;
    }
    Serial.print(caracter);
    Serial.print('_');
    Serial.print(bA);
    Serial.print(bB);
    Serial.print(bC);
    Serial.print(bD);
    Serial.println(bE);

                                          //se mandan los 5 pulsos corectos
                                          
    digitalWrite(dataPin, bA);
    delay(delayDataClock);
    digitalWrite(clockPin, HIGH);
    delay(pulsetime);
    digitalWrite(clockPin, LOW);
    delay(delayClockData);

    digitalWrite(dataPin, bB);
    delay(delayDataClock);
    digitalWrite(clockPin, HIGH);
    delay(pulsetime);
    digitalWrite(clockPin, LOW);
    delay(delayClockData);
    
    digitalWrite(dataPin, bC);
    delay(delayDataClock);
    digitalWrite(clockPin, HIGH);
    delay(pulsetime);
    digitalWrite(clockPin, LOW);
    delay(delayClockData);
    
    digitalWrite(dataPin, bD);
    delay(delayDataClock);
    digitalWrite(clockPin, HIGH);
    delay(pulsetime);
    digitalWrite(clockPin, LOW);
    delay(delayClockData);
    
    digitalWrite(dataPin, bE);
    delay(delayDataClock);
    digitalWrite(clockPin, HIGH);
    delay(pulsetime);
    digitalWrite(clockPin, LOW);
    delay(delayClockData);

    digitalWrite(dataPin, LOW);    
  }
}

