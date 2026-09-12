# SmartBMS Fault Test Results

| Test Case | Input Condition | Expected State | LED Result | Actual Result |
|---|---|---|---|---|
| Normal operation | Voltage = 12.4 V, Current = 1.5 A, Temperature = 30°C | NORMAL | OFF | PASS |
| Overvoltage | Voltage > 14.0 V | FAULT | ON | PASS |
| Undervoltage | Voltage < 10.0 V | FAULT | ON | PASS |
| Overcurrent | Current > 5.0 A | FAULT | ON | PASS |
| Overtemperature | Temperature > 45°C | FAULT | ON | PASS |
| Undertemperature | Temperature < 0°C | FAULT | ON | PASS |