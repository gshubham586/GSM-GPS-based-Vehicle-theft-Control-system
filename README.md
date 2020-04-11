# GSM-GPS-bsed-Vehicle-theft-Control-system
A  GSM  and  GPS  based  tracking  system  that  can  be  tracked  by  sending  encrypted SMS,  To  be  implemented  in  the  vehicle  and  it  provides  you  the  Latitude,  Longitude of   the   location   of   the   vehicle   with   a   google   map   link   through   SMS.       
This project is designed for vehicle theft control. This is a GSM and GPS based project. The special feature of this project is, The location of vehicle can be traced with any mobile with the help of a secured password. When you send the password to the GSM module fixed in the car via text SMS, The GSM module reply you a with a google map link containing the GPS location of your car.
Its accuracy is about 5-10m.
This project can also be used for other purpose like in your luggage bag, Bike etc.

##Connections

Aruino uno   ---  GSM Module
GND --- GND
3 --- Rx
4 --- Tx


Arduino uno            GPS Module
3.3                       VCC
GND                       GND
Rx                        Tx
Tx                        Rx

Note- Please remove the Rx, Tx pin of arduino uno connected with GPS Module while uploading the code. Insert it after uploading the code.
If you have 5V GSM module you can power it with arduino otherwise If you have a 12V GSM Module you can power it from your vehicle battery or 12V adapter.
In this code password is "Send".
