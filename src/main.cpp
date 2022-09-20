#include <Arduino.h>
#include <STM32FreeRTOS.h>

// Motor A connections
int enA = PB9;
int in1 = PB8;
int in2 = PB7;

void OpenBallValve(void *pvParameters)
{
  while (1)
  {
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);

    // Open ball valve
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void CloseBallValve(void *pvParameters)
{
  while (1)
  {
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);

    // Close ball valve
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void TurnOffBallValve(void *pvParameters)
{
  while (1)
  {
    // Turn off ball valve
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void setup()
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  xTaskCreate(OpenBallValve, "Open Ball Valve", 100, NULL, 1, NULL);
  xTaskCreate(CloseBallValve, "Close Ball Valve", 100, NULL, 1, NULL);
  xTaskCreate(TurnOffBallValve, "Turn Off Ball Valve", 100, NULL, 1, NULL);
}

void loop()
{
}

