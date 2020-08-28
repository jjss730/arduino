

#include "SPI.h"
#include "Adafruit_WS2801.h"
#include "PIRSensor.h"


// RevB: Uses the universal PCB connection board
// RevC: This configuration version is designed to work with the dedicated PCB.
// RevD: Add external control via Nextion Display to configure color of LEDs.


// ********************************************************************************************
// ********************** Hardware Setup ******************************************************
// ********************************************************************************************
PIRSensor PIR_up(3);     // PIR_up (sense going down) sensor is wired to DI pos 3
PIRSensor PIR_dw(2);     // PIR_dw (sense going up) sensor is wired to DI pos 2
uint8_t dataPin  = 5;    // Red wire on Led strip is wired to DO pos 5. Lower LED circuit
uint8_t clockPin = 4;    // Green wire on Led strip is wired to DO pos 4. Lower LED circuit
uint8_t dataPin2 = 12;     // Red wire on Led strip is wired to DO pos 12. Higher LED circuit
uint8_t clockPin2= 11;     // Green wire on Led strip is wired to DO pos 11. Higher LED circuit
uint16_t numberPixel = 160;    // Number of pixels in a row
uint16_t numberPixel2 = 160;
Adafruit_WS2801 strip = Adafruit_WS2801(numberPixel, dataPin, clockPin);  // Set the first variable to the NUMBER of pixels from "numberPixel" constant.
Adafruit_WS2801 strip2 = Adafruit_WS2801(numberPixel2, dataPin2, clockPin2);




// ********************************************************************************************
// ******************** Duration and Intensity Setup ******************************************
// ********************************************************************************************
int  MaxIntensity=24;    // Intensity  (0 - 64)
uint32_t riseTime = 200; // Rise Time in mSec   
uint32_t waitTime = 5000; // Time when LED stripe remains lit in mSec


//*********************************************************************************************
// *************************** Pixel Colors ***************************************************
// ********************************************************************************************
float red_1=64, green_1=0, blue_1=0;       //Colors for center pixels (0-64) 
float red_2=0, green_2=64, blue_2=0;       //Colors for border pixels (0-64)


// *********************** Other varialbles ***************************************************
// ********************************************************************************************

uint32_t cCenter, cBorder;    // Global variables for CenterColor (cCenter), BorderColor (cBorder)

unsigned int bco, red, grn, blu;   // Display color variables received from Nextion Display



// ********************************************************************************************
// *********************** Program Starts from Here ***************************************************
// ********************************************************************************************

void setup() {
  strip.begin();  // Update LED contents, to start they are all 'off'
  strip2.begin();
  strip.show(); 
  strip2.show();
  PIR_up.begin();
  PIR_dw.begin();

  Serial.begin(9600);

  pinMode (13, OUTPUT);
  digitalWrite (13,LOW);
}


