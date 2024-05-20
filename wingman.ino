#include <AccelStepper.h>
#include <SoftwareSerial.h> 
#include <Servo.h>

#define PI 3.1415926535897932384626433832795

#define RX 11
#define TX 10

SoftwareSerial HC06(RX,TX);
Servo HS422;

#define pul1 2
#define dir1 5
#define pul2 3
#define dir2 6
#define pul3 4
#define dir3 7
#define enable_pin 8

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);
AccelStepper stepper3(1, pul3, dir3);

bool ready = true;

void setup() {
  HC06.begin(9600);
  Serial.begin(9600);
  HS422.attach(9);

   // Init vitesse et accel
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(1000);
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(1000);
  stepper3.setMaxSpeed(2000);
  stepper3.setAcceleration(1000);
}

void loop() {  
  if (HC06.available()) {
    Serial.write(HC06.read());
    if (ready) {
      char recievedChar = HC06.read();
      switch (recievedChar) {
        case 'c':
          carre(10);
          break;
        case 't':
          triangle(10);
          break;
        case 'r':
          cercle(10);
          break;
        case 'b':
          cercleTriangle(10);
          break;
        default:
          break;
      }
    }
    // Serial.print(HC06.read());
  }
  if (Serial.available()) {
    HC06.write(Serial.read());
  }
}

// void monter() {
//   HS422.write(-30);
// }
// void descendre() {
//   HS422.write(0);
// }

void avancer(int distance) {
  double steps_per_cm = 200 / ( PI * 6); // 200pas par tours, 6 cm de diametre
  long steps = distance * steps_per_cm;

  digitalWrite(enable_pin, LOW);
  stepper2.moveTo(steps);
  stepper3.moveTo(-steps);
  stepper2.run();
  stepper3.run(); 
  digitalWrite(enable_pin, HIGH);
}

void tourner(int degre) {
  double steps_per_cm = 200 / ( PI * 6); // pas / circonference
  long steps = 19.8*PI/360*degre * steps_per_cm; // circonference / 360° * degres * (pas / circonference)

  digitalWrite(enable_pin, LOW);
  stepper1.moveTo(steps);
  stepper2.moveTo(steps);
  stepper3.moveTo(steps);
  stepper1.run();
  stepper2.run();
  stepper3.run();
  digitalWrite(enable_pin, HIGH);
}

void carre(int distance) {
  for (int i = 0; i < 4; i++) {
    avancer(distance);
    tourner(90);
  }
}

void triangle(int distance) {
  for (int i = 0; i < 3; i++) {
    avancer(distance);
    tourner(120);
  }
}

void cercle(int rayon) {
  int steps = 2 * PI * rayon;
  double angleParPas = 360.0 / steps;

  for (int i = 0; i < steps; i++) {
    avancer(1);
    tourner(angleParPas);
  }
}

void cercleTriangle(int distance) {
  triangle(distance);
  int rayon = distance / sqrt(3);
  cercle(rayon);
}