
![Logo](https://github.com/Kotuu3/ArduinoGhostDetector/blob/main/logo2.png?raw=true)


# ArduinoGhostDetector

Simple Arduino EMF / Ghost Detector \
While watching ghost hunting videos you for sure saw device called "K2", you can buy it on aliexpress or amazon for few bucks but why would you, when you can do it yourself and impress your friends this halloween 🎃 
## Demo

You can see how it (kinda) works [here](https://streamable.com/h38kbq)


## Documentation
Arduino analog input reading are based on an Analog-to-Digital Converter (ADC) wich convert analog signal to digital values. Arduino ADC has 10bit resolution so it's range is 0-1023, that's why "strongest" value is 1023 for led6. You can use external ADC, wich will really improve range of detector but i won't cover that as for now.. \
\
LEDS/Antena:
```
int antenna = A0;  
int led1 = 13;       
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 8;
int led6 = 9;
```
A0 pin represents Antenna, it can be solid copper wire or antenna from old radio that i used for this project, most important part is that connection has to be really good or else readings will be noisy. \
Rest is amount of LED's, i was using single LED for testing, then 3 and now 6 for better "range". \
\
Setup:
```
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  Serial.begin(9600);  
}
```

The setup() function is used to configure initial state of pins and start serial comunication, this runs on every reset of Arduino. \
OUTPUT "option" allows Arduino to control pins of LED's. \
```Serial.begin(9600)``` 
is really important for configuration, it allows you to communicate with arduino via computer, it's easier to debug project, since you can see readings of antenna in IDE it's easier to set each led for it's range ;D \
\
Loop, the main and most important section of our code:

```
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
``` 

```c
  int reading = analogRead(antenna);  
  Serial.println(reading);   
```
This part allows us to check readings in IDE console.

```c
 if (reading > 166) {
    digitalWrite(led1, HIGH);   
  } else {
    digitalWrite(led1, LOW);    
```
if reading is more than 166 arduino turns on LED , if it's less than 166 arduino turns LED off or don't turn it on in first place. 

```c
delay(30);
```
Delay is preventing arduino from looping all the time, in the end of each loop arduino has 30 milliseconds of rest 🥱, you can change it to more or less. 
If you're going to use different amount of LED's i would suggest setting it to 200ms sou you can have better view of readings in IDE debug console for setting ranges for LED's and then tweaking it for actual usage. \
Changing this value also changes how fast every led turns on or off when set reading "turns on LED", setting it too slow will cause "lag" and setting it too high will make LED's strobe when all of them are ON

## Authors

- [@kotuu3](https://github.com/Kotuu3)

