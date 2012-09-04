//-----------------------------------------------------------------------------------------
//init ph by making sure we can communicate
void start_ph(){
  
 Serial2.begin(DATABAUD);
 //Serial2.setTimeout(3000);
 Serial2.print("L1\r");
 delay(1000);
 Serial2.print("L0\r");
 delay(1000);
 Serial2.print("L1\r");
 
}
//-----------------------------------------------------------------------------------------
//function to ask for pH and return as float
float get_ph(float _c){
 Serial.println("R\\r --> PH"); //let us know we are asking
 Serial2.print(_c);
 Serial2.write(13); //ask device
 delay(500);
 return Serial2.parseFloat(); //return data as float
}

//-----------------------------------------------------------------------------------------
void start_ec(){
 
 Serial1.begin(DATABAUD);
 //Serial1.setTimeout(3000);
 Serial1.print("L1\r");
 delay(1000);
 Serial1.print("L0\r");
 delay(1000);
 Serial1.print("L1\r");
  
}

//-----------------------------------------------------------------------------------------
EC get_ec(float _c){
 EC t;
 //Serial.println("R\\r --> EC"); //let us know we are asking
 Serial1.print(_c);
 Serial1.print("\r"); //ask device
 delay(500);
 
 t.conductivity= Serial1.parseInt() ;
 t.tds = Serial1.parseInt();
 t.salinity = Serial1.parseFloat();
 
 return t;
 
}

void print_ec(EC &_t){
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("EC");
  Serial.print("Conductivity \t");
  Serial.println(_t.conductivity);
  Serial.print("tds \t");
  Serial.println(_t.tds);
  Serial.print("salinity \t");
  Serial.println(_t.salinity);
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  
}
