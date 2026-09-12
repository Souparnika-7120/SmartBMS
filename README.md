# SmartBMS — Embedded Battery Monitoring & Protection System

SmartBMS is an educational low-voltage Battery Management System prototype developed using an ESP32 microcontroller.

The project focuses on embedded firmware development, battery parameter monitoring, fault detection, safety-state management, and status indication. It is designed as a learning and portfolio project for embedded systems, firmware, and electric vehicle battery-management applications.

> **Note:** This is an educational low-voltage prototype and is not intended for direct use in real electric vehicles or high-voltage battery packs.

---

## Project Objectives

- Monitor battery voltage, current, temperature, and State of Charge (SOC).
- Compare battery readings with predefined safety limits.
- Detect abnormal battery conditions.
- Classify the overall Battery Management System state.
- Indicate fault conditions using an LED.
- Develop modular and maintainable embedded C++ firmware.
- Prepare the project for future sensor and CAN communication integration.

---

## Hardware Used

- ESP32 DevKit V1
- LED
- 220 Ω resistor
- Breadboard
- Jumper wires

### Planned Hardware

- Voltage sensor
- Current sensor
- Temperature sensor
- CAN transceiver
- Battery monitoring circuit

---

## Software and Technologies

- Embedded C++
- Arduino Framework
- PlatformIO
- ESP32
- GPIO programming
- Fault detection logic
- Modular firmware design
- Git and GitHub

---

## System Features

### 1. Battery Data Monitoring

The firmware monitors the following battery parameters:

| Parameter | Description |
|---|---|
| Voltage | Battery voltage in volts |
| Current | Battery current in amperes |
| Temperature | Battery temperature in degrees Celsius |
| SOC | Estimated State of Charge in percentage |

Currently, the battery readings are simulated in software. Physical sensors will be integrated in a future stage.

---

### 2. Fault Detection

The system checks the battery values against predefined safety limits.

The following faults are supported:

- Overvoltage
- Undervoltage
- Overcurrent
- Overtemperature
- Undertemperature

---

### 3. BMS State Management

The system uses the following states:

- `INIT` — Initial system state
- `NORMAL` — Battery parameters are within safe limits
- `WARNING` — Reserved for future warning conditions
- `FAULT` — One or more safety limits have been violated
- `RECOVERY` — Reserved for future fault-recovery logic

---

### 4. LED Status Indication

The status LED is connected to **GPIO 23**.

| Condition | LED Behavior |
|---|---|
| Normal operation | OFF |
| Overvoltage | Fast blinking |
| Other fault conditions | Continuously ON |

---

## Safety Limits Used for Testing

| Parameter | Limit |
|---|---:|
| Maximum voltage | 14.0 V |
| Minimum voltage | 10.0 V |
| Maximum current | 5.0 A |
| Maximum temperature | 45.0 °C |
| Minimum temperature | 0.0 °C |

These values are used only for educational simulation and testing.

---

## Project Structure

```text
SmartBMS/
├── .gitignore
├── platformio.ini
├── README.md
├── src/
│   ├── main.cpp
│   └── fault.cpp
├── include/
│   ├── battery.h
│   └── fault.h
└── docs/
    ├── can_protocol.md
    ├── data_model.md
    ├── fault_management.md
    ├── fault_test_result.md
    ├── progress_log.md
    └── system_design.md
```
Testing and Validation

The firmware was tested using simulated battery values.

Test Condition	Example Value	Expected Result
Normal operation	12.4 V, 1.5 A, 30 °C	NORMAL, LED OFF
Overvoltage	15.0 V	FAULT, LED blinking
Undervoltage	9.0 V	FAULT, LED ON
Overcurrent	6.0 A	FAULT, LED ON
Overtemperature	50.0 °C	FAULT, LED ON
Undertemperature	−5.0 °C	FAULT, LED ON

Detailed test results are available in:

docs/fault_test_result.md
How to Run the Project
Requirements

Install the following software:

Visual Studio Code
PlatformIO extension
USB driver required for the ESP32 board, if necessary
Steps
Clone or download this repository.
Open the project folder in Visual Studio Code.
Open the PlatformIO project.
Connect the ESP32 board to the computer.
Select the correct ESP32 board and COM port.
Upload the firmware.
Open the Serial Monitor at:
115200 baud
Observe the battery readings, fault information, and BMS state.
Future Improvements
Integrate real voltage, current, and temperature sensors.
Add battery State of Charge estimation.
Add sensor calibration.
Implement warning and recovery states.
Add data logging.
Integrate CAN communication.
Connect the ESP32 to a Vehicle Control Unit simulator.
Develop a real-time monitoring dashboard.
Add improved battery protection and diagnostic features.
Learning Outcomes

Through this project, the following concepts are being practiced:

Embedded C++ programming
ESP32 microcontroller programming
GPIO control
Modular firmware architecture
Structures and enumerations
Function-based code organization
Battery monitoring concepts
Fault detection and validation
Git and GitHub project management


Author

S Souparnika

B.Tech Electronics and Communication Engineering
AI & Cybernetics
VIT Bhopal University
