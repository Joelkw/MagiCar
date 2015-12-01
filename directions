#include <DigitalPin.h>

DigitalPin forward(13);
DigitalPin backward(12);
DigitalPin right(9);
DigitalPin left(8);

void setup(){
}

void loop() {
  go_forward();
  delay(1000);
  go_backward();
  delay(1000);
  go_forward_right();
  delay(1000);
  go_backward_right();
  delay(1000);
  go_forward_left();
  delay(1000);
  go_backward_left();
  delay(1000);
}

int go_forward() {
  forward.on();
  backward.off();
  right.off();
  left.off();
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
}
