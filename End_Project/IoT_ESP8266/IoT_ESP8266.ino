#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClientSecureAxTLS.h>
//#include <SoftwareSerial.h>

void Line_Notify(String message);
     
// ใส่ชื่อพาสเวิดไฟไวของเรา
const char* ssid = "true_home2G_7Wq";
const char* password = "AdminPassword";

#define LINE_TOKEN "token"

ESP8266WebServer server(80);
MDNSResponder mdns;
     
String webPage = "";
String message = "Status Request";
String inString;
     
void setup(void)
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // ปริ้นค่าสถานะต่างๆ
  Serial.println("");
  Serial.println("ESP8266 board info:");
  Serial.print("\tChip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("\tCore Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("\tChip Real Size: ");
  Serial.println(ESP.getFlashChipRealSize());
  Serial.print("\tChip Flash Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("\tChip Flash Speed: ");
  Serial.println(ESP.getFlashChipSpeed());
  Serial.print("\tChip Speed: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("\tChip Mode: ");
  Serial.println(ESP.getFlashChipMode());
  Serial.print("\tSketch Size: ");
  Serial.println(ESP.getSketchSize());
  Serial.print("\tSketch Free Space: ");
  Serial.println(ESP.getFreeSketchSpace());

  // แสดงบนหน้าเว็บ
  webPage += "<h1>SMART MOBILE SHELF</h1>";
  webPage += "<p>LED state <a href=\"LedON\"><button>ON</button></a>&nbsp;<a href=\"LedOFF\"><button>OFF</button></a></p>";
  webPage += "<p><a href=\"request_status\"><button>Request Status</button></a></p>";
  //webPage += "<p>Status</p>";
  //webPage += 
  
  // เริ่มการเชื่อมต่อไวไฟ
  WiFi.begin(ssid, password);
  Serial.println("");
     

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP()))
  {
    Serial.println("MDNS responder started");
  }
     
  server.on("/", []()
  {
    server.send(200, "text/html", webPage);
  });

  server.on("/request_status", []()
  {
    server.send(200,"text/html",webPage);
    digitalWrite(13,1);
    Serial.println("[Request Status]");
    //Line_Notify(message);
    //return;
  });
  
  server.on("/LedON", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(13, HIGH);
    Serial.println("[ON]");
    delay(1000);
  });
  
  server.on("/LedOFF", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(13, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });

    server.on("/Led?????", []()
    {
    server.send(200, "text/html", webPage);
    digitalWrite(13, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });
  
  server.begin();
  Serial.println("HTTP server started");
  
}
     
void loop()
{
  server.handleClient();
  //Line_Notify(message);
}

void serial()
{
  if (Serial.available())
  {
    int inByte = Serial.read();
    Serial.write(inByte);
  }
  delay(100);
  /*while(Serial.available())
  {
    char Text = Serial.read();
    Serial.write(Text);
    inString += Text;
    if(Text == ']')
    {
      if(inString.indexOf("[Complete]")>0)
      {
        Serial.print("Complete!!!!!");
      }
      else
      {
        Serial.print("Nothing");
      }
      inString = "";
    }
  }*/
}

void Line_Notify(String message)
{
  axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  // Serial.println(req);
  client.print(req);
    
  delay(20);

  // Serial.println("-------------");
  while(client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
    //Serial.println(line);
  }
  // Serial.println("-------------");
}
