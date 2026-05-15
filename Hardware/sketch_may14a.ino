#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// ===== MOTOR PINS =====

#define IN1 26
#define IN2 27
#define IN3 32
#define IN4 33

char command;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(115200);

  // Bluetooth name

  SerialBT.begin("ESP32_ROBOT");

  stopRobot();
}

void loop() {

  if (SerialBT.available()) {

    command = SerialBT.read();

    Serial.println(command);

    // ===== FORWARD =====

    if (command == 'F') {

      moveForward();
    }

    // ===== BACKWARD =====

    else if (command == 'B') {

      moveBackward();
    }

    // ===== LEFT =====

    else if (command == 'L') {

      turnLeft();
    }

    // ===== RIGHT =====

    else if (command == 'R') {

      turnRight();
    }

    // ===== STOP =====

    else if (command == 'S') {

      stopRobot();
    }
  }
}

// ===== FUNCTIONS =====

void moveForward() {

  analogWrite(IN1, 120);
  analogWrite(IN2, 0);

  analogWrite(IN3, 120);
  analogWrite(IN4, 0);
}

void moveBackward() {

  analogWrite(IN1, 0);
  analogWrite(IN2, 120);

  analogWrite(IN3, 0);
  analogWrite(IN4, 120);
}

void turnLeft() {

  analogWrite(IN1, 0);
  analogWrite(IN2, 120);

  analogWrite(IN3, 120);
  analogWrite(IN4, 0);
}

void turnRight() {

  analogWrite(IN1, 120);
  analogWrite(IN2, 0);

  analogWrite(IN3, 0);
  analogWrite(IN4, 120);
}

void stopRobot() {

  analogWrite(IN1, 0);
  analogWrite(IN2, 0);

  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}