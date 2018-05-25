
void setup() {
  Serial.begin(19200);
                                                                                                                 
  pinMode (A0, INPUT);
  pinMode (A2, INPUT);

}

void loop() {
  int value;
  int value2;
  value = analogRead(A0);
  value2 = analogRead(A2);
  Serial.print(value);
  Serial.print(" ");
  Serial.print(value2);
  Serial.println(" 0 1023");
 
  
  
  // put your main code here, to run repeatedly:

}
