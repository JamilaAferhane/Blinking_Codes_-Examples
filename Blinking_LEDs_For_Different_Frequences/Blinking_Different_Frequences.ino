//In this code the red LED(0) is blinking for a frequence of 10HZ
//and the green LED(1) is blinking for a frequence of 5HZ
void setup(){
pinMode(0,OUTPUT); //set digital pin number 0 on the Arduino board to output mode for the red LED
pinMode(1,OUTPUT); //set digital pin number 0 on the Arduino board to output mode for the green LED
}

void loop(){
digitalWrite(0,HIGH); //the red LED lights up for 50 milliseconds
digitalWrite(1,HIGH); //the green LED lights up for 50 milliseconds
delay(50);
digitalWrite(0,LOW);//the red LED goes out for 50 milliseconds
digitalWrite(1,HIGH);//the green LED lights up for 50 milliseconds
delay(50);
digitalWrite(0,HIGH);//the red LED lights up for 50 milliseconds
digitalWrite(1,LOW);//the green LED goes out for 50 milliseconds
delay(50);
digitalWrite(0,LOW);//the red LED goes out for 50 milliseconds
digitalWrite(1,LOW);//the green LED goes out for 50 milliseconds
delay(50);
}
