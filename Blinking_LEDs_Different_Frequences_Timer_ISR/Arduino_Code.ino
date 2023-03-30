//In this code, the first LED (red on 0) is blinking at the frequency of 2HZ and the second LED (green on 1) is blinking at the frequency of 5HZ
// We set up a timer2 to measure time and to generate interrupts at specific time intervals

const byte Led = 0; // Red LED
const byte Led2 = 1; // Green LED
#define LedToggle digitalWrite (Led, !digitalRead(Led))
#define Led2Toggle digitalWrite (Led2, !digitalRead(Led2))

void setup () {
pinMode (Led, OUTPUT);// set digital pin number 0 on the Arduino board to output mode 
pinMode (Led2, OUTPUT);// set digital pin number 1 on the Arduino board to output mode
cli(); // Disable global interrupt
bitClear (TCCR2A, WGM20); // WGM20 = 0
bitClear (TCCR2A, WGM21); // WGM21 = 0
TCCR2B = 0b00000110; //Set the prescaler to 256, which means that Timer2 will increment every 16 microseconds,
TIMSK2 = 0b00000001; // Enable Timer2 overflow interrupts
sei(); // Enagle global interrupt
}

byte counter = 0; // the counter variable 

// Routine d'interruption
ISR(TIMER2_OVF_vect) {//toggles the state of the second LED every 25 overflows of Timer2, this means that the green LED toggles on and off every 25 x 4 = 100 milliseconds
TCNT2 = 256 - 250; // 250 x 16 µS = 4 ms
if (counter++ > 25) { // 25 * 4 ms = 100 ms (Half period)
counter = 0;
Led2Toggle;
}
}

void loop () {
LedToggle;
delay (250); // Half period of the second LED
}
