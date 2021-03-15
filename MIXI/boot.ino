void boot(){

Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  initLEDs();
  delay(2000);
 switchVal = 1;
}

void initializeButtons(){
  for (int i = 0; i < 8; i++){
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(20);  
  }
}

void updatePots(){
  for (int i = 0; i < 4; i++){
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}
