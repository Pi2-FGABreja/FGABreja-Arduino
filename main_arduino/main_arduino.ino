String opcao;


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

}

/*PRE BRASSAGEM*/
void insert_water() {

  if (Serial.available() > 0) {
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "insert_water") {
  }
}



void turn_on_engine() {
  if (Serial.available() > 0) {
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "turn_off_engine") {
  }

  }

/*BRASSAGEM*/
void turn_on_resistor_1(float temperatura) {
  if (Serial.available() > 0) {
   String opcao = Serial.readStringUntil(':');
  }
  if(opcao == "read_thermal_sensor") {}
  if (opcao == "turn_off_resistor_1") {
  }
  }

void activate_alarm() {

}

/*FERVURA*/
void turn_on_resistor_2(){

  /*ADICIONAR LUPULO*/
  if (Serial.available() > 0) {
   String opcao = Serial.readStringUntil(':');
  }

  if(opcao == "read_thermal_sensor") {}

  if (opcao == "add_hop") {
    int id = Serial.parseInt();
  }
}

/*RESFRIAMENTO*/

void turn_on_chiller() {
  if (Serial.available() > 0) {
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "turn_off_chiller") {
  }

}

/*FERMENTAÇÃO*/

void turn_on_freezer() {
  if(opcao == "read_thermal_sensor") {}

}



void loop() {
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
    float temperatura = Serial.parseFloat();
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
    turn_on_freezer();
  }

}
