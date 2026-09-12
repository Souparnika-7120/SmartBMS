#include <Arduino.h>
#include "battery.h"
#include "fault.h"

// LED connected to GPIO 23
const int STATUS_LED = 23;

// Battery data
BatteryData battery;

// Fault information
FaultStatus faults;

// BMS safety limits
BMSLimits limits;

// Current BMS state
BMSState currentState;

// Monitoring timer
unsigned long previousMillis = 0;
const unsigned long monitoringInterval = 2000;

// LED blinking timer
unsigned long ledPreviousMillis = 0;
const unsigned long ledBlinkInterval = 200;

// LED state
bool ledState = false;


// --------------------------------------------------
// Convert BMS state into readable text
// --------------------------------------------------

const char* stateToString(BMSState state)
{
    switch (state)
    {
        case INIT:
            return "INIT";

        case NORMAL:
            return "NORMAL";

        case WARNING:
            return "WARNING";

        case FAULT:
            return "FAULT";

        case RECOVERY:
            return "RECOVERY";

        default:
            return "UNKNOWN";
    }
}


// --------------------------------------------------
// Simulate battery sensor readings
// This function will be replaced with real sensors
// on Monday.
// --------------------------------------------------

void readBatteryData()
{
    // Normal simulated battery readings
    battery.voltage = 12.4;
    battery.current = 1.5;
    battery.temperature = 30.0;
    battery.soc = 80.0;
}


// --------------------------------------------------
// Update LED according to the detected fault
// --------------------------------------------------

void updateLED()
{
    unsigned long currentMillis = millis();

    if (faults.overVoltage)
    {
        // Fast blinking for overvoltage
        if (currentMillis - ledPreviousMillis >= ledBlinkInterval)
        {
            ledPreviousMillis = currentMillis;

            ledState = !ledState;
            digitalWrite(STATUS_LED, ledState);
        }
    }
    else if (currentState == FAULT)
    {
        // Continuous ON for other faults
        digitalWrite(STATUS_LED, HIGH);
        ledState = true;
    }
    else
    {
        // LED OFF during normal operation
        digitalWrite(STATUS_LED, LOW);
        ledState = false;
    }
}


// --------------------------------------------------
// Display battery and fault information
// --------------------------------------------------

void printBMSStatus()
{
    Serial.println();
    Serial.println("----------- BMS STATUS -----------");

    Serial.print("Battery Voltage : ");
    Serial.print(battery.voltage);
    Serial.println(" V");

    Serial.print("Battery Current  : ");
    Serial.print(battery.current);
    Serial.println(" A");

    Serial.print("Temperature      : ");
    Serial.print(battery.temperature);
    Serial.println(" C");

    Serial.print("SOC              : ");
    Serial.print(battery.soc);
    Serial.println(" %");

    Serial.println();

    Serial.print("Over Voltage     : ");
    Serial.println(faults.overVoltage ? "YES" : "NO");

    Serial.print("Under Voltage    : ");
    Serial.println(faults.underVoltage ? "YES" : "NO");

    Serial.print("Over Current     : ");
    Serial.println(faults.overCurrent ? "YES" : "NO");

    Serial.print("Over Temperature : ");
    Serial.println(faults.overTemperature ? "YES" : "NO");

    Serial.print("Under Temperature: ");
    Serial.println(faults.underTemperature ? "YES" : "NO");

    Serial.println();

    Serial.print("BMS STATE        : ");
    Serial.println(stateToString(currentState));

    Serial.print("STATUS LED       : ");

    if (faults.overVoltage)
    {
        Serial.println("BLINKING");
    }
    else if (currentState == FAULT)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.println("----------------------------------");
}


// --------------------------------------------------
// Setup
// --------------------------------------------------

void setup()
{
    Serial.begin(115200);

    pinMode(STATUS_LED, OUTPUT);
    digitalWrite(STATUS_LED, LOW);

    Serial.println("================================");
    Serial.println("        SmartBMS v0.6");
    Serial.println("    Simulated Battery Monitoring");
    Serial.println("================================");

    // Configure BMS safety limits
    limits.maxVoltage = 14.0;
    limits.minVoltage = 10.0;

    limits.maxCurrent = 5.0;

    limits.maxTemperature = 45.0;
    limits.minTemperature = 0.0;

    // Initial BMS state
    currentState = INIT;
}


// --------------------------------------------------
// Main loop
// --------------------------------------------------

void loop()
{
    unsigned long currentMillis = millis();

    // Periodic battery monitoring
    if (currentMillis - previousMillis >= monitoringInterval)
    {
        previousMillis = currentMillis;

        // Read simulated battery measurements
        readBatteryData();

        // Check battery values against safety limits
        checkFaults(battery, limits, faults);

        // Determine overall BMS state
        currentState = determineState(faults);

        // Print monitoring information
        printBMSStatus();
    }

    // Update LED continuously without blocking monitoring
    updateLED();
}
