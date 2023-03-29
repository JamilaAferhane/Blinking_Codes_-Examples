void setup(){
pinMode(0,OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie pour la LED rouge
pinMode(1,OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie pour la LED verte
}

void loop(){
digitalWrite(0,HIGH); //la LED rouge s’allume
digitalWrite(1,LOW); // la LED verte s’éteint
delay(1000);
digitalWrite(0,LOW); //la LED rouge s’éteint
digitalWrite(1,HIGH); //la LED verte s’allume
delay(2000);
}
