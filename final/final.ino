
#include <MPU9250_asukiaaa.h>
#include <SPI.h>
#include <SD.h>

//Sd2Card card;
//SdVolume volume;
//SdFile root;

//int led = 13;
MPU9250 mySensor;
float mDirection;
uint16_t mX, mY, mZ;
File myFile;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 9;
int BIN2 = 6;

int triggerPin = 4;
int echoPin = 5;
const int chipSelect = 10;
//unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
//unsigned long distance = (currentMillis - previousMillis);





void setup() {
  //pinMode (led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);

  Wire.begin();
  mySensor.setWire(&Wire);
  mySensor.beginMag();
  mDirection = mySensor.magHorizDirection();
  mySensor.magXOffset = -60;
  mySensor.magYOffset = -48;
  mySensor.magZOffset = -17;
  //magnetometer setup & calibration

  Serial.println("1");
  //opening file on SD and creating column headers

  if  (!SD.begin(chipSelect)) {
    Serial.println ("card failed");
    return;
  }


  myFile = SD.open("heading.txt", FILE_WRITE);
  if (!myFile) {
    Serial.println("open failed");
    return;
  }

  Serial.println("11");
  myFile.print ("distance");

  Serial.println("12");
  myFile.print("\t");

  Serial.println("13");
  myFile.println("direction");

  Serial.println("14");
  myFile.close();

  Serial.println("15");

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

  mySensor.magUpdate();
  mDirection = mySensor.magHorizDirection();
  unsigned long currentMillis = millis();

  //previousMillis = currentMillis;

  float inches = ping();

  while (inches > 10) {
    float inches = ping();

    ping();
    forward();
    //Serial.println("forward");
    Serial.println(mDirection);
    delay(60);
    if (inches < 10) {
      myFile = SD.open("heading.txt", FILE_WRITE);
      //  if (myFile) {
      Serial.println(millis() - previousMillis);
      myFile.print(currentMillis - previousMillis);
      myFile.print("\t");
      myFile.println(mDirection);
      myFile.close();
      //  record time and heading
      break;

    }
    //    break;
  }

  while (inches < 10) {
    float inches = ping();
    stop();


    left();
    //Serial.println("left");
    ping();


    delay(60);
    if (inches > 10) {
      previousMillis = currentMillis;
      //reset time before moving again 
      break;
    }
  }
  delay(60);

}
