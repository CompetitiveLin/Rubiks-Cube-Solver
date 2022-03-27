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

void TURN(char pos, char parameter);

void TURN_OPP(char pos1, char pos2, char dir1, char dir2, bool turn_180);

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


void TURN(char pos, char parameter){
  int DIRPIN,STEPPIN,LEVEL,number;
  if (pos == 'F'){
    DIRPIN = DIRPIN_F;
    STEPPIN = STEPPIN_F;
  }
  else if(pos == 'B'){
    DIRPIN = DIRPIN_B;
    STEPPIN = STEPPIN_B;
  }
  else if(pos == 'U'){
    DIRPIN = DIRPIN_U;
    STEPPIN = STEPPIN_U;
  }
  else if(pos == 'D'){
    DIRPIN = DIRPIN_D;
    STEPPIN = STEPPIN_D;
  }
  else if(pos == 'L'){
    DIRPIN = DIRPIN_L;
    STEPPIN = STEPPIN_L;
  }
  else if(pos == 'R'){
    DIRPIN = DIRPIN_R;
    STEPPIN = STEPPIN_R;
  }
  else return;
  
  if (parameter == ' ' || parameter == 13 || parameter == 10){   // 13 is CR(Carriage Return) = '\r'; 10 is LR(Line Feed) = '\n'. Windows 操作系统默认的文本换行符为 CRLF；Linux 以及 macOS 系统默认使用 LF
    number = 800;
    LEVEL = HIGH;
  }
  else if(parameter == '\''){
    number = 800;
    LEVEL = LOW;
  }
  else if(parameter == '2'){
    number = 1600;
    LEVEL = HIGH;
  }
  else return;
  Serial.println(String(pos) + String(parameter));
  digitalWrite(DIRPIN, LEVEL);
  for (int x = 0; x < number; x ++){
    digitalWrite(STEPPIN, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN, LOW);
    delayMicroseconds(40);
  }
}

void TURN_OPP(char pos1, char pos2, char dir1, char dir2, bool turn_180){
  int DIRPIN1,DIRPIN2,STEPPIN1,STEPPIN2,LEVEL1,LEVEL2,number;
  if (pos1 == 'F' && pos2 == 'B'){
    
  }

  digitalWrite(DIRPIN1, LEVEL1);
  digitalWrite(DIRPIN2, LEVEL2);
  for (int x = 0; x < number; x ++){
    digitalWrite(STEPPIN1, HIGH);
    digitalWrite(STEPPIN2, HIGH);
    delayMicroseconds(40);
    digitalWrite(STEPPIN1, LOW);
    digitalWrite(STEPPIN2, LOW);
    delayMicroseconds(40);
  }
}



//================================
void solve(){
  int i = 0;
  while(buf[i]!=0){
    TURN(buf[i],buf[i+1]);
    if(buf[i+1] == ' ') i += 2;
    else i += 3;
  }
}
