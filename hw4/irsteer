#include <IRremote.h>

int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 10;
int BIN2 = 12;
int RECV_PIN = 4;



IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  pinMode (led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
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

  if (irrecv.decode(&results)) {
    if (results.value == 0x10EFA05F) {
      Serial.println("forward");
      forward();
      delay(1000);
      stop();
    }

    else if (results.value == 0x10EF00FF) {
      Serial.println("backward");
      backward();
      delay(1000);
      stop();
    }

    else if (results.value == 0x10EF10EF) {
      Serial.println("left");
      left();
      delay(500);
      stop();
    }

    else if (results.value == 0x10EF807F) {
      Serial.println("right");
      right();
      delay(500);
      stop();
    }
    else {
      Serial.print("Unrecofnized: ");
      Serial.print(results.value, HEX);
      Serial.println();
    }

    irrecv.resume();
  }
}




//f 10EFA05F
//b 10EF00FF

//l 10EF10EF
//r 10EF807F
