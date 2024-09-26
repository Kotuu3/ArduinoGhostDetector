int antenna = A0;  
int led1 = 13;       
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 8;
int led6 = 9;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  int reading = analogRead(antenna);  
  Serial.println(reading);            

 
  if (reading > 166) {
    digitalWrite(led1, HIGH);    
  } else {
    digitalWrite(led1, LOW);    
  }
  if (reading > 333) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  if (reading > 500) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
  if (reading > 667) {
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);
  }
  if (reading > 833) {
    digitalWrite(led5, HIGH);
  } else {
    digitalWrite(led5, LOW);
  }
  if (reading > 1000) {
    digitalWrite(led6, HIGH);
  } else {
    digitalWrite(led6, LOW);
  }

  delay(30);
}
