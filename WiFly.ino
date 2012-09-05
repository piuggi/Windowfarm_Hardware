//Via the Wifly-Pachube example code.
//Preset wifly using AT-commands to SSID & Password for better connection

//See : http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Wireless/WiFi/WiFly-RN-UM.pdf

//WiFlyClient client("api.pachube.com", 80);


WiFlyClient client("http://requestb.in", 80);

void setup_wifly() {
  Serial.println("Set-up WiFly");
  // lots of time for the WiFly to start up and also in case I need to stop the transmit

  
  Serial3.begin(BAUD);  // default WiFly baud rate - good enough for this

  WiFly.setUart(&Serial3); // Tell the WiFly library that we are not using the SPIUart
  delay(10000);
  Serial.println("Wifly begin..");
  
  WiFly.begin();    // startup the WiFly

  Serial.println("Wifly ready..");
}

//char buff[64];
//int i;
void send_data(AllVals &_val){

    Serial.println("connecting...");
    if (client.connect()) {
      Serial.println("connected");
      client.print("PUT /v2/feeds/");  // APIV2
      client.print(PACHUBEFEED);
      client.println(".csv HTTP/1.1");
      client.println("Host: api.pachube.com");
      client.print("X-PachubeApiKey: ");
      client.println(APIKEY);
  
      client.println("User-Agent: Arduino (WiFly RN-XV)");
      client.print("Content-Type: text/csv\nContent-Length: ");
      client.println("110");
      client.println("Connection: close");
      client.println();
  
      client.print("ph,");client.println(_val._ph);
      client.print("hum,");client.println(_val._hum);
      client.print("air,");client.println(_val._temp.air);
      client.print("water,");client.println(_val._temp.water);
      //client.print("moisture,");client.println(moisture);
      client.print("ec,");client.println(_val._ec.conductivity);  
      client.print("tds,");client.println(_val._ec.tds); 
      client.print("sal,");client.println(_val._ec.salinity);  
      client.print("lux,");client.println(_val._light.lux);  
      client.print("lum,");client.println(_val._light.lum);    
      client.print("vis,");client.println(_val._light.visible);
      client.print("ir,");client.println(_val._light.ir);  
      client.print("full,");client.println(_val._light.full); 
      client.print("co2,");client.println(_val._co2); 
      client.println();
  
    } else {
      Serial.println("connection failed");
    }

    delay(2000);
    while (client.available()) {
      // TODO verify success (HTTP/1.1 200 OK)
      Serial.write(client.read());  // display the result
    }
    Serial.println();
   
    if (client.connected()) {
      Serial.println("disconnecting.");
      client.stop();
      Serial.println("disconnected.");
    }
}
