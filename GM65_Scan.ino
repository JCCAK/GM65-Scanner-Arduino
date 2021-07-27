///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  27.07.21    by Juan C aka JckRowling ;)
//  Free of use and for educational purpouses, or not 
//  No libraries needed and the UART2 is a hardware UART not a SoftSerial UART
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define BUTTON 0
#define SERVO 25

#define BUTTON 0 
   
//set the RX and TX pins for UART2  
#define Tx 38                           
#define Rx 39     

String Data;
char trigger[]= "7E000801000201ABCD" ;  // Not used in this sketch, can be used after module setup for tigger command --> see GM65 Datasheet.

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 Serial2.begin(9600, SERIAL_8N1, Tx, Rx); //init UART2 for Scanner DATA input

 pinMode(BUTTON,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  TrapServo.write(CLOSE);

  if(!digitalRead(BUTTON)){
    //Serial2.write(trigger);  // Not used, not working
    Serial.println(trigger);
    }
  
  while(Serial2.available()>0){
    Data = Serial2.readString();
    Serial.println(Data); 
  }

  delay(1000);
}
