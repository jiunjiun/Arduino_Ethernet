#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // 乙太網路
IPAddress ip(192, 168, 0, 30);                     // local IP
IPAddress remote(192, 168, 0, 130);                // remote IP
EthernetServer Listen(80);                         // server
EthernetClient client;                             // client

int time = 0;
String Request; 

void setup() {
  Ethernet.begin(mac, ip);
  Listen.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP()); 
}

void loop() {
  EthernetSend();
  EthernetListen();
}

void EthernetSend() {
  if(time == 5) { 
    Deliver();
    time = 0;
  }
  time++;
}

void Deliver() {
  Serial.println("connecting...");
  if (client.connect(remote, 80)) {
    Serial.println("connected");
    client.print("GET /");  //
    client.print("/");
    client.println(" HTTP/1.0");
    client.println();

    client.stop();
    client.flush();
    Serial.println("send!!");
  } else {
    Serial.println("connection failed");
  }
}

void EthernetListen() {
  // Listen for incoming clients
  EthernetClient client = Listen.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Request += c;
        if (c == '\n' && currentLineIsBlank) {
          Control(Request);
          Serial.println(Request);
          Request = "";
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    client.stop();
    Serial.println("client disonnected");
  }
}

void Control(String Request) {
  if(Request.indexOf("/do_something1") > -1) {
    //do something 1  ....
  } else if(Request.indexOf("/do_something2") > -1) {
    //do something 2  .... 
  }
}
