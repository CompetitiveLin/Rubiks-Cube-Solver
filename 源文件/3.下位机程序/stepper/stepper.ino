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

// HIGH:clockwise; LOW:anti-clockwise


char buf[128];// serial buffer

void F_90_HIGH();
void F_90_LOW();
void F_180();

void B_90_HIGH();
void B_90_LOW();
void B_180();

void U_90_HIGH();
void U_90_LOW();
void U_180();

void D_90_HIGH();
void D_90_LOW();
void D_180();

void L_90_HIGH();
void L_90_LOW();
void L_180();

void R_90_HIGH();
void R_90_LOW();
void R_180();

unsigned char solve();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(Serial.read()>= 0){}  //clear serial buffer
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
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<128; i++)  buf[i] = 0;
  if(Serial.available()){
    delay(100);
    int n = Serial.readBytesUntil('\n', buf, 128);
    if(n!=0){
      Serial.println("Start");
      int result = solve();
      if(result == 1) Serial.println("Done");
      else Serial.println("Error");
    }
  }
  while(Serial.read()>= 0){}  //clear serial buffer
}

//================================
unsigned char solve(){
  int i = 0;
  while(buf[i]!=0){
    switch(buf[i]){
      case 'F':
        if (buf[i+1] == '2'){
          Serial.println("F2");
          F_180();
          i += 3;
        }
        else if (buf[i+1] == '\''){
          Serial.println("F'");
          F_90_LOW();
          i += 3;
        }
        else if (buf[i+1] == ' '){
          Serial.println("F");
          F_90_HIGH();
          i += 2;
        }
        else return 0;
        break;
//======
        case 'B':
          if (buf[i+1] == '2'){
            Serial.println("B2");
            B_180();
            i += 3;
          }
          else if (buf[i+1] == '\''){
            Serial.println("B'");
            B_90_LOW();
            i += 3;
          }
          else if (buf[i+1] == ' '){
            Serial.println("B");
            B_90_HIGH();
            i += 2;
          }
          else return 0;
          break;
//======
        case 'U':
          if (buf[i+1] == '2'){
            Serial.println("U2");
            U_180();
            i += 3;
          }
          else if (buf[i+1] == '\''){
            Serial.println("U'");
            U_90_LOW();
            i += 3;
          }
          else if (buf[i+1] == ' '){
            Serial.println("U");
            U_90_HIGH();
            i += 2;
          }
          else return 0;
          break;
//======
        case 'D':
          if (buf[i+1] == '2'){
            Serial.println("D2");
            D_180();
            i += 3;
          }
          else if (buf[i+1] == '\''){
            Serial.println("D'");
            D_90_LOW();
            i += 3;
          }
          else if (buf[i+1] == ' '){
            Serial.println("D");
            D_90_HIGH();
            i += 2;
          }
          else return 0;
          break;
//======
        case 'L':
          if (buf[i+1] == '2'){
            Serial.println("L2");
            L_180();
            i += 3;
          }
          else if (buf[i+1] == '\''){
            Serial.println("L'");
            L_90_LOW();
            i += 3;
          }
          else if (buf[i+1] == ' '){
            Serial.println("L");
            L_90_HIGH();
            i += 2;
          }
          else return 0;
          break;
//======
        case 'R':
          if (buf[i+1] == '2'){
            Serial.println("R2");
            R_180();
            i += 3;
          }
          else if (buf[i+1] == '\''){
            Serial.println("R'");
            R_90_LOW();
            i += 3;
          }
          else if (buf[i+1] == ' '){
            Serial.println("R");
            R_90_HIGH();
            i += 2;
          }
          else return 0;
          break;
//======
        default:
          return 0;
    }
  }
  return 1;
}

//================================
void F_90_HIGH(){
  digitalWrite(DIRPIN_F, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_F, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_F, LOW);
    delayMicroseconds(40);
  }
}

void F_90_LOW(){
  digitalWrite(DIRPIN_F, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_F, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_F, LOW);
    delayMicroseconds(40);
  }
}

void F_180(){
  digitalWrite(DIRPIN_F, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_F, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_F, LOW);
    delayMicroseconds(40);
  }
}
//================================
void B_90_HIGH(){
  digitalWrite(DIRPIN_B, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_B, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_B, LOW);
    delayMicroseconds(40);
  }
}

void B_90_LOW(){
  digitalWrite(DIRPIN_B, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_B, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_B, LOW);
    delayMicroseconds(40);
  }
}

void B_180(){
  digitalWrite(DIRPIN_B, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_B, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_B, LOW);
    delayMicroseconds(40);
  }
}
//================================
void U_90_HIGH(){
  digitalWrite(DIRPIN_U, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_U, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_U, LOW);
    delayMicroseconds(40);
  }
}

void U_90_LOW(){
  digitalWrite(DIRPIN_U, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_U, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_U, LOW);
    delayMicroseconds(40);
  }
}

void U_180(){
  digitalWrite(DIRPIN_U, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_U, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_U, LOW);
    delayMicroseconds(40);
  }
}
//================================
void D_90_HIGH(){
  digitalWrite(DIRPIN_D, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_D, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_D, LOW);
    delayMicroseconds(40);
  }
}

void D_90_LOW(){
  digitalWrite(DIRPIN_D, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_D, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_D, LOW);
    delayMicroseconds(40);
  }
}

void D_180(){
  digitalWrite(DIRPIN_D, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_D, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_D, LOW);
    delayMicroseconds(40);
  }
}
//================================
void L_90_HIGH(){
  digitalWrite(DIRPIN_L, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_L, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_L, LOW);
    delayMicroseconds(40);
  }
}

void L_90_LOW(){
  digitalWrite(DIRPIN_L, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_L, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_L, LOW);
    delayMicroseconds(40);
  }
}

void L_180(){
  digitalWrite(DIRPIN_L, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_L, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_L, LOW);
    delayMicroseconds(40);
  }
}
//================================
void R_90_HIGH(){
  digitalWrite(DIRPIN_R, HIGH);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_R, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_R, LOW);
    delayMicroseconds(40);
  }
}

void R_90_LOW(){
  digitalWrite(DIRPIN_R, LOW);
  for (int x = 0; x < 800; x ++){
    digitalWrite(STEPPIN_R, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_R, LOW);
    delayMicroseconds(40);
  }
}

void R_180(){
  digitalWrite(DIRPIN_R, HIGH);
  for (int x = 0; x < 1600; x ++){
    digitalWrite(STEPPIN_R, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN_R, LOW);
    delayMicroseconds(40);
  }
}
