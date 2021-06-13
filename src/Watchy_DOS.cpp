#include "Watchy_DOS.h"

WatchyDOS::WatchyDOS(){} //constructor

void WatchyDOS::drawWatchFace(){
    char time[6];
    String batteryLevel = "";
    float VBAT = getBatteryVoltage();
    if(VBAT > 4.1){
        batteryLevel = "HIGH";
    }
    else if(VBAT > 3.95 && VBAT <= 4.1){
        batteryLevel = "MEDIUM";
    }
    else if(VBAT > 3.80 && VBAT <= 3.95){
        batteryLevel = "LOW";
    }    
    else if(VBAT <= 3.80){
        batteryLevel = "DEAD";
    }
    time[0] = '0' + ((currentTime.Hour/10)%10);
    time[1] = '0' + (currentTime.Hour%10); 
    time[2] = ':';
    time[3] = '0' + ((currentTime.Minute/10)%10);
    time[4] = '0' + (currentTime.Minute%10); 
    time[5] = 0;
    display.setTextSize(0.5);
    display.setRotation(1);
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS5pt7b);
    display.setCursor(0, 24);
    display.println("PowerWatchy 1.0.0");
    display.println("Copyright (c) EricD.");
    display.println(" ");
    display.print("AUTOEXEC BAT ");
    display.println(batteryLevel);
    display.println(" ");
    display.println("CLIHero >_ Get-Date");
    display.println("\n");
    display.setTextSize(2);
    display.print("  ");
    display.println(time);
    display.setTextSize(1);
    display.print("     ");
    display.print(currentTime.Year + YEAR_OFFSET);
    display.print("-");
    if (currentTime.Month <= 9)
    {
        display.print("0");
    }
    
    display.print(currentTime.Month);
    display.print("-");
    display.print(currentTime.Day);
    display.println("\n\nCLIHero >_");
}