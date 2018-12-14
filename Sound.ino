int getSound(int sensorPin)
{
  c = 0;
  sum = 0;
  while (c <= 20)
  {
    val = digitalRead(sensorPin);
    sum += val;
    c++;
  }
  dir_flag = 0;

  if (sum > 2)
    dir_flag = 1;

  return (dir_flag);
}

void getSoundDir(int s0, int s1)
{
  dirr =  (s0 == 0 && s1 == 0) ? -1 : (s0 > s1 ? 1 : 0);
  /*
     -1 if no sound
     1 if right
     0 if left
  */
  
}


