// Maded by hacerio
// Version 1.0

#define Motor_pin 2
#define Servo_left_pin 4
#define Servo_right_pin 5
#define Servo_back_pin 6
#define Power_pin A1

#define Motor_min 800
#define Motor_max 2300
#define Servo_left_min 0
#define Servo_left_max 180
#define Servo_left_normal 90
#define Servo_right_min 0
#define Servo_right_max 180
#define Servo_right_normal 90
#define Servo_back_min 0
#define Servo_back_max 180
#define Servo_back_normal 90


#define Is_Led1 0
#define Led1_pin 3

#define Is_Led2 1
#define Led2_pin 9

#define Is_led2_auto 0
#define Light_sensor_pin A2
#define Led2_trigger 600

#include <Servo.h>

Servo motor;
Servo servoleft;
Servo servoright;
Servo servoback;

void setup() {
  pinMode(Motor_pin, OUTPUT);
  pinMode(Servo_left_pin, OUTPUT);
  pinMode(Servo_right_pin, OUTPUT);
  pinMode(Servo_back_pin, OUTPUT);
  pinMode(Led2_pin, OUTPUT);
  pinMode(Power_pin, INPUT);
  if(Is_led1){
      pinMode(Led1_pin, OUTPUT);
    }
  if(Is_Led2){
      if(Is_led2_auto){
        pinMode(Light_sensor_pin, INPUT);
      }
      else{
        digital.write(Led2_pin, 1);
      }
  }

  motor.attach(Motor_pin);
  servoleft.attach(Servo_left_pin);
  servoright.attach(Servo_right_pin);
  servoback.attach(Servo_back_pin);
  Serial.begin(9600);

  Serial.println("hacerioPilot 1.0 is startig...");
  Serial.println("Maded whith love from hacerio");
  Serial.println("Calibrating motor");
  motor.write(Motor_max);
  Serial.println(Motor_max);
  delay(3000);
  motor.write(Motor_min);
  Serial.println(Motor_min);
  delay(8000);
  motor.write(Motor_max);
  delay(500);
  motor.write(Motor_min);
  delay(1500);
  servoleft.write(Servo_left_min);
  servoright.write(Servo_right_min);
  servoback.write(Servo_back_min);
  delay(1500);
  servoleft.write(Servo_left_max);
  servoright.write(Servo_right_max);
  servoback.write(Servo_back_max);
  delay(1500);
  servoleft.write(Servo_left_normal);
  servoright.write(Servo_right_normal);
  servoback.write(Servo_back_normal);
  Serial.println("Calibrating is complete");
}
void loop() {
  
}
