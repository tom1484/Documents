#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial myPort(4, 5);

const char* ssid     = "chenjun618666";
const char* password = "x618666x";

String host = "www.same543.com";
const char* streamId   = "....................";
const char* privateKey = "....................";

#define COLUMNS {"Time", "String", ""}
#define DATAS {"Time", ("\\\"" + string + "\\\""), ""}

void setup() {
  
  Serial.begin(115200);
  myPort.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
  
}

void loop() {

  String string = "";
  
  if (myPort.available()) {
    string = getText();
  }
  
  if (string != "") {
    updateSQL(string);
  }
  
}

void updateSQL (String string) {

  String columns[] = COLUMNS;
  String datas[] = DATAS;

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.println(string);
  Serial.print("connecting to ");
  Serial.println(host);
  
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  String finalData = toJSON(columns, datas);

  String url = "http://" + host + "/info_write.php?sql=" + finalData;
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
}

String getText () {

  String string;
  char buff;
  while (myPort.available()) {
    buff = int(myPort.read());
    string += String(buff);
    delay(20);
  }
  return string;
  
}

String toJSON (String columns[], String datas[]) {
  
  String finalData = "{";
  String col = "";
  String dat = "";

  finalData += "\"Structures\":[";
  for (int i = 0; columns[i] != ""; i++) {
    columns[i].replace(" ", "%20");
    columns[i] = "\"" + columns[i] + "\"";
    if (i == 0) {
      col += columns[i];
    }else {
      col += ("," + columns[i]);  
    }
  }
  finalData += (col + "],");

  finalData += "\"Datas\":[";
  for (int i = 0; datas[i] != ""; i++) {
    datas[i].replace(" ", "%20");
    datas[i] = "\"" + datas[i] + "\"";
    if (i == 0) {
      dat += datas[i];
    }else {
      dat += ("," + datas[i]);  
    }
  }
  finalData += (dat + "]}");

  return finalData;
  
}
