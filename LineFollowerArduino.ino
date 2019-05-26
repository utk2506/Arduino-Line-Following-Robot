// IR Sensor pins
#define leftSensor A4
#define rightSensor A0
#define centerSensor A2

#define SENSEVALUE 200
#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

int l1=1;
int l2=1;
int l3=1;

int f1=0;
int f2=0;
int f3=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(centerSensor, INPUT);

  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
int shouldDelay=1;

void loop(){

//if(shouldDelay==1){
//  shouldDelay=0;
//  delay(2);  
//}

l1=digitalRead(leftSensor);
l2=digitalRead(centerSensor);
l3=digitalRead(rightSensor);
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
if(l1==0&&l2==0&&l3==0)   {
  l1=f1;
  l2=f2;
  l3=f3;

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

else if(l1==0&&l2==1&&l3==0)  {
  
    motor1.setSpeed(200);
    motor2.setSpeed(200);

    motor1.run(FORWARD);
    motor2.run(FORWARD);

    
}
//left turn
else if(l1==1&&l2==0&&l3==0||l1==1&&l2==1&&l3==0){
  
    motor1.run(RELEASE);
    motor1.setSpeed(120);
    
    motor1.run(FORWARD);
    motor2.run(RELEASE);
 
}
//right turn
else if(l1==0&&l2==0&&l3==1||l1==0&&l2==1&&l3==1){
  
    motor2.run(RELEASE);
    motor2.setSpeed(120);
    
    motor2.run(FORWARD);
    motor1.run(RELEASE);
  
}
//stop 
else if(l1==1&&l2==1&&l3==1) {

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
f1=l1;
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
