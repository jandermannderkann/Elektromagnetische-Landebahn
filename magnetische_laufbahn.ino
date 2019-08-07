int offPin = 1;  //  this pin will be used to stop the programm
int activationPin = 2;  //  this pin will be used to start the programm
int outputPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, -1};  //  add as much as you want, LAST ONE HAS GOT TO BE "-1"!!!!!!!!
int onTime = 1000;  //  milliseconds! 1000m s = 1s   time between turning on, and turning off the pin
int waitTime = 1000;  //  time between activation of the outputPins 

/**
 * This Function will set the Modes, of the pins. The offPin for example will be set to inputmode;
 */
void setup() {
  for(int i=0; outputPins[i] != -1; i++) {
      pinMode(outputPins[i], OUTPUT);
  }  
  pinMode(offPin, INPUT);
  pinMode(activationPin, INPUT);
}

/**
 * Will end only if offPin recieves Signal.
 * Upon activation of activatioPin, will sequencially activate all the outputPins, with the specified delayTime
 */
void loop() {
  while (!isTurnedOff()) {
      if (isActivated()) {
          magnetSequence();
      }
  }
}
  
/*
 * activates all outputpins once, with the specified delayTime.
 */
void magnetSequence() {
  for (int i=0; outputPins[i] != -1; i++) {
    digitalWrite(outputPins[i], HIGH);
    delay(onTime);
    digitalWrite(outputPins[i], LOW);
    delay(waitTime);
  }
 }
  
/**
 * Checks wether programm is turned off. 
 * Therefore reads Voltage on offpin.
 */
boolean isTurnedOff() {
  return digitalRead(offPin) == HIGH;
}

/**
 * Checks wether programm is activated
 * Therefore reads Voltage on activationPin
 */
boolean isActivated() {
  return digitalRead(activationPin) == HIGH;
}