void loop() { 
  if (Serial.available()){
    String data_from_display="";
    delay(30);
    while (Serial.available()){
      data_from_display += char(Serial.read());
    }
    Serial.println(data_from_display);
    sendData (data_from_display.substring(0,8), data_from_display);
  }
 
  if (PIR_dw.status()==1) {
    FadeIn (74, MaxIntensity,riseTime);
    FadeIn (64, MaxIntensity,riseTime); 
    FadeIn (54, MaxIntensity,riseTime); 
    FadeIn (44, MaxIntensity,riseTime); 
    FadeIn (34, MaxIntensity,riseTime);
    FadeIn (24, MaxIntensity,riseTime); 
    FadeIn (14, MaxIntensity,riseTime); 
    FadeIn (4, MaxIntensity,riseTime);  
    FadeIn2 (4, MaxIntensity,riseTime);
    FadeIn2 (14, MaxIntensity,riseTime);
    FadeIn2 (24, MaxIntensity,riseTime);
    FadeIn2 (34, MaxIntensity,riseTime);
    FadeIn2 (44, MaxIntensity,riseTime);
    FadeIn2 (54, MaxIntensity,riseTime);
    FadeIn2 (64, MaxIntensity,riseTime);
    FadeIn2 (74, MaxIntensity,riseTime);  

    delay (5000);

    FadeOut (74, MaxIntensity,riseTime);
    FadeOut (64, MaxIntensity,riseTime); 
    FadeOut (54, MaxIntensity,riseTime); 
    FadeOut (44, MaxIntensity,riseTime); 
    FadeOut (34, MaxIntensity,riseTime);
    FadeOut (24, MaxIntensity,riseTime); 
    FadeOut (14, MaxIntensity,riseTime); 
    FadeOut (4, MaxIntensity,riseTime);  
    FadeOut2 (4, MaxIntensity,riseTime);
    FadeOut2 (14, MaxIntensity,riseTime);
    FadeOut2 (24, MaxIntensity,riseTime);
    FadeOut2 (34, MaxIntensity,riseTime);
    FadeOut2 (44, MaxIntensity,riseTime);
    FadeOut2 (54, MaxIntensity,riseTime);
    FadeOut2 (64, MaxIntensity,riseTime);
    FadeOut2 (74, MaxIntensity,riseTime);  
  }

  if (PIR_up.status()==1) {
    FadeIn2 (74, MaxIntensity,riseTime);
    FadeIn2 (64, MaxIntensity,riseTime);
    FadeIn2 (54, MaxIntensity,riseTime);
    FadeIn2 (44, MaxIntensity,riseTime);
    FadeIn2 (34, MaxIntensity,riseTime);
    FadeIn2 (24, MaxIntensity,riseTime);
    FadeIn2 (14, MaxIntensity,riseTime);
    FadeIn2 (4, MaxIntensity,riseTime); 
    FadeIn (4, MaxIntensity,riseTime);
    FadeIn (14, MaxIntensity,riseTime); 
    FadeIn (24, MaxIntensity,riseTime); 
    FadeIn (34, MaxIntensity,riseTime); 
    FadeIn (44, MaxIntensity,riseTime);
    FadeIn (54, MaxIntensity,riseTime); 
    FadeIn (64, MaxIntensity,riseTime); 
    FadeIn (74, MaxIntensity,riseTime);  
 

    delay (5000);

    FadeOut2 (74, MaxIntensity,riseTime);
    FadeOut2 (64, MaxIntensity,riseTime);
    FadeOut2 (54, MaxIntensity,riseTime);
    FadeOut2 (44, MaxIntensity,riseTime);
    FadeOut2 (34, MaxIntensity,riseTime);
    FadeOut2 (24, MaxIntensity,riseTime);
    FadeOut2 (14, MaxIntensity,riseTime);
    FadeOut2 (4, MaxIntensity,riseTime); 
    FadeOut (4, MaxIntensity,riseTime);
    FadeOut (14, MaxIntensity,riseTime); 
    FadeOut (24, MaxIntensity,riseTime); 
    FadeOut (34, MaxIntensity,riseTime); 
    FadeOut (44, MaxIntensity,riseTime);
    FadeOut (54, MaxIntensity,riseTime); 
    FadeOut (64, MaxIntensity,riseTime); 
    FadeOut (74, MaxIntensity,riseTime); 
  }

}
// ************************************************************************************
// ****************  Function Definitions  ********************************************
// ************************************************************************************

