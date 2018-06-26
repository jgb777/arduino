int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 9;
int BIN2 = 6;

int triggerPin = 4;
int echoPin = 5;
const int chipSelect = 10;


void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

    float ping() {
    unsigned long maxTime = 20000;
    unsigned long us;
    float inches;

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    us = pulseIn(echoPin, HIGH, maxTime);

    if (us == 0) {
      us = maxTime;
    }

    inches = us * 0.013504 / 2;
    return inches;
  }



  void forward() {

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }

  void backward() {
    //digitalWrite(led, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  void left() {
    //digitalWrite(led, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }

  void right() {
    //digitalWrite(led, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  void stop() {
    //digitalWrite(led, LOW);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }


  void loop() {

    float inches = ping();

    while (inches > 10) {
      float inches = ping();

      ping();
      forward();
      delay(60);
      if (inches < 10) {

        break;

      }

    }

    while (inches < 10) {
      float inches = ping();
      stop();


      left();
      ping();


      delay(60);
      if (inches > 10) {
        break;
      }
    }
    delay(60);
  }
