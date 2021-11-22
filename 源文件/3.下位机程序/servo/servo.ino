#include<Servo.h>

Servo Fservo;
Servo Bservo;
Servo Lservo;
Servo Rservo;
Servo Uservo;
Servo Dservo;

char buf[128];//串口接收缓存

#define F_servo  A0
#define B_servo  A1
#define L_servo  A2
#define R_servo  A3
#define U_servo  A4
#define D_servo  A5

//Anticlockwise

//↓:Clockwise. ↑:Anticlockwise

#define F_servo_start 0
#define F_servo_end 180

#define B_servo_start  0
#define B_servo_end  180

#define L_servo_start  0
#define L_servo_end  180

#define R_servo_start  180
#define R_servo_end  0

#define U_servo_start  0
#define U_servo_end  180

#define D_servo_start  0
#define D_servo_end  180

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Fservo.attach(F_servo);
  Bservo.attach(B_servo);
  Lservo.attach(L_servo);
  Rservo.attach(R_servo);
  Uservo.attach(U_servo);
  Dservo.attach(D_servo);
  Fservo.write(180);
  Bservo.write(180);
  Lservo.write(0);
  Rservo.write(0);
  Uservo.write(0);
  Dservo.write(180);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Start Loop");
  Dservo.write(55);
  Uservo.write(110);
  delay(500);
  Fservo.write(40);
  Bservo.write(30);
//  delay(500);
//  Lservo.write(135);
//  Rservo.write(147);
//  while(1){
//    Fservo.write(0);
//    }
}
