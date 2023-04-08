//#include "Gyroscope.hpp"
//#include "CameraMount.hpp"
#include "MotorJoint.hpp"

/*

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

*/

// Genou front right 
const uint8_t pot_genou_fr=A1; // pot dans le genou
int esc_genou_fr=5;
const uint8_t control_genou_fr=A0; // donne l'angle à atteindre
MotorJoint genou_fr(esc_genou_fr,pot_genou_fr, 26,178,170,-1);

// Hanche front right
const uint8_t pot_hanche_fr=A2;
int esc_hanche_fr=6;
const uint8_t control_hanche_fr=A3;
MotorJoint hanche_fr(esc_hanche_fr,pot_hanche_fr,60,160,145,-1);

// Epaule front right
const uint8_t pot_epaule_fr=A4;
int esc_epaule_fr=9;
const uint8_t control_epaule_fr=A5;
MotorJoint epaule_fr(esc_epaule_fr,pot_epaule_fr,11,164,100,1);


void setup() {
  Serial.begin(9600);

  //gyro.setup_gyro();

  //support1.setup_cm();
  //support2.setup_cm();

  genou_fr.setup_mj();
  hanche_fr.setup_mj();
  epaule_fr.setup_mj();
}

void loop() {

  //gyro.get_yaw_pitch_roll(ypr);
  // Serial.print(ypr[0]);
  // Serial.print("  ");
  // Serial.print(ypr[1]);
  // Serial.print("  ");
  // Serial.print(ypr[2]);
  // Serial.println("  ");


  //support1.move(-ypr[2],ypr[1]);
  //support2.move(-ypr[2],ypr[1]);
  // Serial.print(analogRefr(A0));
  // Serial.print("   ");
  
  // Serial.print("   ");
  // Serial.print(foot.refr());

  // Serial.print("  ");
  // Serial.println(map(-45,-90,90,750,2250));

  // support1.move_x(map(analogRefr(pot),0,1023,-90,90));
  // support1.get_position(container);
  // Serial.print(analogRefr(pot));
  // Serial.print(map(analogRefr(pot),0,1023,-90,90));
  // Serial.print("  ");
  // Serial.print(container[0]);
  // Serial.print("  ");
  // Serial.println(container[1]);

  // // test genou front right
  // uint16_t setAngle = map(analogRead(control_genou_fr),0,1023,0,90);
  // genou_fr.set_angle(setAngle);
  // Serial.print(map(analogRead(control_genou_fr),0,1023,0,90));
  // Serial.print("  ");
  // Serial.print(genou_fr.get_angle());
  // Serial.print("  ");
  // Serial.println(genou_fr.get_speed());

  //   // test hanche front right
  // uint16_t setAngle = map(analogRead(control_hanche_fr),0,1023,0,90);
  // hanche_fr.set_angle(setAngle);
  // Serial.print(map(analogRead(control_hanche_fr),0,1023,0,90));
  // Serial.print("  ");
  // Serial.print(hanche_fr.get_angle());
  // Serial.print("  ");
  // Serial.println(hanche_fr.get_speed());

    // test epaule front right
  uint16_t setAngle = map(analogRead(control_epaule_fr),0,1023,0,90);
  epaule_fr.set_angle(setAngle);
  Serial.print(map(analogRead(control_epaule_fr),0,1023,0,90));
  Serial.print("  ");
  Serial.print(epaule_fr.get_angle());
  Serial.print("  ");
  Serial.println(epaule_fr.get_speed());

}
