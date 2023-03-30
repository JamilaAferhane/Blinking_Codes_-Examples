// In this code the two leds are blinking for a frequency of 10 Hz
void setup(){
pinMode(0,OUTPUT); 
pinMode(1,OUTPUT); 
}

void loop(){
digitalWrite(0,HIGH); // The red LED is on
digitalWrite(1,HIGH); // The green LED is on
delay(50);
digitalWrite(0,LOW); //The red LED is off
digitalWrite(1,LOW); // The green LED is off
delay(50);
}
