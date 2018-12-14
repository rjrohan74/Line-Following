float getLSA(int pinn)
{
  float lp = analogRead(pinn);
  lp = map(lp, 0, 900, 0, 70);
  lp = lp > 900 ? 71 : lp;
  return lp;
}

void checkJunc()
{
  if(!stop_flag)
  {
  int d1 = digitalRead(A3);
  int d2 = digitalRead(A5);
  int jp = digitalRead(7);
  Serial.print("\t JP = "); Serial.print(jp);
  Serial.print("\t d1 = "); Serial.print(d1);
  Serial.print("\t d2 = "); Serial.print(d2);
  int chk = getLSA(A6);
  
  if (d1 == 1 && d2 == 0)
  {
    forward(100);
    motorStop(1000);
    chk = getLSA(A6);

    if (chk > 70) Left(400);
    else forward(300);
  }
  else if (d1 == 0 && d2 == 1)
  {
    forward(100);
    motorStop(1000);
    chk = getLSA(A6);

    if (chk > 70) right(400);
    else forward(300);
  }
  else if (d1 == 1 && d2 == 1)
  {
    forward(100);
    motorStop(1000);
    Left(400);
  } 
  else if (d1 == 0 && d2 == 0 && chk > 70)
  {
    right(600);
  }
  }
}

