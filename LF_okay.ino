#include <pinmode.h>
pinmode pins;
int Rw, Lw, Rd, Ld;
bool stop_flag = LOW;
int rm = 9, lm = 11, ldp = 10, rdp = 8;
int col, color = 0;
float pid;
int so1 = A0, so2 = A1, cl;
float val = 0;
float sum = 0;
int c = 0;
int dir_flag = 0, dirr;

void setup() {
  // put your setup code here, to run once:
  pins.IN(7, 7, A0, A1, A3, A5, A6, A2);
  pins.OUT(8, 8, 9, 11, 10, 2, 3, 4, 5);

  Serial.begin(9600);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  float lsa_val = getLSA(A6);
  int s1 = getSound(so1), s2 = getSound(so2);
  checkColor();
  if (color == 1 || color == 0)
  {
    getSoundDir(s1, s2);
    int fwd = 500, rgt = 500, lft = 500;
    Serial.print("dirr=  ");Serial.print(dirr);
    stop_flag = HIGH;
    if (color == 1 && dirr == 1)
    {
      Serial.print(" c1 d1 ");
      forward(fwd);
      motorStop(1000);
      Left(lft);
    }
    else if (color == 1 && dirr == 0)
    {
      Serial.print(" c1 d0 ");
      forward(fwd);
      motorStop(1000);
      right(rgt);
    }
    else if (color == 0 && dirr == 1)
    {
      Serial.print(" c0 d1 ");
      forward(fwd);
      motorStop(1000);
      right(rgt);
    }
    else if (color == 0 && dirr == 0)
    {
      Serial.print(" c0 d0 ");
      forward(fwd);
      motorStop(1000);
      Left(500);
    }
    else if(dirr == -1)
    {
      stop_flag == HIGH;
    }
    stop_flag == LOW;
  }
  if(color == -1) stop_flag = LOW;
  checkJunc();
  motion(pid_calc(lsa_val));
    Serial.print("\tLSA "); Serial.print(lsa_val);
    Serial.print("\tPID "); Serial.print(pid);
    Serial.print("\tSpeed "); Serial.print(Rw);
    Serial.print("  "); Serial.print(Lw);
//  Serial.print("\tSound "); Serial.print(s2);
//  Serial.print("  "); Serial.print(s1);
//  Serial.print("\tStop Flag "); Serial.print(stop_flag);
//  Serial.print("\tColor "); Serial.print(color);
  Serial.println();
}
