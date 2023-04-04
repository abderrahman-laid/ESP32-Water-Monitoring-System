#include <splash.h>                          // Used To Display The Adafruit Logo In The Beginning
#include <Adafruit_GFX.h>                    // Used For For Drawing Lines, Rectangles, Circles, Text, And Images, As Well As Functions For Changing The Color And Size Of Drawn Shapes.
#include <Adafruit_SSD1306.h>                // Used For Controlling The Display And Drawing Graphics On It.
#include <WiFi.h>                            // Used For Connecting To A Wi-Fi Network And For Communicating With Other Devices Over The Network. It Allows The Board To Act As A Client Or Server On A Wi-Fi Network    
#include <WebServer.h>                       // Used To Receive Http Requests From Clients, Such As Web Browsers Or Mobile Apps, And To Send Responses Back To Those Clients.
#include <WebSocketsServer.h>                // Used To Establish A Two-way Communication Channel With A Client, Such As A Web Browser Or Mobile App, Over A Single Tcp Connection.
#define OLED_RESET 4                         // Pin For OLED Reseting (For Updating Its Content)
Adafruit_SSD1306 display(OLED_RESET);        // Used To Updates The Display With The Latest Content (Reseting The Display In This Case).
#define TRIGGER_PIN  26                      // Pin For The Ultra Sonic's Sensor Trigger
#define ECHO_PIN     27                      // Pin For The Ultra Sonic's Sensor Echo
#define TH 50                                // Write Here The Maximum Height Of The Water Inside The Water Tank In cm (Total Capacity In cm) Note:The Maximum sensor distance is rated at 400-500cm)
#define IGH 20                               // Witre Here The Ignored Height Above The Water Tank In cm (Distance Between The Sensor And The 100% Of Water Level)
#define TC 1600                              // Write Here The Total Capacity Of The Water Tank In Liters
const char* ssid = "SSID";            // Write your SSID here
const char* password = "PASSWORD";     // Write your PASSWORD here
WebServer server(80);                        // Used To Creates A Web Server Object That Listens For Incoming Http Requests On The Specified Port (80 In This Case).
WebSocketsServer webSocket = WebSocketsServer(81);  // Used To Creates A Websocket Server Object That Listens For Incoming Websocket Connections On The Specified Port (81 In This Case).
#define LED 32                               // Pin For The Relay
boolean LEDonoff=false;                      // Boolean Value For The Relay State
String JSONtxt;                              // Used To Declare A String Value To JSONtxt
#include "webpage.h"                         // Use For The Webpage
#include "functions.h"                       // Used For Decaring Some Functions
long duration, distance;                     // Used To Declare Duration And Distance
int WH,P,C;                                  // Used To Declare WH,P,C
//=================================================================================================================================================================================================================================================================================================
void setup() {                               // Used To Put Code Here To Be Ran Once
  Serial.begin(9600);                        // Used To Initializes The Serial Communication With A Baud Rate Of 9600 Bits Per Second.
  pinMode(LED, OUTPUT);                      // Used To Specifie That The Pin Will Be Used As An Output Pin.
  pinMode(TRIGGER_PIN, OUTPUT);              // Used To Specifie That The Pin Will Be Used As An Output Pin.
  pinMode(ECHO_PIN, INPUT);                  //  Used To Specifie That The Pin Will Be Used As An Input Pin.
//=================================================================================================================================================================================================================================================================================================
  WiFi.begin(ssid, password);                // Used To Connects The Board To The Specified Wi-fi Network Using The Provided Ssid (Network Name) And Password.
  while(WiFi.status() != WL_CONNECTED)       // Used To Returns The Current Status Of The Wi-fi Connection, Such As "Connected", "Disconnected", Or "Connecting".
  {
    Serial.print("."); delay(500);           // Used For Showing Text In The Serial Monitor
  }
  WiFi.mode(WIFI_STA);                       // Used To Set The WIFI To A WiFi Station mode.
  Serial.print(" Local IP: ");               // Used For Showing Text In The Serial Monitor
  Serial.println(WiFi.localIP());            // Used To Returns The Local Ip Address Of The Board On The Wi-fi Network.
//=================================================================================================================================================================================================================================================================================================
  server.on("/", handleRoot);                // Used To Sets Up A Handler Function For A Specific Url Path On The Web Server. When A Client Makes An Http Request To That Path, The Handler Function Is Called And Can Generate A Response To Send Back To The Client.
  server.begin();                            // Used To Starts The Websocket Server And Begins Listening For Incoming Connections.
  webSocket.begin();                         // Used To Initializes The WebSocket Server 
  webSocket.onEvent(webSocketEvent);         // Used To Registers An Event Handler Function For Websocket Events On The Websocket Server,The Websocket.Onevent() Function Can Be Called Multiple Times In An Arduino Sketch To Register Multiple Event Handlers For Different Websocket Events.
//=================================================================================================================================================================================================================================================================================================
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Used To Initialize With The I2C Address 0X3C (For The 128X32 OLED Display) 
  display.display();                         // Used To Clear The Display.
  delay(1000);                               // Used To Set A 1 Second Delay.
  display.clearDisplay();                    // Used To Clear The Display (Clear The Buffer).
} 
//=================================================================================================================================================================================================================================================================================================
                                             // The sensor is triggered by a HIGH pulse of 10 or more microseconds. 
                                             // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
