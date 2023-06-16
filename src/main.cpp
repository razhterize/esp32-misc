#include "Arduino.h"
#include "BleKeyboard.h"

BleKeyboard keyboard;

void setup(){
  Serial.begin(115200);
  keyboard.begin();
}

void loop(){
  if (keyboard.isConnected()){
    Serial.println("Sending Data...");
    keyboard.print("Bitch");
    delay(500);
    keyboard.write(KEY_PAGE_DOWN);
  }
  delay(5000);
}