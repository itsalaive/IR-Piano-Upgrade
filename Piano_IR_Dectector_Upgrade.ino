#include <Adafruit_NeoPixel.h>
//#include <rp2040_pio.h>

#include <SoftwareSerial.h>


#define LED_PIN 9
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
const int ProxSensor0 = 2;
const int ProxSensor1 = 4;
const int ProxSensor2 = 7;
const int ProxSensor3 = 8;
int inputVal = 0;
bool pressed[] = {false, false, false, false};
int Prox[] = {ProxSensor0, ProxSensor1, ProxSensor2, ProxSensor3};
int SensorColour[4][3] = {{255,0,0},{0,255,0},{0,0,255},{0,255,255}};




void setup()
{
  pinMode(13, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:
  pinMode(ProxSensor0, INPUT);
  pinMode(ProxSensor1, INPUT);   //Pin 2 is connected to the output of proximity sensor
  pinMode(ProxSensor2, INPUT);
  pinMode(ProxSensor3, INPUT);
  strip.begin();
  //strip.setPixelColor (0, 0, 0, 0);
  strip.show();

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
    strip.setPixelColor(0, SensorColour[val][0], SensorColour[val][1], SensorColour[val][2]);
    strip.show();
    pressed[val] = true;
  }
}
void loop()
{
  bool keysPressed = false;
  for (int i=0; i <=3; i++)
  {
    if (digitalRead(Prox[i]) == LOW)   //Check the sensor output
    {
      checker(i);
      keysPressed = true;
    }
    else
    {
      pressed[i] = false;
    }
  }
  if(keysPressed==false)
  {
    strip.setPixelColor(0,0,0,0);
    strip.show();  
  }
}
