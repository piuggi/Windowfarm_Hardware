#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include "data_types.h"

void setup() {
 
 Serial.begin(9600); 
 start_ph();
 start_ec();
 setup_temp();
 
 
}


void loop() {
  Serial.println(get_ph());
  EC ec = get_ec();
  print_ec(ec);
  temps celcius = return_temps();
  print_temps(celcius);
  delay(4000);
}
