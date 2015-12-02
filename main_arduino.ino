String opcao;


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

}

/*PRE BRASSAGEM*/
void encheagua() {
  
  if (Serial.available() > 0) {  
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "insert_water") {
  }
}
  
    

void ligamotor() {
  if (Serial.available() > 0) {  
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "turn_off_engine") {
  }
  
  }

/*BRASSAGEM*/
void ligares1(float temperatura) {
  if (Serial.available() > 0) {  
   String opcao = Serial.readStringUntil(':');
  }
  if(opcao == "read_thermal_sensor") {}
  if (opcao == "turn_off_resistor_1") {
  }
  }

void alarme() {
  
}

/*FERVURA*/
void fervura(){

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

void ligachiller() {
  if (Serial.available() > 0) {  
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "turn_off_chiller") {
  }
  
}

/*FERMENTAÇÃO*/

void ligageladeira() {

  if(opcao == "read_thermal_sensor") {}
  
}



void loop() {
  if (Serial.available() > 0) {  
   String opcao = Serial.readStringUntil(':');
  }

  if (opcao == "insert_water") {
    encheagua();
  }

 if (opcao == "turn_on_engine") {
    ligamotor();
  }

  if (opcao == "turn_on_resistor_1") {
    float temperatura = Serial.parseFloat();
    ligares1(temperatura);
  }

  if (opcao == "activate_alarm") {
    alarme();
  }


  if (opcao == "resistance2") {
    fervura();
  }

  if (opcao == "turn_on_chiller") {
    ligachiller();
  }

  if (opcao == "turn_on_freezer") {
    ligageladeira();
  }

}
