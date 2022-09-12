#include <FastLED.h>

#define NUM_LEDS 10
#define LED_PIN 2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  fill_gradient_RGB(leds, NUM_LEDS, CRGB::Magenta, CRGB::Yellow);
  FastLED.show();
  delay(5000);

  fill_gradient_RGB(leds, NUM_LEDS, CRGB::Purple, CRGB::Red);
  FastLED.show();
  delay(5000);

  int i;
  for(i=0;i<NUM_LEDS;i++) {
    leds[i] = CRGB::Red; 
  }
  FastLED.show(); 
  delay(22000);

  for(i=NUM_LEDS-1;i>=0;i--) {
    leds[i] = CRGB::Black; 
  }
  FastLED.show();
  delay(500); 

  FastLED.setBrightness(100);
  
  for(i=0;i<NUM_LEDS;i++) {
    leds[i] = CRGB::White; 
  }
  FastLED.show();
  delay(500);

  FastLED.setBrightness(50);

  int count=0;

  while(count<12) {
    for(i=0;i<NUM_LEDS/2;i++) {
      leds[i] = CRGB::Blue; 
    }
    FastLED.show();
    delay(500);
  
    for(i=0;i<NUM_LEDS;i++) {
      leds[i] = CRGB::Blue; 
    }
    FastLED.show();
    delay(500);
    
    for(i=NUM_LEDS-1;i>=0;i--) {
      leds[i] = CRGB::Black; 
    }
    FastLED.show();
    delay(500);
 
    count++;
  }

  count=0;
  while(count<6) {
    for(i=0;i<NUM_LEDS/2;i++) {
      leds[i] = CRGB::Purple; 
    }
    FastLED.show();
    delay(500);
  
    for(i=0;i<NUM_LEDS;i++) {
      leds[i] = CRGB::Purple; 
    }
    FastLED.show();
    delay(500);
    
    for(i=NUM_LEDS-1;i>=0;i--) {
      leds[i] = CRGB::Black; 
    }
    FastLED.show();
    delay(500);
  
    count++;
  }

  count=0;
  while(count<25) {
    for(i=0;i<NUM_LEDS;i++) {
      leds[i] = CRGB::Orange;    
    }
    FastLED.show();
    delay(100);
  
    for(i=0;i<NUM_LEDS;i++) {
      leds[i] = CRGB::Orange; 
    }
    FastLED.show();
    delay(100);
    
    for(i=NUM_LEDS-1;i>=0;i--) {
      leds[i] = CRGB::Black; 
    }
    FastLED.show();
    delay(100);
  
    count++;
  }

   FastLED.setBrightness(100);
   
   for(i=0;i<NUM_LEDS;i++) {
      leds[i] = CRGB::White; 
    }
    FastLED.show();

  delay(10000);
}
