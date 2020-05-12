# Gearbox Project (featuring snap fits)

Just a simple 3D printed gearbox to be used with my TM 9V Arduino kit motor. Gears down the high speed to a potentiometer - compatible speed.

## Motivation

I wanted to use a 9V TM motor with a 10K ACP Potentiometer (180 degrees of rotation). 
I was hopping to put something physical with the Arduino PID library. 
I also wanted to explore 3D printed snap fits and gears.
And, finally, write better README's.

## Features

### Snap Fits

![Snap Fit Demo](media/snapfit.gif)

The snap fits are designed to fit 5mm holes. The ones I printed with 20% infill PLA can be removed without damaging the mechanism. 

### Gears

All gear are metric module 1.5 spur gears with a 7.5 cm hex bore. Each gear interacts with 5 mm of height.

### Gearing

This is a 6-stage gearbox with a total ratio of 3918.75:1.
A second output exists after the second stage with a ratio of 16.5:1

| Stage | Gears | Ratio | Cummulative Ratio |
| --- | --- | --- | --- |
| 1 | 33:10 | 3.3:1 | 3.3:1 |
| 2 | 50:10 | 5:1 | 16.5:1 |
| 3 | 50:10 | 5:1 | 82.5:1 |
| 4 | 50:10 | 5:1 | 412.5:1 |
| 5 | 50:10 | 5:1 | 2062.5:1 |
| 6 | 19:10 | 1.9:1 | 3918.75:1 |

## Development

### Constraints

The primary constraint was the 180 degree limit on the potentiometer. Beyond that, all parts needed to fit the bed of my 3D printer and, ideally, not take ages to print.

### SolidWorks

SolidWorks Render:

![Gearbox Solidworks - Render](media/gearbox.gif)

All parts were modeled in SolidWorks in metric. 
As the gear models are based off toolbox components, these need to opened before the assembly to prevent SolidWorks from referencing the wrong parts. 

### 3D Printing

All parts were printed on my custom Prusa Mk2 - similar 3D printer with 20% infill. 

### Electronics

All control is done via an Arduino UNO. The 9V from a battery are used with an L293DNE H-bridge. The ACP potentiometer takes 5V and ground with the slider pin going into one of the Arduino's ADCs. 

