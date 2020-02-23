
// we replicated the display that wall e had in the original movie

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <stdio.h>
// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define YELLOW2 0xFF81
#define PALEYELLOW 0xBDA1
#define PALEYELLOW2 0x9460
#define WHITE   0xFFFF

#define __CS 10
#define __DC 9

TFT_ILI9163C display = TFT_ILI9163C(__CS, 8, __DC);
class point {
  public:
    int x;
    int y;
    point(int x = 0, int y = 0) {
      this->x = x;
      this->y = y;
    }

};

void drawCircle(int x, int y, int radius, int color)
{
  for (int i = 0; i < 360; i++)
  {
    double radians = i * PI / 180;
    double px = x + radius * cos(radians);
    double py = y + radius * sin(radians);
    display.drawPixel(px, py, color);
  }
}




// Function to find the line given two points
int getXOnLine(int Y, int ax, int ay, int bx, int by)
{
  double a = by - ay;
  double b = ax - bx;
  double c = a * (ax) + b * (ay);

  //line ecuation: ax + by = c
  //if we want x = (c-by) / a
  //if we want y = (c-ax) / b
  /*Serial.println(ax);
    Serial.println(ay);
    Serial.println(bx);
    Serial.println(by);*/

  return (c - b * Y) / a;
}
int getYOnLine(int X, int ax, int ay, int bx, int by)
{
  double a = by - ay;
  double b = ax - bx;
  double c = a * (ax) + b * (ay);
  //line ecuation: ax + by = c
  //if we want x = (c-by) / a
  //if we want y = (c-ax) / b
  return (c - a * X) / b;
}

void drawSunWaves(int x, int y, int radius, int color)
{
  int waveLen = 5;
  int smallWaveLen = 3;
  for (int i = 5; i < 360; i += 20)
  {
    double radians = i * PI / 180;
    double px = x + radius * cos(radians);
    double py = y + radius * sin(radians);
    //int xOnLine = getXOnLine(py + 1, px, py, x, y);
    //int yOnLine = getYOnLine(px + 1, px, py, x, y);
    if (i > 0 && i < 85)
    {

      int yOnLine = getYOnLine(px + waveLen, px, py, x, y);
      display.drawLine(px, py, px + waveLen, yOnLine, color);
      /*Serial.println(py);
        Serial.println(px+1);
        Serial.println(yOnLine);*/

    }
    else if (i > 105 && i < 165)
    {
      int yOnLine = getYOnLine(px - waveLen, px, py, x, y);
      display.drawLine(px, py, px - waveLen, yOnLine, color);

    }
    else if (i > 180 &&  i < 265)
    {
      int yOnLine = getYOnLine(px - waveLen, px, py, x, y);
      display.drawLine(px, py, px - waveLen, yOnLine, color);
    }
    else if (i > 285 && i < 360)
    {
      int yOnLine = getYOnLine(px + waveLen, px, py, x, y);
      display.drawLine(px, py, px + waveLen, yOnLine, color);
    }
    else if (i == 285)
    {
      smallWaveLen = 3;
      int yOnLine = getYOnLine(px + smallWaveLen, px, py, x, y);
      display.drawLine(px, py, px + smallWaveLen, yOnLine, color);
    } else if (i == 265)
    {
      smallWaveLen = 2;
      int yOnLine = getYOnLine(px - smallWaveLen, px, py, x, y);
      display.drawLine(px, py, px - smallWaveLen, yOnLine, color);
    } else if (i == 165)
    {
      smallWaveLen = 2;
      int yOnLine = getYOnLine(px - smallWaveLen, px, py, x, y);
      display.drawLine(px, py, px - smallWaveLen, yOnLine, color);
    } else if (i == 105)
    {
      smallWaveLen = 4;
      int yOnLine = getYOnLine(px - smallWaveLen, px, py, x, y);
      display.drawLine(px, py, px - smallWaveLen, yOnLine, color);
    }

    // down line



  }
  int i = 84;
  double radians = i * PI / 180;
  double px = x + radius * cos(radians);
  double py = y + radius * sin(radians);
  int yOnLine = getYOnLine(px + 1, px, py, x, y);
  display.drawLine(px, py, px + 1, yOnLine, color);

}

void setup() {
  Serial.begin(9600);
  display.begin();
  display.clearScreen();
  display.setCursor(0, 0);

  // draw the solar light battery level

  //display.drawLine(0, 0, 50, 50, RED);
  display.fillRect(45, 100, 70, 20, YELLOW);
  display.fillRect(45, 90, 70, 5, YELLOW);
  display.fillRect(45, 80, 70, 5, YELLOW);
  display.fillRect(45, 70, 70, 5, YELLOW);
  display.fillRect(45, 60, 70, 5, YELLOW);
  display.fillRect(45, 50, 70, 5, YELLOW);
  display.fillRect(45, 40, 70, 5, YELLOW);

  // display the sun drawing from on the display
  drawCircle(25, 50, 12, YELLOW2);
  drawCircle(25, 50, 11, YELLOW2);
  drawCircle(25, 50, 10, YELLOW2);
  //drawCircle(20, 25, 13, PALEYELLOW);

  drawCircle(25, 50, 8, PALEYELLOW2);
  drawSunWaves(25, 50, 12, YELLOW2);

  display.setCursor(13, 10);
  display.setTextColor(YELLOW);
  display.print("SOLAR CHARGE LEVEL");
}

void loop() {

  // turns on and off the line that shows how high the solar light level is
  display.fillRect(45, 40, 70, 5, BLACK);
  delay(2000);
  display.fillRect(45, 40, 70, 5, YELLOW);
  delay(2000);

}
