[![arduino-library-badge](https://www.ardu-badge.com/badge/AccelStepper.svg?)](https://www.ardu-badge.com/AccelStepper)
# manualcnc ![Build](https://github.com/Droghi/manualcnc/actions/workflows/blank.yml/badge.svg)

<div align="center">
  <p>
      <img width="20%" src="img/arduino-icon.svg">
  </p>
  <p> An manual controling using push-buttons for 3 Axis of an CNC Machine using  <a href="https://www.arduino.cc"> Arduino </a>, Stepper motor Drivers, Stepper motors with variable speed and selectable axis </p>
</div>
<br>
<br>
This is a simple code on Arduino IDE for controlling a 3 Axis CNC Maschine with simple controls :
  * Variable Speed (using a potentiometer)
  * Selectable Axis (using simple 4-pole selector)
  * Direction control (FWD/REV)

# Dependencies :

[![arduino-library-badge](https://www.ardu-badge.com/badge/AccelStepper.svg?)](https://www.ardu-badge.com/AccelStepper)


# Compatibility

  * A4988
  * DRV8825/DRV8834/DRV8880
  * TB6600
  * generic stepper motor drivers (DIR/STEP)

# Microstepping support :

   - <a href="https://www.pololu.com/product/2134">DRV8834</a> Stepper Motor Driver up to `1:32`
   - <a href="https://www.pololu.com/product/1182">A4988</a> Stepper Motor Driver up to `1:16`
   - <a href="https://www.pololu.com/product/2131">DRV8825</a> Stepper Motor Driver up to `1:32`
   - <a href="https://www.pololu.com/product/2971">DRV8880</a> Stepper Motor Driver up to `1:16`
   - any other 2-pin stepper via DIR and STEP pins, microstepping up to `1:128` externally set

# Stepper Motors support :

  - 4-wire bipolar stepper motor or 
  - some 6-wire unipolar in 4-wire configuration (leaving coil centers out)

# Hardware :

  * Arduino Compatible Board
  * 3x <a href="https://www.pololu.com/category/120/stepper-motor-drivers">Stepper motor driver</a>, with 2-pin (DIR/STEP)
  * 3x <a href="http://www.circuitspecialists.com/stepper-motor">Stepper Motor</a>, like NEMAxx (4-wire stepper motor)
  * A <a href="https://www.tme.eu/en/details/ck1031/rotary-switches/lorlin/">Rotary Switch</a> (4-pole)
  * A <a href="https://www.tme.eu/en/details/prp167-10k-a/carbon-single-turn-potentiometers/telpod/prp167-10k-a-20p1/">10 KOhm Potentiometer</a>
  * 2x <a href="https://www.tme.eu/en/details/r13-553bl-01/standard-switches/sci/">ON-OFF SWITCH</a> (SPST)

# Wiring :

This is suggested wiring for running the examples unmodified. All the pins below can be changed.

- Arduino to driver board:
    - DIR - D2
    - STEP - D3
    - GND - Arduino GND
    - VMOT - Motor PSU + (positive voltage) **(check what PSU request the drivers)*
    - EN (Enable Driver Pin for X Axis) - D4
    - EN (Enable Driver Pin for Y Axis) - D5
    - EN (Enable Driver Pin for Z Axis) - D6
- Rotary Switch :
    - Pin C/COM - Arduino GND
    - Pin 1 - D7
    - Pin 2 - D8
    - Pin 3 - D9
- FWD & REV Buttons
    - FWD Pin 1 - Arduino GND
    - FWD Pin 2 - A0
    - REV Pin 1 - Arduino GND
    - REV Pin 2 - A1
- Speed Control (POT)
    - Cursor Left - Arduino GND
    - Center - A2
    - Cursor Right - Arduino 5V


*- Driver board to motor (check motor coils pinout/colorcode).*

*- Make sure to set the max current on the driver board to the motor limit.*

*- Make sure the motor power supply voltage is within the range supported by the driver board.*


# Schematic :

<div align="center">
  <p>
      <img width="100%" src="img/Schematic Nano.png">
  </p>
</div>


$${\color{purple}Purple \space is \space DIR \space Pin}$$

$${\color{magenta}Light-Purple \space is \space STEP \space Pin}$$

$${\color{blue}Blue \space is \space for \space enabling \space each \space driver \space individualy}$$

$${\color{white}White \space is \space for \space selecting \space the \space axis \space with \space rotary \space switch}$$

$${\color{cyan}Cyan \space is \space for \space speed \space control}$$

$${\color{yellow}Yellow \space is \space for \space forward \space motion}$$

$${\color{green}Green \space is \space for \space reverse \space motion}$$



# Code Setup :

### Set Pins with internal pull-up resistors and MaxSpeed + Acceleration.
```C++
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
```


### If you have 5+ Pole rotary switch none driver will be enabled for safety reasons. 
```C++
  } else {
    // No input is LOW, set all output pins LOW
    digitalWrite(OutputX, LOW);
    digitalWrite(OutputY, LOW);
    digitalWrite(OutputZ, LOW);
  }
```



### Min and Max speed values can be changed when mapping of potentiometer is maked and should not be exceding the MaxSpeed.
```C++
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
```
