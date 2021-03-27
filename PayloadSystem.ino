#include <Adafruit_MotorShield.h>
#include <SoftwareSerial.h>
#include <Wire.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);
SoftwareSerial Genotronex(10,11); //(Tx,Rx)

int motorSpeed = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Genotronex.begin(9600);
  AFMS.begin();
  myMotor1->setSpeed(motorSpeed);
  myMotor2->setSpeed(motorSpeed);
  myMotor3->setSpeed(motorSpeed);
  myMotor4->setSpeed(motorSpeed);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available() > 0){
    char control = Genotronex.read();
    //Check for no button press value of control!!!
    Serial.print("Control:");
    Serial.println(control);

    if(control == 'u'){ //Move forward
      myMotor4->run(FORWARD);
      myMotor2->run(FORWARD);
    }
    else if(control == 'l'){ //Left
      myMotor4->run(BACKWARD);
      myMotor2->run(FORWARD);
    }
    else if(control == 'r'){ //Right
      myMotor4->run(FORWARD);
      myMotor2->run(BACKWARD);
    }
    else if(control == 'd'){ //Back
      myMotor4->run(BACKWARD);
      myMotor2->run(BACKWARD);
    }
    else if(control == 'x'){ //Stop rover movement
      myMotor4->run(RELEASE);
      myMotor2->run(RELEASE);
    }
    
    else if(control == 'i'){ //Fold rover arms in
      myMotor3->run(FORWARD);
      myMotor1->run(BACKWARD);
    }
    else if(control == 'o'){ //Fold rover arms out
      myMotor3->run(BACKWARD);
      myMotor1->run(FORWARD);
    }
    else if(control == 's'){ //Stop folding proccess
      myMotor3->run(RELEASE);
      myMotor1->run(RELEASE);
    }
    else{
      
    }
  }
  delay(50);
}
