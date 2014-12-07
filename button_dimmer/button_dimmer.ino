const int LED = 9; //LED pin
const int BUTTON = 7; // input pin of push button

int val = 0; //stores state of input pin

int old_val = 0; //stores previous value of 'val'
int state = 0; // 0 = LED off while 1 = LED on

int brightness = 128; // stores brightness value

unsigned long startTime = 0; // when did we begin pressing?


void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {

  val = digitalRead(BUTTON); //read input value and store it
    
  //check if transition
  if ((val == HIGH) && (old_val == LOW)){
    state = 1 - state; //change state from off to on or vice-versa
    
    startTime = millis(); //how many miliseconds have passed since board reset
    delay(10);
  }
  
  if ((val == HIGH) && (old_val == HIGH)){
    if (state == 1 && (millis() - startTime) > 500) {
      brightness ++;
      delay(10);
      
      if (brightness > 255){
        brightness = 0;
      }
    }
  }
  
  old_val = val;
  
  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
  

}
