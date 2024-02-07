#include <AccelStepper.h>

const int dirPin = 2;      // Direction pin
const int pulsePin = 3;    // Pulse pin

const int buttonForwardPin = A0;   // Push button for forward
const int buttonReversePin = A1;   // Push button for reverse
const int potentiometerPin = A2;   // Potentiometer pin

AccelStepper stepper(AccelStepper::DRIVER, pulsePin, dirPin);

const int AxisX = 7;      // D7
const int AxisY = 8;      // D8
const int AxisZ = 9;      // D9

const int OutputX = 4;    // D4
const int OutputY = 5;    // D5
const int OutputZ = 6;    // D6

void setup() {
  pinMode(AxisX, INPUT_PULLUP);
  pinMode(AxisY, INPUT_PULLUP);
  pinMode(AxisZ, INPUT_PULLUP);

  pinMode(OutputX, OUTPUT);
  pinMode(OutputY, OUTPUT);
  pinMode(OutputZ, OUTPUT);

  pinMode(buttonForwardPin, INPUT_PULLUP);
  pinMode(buttonReversePin, INPUT_PULLUP);

  pinMode(potentiometerPin, INPUT);

  stepper.setMaxSpeed(1000);   // Adjust the maximum speed of your stepper motor
  stepper.setAcceleration(800);   // Adjust the acceleration
}

void loop() {
  // Check the state of each input pin (LOW when activated due to internal pull-up)
  if (digitalRead(AxisX) == LOW) {
    digitalWrite(OutputX, HIGH);
    digitalWrite(OutputY, LOW);
    digitalWrite(OutputZ, LOW);
  } else if (digitalRead(AxisY) == LOW) {
    digitalWrite(OutputX, LOW);
    digitalWrite(OutputY, HIGH);
    digitalWrite(OutputZ, LOW);
  } else if (digitalRead(AxisZ) == LOW) {
    digitalWrite(OutputX, LOW);
    digitalWrite(OutputY, LOW);
    digitalWrite(OutputZ, HIGH);
  } else {
    // No input is LOW, set all output pins LOW
    digitalWrite(OutputX, LOW);
    digitalWrite(OutputY, LOW);
    digitalWrite(OutputZ, LOW);
  }

  // Check the state of the forward button
  if (digitalRead(buttonForwardPin) == LOW) {
    int potValue = analogRead(potentiometerPin);
    int speed = map(potValue, 0, 1023, 150, 1000);  // Map the potentiometer value to the speed range
    stepper.setSpeed(speed);
    stepper.runSpeed();  // Run the stepper motor at the set speed
  }

  // Check the state of the reverse button
  if (digitalRead(buttonReversePin) == LOW) {
    int potValue = analogRead(potentiometerPin);
    int speed = map(potValue, 0, 1023, -150, -1000);  // Map the potentiometer value to the speed range
    stepper.setSpeed(speed);
    stepper.runSpeed();  // Run the stepper motor at the set speed
  }
}
