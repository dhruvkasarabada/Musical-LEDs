#include <FastLED.h>

#define NUM_LEDS 20
#define LED_PIN 2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  gradient(0, NUM_LEDS-1, CRGB::Magenta, CRGB::Yellow, 5000);
  gradient(0, NUM_LEDS-1, CRGB::Purple, CRGB::Red, 5000);

  flash(0, NUM_LEDS-1, CRGB::Red, 22000);
  flash(0, NUM_LEDS-1, CRGB::Black, 500);
  flash(0, NUM_LEDS-1, CRGB::White, 500);

  int count=1;
  while(count<13) {
    throb(0, NUM_LEDS-1, CRGB::Blue, 500);
    count++;
  }

  count=1;
  while(count<6) {
    throb(0, NUM_LEDS-1, CRGB::Purple, 500); 
    count++;
  }

  count=0;
  while(count<25) {
    flash(0, NUM_LEDS-1, CRGB::Orange, 100);
    flash(0, NUM_LEDS-1, CRGB::Black, 100);
    count++;
  }
   
  flash(0, NUM_LEDS-1, CRGB::White, 10000);
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
