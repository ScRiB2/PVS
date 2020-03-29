
int direction = HIGH; 

const int DEFAULT_DELAY = 800;
int myDelay = DEFAULT_DELAY;

int previousMillis =  0;

#define PIN_BUTTON 2

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  for (int i = 3; i < 10; i++){
    pinMode(i, OUTPUT);
  }
  
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(0, myInterrupt, FALLING);
}

void myInterrupt(){
    if (millis() - previousMillis >= 200) {
      previousMillis = millis();
      changeDirection();
    }
}

void changeDirection(){
    Serial.println("changeDirection");
    direction = !direction;
}

void light(){
  if (direction){
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    delay(myDelay);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    delay(myDelay);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
    delay(myDelay);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    delay(myDelay);
  }
}


void loop() {
  int sensorValue = analogRead(A0);
  myDelay = DEFAULT_DELAY - sensorValue;
  
  light();
}
