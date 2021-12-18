
/*
 * Push button to toggle state between ON = 1 and OFF = 0
 * If the state is ON, the LED blinks
 * 
 */

const int led1 = 7;
const int led2 = 8;
const int pushbutton = 10;
int state;

#define OFF 0;
#define ON 1; 

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pushbutton, INPUT);
  
  state = OFF;
  digitalWrite(led2, HIGH);
 
}

void changeState() {


  if (digitalRead(pushbutton) == HIGH && state == 0) {

     state = 1;
  }

  if (digitalRead(pushbutton) == HIGH && state == 1) {

     state = 0;
  }
}

void loop() {

  changeState();

  if (state == 1) {
    digitalWrite(led1, HIGH);
    
    delay(1000); 
    changeState();
                    
    digitalWrite(led1, LOW);   
    delay(1000); 
  } 
                      
}
