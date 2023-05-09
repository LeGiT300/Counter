#include <SevSeg.h>

SevSeg show;

int ledPin = 13, echoPin = 11, trigPin = 12;
int duration,  current = 0, previous = 0, counter = 0;
float distance;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);

  byte digi = 1;
  byte pins[] = {};
  byte segpins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;
  
  byte hardwareConfig = COMMON_CATHODE;
  show.begin(hardwareConfig, digi, pins, segpins, resistorsOnSegments);
  show.setBrightness(90);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(50);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, HIGH);
  
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration/1000000.)*343.2);
  
  if(distance <= 2.0){
    current = 1;
  }
  else{
    current = 0;
  }
  delay(200);
  if (current != previous ){ //continuously checking to see if it satisfies
    counter +=1; // Do the count to be displayed
    
    for(int i = 0; i < counter; i++){
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
    }
    if (counter > 9){
      counter = 0;
    }
    
    show.setNumber(counter); // Display on the LCD
    show.refreshDisplay();
  }

  Serial.println(counter);
}
