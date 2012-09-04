
//Temp & onewire functions referenced from: 
//Beginning Arduino by Michael McRoberts
//Pages 307-315

//define one wire for temps
#define ONE_WIRE_BUS 4
#define TEMPERATURE_PRECISION 12

DeviceAddress WATER = {
  0x28, 0x76, 0xE6, 0xC1, 0x3, 0x00, 0x00, 0x20
};

DeviceAddress AIR = {
  0x28, 0x5D, 0x5B, 0xC2, 0x3, 0x00, 0x00, 0x45
};

float tempCAir, tempCWater;

//Create OneWire Object
OneWire onewire(ONE_WIRE_BUS);

DallasTemperature tempSensors(&onewire);

//-------------------------------------------------------
void setup_temp() {
  Serial.print("Setting up Temps...");
  tempSensors.begin();
  
  int sensors = tempSensors.getDeviceCount();
  
  tempConnect(AIR, 0);
  tempConnect(WATER, 1);
  
  tempSensors.setResolution(AIR, TEMPERATURE_PRECISION);
  tempSensors.setResolution(WATER, TEMPERATURE_PRECISION);

}

//-------------------------------------------------------
//Function to check an verify connection requires a reboot function
void tempConnect(DeviceAddress address, int num) {
  boolean tempInit = true;
  if(!tempSensors.getAddress(address, num)) tempInit = false;
  
  //-- if we don't get a connection with the device
  if(!tempInit){
    Serial.print("Error: Temp Connect Failed...");
    Serial.write(13);
    
    tempInit = true;
    if(!tempSensors.getAddress(address, num)) tempInit = false;
     
  }

  //-- if we don't get a connection with the device
  if(!tempInit){
    tempInit = true;

    if(!tempSensors.getAddress(address, num)){
      tempInit = false;      
      //reset the board
      //_reset();
    }
  } 
}

//-------------------------------------------------------
TEMPS return_temps(){
   //request our temps
   TEMPS _temp;
   tempSensors.requestTemperatures();

   _temp.air = celcius(AIR);
   _temp.water = celcius(WATER);
   return _temp;
}

//-------------------------------------------------------
void print_temps(TEMPS &_te){
   Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   Serial.print("Temps Air: ");
   Serial.print(_te.air);
   Serial.print("  Water: ");
   Serial.println(_te.water);
   Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

//-------------------------------------------------------
float celcius(DeviceAddress address) {

  float tempC = tempSensors.getTempC(address);
  return tempC; 

}
