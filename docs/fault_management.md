# SmartBMS Fault Management

## 1. Purpose

The fault-management module evaluates battery measurements
against configured prototype operating limits.

## 2. Monitored Parameters

- Battery voltage
- Battery current
- Battery temperature

## 3. Fault Conditions

### Over-voltage

Triggered when:

Battery voltage > configured maximum voltage

### Under-voltage

Triggered when:

Battery voltage < configured minimum voltage

### Over-current

Triggered when:

Battery current > configured maximum current

### Over-temperature

Triggered when:

Battery temperature > configured maximum temperature

### Under-temperature

Triggered when:

Battery temperature < configured minimum temperature

## 4. Fault Processing

Battery measurements
        ↓
Fault evaluation
        ↓
Fault flags
        ↓
BMS state

## 5. Initial State Logic

If no fault is active:

NORMAL

If any critical fault is active:

FAULT

WARNING and RECOVERY states will be implemented
during later development.

## 6. Safety Note

The limits used by this educational prototype will be selected
for the specific low-voltage laboratory setup. They are not
intended to represent production EV battery protection limits.

## 7. Fault Indication Strategy

The SmartBMS uses a status LED connected to ESP32 GPIO 23
to indicate the current battery safety condition.

- Normal operation: LED OFF
- Overvoltage: Fast blinking
- Undervoltage: Slow blinking
- Overcurrent: Two short flashes
- Overtemperature: Continuous ON
- Undertemperature: Three short flashes

This indication strategy allows the user to identify the
fault type without continuously observing the Serial Monitor.

Normal voltage range:10.0-14.0V
Maximum current: 5.0A
Normal temperature range:0-45 degree celcius
Any violation produces a FAULT state
OverVoltage currently produces a blinking LED
Other faults currently produce a continuously ON LED