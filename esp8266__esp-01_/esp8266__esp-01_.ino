#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "efe-wifi"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377


#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 2, 0, 0, 0, 30, 0, 11, 13, 0,
  1, 0, 14, 9, 12, 12, 0, 31, 88, 0,
  2, 0, 41, 10, 22, 11, 50, 26, 31, 31,
  79, 78, 0, 79, 70, 70, 0
};

struct {

  uint8_t button_2;
  uint8_t switch_1;

  uint8_t connect_flag;

} RemoteXY;
#pragma pack(pop)

#define PIN_BUTTON_2 9
#define PIN_SWITCH_1 8


void setup()
{
  RemoteXY_Init ();

  pinMode (PIN_BUTTON_2, OUTPUT);
  pinMode (PIN_SWITCH_1, OUTPUT);
}

void loop()
{
  RemoteXY_Handler ();

  digitalWrite(PIN_BUTTON_2, (RemoteXY.button_2 == 0) ? LOW : HIGH);
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1 == 0) ? LOW : HIGH);
}
