#include <FastLED.h>
#include <elapsedMillis.h>
#define LED_COUNT 4      //FOR TESTING w/ SIGN
//  /---LED FX VARS
int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 0;                //-HUE (0-255)
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR
 int BOTTOM_INDEX = 0;
int TOP_INDEX = int(LED_COUNT/2);
int EVENODD = LED_COUNT%2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)
//int ledMode = 3;           //-START IN RAINBOW LOOP
//int ledMode = 888;         //-START IN DEMO MODE
//int ledMode = 4;             //-START IN BURST
int ledMode = 13;             // SStart in Rainbow

int thisdelay = 20;          //-FX LOOPS DELAY VAR
int thisstep = 10;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR
int max_bright = 64;         //-SET MAX BRIGHTNESS TO 1/4

int thisindex = 0;           //-SET SINGLE LED VAR
int thisRED = 0;
int thisGRN = 0;
int thisBLU = 0;      

void setup() {
   FastLED.addLeds<APA102,3,13,BGR>(leds, LED_COUNT);

}

void loop() {
random_burst_md();

}

void random_burst_md() {                       
  idex = random(0, LED_COUNT);
  ihue = random(30, 60);  
  ibright = random(160, 200);
  leds[idex] = CHSV(ihue, thissat, ibright);
  LEDS.show();
  waitNine();
    
    idex = random(0, LED_COUNT);  //Neal Fixed it by adding these lines that add a black pixel each cycle
   
    leds[idex] = CHSV(0, 0, 0);
    
     LEDS.show();
     
    waitNine(); 
  
}

void waitNine() { 
unsigned long startTime = millis();
while(millis() - startTime < 120){}
}
