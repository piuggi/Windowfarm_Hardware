typedef struct {
  
   long int conductivity;
   long int tds;
   float salinity;
  
} EC;

typedef struct{

    float air;
    float water;

} TEMPS;

typedef struct {
    
  uint32_t lum, lux;
  uint16_t ir, full, visible;
  
}Light;

typedef struct {
      Light _light;
      TEMPS _temp;
      EC _ec;
      float _ph;
      float _hum;
      int _co2; 
      int _mos;
}AllVals;

