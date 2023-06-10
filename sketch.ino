#include <Adafruit_NeoPixel.h>

#define LED_PIN    5       // Pin connected to the Neopixel LED strip
#define NUM_LEDS   19      // Number of LEDs in the strip

#define BUTTON_PIN 4       // Pin connected to the tactile button, replace "X" with the GPIO pin number

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int buttonState = HIGH;    // Current state of the button
int lastButtonState = HIGH; // Previous state of the button
int buttonCounter = 0;     // Number of button presses

void setup() {
  strip.begin();
  strip.show();             // Initialize all LEDs to off
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  
  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // If the button is pressed, increment the counter
    if (buttonState == LOW) {
      buttonCounter++;
      if (buttonCounter > 4) {
        buttonCounter = 0;   // Reset counter if it exceeds 3
      }
      updateLEDColor();
    }
    delay(50);               // Debounce delay to avoid multiple readings for one press
  }
  
  lastButtonState = buttonState;
}

void updateLEDColor() {
  // Turn off all LEDs
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   strip.setPixelColor(i, strip.Color(0, 0, 0));
  // }
  
  switch (buttonCounter) {
    case 1:
      // Red color
      strip.fill(strip.Color(255, 0, 0));
      strip.show();
      break;
    case 2:
      // Green color
      strip.fill(strip.Color(0, 255, 0));
      strip.show();
      break;
    case 3:
      // Blue color
      strip.fill(strip.Color(0, 0, 255));
      strip.show();
      break;
    case 4:
      // Reset
      strip.fill(strip.Color(0, 0, 0));
      strip.show();
      buttonCounter = 0;
      break;
    default:
      break;
  }
}
