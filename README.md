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
