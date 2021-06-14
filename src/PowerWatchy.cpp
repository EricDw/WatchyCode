#include "PowerWatchy.h"

#define DARKMODE false

PowerWatchy::PowerWatchy() {} //constructor

void PowerWatchy::drawWatchFace()
{
    String batteryLevel = "";

    float VBAT = getBatteryVoltage();

    if (VBAT > 4.1)
    {
        batteryLevel = "HIGH";
    }
    else if (VBAT > 3.95 && VBAT <= 4.1)
    {
        batteryLevel = "MEDIUM";
    }
    else if (VBAT > 3.80 && VBAT <= 3.95)
    {
        batteryLevel = "LOW";
    }
    else if (VBAT <= 3.80)
    {
        batteryLevel = "DEAD";
    }
    
    display.setTextSize(0.5);
    display.setRotation(1);
    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    display.setFont(&Px437_IBM_BIOS5pt7b);
    display.setCursor(0, 24);
    display.setTextSize(2);
    display.println("B: " + batteryLevel);
    drawSpacer();
    display.print("Y: ");
    display.println(currentTime.Year + YEAR_OFFSET);
    drawSpacer();
    display.print("M: ");

    if (currentTime.Month <= 9)
    {
        display.print("0");
    }

    display.println(currentTime.Month);
    drawSpacer();
    display.print("D: ");
    display.println(currentTime.Day);
    drawSpacer();
    display.print("T: ");
    display.print(currentTime.Hour);
    display.print(':');
    display.println(currentTime.Minute);
}