// This program reads the state of two switches and increments a counter based on the state of the first switch.
// It also controls a LED that turns on when the counter reaches 10 

#include <LiquidCrystal.h>

// Define the pins used
const int incrementSwitchPin = 2;
const int resetSwitchPin = 3;
const int ledPin = 13;

// Define variables
int count = 0;

// Initialize the LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // Set the pin modes
  pinMode(incrementSwitchPin, INPUT_PULLUP); // Use pull-up resistor to avoid false readings
  pinMode(resetSwitchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // Initialize the LCD
  lcd.begin(16, 2);

  // Display a welcome message on the LCD
  lcd.print("Heeey!");

  // Wait for the LCD to initialize
  delay(1000);
}

void loop() {
  // Check the state of the increment switch
  if (digitalRead(incrementSwitchPin) == HIGH) {
    // Increment the count variable and display it on the LCD
    count++;
    if (count>10){
      count = 0;
    }
    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(count);

    // Turn on the LED if the count reaches 10
    if (count == 10) {
      digitalWrite(ledPin, HIGH);
    }
  }

  // Check the state of the reset switch
  if (digitalRead(resetSwitchPin) == HIGH) {
    // Reset the count variable and display it on the LCD
    count = 0;
    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(count);

    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  }

  // Turn off the LED if the count is less than 10
  if (digitalRead(ledPin) == HIGH && count < 10) {
    digitalWrite(ledPin, LOW);
  }

  // Delay to debounce the switches
  delay(500);
}
