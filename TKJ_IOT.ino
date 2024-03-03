
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "TKJ IOT"
#define REMOTEXY_WIFI_PASSWORD "08121212"
#define REMOTEXY_SERVER_PORT 6377


#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 93 bytes
  { 255,2,0,0,0,86,0,16,160,1,2,1,21,30,22,11,135,26,31,1,
  79,78,0,79,70,70,0,2,1,20,57,22,11,135,26,31,36,79,78,0,
  79,70,70,0,129,0,15,4,33,6,164,84,75,74,32,83,65,84,79,69,
  0,129,0,20,23,23,6,246,83,97,107,108,97,114,32,49,0,129,0,19,
  51,23,6,234,83,97,107,108,97,114,32,50,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


#define PIN_SWITCH_1 D0
#define PIN_SWITCH_2 D1


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  

}
