void setup(){
pinMode(0,OUTPUT); 
pinMode(1,OUTPUT); 
}

void loop(){
digitalWrite(0,HIGH); //Turn on the first LED
digitalWrite(1,LOW); // Turn off the second LED
delay(1000);
digitalWrite(0,LOW); //Turn off the first LED
digitalWrite(1,HIGH); //Turn on the second LED
delay(2000);
}
