int mx = 80;
int maxspeedl = mx, maxspeedr = mx;
int maxspeeedl = 80, maxspeeedr = 80;
float it = 0, last_error = 0;

float pid_calc(float pv)
{
  float kp = 3, ki = 0.001, kd = 0;
  int setpoint = 35;
  float limi = 100;
  float error = pv - setpoint;
  it += error;
  it = it > limi ? limi : it;
  it = it < -limi ? -limi : it;
  float dir = error - last_error;
  float last_error = error;

  pid = kp * error + ki * it + kd * dir;
  return pid;
}

void motion(float pidval)
{
  Rw = maxspeedr + pidval;
  Rw = Rw >= maxspeedr ? maxspeedr : Rw;
  Rw = Rw <= -maxspeedr ? -maxspeedr : Rw;

  Lw = maxspeedl - pidval;
  Lw = Lw >= maxspeedl ? maxspeedl : Lw;
  Lw = Lw <= -maxspeedl ? -maxspeedl : Lw;

  Rd = Rw >= 0 ? 1 : 0;
  Ld = Lw >= 0 ? 1 : 0;
  if(stop_flag) analogWrite(rm, 0), analogWrite(lm, 0);
  else analogWrite(rm, abs(Rw)), analogWrite(lm, abs(Lw));
//  analogWrite(rm, 0), analogWrite(lm, 0);
  digitalWrite(rdp, Rd);
  digitalWrite(ldp, Ld);
}

void forward(int d)
{
  analogWrite(rm, maxspeeedr);
  digitalWrite(rdp, 1);
  analogWrite(lm, maxspeeedl);
  digitalWrite(ldp, 1);
  delay (d);
  Serial.print("\t FORWARD");
}

void Left(int d)         //CHANGED
{
  analogWrite(rm, maxspeeedr);
  digitalWrite(rdp, 1);
  analogWrite(lm, maxspeeedl);
  digitalWrite(ldp, 0);
  delay(d);
  Serial.print("\t LEFT");
}

void right(int d)
{
  analogWrite(rm, maxspeeedr);
  digitalWrite(rdp, 0);
  analogWrite(lm, maxspeeedl);
  digitalWrite(ldp, 1);
  delay (d);
  Serial.print("\t RIGHT");
}

void motorStop(int d)
{
  analogWrite(rm, 0);
  digitalWrite(rdp, 1);
  analogWrite(lm, 0);
  digitalWrite(ldp, 1);
  delay (d);
  Serial.print("\t STOP ");
}
