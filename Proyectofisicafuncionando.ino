#include <Servo.h>


Servo servoBase;
Servo servoAlejar;
Servo servoAltura;
Servo servoPinza;

int pinBase = 2; //base
int pinAltura = 3; // altura eje derecho//
int pinAlejar = 4; // alejar acercar eje izquierdo
int pinPinza = 5; //pinzas


int pinza = 20;
int base = 0;
int altura = 120;
int alejar = 90;


int a=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoBase.attach(pinBase);
  servoAltura.attach(pinAltura);
  servoAlejar.attach(pinAlejar);
  servoPinza.attach(pinPinza);
  servoBase.write(base);
  servoAlejar.write(alejar);
  servoAltura.write(altura);
  servoPinza.write(pinza);
  
}

void loop() {
  
  if (Serial.available()){
       a=Serial.read()-'0'; 

       if(a>=0){
           Serial.print("en inicio con el valor ");
           Serial.println(a);
    
         if(a==4){
          Serial.println("IZQUIERDA");
          if(base<175){
            base=base+2;
            servoBase.write(base);
            Serial.println(base);
            delay(150);
          }
        }
        else if(a==6){
          Serial.println("DERECHA");
          if(base>9){
            base=base-2;
            servoBase.write(base);
            Serial.println(base);
            delay(150);
          }
        }
        else if(a==8){
          //brazo hacia arriba
          Serial.println("ARRIBA");
          if(altura<160){
            altura=altura+2;
            servoAltura.write(altura);
            Serial.println(altura);
            delay(150);
          }
        }
        else if(a==2){
          //brazo hacia abajo
          Serial.println("ABAJO");
           if(altura>45){
            altura=altura-2;
            servoAltura.write(altura);
            Serial.println(altura);
            delay(150);
          }
        }
        else if(a==7){
          //abrimos el brazo moviemnto hacia adelante 
          Serial.println("ADELANTE");
          if(alejar<160){
            alejar=alejar+2;
            servoAlejar.write(alejar);
            Serial.println(alejar);
            delay(150);
          }
        }
        else if(a==1){
          //recogemos el brazo movimento hacia atras
          Serial.println("ATRAS");
          if(alejar>80){
            alejar=alejar-2;
            servoAlejar.write(alejar);
             Serial.println(alejar);
            delay(150);
          }
        }
        else if(a==9){
          Serial.println("CERRANDO PINZAS");
          if(pinza<120){
            pinza=pinza+2;
            servoPinza.write(pinza);
             Serial.println(pinza);
            delay(150);
          }
        }
        else if(a==3){
          Serial.println("ABRIENDO PINZAS");
          if(pinza>20){
            pinza=pinza-2;
            servoPinza.write(pinza);
             Serial.println(pinza);
            delay(150);
          }
        }
        
        delay(100);
       }
  }
  
  /**/
  

}
