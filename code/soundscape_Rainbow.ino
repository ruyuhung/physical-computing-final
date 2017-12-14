
#include "Particle.h"
#include <neopixel.h>
#define PIN_ANALOG_IN A0



Servo myservo;
int servoPin = D0;  //declare variable for servo
int val =0;


SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D3
#define PIXEL_COUNT 45
#define PIXEL_TYPE WS2812B



Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_ANALOG_IN, INPUT);


  myservo.attach(servoPin);  //Initialize the servo attached to pin D0
  myservo.write(180);        //set servo to 180. This position will hold the food
  delay(500);                //delay to give the servo time to move to its position
  myservo.detach();          //detach the servo to prevent it from jittering


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'



Particle.variable("soundValue", &val, INT);
  // configure input to interrupt


}



int readSound()
{
    val = analogRead(PIN_ANALOG_IN);
    return val;
}


void loop()
{

    Serial.print("Value:");
    Serial.println(readSound());
    delay(100);

    if (val > 150)
    {

    myservo.attach(servoPin);
    myservo.write(0);

    myservo.write(180);
    delay(200);
    myservo.detach();
    }
    else{
        myservo.detach();
    }




if (val>100)
{
     rainbow(20);
 }
else if (val < 80)
  {   clear();
      delay(1000);
    }
else
    {
for(int n=0; n<45; n++){
strip.setPixelColor(n,100,200,0);
strip.show();
delay(1000);
}
    }

}

void clear()
{
  for(int i=0; i<strip.numPixels(); i++)
  {
  strip.setPixelColor(i,0);
  }
  strip.show();

}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
