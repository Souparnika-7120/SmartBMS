# SmartBMS — Embedded Battery Monitoring & Protection System

SmartBMS is an educational low-voltage Battery Management System prototype developed using an ESP32 microcontroller and PlatformIO.

The project demonstrates embedded firmware concepts including battery parameter monitoring, input validation, signal filtering, State of Charge (SOC) estimation, fault detection, warning management, BMS state transitions, CAN message generation, and Vehicle Control Unit (VCU) decision logic.

The project is designed as a learning and portfolio project for embedded systems, firmware, battery-management systems, and electric-vehicle applications.

> **Note:** This is an educational low-voltage prototype and is not intended for direct use in real electric vehicles, high-voltage battery packs, or production battery-management systems.

---

## Project Objectives

- Monitor battery voltage, current, temperature, and estimated State of Charge (SOC).
- Validate incoming battery parameters.
- Apply basic signal filtering to simulated battery measurements.
- Compare battery values with predefined safety and warning limits.
- Detect abnormal battery conditions.
- Implement fault persistence and recovery logic.
- Manage BMS operating states.
- Generate CAN-formatted battery and BMS status messages.
- Simulate VCU decision-making based on BMS status.
- Indicate battery conditions using an ESP32-connected status LED.
- Demonstrate modular and maintainable embedded C++ firmware.

---

## System Architecture

```text
          Battery Parameters
        (Manual / Simulated)
                 │
                 ▼
        ┌─────────────────┐
        │ Input Validation│
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │ Moving Average  │
        │    Filtering    │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │ SOC Estimation  │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │ Fault & Warning │
        │    Detection    │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │ BMS State Machine│
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │ CAN Message     │
        │   Generation    │
        └────────┬────────┘
                 │
                 ▼
        ┌─────────────────┐
        │  VCU Simulator  │
        └────────┬────────┘
                 │
       ┌─────────┼─────────┐
       ▼         ▼         ▼
    ENABLED    LIMITED   DISABLED
     100%        50%        0%
```
Hardware Used
ESP32 DevKit V1
LED
220 Ω resistor
Breadboard
Jumper wires
LED Connection

The status LED is connected as follows:

ESP32 GPIO 23
      │
    220 Ω
      │
     LED
      │
     GND
Planned Hardware Extensions
Voltage sensor
Current sensor
Temperature sensor
CAN transceiver
Battery monitoring circuitry
Software and Technologies
Embedded C++
Arduino Framework
PlatformIO
ESP32
GPIO programming
Serial communication
Modular firmware architecture
Signal filtering
Fault detection and state management
CAN message encoding
Git
GitHub
System Features
1. Battery Data Monitoring

The firmware works with the following battery parameters:

Parameter	Description
Voltage	Battery voltage in volts
Current	Battery current in amperes
Temperature	Battery temperature in degrees Celsius
SOC	Estimated State of Charge in percentage

Currently, battery values are entered manually through the Serial Monitor and processed as simulated battery measurements.

Physical sensor integration is planned as a future hardware extension.

2. Input Validation

Before processing battery data, the firmware checks whether the input values are within the accepted software validation ranges.

Current validation ranges:

Parameter	Validation Range
Voltage	0 to 20 V
Current	-10 to 10 A
Temperature	-40 to 100 °C
SOC	0 to 100%

Invalid inputs are rejected before further processing.

3. Signal Filtering

A 5-sample moving average filter is implemented for:

Voltage
Current
Temperature

The filter helps demonstrate basic embedded signal-processing techniques and reduces the effect of sudden changes in simulated measurements.

4. State of Charge Estimation

The project implements a simplified voltage-based SOC estimation model.

The educational model maps:

Voltage	Estimated SOC
10.0 V	0%
10.65 V	~25%
11.30 V	~50%
11.95 V	~75%
12.60 V	100%

Note: This is a simplified educational model and is not chemistry-specific or suitable for production battery management.

5. Fault Detection

The system detects the following battery faults:

Overvoltage
Undervoltage
Overcurrent
Overtemperature
Undertemperature
Safety Limits
Parameter	Limit
Maximum voltage	14.0 V
Minimum voltage	10.0 V
Maximum current	5.0 A
Maximum temperature	45.0 °C
Minimum temperature	0.0 °C

These values are used only for educational simulation and testing.

6. Warning Detection

Warning thresholds are implemented before critical fault limits.

Parameter	Warning Condition
Voltage	10.0–10.5 V or 13.5–14.0 V
Current	4.0–5.0 A
Temperature	0–5 °C or 40–45 °C

Warnings do not immediately disable the simulated vehicle drive.

7. BMS State Management

The system uses five BMS states:

INIT
NORMAL
WARNING
FAULT
RECOVERY
State Description
State	Description
INIT	Initial system state
NORMAL	Battery parameters are within safe operating limits
WARNING	Battery parameter is approaching a defined safety limit
FAULT	A critical battery limit has been violated
RECOVERY	System is confirming that safe conditions have returned
Fault Persistence

A critical fault must be detected for 3 consecutive checks before the BMS enters FAULT.

Fault detected
      ↓
Check 1 → Confirmation pending
      ↓
Check 2 → Confirmation pending
      ↓
Check 3 → FAULT
Fault Recovery

After a fault disappears, the system requires 3 consecutive safe checks before returning to NORMAL.

FAULT
  ↓
Safe check 1
  ↓
RECOVERY
  ↓
Safe check 2
  ↓
RECOVERY
  ↓
Safe check 3
  ↓
NORMAL
8. LED Status Indication

The status LED is connected to GPIO 23.

Condition	LED Behavior
Normal operation	OFF
Warning	OFF
Overvoltage	Fast blinking
Other confirmed fault	ON
Recovery / normal after recovery	OFF

