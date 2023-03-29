// In this code the two leds are blinking for a frequence of 10 hz
void setup(){
pinMode(0,OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie
pinMode(1,OUTPUT); //règle la borne numérique numéro 1 de la carte Arduino en mode sortie
}

void loop(){
digitalWrite(0,HIGH); //la LED rouge s’allume
digitalWrite(1,HIGH); // la LED vert s’éteint
delay(50);
digitalWrite(0,LOW); //la LED rouge s’éteint
digitalWrite(1,LOW); //la LED vert s’allume
delay(50);
}