void loop() {                                // Used To Put Code Here To Be Ran Repeatedly
  digitalWrite(TRIGGER_PIN, LOW);            // Used To sets the digital output pin TRIGGER_PIN to a low voltage level, which corresponds to a logical value of 0.
  delayMicroseconds(5);                      // Used To Set A 5 Micro-Second Delay
  digitalWrite(TRIGGER_PIN, HIGH);           // Used To sets the digital output pin TRIGGER_PIN to a high voltage level, which corresponds to a logical value of 1.
  delayMicroseconds(10);                     // Used To Set A 10 Micro-Second Delay
  digitalWrite(TRIGGER_PIN, LOW);            // Used To sets the digital output pin TRIGGER_PIN to a low voltage level, which corresponds to a logical value of 0. 
                                             // Read the signal from the sensor: a HIGH pulse whose 
                                             // duration is the time (in microseconds) from the sending 
                                             // of the ping to the reception of its echo off of an object. 
  duration = pulseIn(ECHO_PIN, HIGH);        // Used To Measures The Duration Of A Pulse On A Digital Input Pin Echo_Pin.
  distance = (duration/2) / 29.1;            // Used To convert the time into a distance 
  WH=(TH+IGH)-distance;                      // WH Is The Water Height In cm
  P=(WH*100)/TH;                             // P Is The Water Percentage
  C=(P*TC)/100;                              // C Is The Real Time Capacity Of The Water Tank
//=================================================================================================================================================================================================================================================================================================
  if (P > 100 || P<0) {                      // Used To Set An If Condition In Case The Water Rises More That 100%
    Serial.print("The Water Is Leaking\n");  // Used For Showing Text In The Serial Monitor
  } 
  else {                                     // Used For The Resting Condition
    Serial.print("Capacity: " + String(C) + " Liters\n"); // Used For Showing Text In The Serial Monitor
    Serial.print("Percentage: " + String(P) + " %\n");    // Used For Showing Text In The Serial Monitor
  } 
//=================================================================================================================================================================================================================================================================================================
  if (P > 100 || P<0) {                      // Used To Set An If Condition In Case The Water Rises More That 100%
  display.clearDisplay();                    // Used To Clear The Display
  display.setTextSize(1);                    // Used To Set The Text's Size
  display.setTextColor(WHITE);               // Used To Set The Font's Color        
  display.setCursor(0,0);                    // Used To  Sets The Cursor Position For Text On The Display.
  display.print("---------------------\n");  // Used For Showing Text On The Display
  display.print("   W A R N I N G !   \n");  // Used For Showing Text On The Display 
  display.print(" Water Level > 100 % \n");  // Used For Showing Text On The Display
  display.print("---------------------\n");  // Used For Showing Text On The Display
  } 
  else {                                     // Used For The Resting Condition
  display.clearDisplay();                    // Used To Clear The Display
  display.setTextSize(2);                    // Used To Set The Text's Size
  display.setTextColor(WHITE);               // Used To Set The Font's Color   
  display.setCursor(0,0);                    // Used To  Sets The Cursor Position For Text On The Display. 
  display.println("" + String(C) + "Liters");// Used For Showing Text On The Display
  display.print("Or " + String(P) + " %");   // Used For Showing Text On The Display
  } 
  display.display();                         // Used To Clear The Display
//=================================================================================================================================================================================================================================================================================================
  webSocket.loop();                          // Used to repeatedly processe incoming WebSocket messages and events on the WebSocket server.
  server.handleClient();                     // Used To processe incoming client requests on the HTTP server.
//=================================================================================================================================================================================================================================================================================================
  static unsigned long l = 0;                // Used To Track time intervals and retain their values across multiple iterations of the loop.
  unsigned long t = millis();                // Used to track the starting time of an operation and calculate elapsed time using the millis() function.
  if((t-l) > 1000)                           // Used To Set An If Condition In Case The (t-l) > 1000
  {
    if(LEDonoff == false) digitalWrite(LED, LOW); // Used to turn the Relay Off if the condition is off
    else digitalWrite(LED, HIGH);            // Used to turn the Relay On if the condition is on
    String LEDstatus = "OFF";                // Status of the Relay
    if(LEDonoff == true) LEDstatus = "ON";   // sed to turn the Relay On if the condition is on
//================================================================================================================================================================================================================================================================================================= 
    String capacityvalString = String(C);    // Used to give a value to a string
    String percentagevalString = String(P);  // Used to give a value to a string
//=================================================================================================================================================================================================================================================================================================
    JSONtxt  = "{\"capacity\":\""+ capacityvalString +"\",";     // Used For generating a JSON-formatted string with a single key-value pair,
    JSONtxt += "\"percentage\":\""+ percentagevalString +"\",";  // where the value is the contents of a variable.This is a common way to transmit data between different
    JSONtxt += "\"LEDonoff\":\""+ LEDstatus +"\"}";              // systems or components using a lightweight and widely supported data format.
    webSocket.broadcastTXT(JSONtxt);                             // sends the JSON-formatted string as a text message to all connected clients.
  }                                                              // This allows the clients to receive and process the message in a way
  }                                                              // that is appropriate for their specific use case.