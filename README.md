# ESP32 Water Monitoring System
![first-timers-difficulty](https://img.shields.io/badge/First--Timers--Difficulty-friendly-green.svg?logo=github) ![License](https://img.shields.io/badge/License-Open--Source-blue.svg?logo=github)

ESP32 Water Monitoring System is an IoT based Liquid Level Monitoring system that has the mechanism to keep the user alerted in case of liquid overflow or when tank depletes. The water tanks can be fixed with ultrasonic sensors that is placed over the container. Ultrasonic sensor is used to measure, compare container depth and liquid level.

The status of the system could be monitored by a LCD screen or a web page that provides a brilliant graphical representation. Colors are used to depict various scenarios with respect to the amount of liquid in the tanks or containers

> note that this is just the  version 1.0 of this project so more added featutres are on the way

The IoT(Hardware) components required are:

- **ESP32 Development Board**  **[Buy From Here](https://www.example.com/)**
- **LCD Screen**  **[Buy From Here](https://www.example.com/)**
- **Wifi Modem**  **[Buy From Here](https://www.example.com/)**
- **Ultra Sonic Sensor**  **[Buy From Here](https://www.example.com/)**
- **5V Power Supply** **[Buy From Here](https://www.example.com/)**
- **5V Relay**  **[Buy From Here](https://www.example.com/)**
- **Jumper Wires**  **[Buy From Here](https://www.example.com/)**

## Getting Started

1. First you need to install the Arduino IDE software
  - **You can download it from **[Here](https://www.arduino.cc/en/software)****
2. Now you need to Add the ESP32 boards to the Arduino IDE in the menu bar, select File> Preferences then Enter the following into the “Additional Board Manager URLs” field:
    
        https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
3. You would need to downlaod and install the following libraries using the following steps:
  - **[Adafruit_SSD1306_EMULATOR](https://github.com/sam-peach/Adafruit_SSD1306_EMULATOR)**
  - **[Adafruit_GFX_Library](https://github.com/adafruit/Adafruit-GFX-Library)**
  - **[Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)**
  - **[Web_Sockets](https://www.arduinolibraries.info/libraries/web-sockets)**
  
  - **Now in the Arduino IDE add the downloaded libraries by navigating to
   Sketch > Include Library > Add . ZIP Library**
  4. Download the Github .ZIP file of this project.
  5. Now extract that .ZIP file and open the CODE.ino file.
  6. Select the **DOIT ESP32 DEVKIT V1** (or a similar ESP32 board) with Tools > Board , then click on the appropriate PORT.
  7. Now change these variables with what you have:
   

    #define  TH  50 // Write Here The Maximum Height Of The Water Inside The Water Tank In cm (Total Capacity In cm) Note:The Maximum sensor distance is rated at 400-500cm)
    
    #define  IGH  20 // Witre Here The Ignored Height Above The Water Tank In cm (Distance Between The Sensor And The 100% Of Water Level)
    
    #define  TC  1600 // Write Here The Total Capacity Of The Water Tank In Liters
    
    const  char* ssid = "SSID"; // Write your SSID here
    
    const  char* password = "PASSWORD"; // Write your PASSWORD here
    
    
 8. Now connect your components like shown in the following image:
 ![Montage Image](Montage%20ESP32.png)
 9. Upload the sketch by pressing CTRL+U inside the Arduino IDE.
 10. After it being compiled and uploaded, go to the Serial Monitor (CTRL+SHIFT+M) and copy the local ip shown then paste it in the search bar of your browser
 > example: Local IP 192.168.43.155
 11. A page like this will be shown to you and it got the live state of the water level with an additional switch to toggle the water pump (aka motor) on or off:
