int sensorRight = HIGH, sensorMid = HIGH, sensorLeft = HIGH;
byte leftWheel = 9;
byte leftDirect = 8;
byte rightWheel = 10;
byte rightDirect = 11;
unsigned long prevMillis = 0;
int interval = 200;
byte lineSensor1 = 5;
byte lineSensor2 = 6;
byte lineSensor3 = 7;

void setup() {
  pinMode(lineSensor1, INPUT);
  pinMode(lineSensor2, INPUT);
  pinMode(lineSensor3, INPUT);
  
  pinMode(leftDirect, OUTPUT);
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
  pinMode(rightDirect, OUTPUT);
  
  digitalWrite(leftDirect, HIGH);
  digitalWrite(rightDirect, HIGH);
}

void loop() {
  sensorRight = digitalRead(lineSensor1);
  sensorMid = digitalRead(lineSensor2);
  sensorLeft = digitalRead(lineSensor3);
  if (millis() - prevMillis >= interval) {
    prevMillis = millis();
    if (sensorRight == LOW && sensorMid == LOW && sensorLeft == LOW) {
      goForward();
    } else if (sensorRight == LOW && sensorMid == LOW && sensorLeft == HIGH) {
      turnRight();
    } else if (sensorRight == HIGH && sensorMid == LOW && sensorLeft == LOW) {
      turnLeft();
    } else if (sensorRight == HIGH && sensorMid == HIGH && sensorLeft == LOW) {
      reverse();
      turnLeft();
    } else if (sensorRight == LOW && sensorMid == HIGH && sensorLeft == HIGH) {
      reverse();
      turnRight();
    } else {
      brake();
    }
    /*
      // this block of code is for line avoidance
      if (sensorRight == HIGH && sensorMid == HIGH && sensorLeft == HIGH) {
      goForward();
      } else if (sensorRight == HIGH && sensorMid == HIGH && sensorLeft == LOW) {
      turnRight();
      } else if (sensorRight == LOW && sensorMid == HIGH && sensorLeft == HIGH) {
      turnLeft();
      } else if (sensorRight == LOW && sensorMid == LOW && sensorLeft == HIGH) {
      reverse();
      turnLeft();
      } else if (sensorRight == HIGH && sensorMid == LOW && sensorLeft == LOW) {
      reverse();
      turnRight();
      } else {
      brake();
      }*/
  }
}

void goForward() {
  analogWrite(leftWheel, 75);
  analogWrite(rightWheel, 75);
}

void turnLeft() {
  analogWrite(leftWheel, 0);
  analogWrite(rightWheel, 150);
}

void turnRight() {
  analogWrite(leftWheel, 150);
  analogWrite(rightWheel, 0);
}

void reverse() {
  digitalWrite(leftDirect, LOW);
  digitalWrite(rightDirect, LOW);
  delay(300);
  digitalWrite(leftDirect, HIGH);
  digitalWrite(rightDirect, HIGH);
}

void brake() {
  analogWrite(leftWheel, 0);
  analogWrite(rightWheel, 0);
}

