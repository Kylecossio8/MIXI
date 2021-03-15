boolean bassStates[] = {false, false, false, false, false,false};

int bassPots[] = {0,0,0,0};
int bassPotTol = 10;



void bass(){

  if(bassMode){
    
    for (int i = 0; i < strip.numPixels(); i++){
      //bassmode
      strip.setPixelColor(i,255,165,0);
      //synthmode
      if (i == 6){
        strip.setPixelColor(i, 227, 66, 52);
      }
      //melodymode
      if (i == 7){
        strip.setPixelColor(i,135, 206, 235);
      }
    }
    strip.show();
    bassMode = false;
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
    bassMode = false;
    synthMode = true;
    switchVal = 1;
  }
  if(thisButton == 1 && i == 7){
    strip.clear();
    melodyMode = true;
    bassMode = false;
    switchVal = 3;
  }
}

  //stores pots
  for (int i = 0; i < 4; i++){
    int thisPot = potStates[i];
    if(abs(thisPot - bassPots[i]) > bassPotTol){
      usbMIDI.sendControlChange(i + 8,thisPot, 1);
      bassPots[i] = thisPot;
    }
  }
}
