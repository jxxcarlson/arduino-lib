
/*
 * Push button.  LED turns ON for 10 seconds, then 
 * turns OFF;
 * 
 */

const int ledBlue = 7;
const int led2 = 8;
const int pushbutton = 10;

bool isOn;
unsigned long timeStarted;
long timeElapsed;
long maxElapsedTime = 10*1000; // seconds


void setup() {

  pinMode(ledBlue, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pushbutton, INPUT);
  
  digitalWrite(led2, HIGH);
 
}

void loop() {

   if (digitalRead(pushbutton) == HIGH) {

     timeStarted = millis();
     digitalWrite(ledBlue, HIGH);
     
    }

    timeElapsed = millis() - timeStarted;

    if (timeElapsed > maxElapsedTime) {
        digitalWrite(ledBlue, LOW);
    }

      

                      
}
