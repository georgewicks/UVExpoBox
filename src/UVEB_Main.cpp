/**
 * @file UVEB_Main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Test code --- from Example by Rui Santos


/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */

#include <OneWire.h>

// Based on the OneWire library example

OneWire ds(15);  //data wire connected to GPIO15

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte i;
  byte addr[8];
  
  if (!ds.search(addr)) {
    Serial.println(" No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  Serial.print(" ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }
}
