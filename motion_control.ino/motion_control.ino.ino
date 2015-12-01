#include <Wire.h>
#include <ZX_Sensor.h>
#include <DigitalPin.h>

DigitalPin pin13(13);
DigitalPin pin12(12);
DigitalPin pin9(9);
DigitalPin pin8(8);

// Constants
const int ZX_ADDR = 0x10;  // ZX Sensor I2C address

// Global Variables
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t x_pos;
uint8_t z_pos;

void setup() {
  
  uint8_t ver;

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println("-----------------------------------");
  Serial.println("SparkFun/GestureSense - I2C ZX Demo");
  Serial.println("-----------------------------------");
  
  // Initialize ZX Sensor (configure I2C and read model ID)
  if ( zx_sensor.init() ) {
    Serial.println("ZX Sensor initialization complete");
  } else {
    Serial.println("Something went wrong during ZX Sensor init!");
  }
  
  // Read the model version number and ensure the library will work
  ver = zx_sensor.getModelVersion();
  if ( ver == ZX_ERROR ) {
    Serial.println("Error reading model version number");
  } else {
    Serial.print("Model version: ");
    Serial.println(ver);
  }
  if ( ver != ZX_MODEL_VER ) {
    Serial.print("Model version needs to be ");
    Serial.print(ZX_MODEL_VER);
    Serial.print(" to work with this library. Stopping.");
    while(1);
  }
  
  // Read the register map version and ensure the library will work
  ver = zx_sensor.getRegMapVersion();
  if ( ver == ZX_ERROR ) {
    Serial.println("Error reading register map version number");
  } else {
    Serial.print("Register Map Version: ");
    Serial.println(ver);
  }
  if ( ver != ZX_REG_MAP_VER ) {
    Serial.print("Register map version needs to be ");
    Serial.print(ZX_REG_MAP_VER);
    Serial.print(" to work with this library. Stopping.");
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // if x < 80 go left, if 80 < x < 120 go straight, 
  // if x > 120 go right

  // if z < 60, 
  // If there is position data available
  if ( zx_sensor.positionAvailable() ) {
    x_pos = zx_sensor.readX();
    z_pos = zx_sensor.readZ();
    // do some quick error checking:
    if ( z_pos != ZX_ERROR && x_pos != ZX_ERROR ) {
        
        // for stopping interference
        if (z_pos >2000) {
          stop_stop();
          Serial.println("NO DATA STOPPED");
        }

        // left direction
        else if (x_pos < 80) {
            // go forward left
            if (z_pos < 60) {
              go_forward_left();
              Serial.println("Forward left!");
            }
            // stop left
            else if (z_pos >= 60 && z_pos < 120) {
              stop_left();
              Serial.println("Stop left!");
            }
            // go backward left
            else if (z_pos >= 120) {
              go_backward_left();
              Serial.println("Backward left!");
            }
        } // end of left 
        //  straight direction
        else if (x_pos >= 80 && x_pos < 160) {
            // go forward 
            if (z_pos < 60) {
              go_forward();
              Serial.println("Forward!");
            }
            // stop
            else if (z_pos >= 60 && z_pos < 120) {
              stop_stop();
              Serial.println("Stop!");
            }
            // go backward
            else if (z_pos >= 120) {
              go_backward();
              Serial.println("Backward!");
            }
        } // end of straight
        //  right direction
        else if (x_pos >= 160) {
            // go forward right
            if (z_pos < 60) {
              go_forward_right();
              Serial.println("Forward Right!");
            }
            // stop right
            else if (z_pos >= 60 && z_pos < 120) {
              stop_right();
              Serial.println("Stop Right!");
            }
            // go backward right
            else if (z_pos >= 120) {
              go_backward_right();
              Serial.println("Backward Right!");
            }
        } // end of right 
    } 

  
  delay(1000);
  } // end of if sensor data loop
  //otherwise stop
  else {
    stop_stop();
    Serial.println("NO DATA");
    delay(1000);
  }
}

// function defs
int go_forward() {
  pin13.off();
  pin12.on();
  pin9.on();
  pin8.on();
}

int go_backward() {
  pin13.off();
  pin12.off();
  pin9.on();
  pin8.on();
}

int go_forward_right() {
  pin13.off();
  pin12.on();
  pin9.off();
  pin8.on();
}

int go_backward_right() {
  pin13.off();
  pin12.off();
  pin9.off();
  pin8.on();
}

int go_forward_left() {
  pin13.off();
  pin12.on();
  pin9.off();
  pin8.off();
}

int go_backward_left() {
  pin13.off();
  pin12.off();
  pin9.on();
  pin8.off();
}

int stop_stop() {
  pin13.off();
  pin12.off();
  pin9.off();
  pin8.off();
}

int stop_right() {
  pin13.on();
  pin12.on();
  pin9.off();
  pin8.on();
}

int stop_left() {
  pin13.on();
  pin12.on();
  pin9.on();
  pin8.off();
}
