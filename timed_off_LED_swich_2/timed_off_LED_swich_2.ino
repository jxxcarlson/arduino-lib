
/*
 * Push button.  LED turns ON for 10 seconds, then 
 * turns OFF;  When it turns off, the Red LED blinks 
 * for a defined number of times.
 * 
 */

const int ledBlue = 7;         // RED
const int indicatorLED = 8;    // WHITE
const int timerOnButton = 10;  // GREEN
const int stepperButton = 11;  // ORANGE
const int resetButton = 12;    // YELLOW

bool isOn;
unsigned long timeStarted;
long timeElapsed;
long maxElapsedTime = 20*60000; // 20  minutes
int intervalNumber = 1;


void blinkLED(int ledPin, int count, int duration) {
   for (int i = 0; i < count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
    delay(duration);
   }
   digitalWrite(ledPin, LOW);
  }

void setup() {

  pinMode(ledBlue, OUTPUT);      
  pinMode(indicatorLED, OUTPUT);
  pinMode(timerOnButton, INPUT);
  pinMode(stepperButton, INPUT);
  pinMode(resetButton, INPUT);

  // Serial.begin(9600);
  
  isOn = false;
  blinkLED(indicatorLED, 2, 60);
 
}

void resetValues () {
  intervalNumber = 1;
  isOn = false;
  digitalWrite(ledBlue, LOW);
  blinkLED(indicatorLED, 3, 100);
  digitalWrite(indicatorLED, LOW);
  
}

void loop() {

   if (digitalRead(timerOnButton) == HIGH) {

     timeStarted = millis();
     digitalWrite(ledBlue, HIGH);
     digitalWrite(indicatorLED, LOW);
     isOn = true;
    }

    if (digitalRead(resetButton) == HIGH) {
          resetValues();
        // digitalWrite(indicatorLED, HIGH);
    } else if (digitalRead(resetButton) == LOW) {
          digitalWrite(indicatorLED, LOW);
    }

    if (digitalRead(stepperButton) == HIGH) {
      intervalNumber = intervalNumber + 1;
      if (intervalNumber > 3) { intervalNumber = 1; }
      digitalWrite(indicatorLED, LOW);
      delay(1000);
      blinkLED(indicatorLED, intervalNumber, 400);
    }

    if (isOn == true) {
       timeElapsed = millis() - timeStarted;
    }

    if (timeElapsed > intervalNumber * maxElapsedTime) {
        digitalWrite(ledBlue, LOW);
        blinkLED(indicatorLED, 5, 150);
        isOn = false;
        timeStarted = millis();
        timeElapsed = 0;
       
    }

      
    // Serial.println(intervalNumber);
                      
}
