//-----------------------------------------------------------------------------------------
//init ph by making sure we can communicate
void start_ph(){
  
 Serial2.begin(38400);
 Serial2.print("L1\r");
 delay(1000);
 Serial2.print("L0\r");
 delay(1000);
 Serial2.print("L1\r");
 
}
//-----------------------------------------------------------------------------------------
//function to ask for pH and return as float
float get_ph(){
 Serial.println("R\\r --> PH"); //let us know we are asking
 Serial2.print("R\r"); //ask device
 delay(500);
 return Serial2.parseFloat(); //return data as float
}

//-----------------------------------------------------------------------------------------
void start_ec(){
 
 Serial1.begin(38400);
 Serial1.print("L1\r");
 delay(1000);
 Serial1.print("L0\r");
 delay(1000);
 Serial1.print("L1\r");
  
}

//-----------------------------------------------------------------------------------------
void get_ec(){
 Serial.println("R\\r --> EC"); //let us know we are asking
 Serial1.print("R\r"); //ask device
 delay(500);
 
 Serial.print( Serial1.parseInt() );
 Serial.println();
 Serial.print( Serial1.parseInt() );
 Serial.println();
 Serial.print( Serial1.parseFloat() );
 
}
