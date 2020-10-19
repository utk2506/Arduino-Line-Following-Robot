// IR Sensor pins
#define leftSensor A4   //Connect left IR sensor with arduino pin A4
#define rightSensor A0  //Connect right IR sensor with arduino pin A0
#define centerSensor A2 //Connect center IR sensor with arduino pin A4

#define SENSEVALUE 200 //set IR sensor reading value 200 on you choice
#include <AFMotor.h>   //add AFMotor.h library

AF_DCMotor motor1(3); // connect motor 1 with arduino pin 3
AF_DCMotor motor2(4); // connect motor 2 with arduino pin 4

int l1=1; // Store value in l1=1 "1 called as HIGH or ON"
int l2=1; // Store value in l2=1 "1 called as HIGH or ON"
int l3=1; // Store value in l3=1 "1 called as HIGH or ON"

int f1=0; // Store value in l1=0 "1 called as LOW or OFF"
int f2=0; // Store value in l2=0 "1 called as LOW or OFF"
int f3=0; // Store value in l3=0 "1 called as LOW or OFF"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  pinMode(leftSensor, INPUT);     // IR Sensor Out pin send value to arduino "that why we define left sensor as a input"
  pinMode(rightSensor, INPUT);    // IR Sensor Out pin send value to arduino "that why we define right sensor as a input"
  pinMode(centerSensor, INPUT);   // IR Sensor Out pin send value to arduino "that why we define center sensor as a input"

  motor1.setSpeed(150);  //set RPM of motor2 as you required
  motor2.setSpeed(150); // set RPM of motor2 as you required
  motor1.run(RELEASE); // start runing both motor
  motor2.run(RELEASE);
}
int shouldDelay=1; // Store value in shouldDelay=1 "1 called as HIGH or ON"

void loop(){

//if(shouldDelay==1){
//  shouldDelay=0;
//  delay(2);  
//}

l1=digitalRead(leftSensor);       // define l1 as a left sensor"digitalRead because value read by sensor and send to arduino"
l2=digitalRead(centerSensor);    // define l1 as a center sensor"digitalRead because value read by sensor and send to arduino"
l3=digitalRead(rightSensor);    // define l1 as a right sensor"digitalRead because value read by sensor and send to arduino"
//
//Serial.print("Left=");
//Serial.print(l1);
//Serial.print("  Center=");
//Serial.print(l2);
//Serial.print("  right=");
//Serial.println(l3);
//    
/////////////////////////////////////////////////////////////////////
//feedback when comes all sensor on white
if(l1==0&&l2==0&&l3==0)   {  // when 3 sensor read value are 0 
  l1=f1;       // then left sensor is 0 or LOW
  l2=f2;      // then left sensor is 0 or LOW
  l3=f3;     // then left sensor is 0 or LOW

}



////////////////////////////////////////////////////////////////////////////
//left turn
//if(l1==0&&l2==1&&l3==1||l1==0&&l2==0&&l3==1)   {
//}
// //right turn
//else if(l1==1&&l2==1&&l3==0||l1==1&&l2==0&&l3==0) {
//}
////go forward straight 
//else 

else if(l1==0&&l2==1&&l3==0)  { //when upper if program run then  this program also run 
  
    motor1.setSpeed(200); // set the RPM of motor1 as you required
    motor2.setSpeed(200); // set the RPM of motor2 as you required

    motor1.run(FORWARD); // then motor1 go forward
    motor2.run(FORWARD); //then  motor2 go forward

    
}
//left turn
else if(l1==1&&l2==0&&l3==0||l1==1&&l2==1&&l3==0){ //when l1=1,l2=0,l3=0 or l1=1,l2=1,l3=0

  
    motor1.run(RELEASE);
    motor1.setSpeed(120);  // set the RPM of motor2 as you required
    
    motor1.run(FORWARD);    //then motor1 go forward
    motor2.run(RELEASE);
 
}
//right turn
else if(l1==0&&l2==0&&l3==1||l1==0&&l2==1&&l3==1){   //when l1=0,l2=0,l3=1 or l1=0,l2=1,l3=1

  
    motor2.run(RELEASE);  
    motor2.setSpeed(120); // set the RPM of motor2 as you required
    
    motor2.run(FORWARD); //then motor2 go forward
    motor1.run(RELEASE); 
  
}
//stop 
else if(l1==1&&l2==1&&l3==1) { //when 3 sensor read value as a 1 

//    for(int i=0;i<1;i++){
//      motor1.run(FORWARD);
//      motor2.run(RELEASE);
//    }
//    
//   if(l2==0) {
//      for(int i=0;i<2;i++){
//        motor2.run(FORWARD);
//        motor1.run(RELEASE);
//      } 
//   }
//    
   
//     motor1.run(RELEASE);
//     motor2.run(RELEASE);
}

///////////////////////////////////////////////////////////////////
f1=l1; // then both motor stop
f2=l2;
f3=l3;        //memory variables
////////////////////////////////////////////////////////////////////
} 


//void loop() {
//  // put your main code here, to run repeatedly:
//int leftIR = analogRead(leftSensor);
//Serial.println("Left=");
//Serial.print(leftIR);
//if(leftIR>SENSEVALUE){
//    motor1.run(FORWARD);
//  motor2.run(FORWARD);
//  
//  }else{
//     motor1.run(RELEASE);
//  motor2.run(RELEASE);
//    }
//}
