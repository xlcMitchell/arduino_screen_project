#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*
* Connections
* SSD1306 OLED | Arduino Uno
* ---------------------------
*     VCC      |    +5V       (Vcc/power/+ve)
*     GND      |    GND       (Ground/-ve/0v)
*     SCL      |    A5        (Serial Clock Line)
*     SDA      |    A4        (Serial Data Line)
*/

const int SCREEN_WIDTH = 128; // OLED display width, in pixels
const int SCREEN_HEIGHT = 64; // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    while(true);
  }
}

void loop() {
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  // Display static text
  display.println("Software");
  display.display();
  delay(2000);
  setDisplayProperties(50);
  display.println("by");
  display.display();
  delay(2000);
  setDisplayProperties(20);
  display.println("Mitchell");
  display.display();
  delay(1000);
}

void setDisplayProperties(int cursor1){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(cursor1, 10);
}