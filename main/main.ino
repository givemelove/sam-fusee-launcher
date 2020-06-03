#include <Arduino.h>

#include "fuseegelee.h"
#include "trinketLed.h"
#include <Adafruit_CircuitPlayground.h>

// Contains fuseeBin and FUSEE_BIN_SIZE
#include "hekate_ctcaer_4.2.h"


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  CircuitPlayground.begin();
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("orange", 1, 200);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
