#include "Gyroscope.hpp"
#include "CameraMount.hpp"


// // Gyro
Gyroscope gyro;
float ypr[3]; // container for yaw pitch roll

// // Camera mount 1

const uint8_t foot=5;
const uint8_t body=3;
CameraMount support1(body,foot);
int container[2];

// // Camera mount 2

const uint8_t foot2=9;
const uint8_t body2=10;
CameraMount support2(body2,foot2);
int container2[2];

// //  Potentiometre
// const uint8_t pot=A0;

void setup() {
  Serial.begin(9600);

  gyro.setup_gyro();

  support1.setup_cm();
  support2.setup_cm();

}

void loop() {

  gyro.get_yaw_pitch_roll(ypr);
  // Serial.print(ypr[0]);
  // Serial.print("  ");
  // Serial.print(ypr[1]);
  // Serial.print("  ");
  // Serial.print(ypr[2]);
  // Serial.println("  ");


  support1.move(-ypr[2],ypr[1]);
  support2.move(-ypr[2],ypr[1]);
  // Serial.print(analogRead(A0));
  // Serial.print("   ");
  
  // Serial.print("   ");
  // Serial.print(foot.read());

  // Serial.print("  ");
  // Serial.println(map(-45,-90,90,750,2250));

  // support1.move_x(map(analogRead(pot),0,1023,-90,90));
  // support1.get_position(container);
  // Serial.print(analogRead(pot));
  // Serial.print(map(analogRead(pot),0,1023,-90,90));
  // Serial.print("  ");
  // Serial.print(container[0]);
  // Serial.print("  ");
  // Serial.println(container[1]);

  


}