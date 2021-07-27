#include <Servo.h>

#define BUTTON 0
#define SERVO 25

#define BUTTON 0 
#define START_SCAN 7E000801000201ABCD   

//set the RX and TX pins for UART2  
#define Tx 38                           
#define Rx 39     


Servo TrapServo;

const uint8_t OPEN = 0;
const uint8_t CLOSE = 90;

String Data;
char trigger[]= "7E000801000201ABCD" ;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 Serial2.begin(9600, SERIAL_8N1, Tx, Rx);

 pinMode(BUTTON,INPUT);
 pinMode(SERVO,OUTPUT);
 
 TrapServo.attach(SERVO);

}

void loop() {
  // put your main code here, to run repeatedly:

  TrapServo.write(CLOSE);

  if(!digitalRead(BUTTON)){
    //Serial2.write(trigger);
    Serial.println(trigger);
    }
  
  while(Serial2.available()>0){
    Data = Serial2.readString();
    Serial.println(Data);
    Serial.println(OPEN);
    TrapServo.write(OPEN);  
  }

  delay(1000);
}
