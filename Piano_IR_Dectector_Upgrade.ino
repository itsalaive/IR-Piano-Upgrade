#include <SoftwareSerial.h>


const int ProxSensor0 = 2;
const int ProxSensor1 = 4;
const int ProxSensor2 = 7;
const int ProxSensor3 = 8;
int inputVal = 0;
bool pressed[] = {false, false, false, false};
int Prox[] = {ProxSensor0, ProxSensor1, ProxSensor2, ProxSensor3};



void setup()
{
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:
  pinMode(ProxSensor0, INPUT);
  pinMode(ProxSensor1, INPUT);   //Pin 2 is connected to the output of proximity sensor
  pinMode(ProxSensor2, INPUT);
  pinMode(ProxSensor3, INPUT);

  //  pinMode(7, OUTPUT);
  //  tone(ProxSensor1, 36000);
  //  digitalWrite(13, HIGH);
  Serial.begin(9600);
}

void checker(int val)
{
  if (pressed[val] == 0)
  {
    Serial.print("Obstacle Detected: ");
    Serial.println(val+1);
    pressed[val] = true;
  }
}
void loop()
{
  for (int i=0; i <=3; i++)
  {
    if (digitalRead(Prox[i]) == LOW)   //Check the sensor output
    {
      checker(i);
    }
    else
    {
      pressed[i] = false;
    }
    
  }
}
