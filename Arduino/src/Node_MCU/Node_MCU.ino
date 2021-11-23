#include <ESP8266WiFi.h>
 
const char* ssid = "chenjun618666";// type in the SSID name which you want to connect
const char* password = "x618666x";// type the password of the WiFi AP you choose

WiFiServer server(80);// ESP8266 server
 
void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  if (req == "GET /favicon.ico HTTP/1.1")
    return;
  Serial.println(req);
  client.flush();

  String main =
  "<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP8266 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Hello from ESP8266!</h1>\
    <a href='192.168.1.216/gpio/1'> On </a>\
    </br>\
    <a href='192.168.1.216/gpio/0'> 0ff </a>\
    </br>\
    </br>\";
    
  String tail = 
  "\n</body>\
  </html>"

  // Match the request
  //.
  //.something happen during here
  //.
  // use indexOf() to know about if there is any condition matching the request 
 
  // below is the webpage already in the server
  //.
  //.
  //.
  // skip this part cause it just a webpage not the main point

  int val;
  if (req.indexOf("/gpio/0") != -1)
    val = 0;
  else if (req.indexOf("/gpio/1") != -1)
    val = 1;
  else {
    Serial.println("Nothing");  
  }
  
  String r = (val)?"On":"Off";
  Serial.println(r);
  String s = "<p> On </p>\\";
  
  client.print(main + s + tail);
  delay(1);
  Serial.println("Client disonnected\n");
 
}
