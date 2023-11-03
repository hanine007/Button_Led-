#include <Arduino.h>

#include <ezButton.h>


#define BUTTON_PIN  18 // ESP32 pin GPIO18, which connected to button
#define LED_PIN     2 // ESP32 pin GPIO2, which connected to led

ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 18;


void setup() {
  Serial.begin(115200);         // initialize serial
  pinMode(LED_PIN, OUTPUT);   // set ESP32 pin to output mode
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("The button is pressed");

    
    

    // control LED 
    digitalWrite(LED_PIN, HIGH);
  }
  else if (button.isReleased())
  {
    Serial.println("The button is  not pressed");

    

    // control LED 
    digitalWrite(LED_PIN, LOW);
  }
  
}
