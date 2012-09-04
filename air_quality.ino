//define analog pins 
#define HUMIDITY A1
#define CO2 A0 

//define digital pins
#define CO2_CRTL 2

//-------------------------------------------------------
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

//-------------------------------------------------------
//Turn out control pin to High on our Parallax CO2 Break out board.
void setup_co2(){
 pinMode(CO2_CRTL, OUTPUT); //Digital Pin
 digitalWrite(CO2_CRTL, HIGH);
 //Serial.print("CO2 Ready..."); 
}

//-------------------------------------------------------
//return analog value from co2 sensor
int return_co2(){
  int val = analogRead(CO2);
  return val;
}
