#include<Servo.h>
#include<Wire.h>


Servo myservo1;

int pos=0;
void setup()
{
    myservo1.attach(9);
    myservo1.write(70);
    Serial.begin(9600);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    for (int i = 2; i < 6; i++) 
    {
        pinMode(i, OUTPUT);
    }
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
}
int h=12,m=30;
void loop()
{


    while(Serial.available()){
        
       char c = Serial.read();
       if(c=='a')//开左灯
       {
        for(pos;pos<120;pos++)
          {
             myservo1.write(pos);
             delay(15);
          }
          pos=70;
          myservo1.write(pos);
          digitalWrite(11,HIGH);
       }
        else if(c=='b')//开右灯
        {
          
          
          for (int count = 0; count < 512; count++)
          {
             for (int i = 2; i < 6; i++)
             {
                 digitalWrite(i, HIGH);
                 delay(3);
                 digitalWrite(i, LOW);
             }
          }
          digitalWrite(12,HIGH);

          for(pos;pos<120;pos++)
          {
             myservo1.write(pos);
             delay(15);
          }
          pos=70;
          myservo1.write(pos);

          
          for (int count = 0; count < 512; count++)
          {
             for (int i = 5; i > 1; i--)
             {
                 digitalWrite(i, HIGH);
                 delay(3);
                 digitalWrite(i, LOW);
             }
          }
          Serial.println("LED bright");
          
        }
        else if(c=='c')//关左灯
        {
          for(pos;pos>=20;pos--)
          {
             myservo1.write(pos);
             delay(15);
          }
          pos=70;
          myservo1.write(pos);
          digitalWrite(11,LOW);
        }
        else if(c=='d')//关右灯
        {
          
          for (int count = 0; count < 512; count++)
          {
             for (int i = 2; i < 6; i++)
             {
                 digitalWrite(i, HIGH);
                 delay(3);
                 digitalWrite(i, LOW);
             }
          }
          
          digitalWrite(12,LOW);
          for(pos;pos>=20;pos--)
          {
             myservo1.write(pos);
             delay(15);
          }
          pos=70;
          myservo1.write(pos);
          
          for (int count = 0; count < 512; count++)
          {
             for (int i = 5; i > 1; i--)
             {
                 digitalWrite(i, HIGH);
                 delay(3);
                 digitalWrite(i, LOW);
             }
          }
        }
    }
}
