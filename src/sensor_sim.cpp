#include <Arduino.h>
#include "sensor_sim.h"

void generateManualBatteryData(
    BatteryData &battery
)
{
    Serial.println();
    Serial.println("Enter Battery Parameters");

    Serial.print("Voltage (V): ");
    while (Serial.available() == 0)
    {
    }
    battery.voltage = Serial.parseFloat();

    while (Serial.available() > 0)
    {
        Serial.read();
    }

    Serial.print("Current (A): ");
    while (Serial.available() == 0)
    {
    }
    battery.current = Serial.parseFloat();

    while (Serial.available() > 0)
    {
        Serial.read();
    }

    Serial.print("Temperature (C): ");
    while (Serial.available() == 0)
    {
    }
    battery.temperature = Serial.parseFloat();

    while (Serial.available() > 0)
    {
        Serial.read();
    }
}