#include "const.h"
#include "drinks.h"
#include "store.h"
#include "screen.h"
#include "pump.h"
#include "controls.h"

Screen screen = Screen();
Controls controls = Controls();

Pump pumps[PUMP_COUNT] = {
  Pump(PUMP_1_PIN, PUMP_1_ING),
  Pump(PUMP_2_PIN, PUMP_2_ING),
  Pump(PUMP_3_PIN, PUMP_3_ING),
  Pump(PUMP_4_PIN, PUMP_4_ING),
  Pump(PUMP_5_PIN, PUMP_5_ING),
  Pump(PUMP_6_PIN, PUMP_6_ING)
};

void setup() {
  Serial.begin(19200);
  screen.init();;
}

void loop() {
  if(Store::startButtonPressed) {
    makeDrink();
  }
  
  if(Store::status == STATUS_BUSY) {
    checkReadyStatus();
  }

  for(byte i = 0; i < PUMP_COUNT; i++) {
    pumps[i].loop();
  }

  controls.loop();
  screen.loop();
}

void makeDrink() {
  if(Store::status == STATUS_READY) {
    Store::status = STATUS_BUSY;
    
    float maxWaitTime = 0;

    for (byte i = 0; i < PUMP_COUNT; i++) {
      float quantity = Store::selectedDrink.quantity[i];
      float waitTime = (quantity * Store::multiplier) * FLOW_RATE * 1000;
      
      if(quantity != 0) {
        int pumpIndex = getPumpIndexByIngredient(Store::selectedDrink.ingredients[i]);

        if(pumpIndex >= 0) {
          pumps[pumpIndex].on(waitTime);
          
          if(waitTime > maxWaitTime) {
            maxWaitTime = waitTime;
          }
        }
      }
    }
  }
}

int getPumpIndexByIngredient(byte ingredient) {
  for (byte i = 0; i < PUMP_COUNT; i++) {
    if(pumps[i].getIngredient() == ingredient) {
      return i;
    }
  }

  return -1;
}

void checkReadyStatus() {
  for(byte i = 0; i < PUMP_COUNT; i++) {  
    if(pumps[i].getStatus() == STATUS_BUSY) {
      return;
    }
  }

  Store::status = STATUS_READY;
}
