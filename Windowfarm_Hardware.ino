#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <TSL2561.h>
#include <SPI.h>
#include <WiFly.h>
#include "keys.h"
#include "data_types.h"


#define BAUD 9600
#define DATABAUD 38400

void setup() {
 
 Serial.begin(BAUD); 
 setup_wifly();
 start_ph();
 start_ec();
 setup_temp();
 setup_co2();
 
}

void loop() {
  
  AllVals sensor;
  
  sensor._temp = return_temps();
  print_temps(sensor._temp);
  
  sensor._ph = get_ph(sensor._temp.water);
  Serial.println(sensor._ph);
  
  sensor._ec = get_ec(sensor._temp.water);
  print_ec(sensor._ec);
  
  sensor._hum = return_rH(sensor._temp.air);
  
  Serial.print("Relative Humidity: \t");
  Serial.println(sensor._hum);
  
  sensor._co2 = return_co2();
  Serial.print("CO2 \t");
  Serial.println(sensor._co2);
  
  sensor._mos = return_moisture();
  Serial.print("MOISTURE \t");
  Serial.println(sensor._mos);
  
  sensor._light = get_light();
  print_light(sensor._light);
  
  send_data(sensor);
  delay(4000);
}
