const int buttonPin = 11;
const int relay = 12;
const int ledPin =  13;


int statusActive = 0 ;
int statusPush = 0;


int buttonState = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Micro Project Thailand ~^.^~ ");
  pinMode(ledPin, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (statusPush == 0) {
      statusPush = 1;

      Serial.println("-------------- Push ----------------");

      if (statusActive == 0) {
        statusActive = 1;
      }
      else if (statusActive == 1) {
        statusActive = 0;
      }
    }
  }

  else if (buttonState == LOW) {
    statusPush = 0;
  }


  if (statusActive == 0) {
    digitalWrite(ledPin, LOW);
    digitalWrite(relay, HIGH);
  }
  else if (statusActive == 1) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(relay, LOW);
  }



}
