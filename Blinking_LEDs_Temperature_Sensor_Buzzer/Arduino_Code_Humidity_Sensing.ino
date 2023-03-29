
//This code uses humidity values measured by DH11 sensor to vary the frequence of blinking of two LEDs
//and activates the buzzer when the humidity value reaches 80° 

# include <DHT.h>  // Include the DHT library

const int blueLED = 7;//connect the bleu LED to digital pin 7
const int yellowLED = 6;//connect the yellow LED to digital pin 6
const int buzzPin = 5;//connect buzzer to digital pin 5
const int sensorPin = 2;//connect humidity sensor to digital pin 2

DHT dht(sensorPin, DHT11); // Create DHT object

int blinkInterval = 500; // starting blink interval (1HZ)

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);//initialize serial communication at 9600 bits per second
  dht.begin(); // Initialize DHT sensor
}

void loop() {
  float humidity = dht.readHumidity(); // Read humidity from sensor

  if (isnan(humidity)){
    Serial.println("Failed to read humidity from DHT sensor!");
    return;
  }
  else{
    Serial.print("Humidity:   ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  blinkInterval = map(humidity, 0, 100, 100, 1000); // map temperature value to blink interval range
  Serial.print("Frequence:   ");
  Serial.println(1000/blinkInterval); // printing the frequence of blinking on the serial port

  digitalWrite(blueLED, HIGH); // turn on first LED
  digitalWrite(yellowLED, LOW); // turn off second LED
  delay(blinkInterval/2); // wait for half the blink interval

  digitalWrite(blueLED, LOW); // turn off first LED
  digitalWrite(yellowLED, HIGH); // turn on second LED
  delay(blinkInterval/2); // wait for half the blink interval

  if (humidity != 80){
    digitalWrite(buzzPin, LOW);//turn off the buzzer 
  }else{
    digitalWrite(buzzPin, HIGH);//turn on the buzzer
  }
}
