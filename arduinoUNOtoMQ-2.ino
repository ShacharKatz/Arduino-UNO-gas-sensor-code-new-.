#include <Adafruit_NeoPixel.h>

int Input = A0; // חיישן גז
int Buzzer = A1; // באזר
int value;
int MAX = 350;

#define PIXEL_PIN 6
#define NUMPIXELS 8   

Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(Input ,INPUT);
  pinMode(Buzzer ,OUTPUT);

  pixels.begin();
  pixels.setBrightness(50);
  pixels.show(); 
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
}

void loop() {

  Serial.print("Sensor Value: ");
  Serial.print(value);
  Serial.print(" | MAX: ");
  Serial.print(MAX);

  if (value >= MAX) {
    Serial.println("  ---> GAS DETECTED!");
  } else {
    Serial.println("  ---> SAFE");
  }

  if (value >= MAX) { // גז
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    pixels.show();
    digitalWrite(Buzzer ,HIGH);
    delay(60);
    digitalWrite(Buzzer ,LOW);
    delay(60);
  }

  else { // בטוח

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // הכל ירוק
  }
    digitalWrite(Buzzer ,LOW);
    pixels.show();
}

  delay(50); 
}