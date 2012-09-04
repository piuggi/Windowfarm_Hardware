#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <TSL2561.h>
#include "data_types.h"

#define BAUD 9600
#define DATABAUD 38400

void setup() {
 
 Serial.begin(BAUD); 
 start_ph();
 start_ec();
 setup_temp();
 setup_co2();
 
}


void loop() {
  
  TEMPS currentTemp = return_temps();
  print_temps(currentTemp);
  
  Serial.println(get_ph(currentTemp.water));
  
  EC ec = get_ec(currentTemp.water);
  print_ec(ec);
  
  Serial.print("Relative Humidity: \t");
  Serial.println(return_rH(currentTemp.air));
  
  Serial.print("CO2 \t");
  Serial.println(return_co2());
  
  Light currentLight = get_light();
  print_light(currentLight);
  
  delay(4000);
}
