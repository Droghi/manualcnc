[![arduino-library-badge](https://www.ardu-badge.com/badge/AccelStepper.svg?)](https://www.ardu-badge.com/AccelStepper)
# manualcnc
<div align="center">
  <p>
      <img width="20%" src="img/arduino-icon.svg">
  </p>
  <p> An manual control for 3 Axis of an CNC Machine using  <a href="https://www.arduino.cc"> Arduino </a>, Stepper motor Drivers, Stepper motors with variable speed and selectable axis </p>
</div>
<br>
An manual control for 3 Axis of an CNC Machine using Arduino, DRV8825 Drivers, Stepper motors with variable speed and selectable axis

# Compatibility

  * A4988
  * DRV8825/DRV8834/DRV8880
  * TB6600
  * generic stepper motor drivers (DIR/STEP)

# Microstepping support :

   - <a href="https://www.pololu.com/product/2134">DRV8834</a> Stepper Motor Driver up to 1:32
   - <a href="https://www.pololu.com/product/1182">A4988</a> Stepper Motor Driver up to 1:16
   - <a href="https://www.pololu.com/product/2131">DRV8825</a> Stepper Motor Driver up to 1:32
   - <a href="https://www.pololu.com/product/2971">DRV8880</a> Stepper Motor Driver up to 1:16
   - any other 2-pin stepper via DIR and STEP pins, microstepping up to 1:128 externally set

# Stepper Motors support :

  - 4-wire bipolar stepper motor or 
  - some 6-wire unipolar in 4-wire configuration (leaving coil centers out)
