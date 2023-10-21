#include <Arduino.h>

#define dataPin 4


char index[37] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'};
//generamos un indice comun para que los dos programas tengan un codigo comun

int data[6];      //los bits son guardados en un array envez de variables apaartes para optimizar i facilitar la expansion

char caracter;    //el caracter que escribiremos al puerto serie
int numeroLetra;  //el el numero que se le asignara al caracter para hacer la conversion a binaria

int dataDelay = 100; //la pausa que habra al mandar el pulso de reloj despues de que el bit de data se coloque
int delaystart= 10;

void setup() {
  pinMode(dataPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {                            //la conversion del caracter a un numero decimal
  if (Serial.available() > 0){
    caracter = Serial.read();
    
      for(int i=0; i<37; i++){
        if(caracter == index[i]){
          numeroLetra = i;
        }
    }  
                                     //la conversion de el numero del caracter a binario para mandar los pulsos
      if(numeroLetra >= 32){
        data[6] = 1;
     }else{
        data[6] = 0;
     }
      if(numeroLetra >= 32 * data[6] + 16){
        data[5] = 1;
      }else{
       data[5] = 0;
      }
      if(numeroLetra >= 32 * data[6] + 16 * data[5] + 8){
        data[4] = 1;
     }else{
        data[4] = 0;
     }
     if(numeroLetra >= 32 * data[6] + 16 * data[5] + 8 * data[4] + 4){
        data[3] = 1;
     }else{
       data[3] = 0;
      }
      if(numeroLetra >= 32 * data[6] + 16 * data[5] + 8 * data[4] + 4 * data[3] + 2){
        data[2] = 1;
      }else{
        data[2] = 0;
      }
          if(numeroLetra >= 32 * data[6] + 16 * data[5] + 8 * data[4] + 4 * data[3] + 2* data[2]){
        data[1] = 1;
      }else{
        data[1] = 0;
      }
    Serial.print(caracter);
    Serial.print('_');

    digitalWrite(dataPin, HIGH);
    delay(delaystart);
    digitalWrite(dataPin, LOW);
    delay(delaystart);
                                          //se mandan los 5 pulsos corectos
    for(int i = 6; i > 0; i = i-1) {
        digitalWrite(dataPin, data[i]);
        Serial.print(data[i]);
        delay(dataDelay);
    }
    digitalWrite(dataPin, LOW);                                     
     Serial.println();

  }
}