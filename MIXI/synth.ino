boolean synthStates[] = {false, false, false, false, false,false};

int synthPots[] = {0,0,0,0};
int synthPotTol = 10;


void synth(){

  if(synthMode){
    
    for (int i = 0; i < strip.numPixels(); i++){
      //synthmode
      strip.setPixelColor(i, 227, 66, 52);
      //bassmode
      if (i == 6){
        strip.setPixelColor(i,255,165,0);
      }
      //melodymode
      if (i == 7){
        strip.setPixelColor(i,135, 206, 235);
      }
    }
    strip.show();
    synthMode = false;
  }

  for(int i = 0; i < 8; i++){
  int thisButton = buttonStates[i];
  
  if(thisButton == 1 && i != 0 && 1 !=4 ){
    synthStates[i] = !synthStates[i];
    if(synthStates[i])
    {usbMIDI.sendControlChange(i,127,1);}
    
    else
    {usbMIDI.sendControlChange(i, 0 ,1);}
  }
  if(thisButton == 1 && i == 6){
    strip.clear();
    synthMode = false;
    bassMode = true;
    switchVal = 2;
  }
  if(thisButton == 1 && i == 7){
    strip.clear();
    synthMode = false;
    melodyMode = true;
    switchVal = 3;
  }
}

  //stores pots
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    if(abs(thisPot - synthPots[i]) > synthPotTol){
      usbMIDI.sendControlChange(i + 8,thisPot, 1);
      synthPots[i] = thisPot;
    }
  }
}