void FadeIn (int num, int maxIntensity, uint32_t transTime) {      // Turn on Pixels 

     uint32_t currentTime, previousTime;

     currentTime = millis();
     previousTime = currentTime;
       
     for (int i=1; i<MaxIntensity; i=i+4){   
        cCenter=Color(i*(red_1/64),i*(green_1/64),i*(blue_1/64));
        cBorder=Color(i*(red_2/64),i*(green_2/64),i*(blue_2/64));
        strip.setPixelColor(num-4,cBorder);
        strip.setPixelColor(num-3,cCenter);
        strip.setPixelColor(num-2,cCenter);
        strip.setPixelColor(num-1,cCenter);
        strip.setPixelColor(num,cCenter);
        strip.setPixelColor(num+1,cCenter);
        strip.setPixelColor(num+2,cCenter);
        strip.setPixelColor(num+3,cCenter);
        strip.setPixelColor(num+4,cCenter);
        strip.setPixelColor(num+5,cBorder);
        strip.show(); 
        currentTime=millis();
        if ((currentTime - previousTime)<(4*transTime/MaxIntensity)){
          while((currentTime - previousTime)<(4*transTime/MaxIntensity)){
            currentTime=millis();
//            Serial.print (currentTime - previousTime);                    // Remove comment for troubleshooting
//            Serial.println ("   Waiting... ");                    // Remove comment for troubleshooting
          }
        }
        previousTime=currentTime;
  //      Serial.print ("Fade In ");                    // Remove comment for troubleshooting
  //      Serial.print (i);                    // Remove comment for troubleshooting
  //      Serial.print ("    tranTime ");                    // Remove comment for troubleshooting
  //      Serial.println (transTime/MaxIntensity);                    // Remove comment for troubleshooting
     }
  
}

void FadeIn2 (int num, int maxIntensity, uint32_t transTime) {      // Turn on Pixels 

     uint32_t currentTime2, previousTime2;

     currentTime2 = millis();
     previousTime2 = currentTime2;
       
     for (int i=1; i<MaxIntensity; i=i+4){   
        cCenter=Color(i*(red_1/64),i*(green_1/64),i*(blue_1/64));
        cBorder=Color(i*(red_2/64),i*(green_2/64),i*(blue_2/64));
        strip2.setPixelColor(num-4,cBorder);
        strip2.setPixelColor(num-3,cCenter);
        strip2.setPixelColor(num-2,cCenter);
        strip2.setPixelColor(num-1,cCenter);
        strip2.setPixelColor(num,cCenter);
        strip2.setPixelColor(num+1,cCenter);
        strip2.setPixelColor(num+2,cCenter);
        strip2.setPixelColor(num+3,cCenter);
        strip2.setPixelColor(num+4,cCenter);
        strip2.setPixelColor(num+5,cBorder);
        strip2.show(); 
        currentTime2=millis();
        if ((currentTime2 - previousTime2)<(4*transTime/MaxIntensity)){
          while((currentTime2 - previousTime2)<(4*transTime/MaxIntensity)){
            currentTime2=millis();
//            Serial.print (currentTime - previousTime);                    // Remove comment for troubleshooting
//            Serial.println ("   Waiting... ");                    // Remove comment for troubleshooting
          }
        }
        previousTime2=currentTime2;
  //      Serial.print ("Fade In ");                    // Remove comment for troubleshooting
  //      Serial.print (i);                    // Remove comment for troubleshooting
  //      Serial.print ("    tranTime ");                    // Remove comment for troubleshooting
  //      Serial.println (transTime/MaxIntensity);                    // Remove comment for troubleshooting
     }
  
}

void FadeOut (int num, int MaxIntensity, uint32_t transTime) {     // Turn off Pixels
     uint32_t currentTime, previousTime;

     currentTime = millis();
     previousTime = currentTime;
  
   for (int i=0; i<=MaxIntensity; i=i+4){   
        cCenter=Color((MaxIntensity-i)*(red_1/64),(MaxIntensity-i)*(green_1/64),(MaxIntensity-i)*(blue_1/64));
        cBorder=Color((MaxIntensity-i)*(red_2/64),(MaxIntensity-i)*(green_2/64),(MaxIntensity-i)*(blue_2/64));
        strip.setPixelColor(num-4, cBorder);
        strip.setPixelColor(num-3,cCenter);
        strip.setPixelColor(num-2,cCenter);
        strip.setPixelColor(num-1,cCenter);
        strip.setPixelColor(num,cCenter);
        strip.setPixelColor(num+1,cCenter);
        strip.setPixelColor(num+2,cCenter);
        strip.setPixelColor(num+3,cCenter);
        strip.setPixelColor(num+4,cCenter);
        strip.setPixelColor(num+5,cBorder);
        strip.show(); 
        currentTime=millis();
        if ((currentTime - previousTime)<(4*transTime/MaxIntensity)){
          while((currentTime - previousTime)<(4*transTime/MaxIntensity)){
            currentTime=millis();
  //          Serial.print (currentTime - previousTime);                    // Remove comment for troubleshooting
  //          Serial.println ("   Waiting... ");                    // Remove comment for troubleshooting
          }
        }
        previousTime=currentTime;
  //      Serial.print ("Fade Out ");                    // Remove comment for troubleshooting
  //      Serial.print (i);                    // Remove comment for troubleshooting
  //      Serial.print ("    tranTime ");                    // Remove comment for troubleshooting
  //      Serial.println (transTime/MaxIntensity);                    // Remove comment for troubleshooting
      } 
  
}

