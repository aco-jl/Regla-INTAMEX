#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h> //Se implementa la librería EEPROM

// Configura la pantalla
LiquidCrystal_I2C lcd(0x3F,16,2); //Dir-Esclavo // Pines slc-sda 

// Configura el Teclado
const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]={12, 11, 10, 9};
byte pinsColumnas[columnas]={8, 7, 6, 5};
char teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);

// Declaracion de Pines   
const int stepPin = 2;
const int dirPin = 3;
const int enablePin = 4;
const int limitPin = 13;

// Declaracion de Constantes 
const int dirEeprom = 500; 

// Declaracion de Variables
// Variables para retener el numero introducido por el teclado
volatile int numero[4] = {99, 99, 99, 99};
volatile int fullnumber = 0;

int pos;
int actual;

int enableTeclado;

byte L; //Se crean dos variables de tipo byte para almacenar la información.
byte H;


void setup() {
  pinMode(stepPin,OUTPUT);                      //Definimos Pines Driver Motor PaP   
  pinMode(dirPin,OUTPUT);
  pinMode(enablePin,OUTPUT);
  pinMode(limitPin,INPUT);
  
  digitalWrite(enablePin,LOW);                  //habilitamos la salida de pulsos del motor  

  pos = 0;

  H = EEPROM.read(dirEeprom);
  L = EEPROM.read(dirEeprom + 1);
  actual=H; actual=actual<<8|L;
  pantalla0();
}

void loop() {
  if (enableTeclado == 1) {
    char tecla = teclado.getKey();
    if (tecla != NO_KEY){  // Si algun boton fue precionado checar que tecla fue
      switch (tecla) {
        case '1':
          checknumber(1);
        break; 
        case '2':
          checknumber(2);
        break;
        case '3':
          checknumber(3);
        break;
        case '4':
          checknumber(4);
        break;
        case '5':
          checknumber(5);
        break;
        case '6':
          checknumber(6);
        break;
        case '7':
          checknumber(7);
        break;
        case '8':
          checknumber(8);
        break;
        case '9':
          checknumber(9);
        break;
        case '0':
          checknumber(0);
        break;
        case '*':
          deletenumber();
        break;
        case '#':
          if (pos == 0){
            digitalWrite(dirPin,LOW);
            while (digitalRead(limitPin) == LOW) {
              digitalWrite(stepPin, HIGH);
              delayMicroseconds(500);
              digitalWrite(stepPin, LOW);
              delayMicroseconds(500);
            }
            actual = pos;
            lcd.setCursor(2,0);
            lcd.print("     ");
            lcd.setCursor(2,0);
            lcd.print(actual);
          }
          else {
            if (actual < pos){
              digitalWrite(dirPin,HIGH);
               inc_dec_pap(pos);
            }
            if (actual > pos){
              digitalWrite(dirPin,LOW);
              inc_dec_pap(pos);
            }
          }
          //Se almacenan los bytes más y menos significativos.
          H = highByte(actual);
          L = lowByte(actual);
          //Se escriben los bytes en direcciones de memoria contiguas.
          EEPROM.write(dirEeprom, H);
          EEPROM.write(dirEeprom + 1, L);
          //EEPROM.write(500, actual); //write(posición, valor) 
      
          H = EEPROM.read(dirEeprom);
          L = EEPROM.read(dirEeprom + 1);
          actual=H  ;actual=actual<<8|L;
          lcd.setCursor(2,0);
          lcd.print("     ");
          lcd.setCursor(2,0);
          lcd.print(actual); 
        break;
        case 'A':
          // Distancia Guardada : 5 cm
        break;
        case 'B':
          // Distancia Guardada : 10 cm
        break;
        case 'C':
          // Distancia Guardada : 15 cm
        break;
        case 'D':
          // Distancia Guardada : 30 cm
        break;
      }
    }
  }
}



