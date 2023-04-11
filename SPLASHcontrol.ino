/*
 * This code is designed to work with the Arduino Micro
 * using the ATmega32U4
 */

void setup() {
  pinMode(9, OUTPUT);                               // Set digital pin 9 (D9) to an output
  pinMode(10, OUTPUT);                              // Set digital pin 10 (D10) to an output
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);  // Enable PWM outputs for OC1A and OC1B on digital pins 9, 10
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11);     // Set fast PWM and prescaler of 8 on timer 1
  ICR1 = 19999;                                      // Set the PWM frequency to (16MHz / (8 * (999 + 1)))
  //OCR1A = 6000;                                      // Set duty-cycle to 50% on D9
  //OCR1B = 250;                                      // Set duty-cycle to 25% on D10
}

void loop() {
  for (uint16_t i=0; i<6000; i+=100) {
    OCR1A = i;
    delay(1);
  }
  delay(5000);
  for (uint16_t i=6000; i>0; i-=100) {
    OCR1A = i;
    delay(1);
  }
  delay(5000);
}
