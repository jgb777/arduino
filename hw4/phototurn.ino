int l1 = A0;
int l2 = A2;
int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 10;
int BIN2 = 12;


void setup() {
  Serial.begin(19200);
  pinMode(l1, INPUT);
  pinMode(l2, INPUT);
  pinMode (led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);


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
  int val1;
  int val2;
  val1 = analogRead(A0);
  val2 = analogRead(A2);
  /* Serial.print(val1);
    Serial.println("  01");
    delay(500);
    Serial.print(val2);
    Serial.println("  02");
    delay(500); */

  if (val1 > val2-10) {
    left();

  }

  else if (val1 < val2-10) {
    right();

  }



  else {
    stop( );
  }


}
