
#include <MPU6050_tockn.h>
#include <Wire.h>
float x_ang,y_ang,z_ang;
//float

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
   
  mpu6050.update();
 x_ang= mpu6050.getAngleX();
y_ang=  mpu6050.getAngleY();
 z_ang =mpu6050.getAngleZ();
 Serial.println("x_ang");Serial.println(x_ang);
 LED_on(x_ang,y_ang,z_ang);
  
}
void LED_on(float x,float y,float z)
{
  if(x>0 && x<10)
  {
    Serial.println("x between 0 and 20");
  digitalWrite (2,1);
   digitalWrite (3,0);
   digitalWrite (4,0);
   digitalWrite(5,0);
   
  }
   else if(x>10 && x <20)
  {
    Serial.println("x between 20 and 40");
      digitalWrite (2,0);
   digitalWrite (3,1);
   digitalWrite (4,0);
   digitalWrite(5,0);
  }
 
 else if(x>20 && x <30)
  {
    Serial.println("x between 20 and 40");
      digitalWrite (2,0);
   digitalWrite (3,0);
   digitalWrite (4,1);
   digitalWrite(5,0);
  }
  
 else if(x>30 && x <40)
  {
    Serial.println("x between 20 and 40");
       digitalWrite (2,0);
   digitalWrite (3,0);
   digitalWrite (4,0);
   digitalWrite(5,1);
  }

  if(y>0 && y<10)
  {
    Serial.println("x between 0 and 20");
  digitalWrite (6,1);
   digitalWrite (7,0);
   digitalWrite (8,0);
  
   
  }
   else if(y>10 && y <20)
  {
    Serial.println("y between 20 and 40");
      digitalWrite (6,0);
   digitalWrite (7,1);
   digitalWrite (8,0);
  
  }
 
 else if(y>20 && y <30)
  {
    Serial.println("y between 20 and 40");
      digitalWrite (6,0);
   digitalWrite (7,0);
   digitalWrite (8,1);
  
  }
  
  else {
    Serial.println ("error  try again ☺ ");
       digitalWrite (2,0);
   digitalWrite (3,0);
   digitalWrite (4,0);
   digitalWrite(5,0);
    digitalWrite (6,0);
   digitalWrite (7,0);
   digitalWrite(8,0);
  }
  
  
}
