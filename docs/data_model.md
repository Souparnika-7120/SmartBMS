# SmartBMS CAN Protocol

## 1. Purpose

The CAN interface allows SmartBMS to communicate battery
status, fault information and heartbeat information to
a Vehicle Control Unit (VCU).

## 2. CAN Nodes

### Node 1
SmartBMS ESP32

### Node 2
VCU Simulator

## 3. CAN Messages

### 0x100 - Battery Status

| Byte | Parameter       |
|------|-----------------|
| 0-1  | Battery Voltage |
| 2-3  | Battery Current |
| 4    | Temperature     |
| 5    | SOC             |
| 6    | BMS State       |
| 7    | Reserved        |

Transmission period: 100 ms

### 0x101 - Fault Status

| Bit | Fault             |
|-----|-------------------|
| 0   | Over-voltage      |
| 1   | Under-voltage     |
| 2   | Over-current      |
| 3   | Over-temperature  |
| 4   | Under-temperature |
| 5-7 | Reserved          |

Transmission period: 100 ms

### 0x102 - BMS Heartbeat

| Byte | Parameter        |
|------|------------------|
| 0    | BMS Status       |
| 1    | Firmware Version |
| 2    | Message Counter  |
| 3-7  | Reserved         |

Transmission period: 500 ms

## 4. BMS States

| Value | State    |
|-------|----------|
| 0     | INIT     |
| 1     | NORMAL   |
| 2     | WARNING  |
| 3     | FAULT    |
| 4     | RECOVERY |

## 5. CAN Node Architecture

SmartBMS
    |
    | CAN
    |
VCU Simulator 