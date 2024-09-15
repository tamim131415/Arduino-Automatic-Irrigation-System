int relay = 2;
int sensor = A0;
int redLed = 5;
int greenLed = 6;
int buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Welcome to Smart Irrigation system.");

  pinMode(sensor,INPUT); 
  pinMode(relay,OUTPUT);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(sensor);

  if(value > 950) {
    Serial.println("Sensor is now in LOW State. Please, water it."); 
    digitalWrite(relay, HIGH);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);
  } else if(value > 300 && value < 950) { 
    Serial.println("Thanks for watering. It is now in MID state.");
    digitalWrite(relay, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
  } else {
    Serial.println("Thanks for watering. It is now in HIGH state.");
    digitalWrite(relay, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
  }
}