The LED was physically tested using the ESP32 hardware.

CAN Communication

The project currently implements software-based CAN message generation and display.

The ESP32 firmware creates CAN-formatted messages and displays their identifiers, DLC, and data bytes through the Serial Monitor.

Important: Physical CAN bus communication has not yet been implemented because an external CAN transceiver is required for the CAN physical layer.

CAN Message 0x100 — Battery Data

CAN ID:

0x100

DLC:

8

Data format:

Byte	Parameter	Scaling
0–1	Voltage	×100
2–3	Current	×100
4–5	Temperature	×100
6–7	SOC	×100

Example:

CAN ID : 0x100
DLC    : 8
DATA   : 5A 05 C8 00 C4 09 10 27

This represents approximately:

Voltage     = 13.70 V
Current     = 2.00 A
Temperature = 25.00 °C
SOC         = 100.00 %
CAN Message 0x101 — BMS Status

CAN ID:

0x101

DLC:

8

Data format:

Byte	Information
0	BMS state
1	Overvoltage flag
2	Undervoltage flag
3	Overcurrent flag
4	Overtemperature flag
5	Undertemperature flag
6	Warning flags
7	Reserved

Example:

CAN ID : 0x101
DLC    : 8
DATA   : 03 01 00 00 00 00 00 00

This represents:

BMS State       = FAULT
Overvoltage     = YES
Other faults    = NO
VCU Simulator

A software-based Vehicle Control Unit simulator has been implemented to demonstrate how vehicle-level decisions can respond to BMS conditions.

The VCU receives the current BMS state and generates a simulated drive command.

BMS State	VCU Decision	Torque Request
NORMAL	DRIVE ENABLED	100%
WARNING	DRIVE LIMITED	50%
RECOVERY	DRIVE LIMITED	50%
FAULT	DRIVE DISABLED	0%
INIT	DRIVE DISABLED	0%

Example:

BMS STATE       : FAULT
DRIVE COMMAND   : DRIVE DISABLED
TORQUE REQUEST  : 0 %

This demonstrates the basic relationship between battery safety monitoring and vehicle-level control decisions.

Testing and Validation

The firmware was tested using manually entered and software-simulated battery values.

Functional Test Results
Test Condition	Result
Normal operation	PASS
Voltage warning	PASS
Persistent overvoltage	PASS
Undervoltage detection	PASS
Overcurrent detection	PASS
Overtemperature detection	PASS
Undertemperature detection	PASS
Fault persistence	PASS
Fault recovery	PASS
VCU drive enable	PASS
VCU drive limiting	PASS
VCU drive disable	PASS
Invalid input rejection	PASS
CAN battery message generation	PASS
CAN BMS status message generation	PASS

Detailed test results are available in:

docs/fault_test_result.md
Project Structure
SmartBMS/
│
├── .gitignore
├── platformio.ini
├── README.md
│
├── include/
│   ├── battery.h
│   ├── fault.h
│   ├── sensor_sim.h
│   ├── soc.h
│   ├── validation.h
│   ├── filter.h
│   ├── can_protocol.h
│   └── vcu.h
│
├── src/
│   ├── main.cpp
│   ├── fault.cpp
│   ├── sensor_sim.cpp
│   ├── soc.cpp
│   ├── validation.cpp
│   ├── filter.cpp
│   ├── can_protocol.cpp
│   └── vcu.cpp
│
└── docs/
    ├── can_protocol.md
    ├── data_model.md
    ├── fault_management.md
    ├── fault_test_result.md
    ├── progress_log.md
    └── system_design.md
How to Run the Project
Requirements

Install:

Visual Studio Code
PlatformIO extension
USB driver required for the ESP32 board, if necessary
Steps
Clone or download this repository.
Open the project folder in Visual Studio Code.
Open the project using PlatformIO.
Connect the ESP32 DevKit V1 to the computer.
Select the correct COM port.
Build the project.
Upload the firmware to the ESP32.
Open the Serial Monitor.
Set the baud rate to:
115200
Enter the requested battery parameters:
Voltage (V)
Current (A)
Temperature (C)
Observe:
Filtered battery values
Estimated SOC
Fault and warning flags
BMS state
CAN messages
VCU decision
Torque request
LED status
Current Limitations
Battery values are manually entered/software simulated.
Physical voltage, current, and temperature sensors are not currently integrated.
Physical CAN bus communication is not currently implemented.
An external CAN transceiver is required for physical CAN communication.
SOC estimation uses a simplified voltage-based educational model.
The safety thresholds are educational test values and are not production battery specifications.
The VCU is a software simulator and does not control an actual vehicle motor or inverter.
Future Improvements
Integrate physical voltage, current, and temperature sensors.
Add sensor calibration and validation.
Replace simulated battery readings with real sensor measurements.
Add an external CAN transceiver.
Implement physical ESP32 CAN communication.
Test communication between BMS and VCU nodes.
Add CAN fault-message handling if required.
Add data logging.
Develop a real-time monitoring dashboard.
Improve SOC estimation using a more appropriate battery model.
Add additional battery diagnostics and protection features.
Learning Outcomes

Through this project, the following concepts were practiced:

Embedded C++ programming
ESP32 microcontroller programming
PlatformIO project development
GPIO control
Serial communication
Structures and enumerations
Modular firmware architecture
Input validation
Moving-average signal filtering
SOC estimation
Battery monitoring concepts
Fault detection
Warning management
State-machine design
Fault persistence
Fault recovery
CAN message encoding
VCU decision logic
Embedded system testing
Git and GitHub project management
Author

S Souparnika

B.Tech Electronics and Communication Engineering
AI & Cybernetics
VIT Bhopal University
