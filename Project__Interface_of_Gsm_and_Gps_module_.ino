/*This project is designed for vehicle theft control. This is a GSM and GPS based project. The special feature of this project is, The location of vehicle can be traced with any mobile with the
help of a secured password. When you send the password to the GSM module fixed in the car via text SMS, The GSM module reply you a with a google map link containing the GPS location of your car.
Its accuracy is about 5-10m.
This project can also be used for other purpose like in your luggage bag, Bike etc.

Connections

Arduino uno            GSM Module
GND                     GND
3                       RX
4                       TX

Arduino uno            GPS Module
3.3                       VCC
GND                       GND
Rx                        Tx
Tx                        Rx

Note- Please remove the Rx, Tx pin of arduino uno connected with GPS Module while uploading the code. Insert it after uploading the code.
If you have 5V GSM module you can power it with arduino otherwise If you have a 12V GSM Module you can power it from your vehicle battery or 12V adapter.
In this code password is "Send".
*/

#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
// Configure software serial port
SoftwareSerial SIM900(3, 4);

// Variable to store text message
String textMessage;
char Gm;



void setup() {
  // Initializing serial commmunication
  Serial.begin(9600); 
  SIM900.begin(9600);

  
  

  // Give time to your GSM shield log on to network
  delay(5000);
  Serial.print("SIM900 is ready to send receive sms");

  // AT command to set SIM900 to SMS mode
  SIM900.println("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
    }

void loop(){
 if(SIM900.available()>0){
    textMessage = SIM900.readString();
    Serial.print(textMessage);
    delay(10); 

 }

 if(textMessage.indexOf("Send")>=0){
    check();
    
  }
}
 
   
 

// Function that extract mobile no. and send sms

void check()
{
        String servo = SIM900.readStringUntil('"');
        if(servo != 0){
            //here you could check the servo number
            String pos = SIM900.readStringUntil('"');
            int int_pos=pos.toInt();
           if(pos != 0){
            //here you could check the servo number
            String nneed = SIM900.readStringUntil('5');
            
           
         
           
            Serial.println("SERVO=");
            Serial.print(servo);
            delay(1000);
            Serial.println("Pos=");
            Serial.print(pos);
            delay(1000);
            delay(100);
            Serial.println("nneed=");
            Serial.print(nneed);
            delay(2000);
            



            
              bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

   for (unsigned long start = millis(); millis() - start < 1000;)
 {
    while (Serial.available())
    {
  char c = Serial.read();
      Serial.print(c);
      if (gps.encode(c))
      newData = true;
    }
 }
       
    if (newData)
    {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    Serial.print(" Longitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.println("latitude");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
   delay(1000);
    
  
  
  SIM900.println("AT+CMGF=1\r"); 
  delay(400);

  SIM900.print("AT + CMGS=\"");
  SIM900.print(pos);
  SIM900.println("\""); 
  delay(300);
   SIM900.print("http://maps.google.com/maps?q=");                       // Creating link of google MAP
   SIM900.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" Longitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
   Serial.print(",");
   SIM900.print(',');
   SIM900.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
   Serial.print("latitude");
   Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
   
  // Send the SMS
   
  delay(1000);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(10000);
    }              
        }
        }
} 
