// In this code, the red LED (on 0) is blinking for a frequence of 2HZ and the green LED (on 1) is blinking for a frequence of 5HZ
//To this, we used the millis()function that returns the number of milliseconds that have passed since the Arduino board started running its current program

const long interval_1 = 250;  // interval at which to blink (milliseconds) for the red LED
const long interval_2 = 100;  // interval at which to blink (milliseconds) for the green LED

int ledState_1 = HIGH;  // ledState_1 used to set the red LED
int ledState_2 = HIGH;  // ledState_2 used to set the green LED
unsigned long previousMillis_1 = 0;
unsigned long previousMillis_2 = 0;

void setup(){
pinMode(0,OUTPUT); //set digital pin number 0 on the Arduino board to output mode for the red LED
pinMode(1,OUTPUT); //set digital pin number 1 on the Arduino board to output mode for the green LED
}

void loop(){
unsigned long currentMillis = millis();

if (currentMillis-previousMillis_2 >= interval_2) {
previousMillis_2=currentMillis;
if (ledState_2 == HIGH)
ledState_2 = LOW;
else
ledState_2 = HIGH;
digitalWrite(1,ledState_2);
}

if (currentMillis-previousMillis_1>=interval_1){
previousMillis_1=currentMillis;
if (ledState_1 == HIGH)
ledState_1 = LOW;
else
ledState_1 = HIGH;
digitalWrite(0,ledState_1);
}

}
