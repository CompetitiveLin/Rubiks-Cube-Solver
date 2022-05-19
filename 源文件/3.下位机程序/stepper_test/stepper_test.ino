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

int TURN(char pos, char parameter1, char parameter2, char parameter3, char parameter4);

void solve();

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
      solve();
      Serial.println("Done");
    }
  }
  while(Serial.read()>= 0){}  //clear serial buffer
  
}


//================================
void solve(){
  int i = 0;
  while(buf[i]!=0){
    int DIRPIN = 0, STEPPIN = 0, LEVEL = 0, number = 0;
    int DIRPIN1 = 0, STEPPIN1 = 0, LEVEL1 = HIGH, number1 = 800, DIRPIN2 = 0, STEPPIN2 = 0, LEVEL2 = HIGH, number2 = 800;
    if((buf[i] == 'F' && buf[i+2] == 'B')||(buf[i] == 'L' && buf[i+2] == 'R')||(buf[i] == 'U' && buf[i+2] == 'D')||(buf[i] == 'B' && buf[i+2] == 'F')||(buf[i] == 'R' && buf[i+2] == 'L')||(buf[i] == 'D' && buf[i+2] == 'U')){ // buf[i+1] == ' ';
      LEVEL1 = HIGH;
      LEVEL2 = HIGH;
      if (buf[i] == 'F'){
        DIRPIN1 = DIRPIN_F;
        STEPPIN1 = STEPPIN_F;
        DIRPIN2 = DIRPIN_B;
        STEPPIN2 = STEPPIN_B;
      }
      else if(buf[i] == 'B'){
        DIRPIN1 = DIRPIN_B;
        STEPPIN1 = STEPPIN_B;
        DIRPIN2 = DIRPIN_F;
        STEPPIN2 = STEPPIN_F;
      }
      else if(buf[i] == 'U'){
        DIRPIN1 = DIRPIN_U;
        STEPPIN1 = STEPPIN_U;
        DIRPIN2 = DIRPIN_D;
        STEPPIN2 = STEPPIN_D;
      }
      else if(buf[i] == 'D'){
        DIRPIN1 = DIRPIN_D;
        STEPPIN1 = STEPPIN_D;
        DIRPIN2 = DIRPIN_U;
        STEPPIN2 = STEPPIN_U;
      }
      else if(buf[i] == 'L'){
        DIRPIN1 = DIRPIN_L;
        STEPPIN1 = STEPPIN_L;
        DIRPIN2 = DIRPIN_R;
        STEPPIN2 = STEPPIN_R;
      }
      else if(buf[i] == 'R'){
        DIRPIN1 = DIRPIN_R;
        STEPPIN1 = STEPPIN_R;
        DIRPIN2 = DIRPIN_L;
        STEPPIN2 = STEPPIN_L;
      }
      else break;
      digitalWrite(DIRPIN1, LEVEL1);
      
      if(buf[i+3]==' ' || buf[i+3] == 13 || buf[i+3] == 10 || buf[i+3] == '\''){
        if(buf[i+3] == '\'') LEVEL2 = LOW;
        digitalWrite(DIRPIN2, LEVEL2);
        Serial.print(String(buf[i]) + String(buf[i+1]) + String(buf[i+2]) + String(buf[i+3]));
        for (int x = 0; x < number1; x++){
          digitalWrite(STEPPIN1, HIGH);
          digitalWrite(STEPPIN2, HIGH);
          delayMicroseconds(40);
          digitalWrite(STEPPIN1, LOW);
          digitalWrite(STEPPIN2, LOW);
          delayMicroseconds(40);
        }
        i+=4;
      }
      else{
        number2 = 800;
        digitalWrite(DIRPIN2, LEVEL2);
        for (int x = 0; x < number1; x++){
          digitalWrite(STEPPIN1, HIGH);
          digitalWrite(STEPPIN2, HIGH);
          delayMicroseconds(40);
          digitalWrite(STEPPIN1, LOW);
          digitalWrite(STEPPIN2, LOW);
          delayMicroseconds(40);
        }
        for (int x = 0; x < number2; x++){
          digitalWrite(STEPPIN2, HIGH);
          delayMicroseconds(40);
          digitalWrite(STEPPIN2, LOW);
          delayMicroseconds(40);
        }
        Serial.print(String(buf[i]) + String(buf[i+1]) + String(buf[i+2]) + String(buf[i+3]) + String(buf[i+4]));
        i+=5;
      }

    }
    else if((buf[i] == 'F' && buf[i+3] == 'B')||(buf[i] == 'L' && buf[i+3] == 'R')||(buf[i] == 'U' && buf[i+3] == 'D')||(buf[i] == 'B' && buf[i+3] == 'F')||(buf[i] == 'R' && buf[i+3] == 'L')||(buf[i] == 'D' && buf[i+3] == 'U')){
      if (buf[i] == 'F'){
        DIRPIN1 = DIRPIN_F;
        STEPPIN1 = STEPPIN_F;
        DIRPIN2 = DIRPIN_B;
        STEPPIN2 = STEPPIN_B;
      }
      else if(buf[i] == 'B'){
        DIRPIN1 = DIRPIN_B;
        STEPPIN1 = STEPPIN_B;
        DIRPIN2 = DIRPIN_F;
        STEPPIN2 = STEPPIN_F;
      }
      else if(buf[i] == 'U'){
        DIRPIN1 = DIRPIN_U;
        STEPPIN1 = STEPPIN_U;
        DIRPIN2 = DIRPIN_D;
        STEPPIN2 = STEPPIN_D;
      }
      else if(buf[i] == 'D'){
        DIRPIN1 = DIRPIN_D;
        STEPPIN1 = STEPPIN_D;
        DIRPIN2 = DIRPIN_U;
        STEPPIN2 = STEPPIN_U;
      }
      else if(buf[i] == 'L'){
        DIRPIN1 = DIRPIN_L;
        STEPPIN1 = STEPPIN_L;
        DIRPIN2 = DIRPIN_R;
        STEPPIN2 = STEPPIN_R;
      }
      else if(buf[i] == 'R'){
        DIRPIN1 = DIRPIN_R;
        STEPPIN1 = STEPPIN_R;
        DIRPIN2 = DIRPIN_L;
        STEPPIN2 = STEPPIN_L;
      }
      else break;
      if(buf[i+4] == ' ' || buf[i+4] == 13 || buf[i+4] == 10){
        LEVEL2 = HIGH;
        digitalWrite(DIRPIN2, LEVEL2);
        if(buf[i+1]=='\''){
          LEVEL1 = LOW;
          number1 = 800;
          digitalWrite(DIRPIN1, LEVEL1);
          for (int x = 0; x < number1; x++){
            digitalWrite(STEPPIN1, HIGH);
            digitalWrite(STEPPIN2, HIGH);
            delayMicroseconds(40);
            digitalWrite(STEPPIN1, LOW);
            digitalWrite(STEPPIN2, LOW);
            delayMicroseconds(40);
          }
        }
        else if(buf[i+1]=='2'){
          number1 = 800;
          number2 = 800;
          LEVEL1 = HIGH;
          digitalWrite(DIRPIN1, LEVEL1);
          for (int x = 0; x < number1; x++){
            digitalWrite(STEPPIN1, HIGH);
            digitalWrite(STEPPIN2, HIGH);
            delayMicroseconds(40);
            digitalWrite(STEPPIN1, LOW);
            digitalWrite(STEPPIN2, LOW);
            delayMicroseconds(40);
          }
          for (int x = 0; x < number2; x++){
            digitalWrite(STEPPIN1, HIGH);
            delayMicroseconds(40);
            digitalWrite(STEPPIN1, LOW);
            delayMicroseconds(40);
          }
        }
        Serial.print(String(buf[i]) + String(buf[i+1]) + String(buf[i+2]) + String(buf[i+3]) + String(buf[i+4]));
        i+=5;
      }
      else{
        if(buf[i+4] == '2'){
          LEVEL2 = HIGH;
          digitalWrite(DIRPIN2, LEVEL2);
          if(buf[i+1] == '2'){
            LEVEL1 = HIGH;
            digitalWrite(DIRPIN1, LEVEL1);
            for (int x = 0; x < 1600; x++){
              digitalWrite(STEPPIN1, HIGH);
              digitalWrite(STEPPIN2, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN1, LOW);
              digitalWrite(STEPPIN2, LOW);
              delayMicroseconds(40);
            }
          }
          else{
            LEVEL1 = LOW;
            digitalWrite(DIRPIN1, LEVEL1);
            for (int x = 0; x < 800; x++){
              digitalWrite(STEPPIN1, HIGH);
              digitalWrite(STEPPIN2, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN1, LOW);
              digitalWrite(STEPPIN2, LOW);
              delayMicroseconds(40);
            }
            for (int x = 0; x < 800; x++){
              digitalWrite(STEPPIN2, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN2, LOW);
              delayMicroseconds(40);
            }
          }
        }
        else if(buf[i+4] == '\''){
          LEVEL2 = LOW;
          digitalWrite(DIRPIN2, LEVEL2);
          if(buf[i+1]=='\''){
            LEVEL1 = LOW;
            digitalWrite(DIRPIN1, LEVEL1);
            for (int x = 0; x < 800; x++){
              digitalWrite(STEPPIN1, HIGH);
              digitalWrite(STEPPIN2, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN1, LOW);
              digitalWrite(STEPPIN2, LOW);
              delayMicroseconds(40);
            }
          }
          else{
            LEVEL1 = HIGH;
            digitalWrite(DIRPIN1, LEVEL1);
            for (int x = 0; x < 800; x++){
              digitalWrite(STEPPIN1, HIGH);
              digitalWrite(STEPPIN2, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN1, LOW);
              digitalWrite(STEPPIN2, LOW);
              delayMicroseconds(40);
            }
            for (int x = 0; x < 800; x++){
              digitalWrite(STEPPIN1, HIGH);
              delayMicroseconds(40);
              digitalWrite(STEPPIN1, LOW);
              delayMicroseconds(40);
            }
          }
        }
        Serial.print(String(buf[i]) + String(buf[i+1]) + String(buf[i+2]) + String(buf[i+3]) + String(buf[i+4]) + String(buf[i+5]));
        i+=6;
      }
    }
    else{
      if (buf[i] == 'F'){
        DIRPIN = DIRPIN_F;
        STEPPIN = STEPPIN_F;
      }
      else if(buf[i] == 'B'){
        DIRPIN = DIRPIN_B;
        STEPPIN = STEPPIN_B;
      }
      else if(buf[i] == 'U'){
        DIRPIN = DIRPIN_U;
        STEPPIN = STEPPIN_U;
      }
      else if(buf[i] == 'D'){
        DIRPIN = DIRPIN_D;
        STEPPIN = STEPPIN_D;
      }
      else if(buf[i] == 'L'){
        DIRPIN = DIRPIN_L;
        STEPPIN = STEPPIN_L;
      }
      else if(buf[i] == 'R'){
        DIRPIN = DIRPIN_R;
        STEPPIN = STEPPIN_R;
      }
      else break;
      
      if (buf[i+1] == ' ' || buf[i+1] == 0){   // 13 is CR(Carriage Return) = '\r'; 10 is LF(Line Feed) = '\n'. Windows 操作系统默认的文本换行符为 CRLF；Linux 以及 macOS 系统默认使用 LF
        number = 800;
        LEVEL = HIGH;
      }
      else if(buf[i+1] == '\''){
        number = 800;
        LEVEL = LOW;
      }
      else if(buf[i+1] == '2'){
        number = 1600;
        LEVEL = HIGH;
      }
      else break;
      
      Serial.print(String(buf[i]) + String(buf[i+1]));
      
      digitalWrite(DIRPIN, LEVEL);
      for (int x = 0; x < number; x ++){
        digitalWrite(STEPPIN, HIGH);
        delayMicroseconds(40);
        digitalWrite(STEPPIN, LOW);
        delayMicroseconds(40);
      }
      if(buf[i+1]==' ') i+=2;
      else i+=3;
      }
  }

}