void FadeOut2 (int num, int MaxIntensity, uint32_t transTime) {     // Turn off Pixels
     uint32_t currentTime2, previousTime2;

     currentTime2 = millis();
     previousTime2 = currentTime2;
  
   for (int i=0; i<=MaxIntensity; i=i+4){   
        cCenter=Color((MaxIntensity-i)*(red_1/64),(MaxIntensity-i)*(green_1/64),(MaxIntensity-i)*(blue_1/64));
        cBorder=Color((MaxIntensity-i)*(red_2/64),(MaxIntensity-i)*(green_2/64),(MaxIntensity-i)*(blue_2/64));
        strip2.setPixelColor(num-4, cBorder);
        strip2.setPixelColor(num-3,cCenter);
        strip2.setPixelColor(num-2,cCenter);
        strip2.setPixelColor(num-1,cCenter);
        strip2.setPixelColor(num,cCenter);
        strip2.setPixelColor(num+1,cCenter);
        strip2.setPixelColor(num+2,cCenter);
        strip2.setPixelColor(num+3,cCenter);
        strip2.setPixelColor(num+4,cCenter);
        strip2.setPixelColor(num+5,cBorder);
        strip2.show(); 
        currentTime2=millis();
        if ((currentTime2 - previousTime2)<(4*transTime/MaxIntensity)){
          while((currentTime2 - previousTime2)<(4*transTime/MaxIntensity)){
            currentTime2=millis();
  //          Serial.print (currentTime - previousTime);                    // Remove comment for troubleshooting
  //          Serial.println ("   Waiting... ");                    // Remove comment for troubleshooting
          }
        }
        previousTime2=currentTime2;
  //      Serial.print ("Fade Out ");                    // Remove comment for troubleshooting
  //      Serial.print (i);                    // Remove comment for troubleshooting
  //      Serial.print ("    tranTime ");                    // Remove comment for troubleshooting
  //      Serial.println (transTime/MaxIntensity);                    // Remove comment for troubleshooting
      } 
  
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}



//*****************************************************************************************
//****************  Nextion Functions Declaration *******************************************
//*****************************************************************************************

void sendData(String data_from_display, String data){
  if(data_from_display == "CntColor"){
    bco = data.substring(10,15).toInt();
    red = bco>>11;
    red = map(red,0,31,0,63);
    grn = bco&2016;
    grn = grn>>5;
//    grn = map(grn,0,63,0,63);  // Not necessary to map green because green already ranges from 0-63
    blu = bco&31;
    blu = map(blu,0,31,0,63);
    red_1 = (float)red;
    green_1 = (float)grn;
    blue_1 = (float)blu;
  }
  if(data_from_display == "SidColor"){
    bco = data.substring(10,15).toInt();
    red = bco>>11;
    red = map(red,0,31,0,63);
    grn = bco&2016;
    grn = grn>>5;
    blu = bco&31;
    blu = map(blu,0,31,0,63);
    red_2 = (float)red;
    green_2 = (float)grn;
    blue_2 = (float)blu;
  }
}
