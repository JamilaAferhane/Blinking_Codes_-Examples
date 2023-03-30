//This code is for two LEDs which are blinking alternatively for one second for each of them
void setup(){
pinMode(0,OUTPUT); //set digital pin number 0 on the Arduino board to output mode for the red LED
//pinMode(1,OUTPUT); //set digital pin number 1 on the Arduino board to output mode for the green LED
}

void loop(){
digitalWrite(13,HIGH); //the red LED lights up 
//digitalWrite(1,LOW); // the green LED goes out
delay(1000);
digitalWrite(13,LOW); //the red LED goes out
//digitalWrite(1,HIGH); //the green LED lights up
delay(1000);
}
