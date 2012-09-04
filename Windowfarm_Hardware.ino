#include "data_types.h"

void setup() {
 
 Serial.begin(9600); 
 start_ph();
 start_ec();
 
 
}


void loop() {
  Serial.println(get_ph());
  EC ec = get_ec();
  print_ec(ec);
  delay(4000);
}
