#include "Leg.h"

#define LEFT_CHANNEL  0
#define RIGHT_CHANNEL 1
#define LEFT_PIN      15
#define RIGHT_PIN     2

#define LEFT_MIN_US              500.0
#define LEFT_MAX_US              2500.0
#define RIGHT_MIN_US             500.0
#define RIGHT_MAX_US             2500.0

#define PWM_FREQ                 50
#define PWM_CYCLE                (1000000.0 / PWM_FREQ)
#define TIMER_WIDTH              16
#define TIMER_RESOLUTION         ((1 << TIMER_WIDTH) - 1)

int channel;

void setup() {
  // initialize Serial
  Serial.begin(115200);

  ledcSetup(LEFT_CHANNEL, PWM_FREQ, TIMER_WIDTH);
  ledcAttachPin(LEFT_PIN, LEFT_CHANNEL);
  
  ledcSetup(RIGHT_CHANNEL, PWM_FREQ, TIMER_WIDTH);
  ledcAttachPin(RIGHT_PIN, RIGHT_CHANNEL);

  channel = LEFT_CHANNEL;
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();

    if (input == "left\n") {
      channel = LEFT_CHANNEL;
      Serial.printf("switch to left\n");
      return;
    }
    else if (input == "right\n") {
      channel = RIGHT_CHANNEL;
      Serial.printf("switch to right\n");
      return;
    }

    int us = input.toInt();

    Serial.printf("us: %d\n", us);

    // us = (duty / TIMER_RESOLUTION) * PWM_CYCLE => duty = (us / PWM_CYCLE) * TIMER_RESOLUTION
    int duty = (us / PWM_CYCLE) * TIMER_RESOLUTION;

    ledcWrite(channel, duty);

    delay(1000);
    ledcWrite(channel, (1500 / PWM_CYCLE) * TIMER_RESOLUTION);
  }
}
