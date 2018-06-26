int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 9;
int BIN2 = 6;

void setup() {
  pinMode (led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  Serial.begin(19200);
}

void forward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void backward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void left() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void right() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void stop() {
  digitalWrite(led, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}


void loop() {
  char c = Serial.read();

  if (c == 'w') {
    Serial.println("forward");
    forward();
    delay(2000);
    stop();
  }

  if (c == 's') {
    Serial.println("backward");
    backward();
    delay(2000);
    stop();
  }

  if (c == 'a') {
    Serial.println("left");
    left();
    delay(500);
    stop();
  }

  if (c == 'd') {
    Serial.println("right");
    right();
    delay(500);
    stop();
  }  }



