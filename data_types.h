struct EC{
  
   long int conductivity;
   long int tds;
   float salinity;
  
};

struct TEMPS{

    float air;
    float water;

};

struct Light{
    
  uint32_t lum, lux;
  uint16_t ir, full, visible;
  
};

struct AllVals{
      Light _light;
      TEMPS _temp;
      EC _ec;
      float _ph;
      float _hum;
      int _co2; 
  
};

