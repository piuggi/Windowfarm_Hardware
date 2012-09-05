//Via the Wifly-Pachube example code.
//Preset wifly using AT-commands to SSID & Password for better connection

//See : http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Wireless/WiFi/WiFly-RN-UM.pdf

WiFlyClient client("api.pachube.com", 80);

void setup_wifly(){
  Serial3.begin(DATABAUD);
  Serial.print("Setting up Wifly....");
  pinMode(13, OUTPUT);

  Serial.print("Set UART...");
  WiFly.setUart(&Serial3);
  delay(1000);
  Serial.print("Begin Wifly...");
  WiFly.begin();
  Serial.print("Connecting...");
  Serial.println("Wifly Ready");
    Serial.println();
  delay(1000);
}

void send_data(AllVals &_val){

   Serial.print("Checking Connection...");
  if(client.connect()){
   Serial.println("Connected!");
   digitalWrite(13,HIGH);
   client.print("PUT /v2/feeds/");
   client.print(PACHUBEFEED); 
   client.println(".csv HTTP/1.1");
   Serial.print("PUT /v2/feeds/");
   Serial.print(PACHUBEFEED); 
   Serial.println(".csv HTTP/1.1");
   client.println("Host: api.pachube.com");
   client.print("X-PachubeApiKey: ");
   client.println(APIKEY);
   Serial.println("Host: api.pachube.com");
   Serial.print("X-PachubeApiKey: ");
   Serial.println(APIKEY);
   client.println("User-Agent: Arduino (WiFly RN-XV)");
   client.println("Content-Type: text/csv");
   client.println("Content-Length: 140");
   client.println("Connection: close");
   client.println();//close header
   Serial.println("User-Agent: Arduino (WiFly RN-XV)");
   Serial.println("Content-Type: text/csv");
   Serial.println("Content-Length: 140");
   Serial.println("Connection: close");
   Serial.println();//close header
   //print formatted data csv body
   client.print("ph,");client.print(_val._ph);client.print("\r\n");
   Serial.print("ph,");Serial.print(_val._ph);Serial.print("\r\n");
   client.print("hum,");client.print(_val._hum);client.print("\r\n");
   Serial.print("hum,");Serial.print(_val._hum);Serial.print("\r\n");
   client.print("air,");client.print(_val._temp.air);client.print("\r\n");
   Serial.print("air,");Serial.print(_val._temp.air);Serial.print("\r\n");
   Serial.print("water,");Serial.print(_val._temp.water);Serial.print("\r\n");
   client.print("water,");client.print(_val._temp.water);client.print("\r\n");
   //Serial.print("moisture,");client.print(moisture);client.print("\r\n");
   //client.print("moisture,");client.print(moisture);client.print("\r\n");
   client.print("ec,");client.print(_val._ec.conductivity);client.print("\r\n");  
   Serial.print("ec,");Serial.print(_val._ec.conductivity);Serial.print("\r\n");  
   client.print("tds,");client.print(_val._ec.tds);client.print("\r\n");  
   Serial.print("tds,");Serial.print(_val._ec.tds);Serial.print("\r\n");  
   client.print("sal,");client.print(_val._ec.salinity);client.print("\r\n");  
   Serial.print("sal,");Serial.print(_val._ec.salinity);Serial.print("\r\n");  
   client.print("lux,");client.print(_val._light.lux);client.print("\r\n");  
   Serial.print("lux,");Serial.print(_val._light.lux);Serial.print("\r\n");  
   client.print("lum,");client.print(_val._light.lum);client.print("\r\n");    
   Serial.print("lum,");Serial.print(_val._light.lum);Serial.print("\r\n");    
   client.print("vis,");client.print(_val._light.visible);client.print("\r\n");
   Serial.print("vis,");Serial.print(_val._light.visible);Serial.print("\r\n");     
   client.print("ir,");client.print(_val._light.ir);client.print("\r\n");
   Serial.print("ir,");Serial.print(_val._light.ir);Serial.print("\r\n");     
   client.print("full,");client.print(_val._light.full);client.print("\r\n");
   Serial.print("full,");Serial.print(_val._light.full);Serial.print("\r\n");    
   client.print("co2,");client.print(_val._co2);client.print("\r\n");
   Serial.print("co2,");Serial.print(_val._co2);Serial.print("\r\n");     
   client.println();
   Serial.println();
   
   
  } else {
    Serial.println("Connection Failed");
  }
  delay(3000);
  if(client.available()>0){
    while(client.available()>0){
    char in = client.read();
    Serial.print(in);
    
    }
  }
  
  if(!client.connected()){
    Serial.println("Stopping Client");
    client.stop();
  }
  
  //Serial3.end();
  digitalWrite(13, LOW);
  
}
