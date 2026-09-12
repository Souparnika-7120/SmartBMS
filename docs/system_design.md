# SmartBMS System Design

## 1. Project Overview

SmartBMS is an educational low-voltage Battery Management
System prototype based on an ESP32 microcontroller.

The system monitors battery voltage, current and temperature,
detects abnormal conditions, calculates basic battery parameters,
and communicates battery status to a VCU simulator using CAN.

## 2. Main Components

- ESP32 microcontroller
- Voltage sensing
- Current sensing
- Temperature sensing
- CAN communication
- VCU simulator
- PC monitoring/dashboard

## 3. System Flow

Battery
    ↓
Sensors
    ↓
ESP32
    ↓
Data Acquisition
    ↓
Battery Parameter Calculation
    ↓
Fault Detection
    ↓
State Management
    ↓
CAN Communication
    ↓
VCU Simulator

## 4. System States

### INIT
System initialization after startup.

### NORMAL
All monitored parameters are within configured
prototype operating limits.

### WARNING
A parameter is approaching a configured limit.

### FAULT
A critical abnormal condition has been detected.

### RECOVERY
The system verifies that a previous fault condition
has cleared before returning to NORMAL.

## 5. Fault Types

- Over-voltage
- Under-voltage
- Over-current
- Over-temperature
- Under-temperature

## 6. Development Approach

The project will be developed incrementally:

1. Firmware initialization
2. GPIO and status indication
3. ADC-based measurement
4. Voltage measurement
5. Temperature measurement
6. Current measurement
7. Battery calculations
8. Fault management
9. State machine
10. CAN communication
11. VCU simulation
12. Data logging
13. Dashboard
14. Testing and fault injection

## Current System Status

The SmartBMS prototype currently uses simulated battery readings
to validate the monitoring and fault-detection logic.

The ESP32 performs the following operations:

1. Reads simulated voltage, current, temperature, and SOC values.
2. Compares the values against predefined safety limits.
3. Determines the BMS operating state.
4. Displays battery and fault information through Serial Monitor.
5. Controls a status LED connected to GPIO 23.
6. Indicates overvoltage using a blinking LED.
7. Indicates other detected faults using a continuously ON LED.

Actual sensor integration is planned for the next development stage.