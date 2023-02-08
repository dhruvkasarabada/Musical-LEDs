#include <FastLED.h>

#define NUM_LEDS 25
#define LED_PIN 2

CRGB leds[NUM_LEDS];
uint8_t hue=0;
int startTime;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
 
  //:00 Prelude 
  startTime=millis();
  rainbow(0,NUM_LEDS-1,22000);
  
  //:22 Main song starts (Sher ki Zubaani) 
  int count=1;
  while(count<11) {
    throb(0, NUM_LEDS-1, CRGB::White, 300);
    count++;
  }
  
  //:31 Main song beats change (Kyunki Farak Hai) 
  count=1;
  while(count<11) {
    throb(0, NUM_LEDS-1, CRGB::Blue, 300);
    count++;
  }

  //:41 Main song beats change (Kaam ka woh kaam)
  gradient(0, NUM_LEDS-1, CRGB::Purple, CRGB::Red, 5000);
  gradient(0, NUM_LEDS-1, CRGB::Magenta, CRGB::Yellow, 5000);
 
  //:50 Bhaag Bhaag Bhaag Sher Aaya Sher 
  count=0;
  while(count<3) {
    for(int i=0;i<3;i++) {
      flash(0, NUM_LEDS-1, CRGB::Red, 200);
      flash(0, NUM_LEDS-1, CRGB::Black, 200);
    }

    flash(0, 4, CRGB::White, 150);
    flash(0, 4, CRGB::Black, 150);
    flash(5, 9, CRGB::White, 150);
    flash(5, 9, CRGB::Black, 150);
    flash(10, 14, CRGB::White, 150);
    flash(10, 14, CRGB::Black, 150);
  
    count++;
  }
}


void flash(int startLEDIdx, int endLEDIdx, CRGB color, int delayTime) {

  int numLEDs = endLEDIdx - startLEDIdx + 1;
  for(int i=startLEDIdx;i<startLEDIdx+numLEDs;i++) {
    leds[i] = color; 
  }
  
  FastLED.show(); 
  delay(delayTime);
}

void gradient(int startLEDIdx, int endLEDIdx, CRGB color1, CRGB color2, int delayTime) {
    int numLEDs = endLEDIdx - startLEDIdx + 1;
    fill_gradient_RGB(leds, numLEDs, color1, color2);
    FastLED.show();
    delay(delayTime);
}

void throb(int startLEDIdx, int endLEDIdx, CRGB color, int delayTime) {
    int numLEDs = endLEDIdx - startLEDIdx + 1;
    
    for(int i=startLEDIdx;i<startLEDIdx+numLEDs/2;i++) {
      leds[i] = color; 
    }
    FastLED.show();
    delay(delayTime);
  
    for(int i=startLEDIdx;i<startLEDIdx+numLEDs;i++) {
      leds[i] = color; 
    }
    FastLED.show();
    delay(delayTime);
    
    for(int i=startLEDIdx+numLEDs-1;i>=startLEDIdx;i--) {
      leds[i] = CRGB::Black; 
    }
    FastLED.show();
    delay(delayTime);
}

void rainbow(int startLEDIdx, int endLEDIdx, int delayTime) {
  int numLEDs = endLEDIdx - startLEDIdx + 1;
  int runTime = startTime;
  
  while(runTime < startTime + delayTime) {
    runTime = millis();
    for(int i=startLEDIdx;i<startLEDIdx+numLEDs;i++) {
      leds[i] = CHSV(hue, 255, 255); 
    }
    EVERY_N_MILLISECONDS(15) {
      hue++;
    }
    FastLED.show();
  }  
}