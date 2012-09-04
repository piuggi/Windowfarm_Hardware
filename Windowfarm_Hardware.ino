void setup() {
 
 Serial.begin(9600); 
 start_ph();
 start_ec();
 
 
}


void loop() {
  Serial.println(get_ph());
  get_ec();
  delay(4000);
}
