#include <Servo.h>

Servo redServo;
Servo greenServo;
Servo blueServo;

const int S0 = 2;
const int S1 = 3;
const int S2 = 4;
const int S3 = 5;
const int OUT = 6;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  redServo.attach(9);
  greenServo.attach(10);
  blueServo.attach(11);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  // Read red value
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(OUT, LOW);

  // Read green value
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(OUT, LOW);

  // Read blue value
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(OUT, LOW);

  // Actuate servos based on color values
  if (redValue > greenValue && redValue > blueValue) {
    redServo.write(90);
    greenServo.write(0);
    blueServo.write(0);
  } else if (greenValue > redValue && greenValue > blueValue) {
    redServo.write(0);
    greenServo.write(90);
    blueServo.write(0);
  } else if (blueValue > redValue && blueValue > greenValue) {
    redServo.write(0);
    greenServo.write(0);
    blueServo.write(90);
  }

  delay(1000); // Delay for stability
}
