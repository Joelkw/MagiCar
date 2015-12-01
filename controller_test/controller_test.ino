#include <Wire.h>
#include <ZX_Sensor.h>
#include <DigitalPin.h>

/* Arduino | TP control pt
 *    9    |    9
 *    8    |    2
 *    -----------
 *    13   |    6
 *    12   |    7  
 */
DigitalPin pin13(13);
DigitalPin pin12(12);
DigitalPin pin8(9);
DigitalPin pin9(8);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  pin13.on();
  pin12.on();
  pin9.on();
  pin8.off();

}

/*
// function defs
int go_forward() {
  forward.off();
  backward.off();
  right.off();
  left.on();
}

int go_backward() {
  forward.off();
  backward.on();
  right.off();
  left.off();
}

int go_forward_right() {
  forward.on();
  backward.off();
  right.on();
  left.off();
}

int go_backward_right() {
  forward.off();
  backward.on();
  right.on();
  left.off();
}

int go_forward_left() {
  forward.on();
  backward.off();
  right.off();
  left.on();
}

int go_backward_left() {
  forward.off();
  backward.on();
  right.off();
  left.on();
}

int stop_stop() {
  forward.off();
  backward.off();
  right.off();
  left.off();
}

int stop_right() {
  forward.off();
  backward.off();
  right.on();
  left.off();
}

int stop_left() {
  forward.off();
  backward.off();
  right.off();
  left.on();
} */
