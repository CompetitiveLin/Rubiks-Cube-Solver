#include<Stepper.h>
#define STEPPIN_F 2
#define DIRPIN_F 3
#define STEPPIN_B 4
#define DIRPIN_B 5
#define STEPPIN_L 6
#define DIRPIN_L 7
#define STEPPIN_R 8
#define DIRPIN_R 9
#define STEPPIN_U 10
#define DIRPIN_U 11
#define STEPPIN_D 12
#define DIRPIN_D 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(STEPPIN_F, OUTPUT);
  pinMode(DIRPIN_F, OUTPUT);
  pinMode(STEPPIN_B, OUTPUT);
  pinMode(DIRPIN_B, OUTPUT);
  pinMode(STEPPIN_L, OUTPUT);
  pinMode(DIRPIN_L, OUTPUT);
  pinMode(STEPPIN_R, OUTPUT);
  pinMode(DIRPIN_R, OUTPUT);
  pinMode(STEPPIN_U, OUTPUT);
  pinMode(DIRPIN_U, OUTPUT);
  pinMode(STEPPIN_D, OUTPUT);
  pinMode(DIRPIN_D, OUTPUT);

  digitalWrite(DIRPIN_F, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_F, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_F, LOW);
    delayMicroseconds(40);
  }
  
  digitalWrite(DIRPIN_B, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_B, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_B, LOW);
    delayMicroseconds(40);
  }

  digitalWrite(DIRPIN_L, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_L, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_L, LOW);
    delayMicroseconds(40);
  }

  digitalWrite(DIRPIN_R, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_R, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_R, LOW);
    delayMicroseconds(40);
  }

  digitalWrite(DIRPIN_U, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_U, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_U, LOW);
    delayMicroseconds(40);
  }

  digitalWrite(DIRPIN_D, HIGH);
  for (int x = 0; x < 800; x ++) {
    digitalWrite(STEPPIN_D, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_D, LOW);
    delayMicroseconds(40);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
