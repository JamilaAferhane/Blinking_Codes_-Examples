
//This code uses the values of the potentiometer to vary the frequency of blinking of two LEDs
//and activates the buzzer when the potentiometer value reaches 1 which correspond to the highest frequency

const int redLed = 7;//connect red LED to digital pin 7
const int greenLed = 6;//connect green LED to digital pin 6
const int buzzPin = 5;//connect buzzer to digital pin 5
const int potPin = A0;//connect potentiometer to analog pin A0

int potValue;// variable to store potentiometer value
int blinkInterval = 500; // starting blink interval (1HZ)

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);//initialize serial communication at 9600 bits per second
}

void loop() {
  potValue = analogRead(potPin); // read potentiometer value
  blinkInterval = map(potValue, 0, 1023, 100, 1000); // map potentiometer value to blink interval range
  Serial.println(1000/blinkInterval);// printing the frequence of blinking on the serial port

  digitalWrite(redLed, HIGH); // turn on first LED
  digitalWrite(greenLed, LOW); // turn off second LED
  delay(blinkInterval/2); // wait for half the blink interval

  digitalWrite(redLed, LOW); // turn off first LED
  digitalWrite(greenLed, HIGH); // turn on second LED
  delay(blinkInterval/2); // wait for half the blink interval

  if (potValue==1){
    digitalWrite(buzzPin, HIGH);//turn on the buzzer 
  }else{
    digitalWrite(buzzPin, LOW);//turn off the buzzer
  }
}
