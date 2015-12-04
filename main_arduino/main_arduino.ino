#include <OneWire.h>
#include <ACPWM.h>

#define ZERO_PIN 2 //Input pin from zero cross detector
#define PWM_PIN 5 //Output pin to TRIAC / SSR
#define FILL_UP 13
#define LEVEL_IN 1
#define ENGINE 3
#define SERVO_1 12
#define SERVO_2 11
#define SERVO_3 9
#define SERVO_4 8
#define ALARM 7
#define FREEZER 6
#define CHILLER 4

OneWire  ds(10);  // on pin 10 (a 4.7K resistor is necessary)

String opcao;
float temperatura;


void setup() {
  Serial.begin(9600);
  pinMode(ZERO_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

}

/*PRE BRASSAGEM*/
void insert_water() {
  opcao = "";
  while (1) {
    digitalWrite(FILL_UP, HIGH);

    if (Serial.available() > 0) {
      opcao = Serial.readStringUntil(':');
      if (digitalRead(LEVEL_IN) == HIGH) {
        Serial.write("TRUE");
      }

      else
        Serial.write("FALSE");

      if (opcao == "stop_water") {
        digitalWrite(FILL_UP, LOW);
        return;
      }
    }
  }
}



void turn_on_engine() {
  opcao = "";
  
  digitalWrite(ENGINE, HIGH);
  Serial.write("TRUE");
  return;
}

void turn_off_engine(){
  opcao = "";

  digitalWrite(ENGINE, LOW);
  return;
}

/*BRASSAGEM*/
void turn_on_resistor_1(float temperatura) {
  while(1){

  /*INSERIR CONTROLE DO RESISTOR*/
  
    opcao = "";
  
    if (Serial.available() > 0) {
      opcao = Serial.readStringUntil(':');
      temperatura = Serial.parseFloat();
    }

    if(opcao == "activate_alarm") {
      activate_alarm();
    }
  
    if(opcao == "read_thermal_sensor") {
      /*ENVIAR LEITURA DOS SENSORES*/
    }
  
    if (opcao == "turn_off_resistor_1") {
      /*DESLIGAR O RESISTOR*/
      turn_off_engine();
      return;
    }
    
  }
}
void activate_alarm() {
  opcao = "";

  digitalWrite(ALARM, HIGH);
  delay(10000);
  digitalWrite(ALARM, LOW);
  return;
}

/*FERVURA*/
void turn_on_resistor_2(){
opcao = "";

Serial.println("Fervura Iniciada");

int id;

  while (1) {
    /*ADICIONAR LUPULO*/
    if (Serial.available() > 0) {
     opcao = Serial.readStringUntil(':');
     id = Serial.parseInt();
    }
  
    if(opcao == "read_thermal_sensor") {
      /*ENVIAR LEITURA DO SENSOR*/
    }
  
    if (opcao == "add_hop") {
      switch(id) {
        case 1: 
          digitalWrite(SERVO_1, HIGH);
          delay(1000);
          digitalWrite(SERVO_1, LOW);
          break;
        case 2:
          digitalWrite(SERVO_2, HIGH);
          delay(1000);
          digitalWrite(SERVO_2, LOW);
          break;
        case 3:
          digitalWrite(SERVO_3, HIGH);
          delay(1000);
          digitalWrite(SERVO_3, LOW);
          break;
        case 4:
          digitalWrite(SERVO_4, HIGH);
          delay(1000);
          digitalWrite(SERVO_4, LOW);
          break;
        default:  /*nothing to do*/
          break;
      }
    }
  
    if (opcao == "turn_off_resistor_2") {
      /*DESLIGAR RESISTOR*/
      Serial.println("Fim da Fervura!");
      return;
    }
  }
}

/*RESFRIAMENTO*/

void turn_on_chiller() {
opcao = "";

  while (1) {
    digitalWrite(CHILLER, HIGH);
    
    if (Serial.available() > 0) {
      opcao = Serial.readStringUntil(':');
    }
  
    if (opcao == "turn_off_chiller") {
      digitalWrite(CHILLER, LOW);
      return;
    }

    if (opcao == "read_thermal_sensor") {
       /*SUBTRAIR A TEMPERATURA DOS DOIS SENSORES E ENVIAR*/
    }
  }
}

/*FERMENTAÇÃO*/

void turn_on_freezer(float temperatura) {
opcao = "";

  if(opcao == "read_thermal_sensor") {}

}


void loop () {

  opcao = "";
  
  if (Serial.available() > 0) {
   opcao = Serial.readStringUntil(':');
  }

  if (opcao == "insert_water") {
    insert_water();
  }

 if (opcao == "turn_on_engine") {
    turn_on_engine();
  }

  if (opcao == "turn_on_resistor_1") {
    temperatura = Serial.parseFloat();
    turn_on_resistor_1(temperatura);
  }

  if (opcao == "activate_alarm") {
    activate_alarm();
  }


  if (opcao == "turn_on_resistor_2") {
    turn_on_resistor_2();
  }

  if (opcao == "turn_on_chiller") {
    turn_on_chiller();
  }

  if (opcao == "turn_on_freezer") {
    temperatura = Serial.parseFloat();
    turn_on_freezer(temperatura);
  }

}
