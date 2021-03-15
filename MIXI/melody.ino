boolean melodyStates[] = {false, false, false, false, false,false};

int  melodyPots[] = {0,0,0,0};
int  melodyPotTol = 10;



void melody(){

  if(melodyMode){
    
    for (int i = 0; i < strip.numPixels(); i++){
      //melodymode
      strip.setPixelColor(i,135, 206, 235);
      
      //synthmode
      if (i == 6){
        strip.setPixelColor(i, 227, 66, 52);
      }
      //bassmode
      if (i == 7){
        strip.setPixelColor(i,255,165,0);
      }
    }
    strip.show();
    melodyMode = false;
  }


  for(int i = 0; i < 8; i++){
  int thisButton = buttonStates[i];
  
  if(thisButton == 1 && i != 0 && 1 !=4 ){
    bassStates[i] = !bassStates[i];
    if(bassStates[i])
    {usbMIDI.sendControlChange(i,127,1);}
    
    else
    {usbMIDI.sendControlChange(i, 0 ,1);}
  }
  if(thisButton == 1 && i == 6){
    strip.clear();
    melodyMode = false;
    synthMode = true;
    switchVal = 1;
  }
  if(thisButton == 1 && i == 7){
    strip.clear();
    melodyMode = false;
    bassMode = true;
    switchVal = 2;
  }
}

  //stores pots
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    if(abs(thisPot - melodyPots[i]) > melodyPotTol){
      usbMIDI.sendControlChange(i + 8,thisPot, 1);
      melodyPots[i] = thisPot;
    }
  }
}
