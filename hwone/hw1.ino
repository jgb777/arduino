const int led1 = 13;
const int led2 = 10;
const int led3 = 7;
int led1State = LOW;
int led2State = HIGH;
int led3State = LOW;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
const long longinterval = 1000;
const long shortinterval = 500;

void setup() {
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);


}



void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMillis2 = millis();

  if (currentMillis - previousMillis >= longinterval) {
    previousMillis = currentMillis;

    if (led1State == LOW) {
      led1State = HIGH;
    } else {
      led1State = LOW;
    }

    if (led2State == LOW) {
      led2State = HIGH;
    } else {
      led2State = LOW;
    }
  }
  if (currentMillis2 - previousMillis2 >= shortinterval) {
    previousMillis2 = currentMillis2;

    if (led3State == LOW) {
      led3State = HIGH;
    } else {
      led3State = LOW;
    }


  }
  digitalWrite (led1, led1State);
  digitalWrite (led2, led2State);
  digitalWrite (led3, led3State);
}
