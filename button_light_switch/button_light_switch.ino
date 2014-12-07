const int LED = 13; //pin for LED

const int BUTTON = 7; //input pin for pushbutton

int val = 0;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {
  
  val = digitalRead(BUTTON);
  
  if (val == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}
