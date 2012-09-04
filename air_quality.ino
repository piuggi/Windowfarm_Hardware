#define HUMIDITY A1

float return_rH(float _t) {
  
  //RH
  int rHReading;
  float rHSample, rHCalc, voltage;
  float supplyVoltage = 5.0;
  
  rHReading = analogRead(HUMIDITY);
  voltage = rHReading/1023.0 * supplyVoltage;
  
  rHSample = 161.0*voltage/supplyVoltage - 25.8;
  rHCalc = rHSample / (1.0546 - 0.0026*_t);
  
  //Serial.println("DONE. ");
  return rHCalc;
  
}
