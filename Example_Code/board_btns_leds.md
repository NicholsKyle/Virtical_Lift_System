
## Buttons and LEDs demonstration

This demo shows how to use push-buttons (BTN0-3), LEDs (LD0-3), and RGB LEDs (LD4-5) on the PYNQ-Z1. 

You can do the following to control the LEDs or RGB LEDs:
    
    Button 0 pressed:        RGB LEDs change color.
    Button 1 pressed:        LEDs shift from right to left (LD0 -> LD3).
    Button 2 pressed:        LEDs shift from left to right (LD3 -> LD0).
    Button 3 pressed:        Turns off all the LEDS and ends this demo.
 


```python
from time import sleep
from pynq.board import LED
from pynq.board import RGBLED
from pynq.board import Button
from pynq.iop import iop_const
from pynq.iop import DevMode
from pynq.iop import PMODA

Delay1 = 0.3
Delay2 = 0.1
color = 0
leds = [LED(index) for index in range(4)]
rgbleds = [RGBLED(index) for index in [4,5]] 
btns = [Button(index) for index in range(4)]
        
for led in leds:
    led.on()    
while (btns[3].read()==0):
    if (btns[0].read()==1):
        color = (color+1) % 8
        for rgbled in rgbleds:
            rgbled.write(color)
        sleep(Delay1)
        
    elif (btns[1].read()==1):
        for led in leds:
            led.off()
        sleep(Delay2)
        for led in leds:
            led.toggle()
            sleep(Delay2)
            
    elif (btns[2].read()==1):
        for led in leds[::-1]:
            led.off()
        sleep(Delay2)
        for led in leds[::-1]:
            led.toggle()
            sleep(Delay2)                  
    
print('End of this demo ...')
for led in leds:
    led.off()
for rgbled in rgbleds:
    rgbled.off()
    
del leds,btns
```


```python
from pynq import Overlay
Overlay("base.bit").download()

from pynq.iop import Arduino_Analog
from pynq.iop import ARDUINO
from pynq.iop import ARDUINO_GROVE_A1

analog1 = Arduino_Analog(ARDUINO,ARDUINO_GROVE_A1)

analog1.write(1)
print('done')
```


```python

```
