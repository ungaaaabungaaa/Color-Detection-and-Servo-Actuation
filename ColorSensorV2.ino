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
  readColor();
  actuateServos();
  delay(1000); // Delay for stability
}

void readColor() {
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
}

void actuateServos() {
  // Actuate servos based on color values
  if (redValue > greenValue && redValue > blueValue) {
    moveServosToColor(90, 0, 0);
  } else if (greenValue > redValue && greenValue > blueValue) {
    moveServosToColor(0, 90, 0);
  } else if (blueValue > redValue && blueValue > greenValue) {
    moveServosToColor(0, 0, 90);
  }
}

void moveServosToColor(int redAngle, int greenAngle, int blueAngle) {
  redServo.write(redAngle);
  greenServo.write(greenAngle);
  blueServo.write(blueAngle);
}
