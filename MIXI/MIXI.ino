#include <Bounce2.h>
int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
Bounce * buttons = new Bounce[8];

int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);

// variable for state machine
int switchVal = 0;

//booleans to help swicth between the different modes
boolean synthMode = false;

boolean bassMode = false;

boolean melodyMode =false;


void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  boot();
}

void loop() {
  updateButtons();
  //printButtons();
  updatePots();
  //printPots();

switch(switchVal){
    case 0: boot(); break;
    case 1: synth(); break;
    case 2: bass(); break;
    case 3: melody();  break;
  }
}

void initLEDs(){
  for (int i = 0; i < 8; i++){
    strip.setPixelColor(i, 255, 0, 255);
    strip.show();
    delay(50);
  }
}



void updateButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].update();
    if(buttons[i].rose()){buttonStates[i] = 1;}
    else{buttonStates[i] = 0;}
  }
}

/*void printButtons(){
  for (int i = 0; i < 8; i++){
    int thisButton = buttonStates[i];
    Serial.print(thisButton);
    Serial.print("\t");
  }  
  //Serial.println();
}


void printPots(){
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    Serial.print(thisPot);
    Serial.print("\t");
  }  
  Serial.println();
}*/
