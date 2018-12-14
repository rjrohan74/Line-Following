void checkColor()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  int r = pulseIn(A2, LOW);
  Serial.print(" R= "); Serial.print(r);

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  int g = pulseIn(A2, LOW);
  Serial.print(" G= "); Serial.print(g);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  int b = pulseIn(A2, LOW);
  Serial.print(" B= "); Serial.print(b);


  if (r < 160 && r > 125 && b < 350 && b > 250 && g > 300) {
    color = 1; // Red
  }
  else if (r < 550 && r > 250 && g < 300 && g > 100 && b < 250 && b > 180) {
    color = 0; // Green
  }
  else
    color = -1;

  if (color == 1 || color == 0)
  {
    stop_flag = HIGH;

  }
  else  stop_flag = LOW;
}


