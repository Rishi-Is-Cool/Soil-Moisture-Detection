# Soil Moisture Detection

This project implements an automated irrigation system using Arduino UNO that monitors soil moisture levels in real-time and controls a water pump via a relay module. The system automatically waters plants when soil becomes dry and stops when adequate moisture is restored, ensuring efficient water usage and optimal plant health.

## System Architecture

The system consists of a simple feedback control loop with the following components:

**Arduino UNO (Controller):**
- Reads analog soil moisture sensor data
- Processes sensor readings and compares against threshold
- Controls relay module to activate/deactivate water pump
- Provides serial monitor output for real-time monitoring and debugging

**Soil Moisture Sensor:**
- Measures soil conductivity to determine moisture level
- Outputs analog voltage (0-1023 scale) inversely proportional to moisture
- Higher values indicate drier soil, lower values indicate moist soil

**Relay Module & Water Pump:**
- Relay acts as an electronic switch controlled by Arduino
- Activates 12V water pump when soil is dry (relay ON)
- Deactivates pump when soil reaches optimal moisture (relay OFF)

## Hardware Requirements

The project requires the following hardware components:

- **1 Arduino UNO/Nano** (5V microcontroller)
- **1 Capacitive Soil Moisture Sensor** (3-pin, analog output)
- **1 Single-Channel 5V Relay Module** (with optocoupler isolation)
- **1 Water Pump** (12V DC submersible pump)
- **1 Power Supply** (12V DC adapter or battery for pump, 5V USB for Arduino)
- **Jumper Wires** (Male-to-Male, Male-to-Female for connections)

## Pin Assignments

The hardware components use the following specific pin assignments:

- **Soil Moisture Sensor:**
  - VCC → Arduino 5V
  - GND → Arduino GND
  - A0 (Analog Output) → Arduino A0

- **Relay Module:**
  - VCC → Arduino 5V
  - GND → Arduino GND
  - IN (Signal) → Arduino Digital Pin 7

- **Water Pump:**
  - Connected to 12V power supply through relay (COM and NO terminals)

## Software and Dependencies

The project uses standard Arduino libraries:

- **Arduino IDE** (Version 1.8.x or higher recommended)
- **Built-in Libraries:**
  - `Serial` (for debugging and monitoring)
  - `pinMode` and `digitalWrite` (for I/O control)
  - `analogRead` (for sensor reading)

No external libraries required - uses only built-in Arduino functions.

## Setup and Configuration

### 1. Threshold Calibration

The moisture threshold determines when the pump activates. The default value in the code is **650**, but you should calibrate it based on your soil type:

**Calibration Steps:**
1. Insert sensor in completely dry soil → note the reading (typically 700-1023)
2. Insert sensor in moist soil → note the reading (typically 300-500)
3. Insert sensor in saturated/wet soil → note the reading (typically 0-300)
4. Set threshold between dry and moist values (recommended: 600-700)

**To modify the threshold:**
```cpp
int threshold = 650;  // Adjust this value in the code
```

### 2. Uploading the Code

1. Open `Soil_moisture_detection.ino` in Arduino IDE
2. Connect Arduino UNO to your computer via USB cable
3. Select **Tools → Board → Arduino UNO**
4. Select the correct **COM Port** under **Tools → Port**
5. Click **Upload** button (or Ctrl+U)
6. Wait for "Done uploading" message

### 3. Hardware Assembly

1. Connect soil moisture sensor to Arduino (VCC, GND, A0)
2. Connect relay module to Arduino (VCC, GND, Pin 7)
3. Wire water pump to relay's COM and NO terminals
4. Connect 12V power supply to pump through relay
5. Verify all connections are secure before powering on

## Operation

### System Initialization

After uploading the code and powering on:
- Arduino initializes serial communication at 9600 baud
- Relay is set to OFF state (HIGH) initially
- Serial Monitor displays: `"Soil Moisture Detection System Started..."`

### Monitoring Operation

**Serial Monitor Output** (Tools → Serial Monitor, set to 9600 baud):
```
Soil Moisture Value: 720
Soil is Dry! Pump ON
Soil Moisture Value: 680
Soil is Dry! Pump ON
Soil Moisture Value: 520
Soil is Moist! Pump OFF
```

The system reads sensor data every 1 second and displays:
- Current soil moisture value (0-1023)
- Soil condition (Dry or Moist)
- Pump status (ON or OFF)

### Automatic Watering Logic

**When soil is DRY (value > threshold):**
- System detects: `Soil Moisture Value > 650`
- Serial prints: `"Soil is Dry! Pump ON"`
- Relay activates (LOW signal) → Pump turns ON
- Water flows until soil becomes moist

**When soil is MOIST (value ≤ threshold):**
- System detects: `Soil Moisture Value ≤ 650`
- Serial prints: `"Soil is Moist! Pump OFF"`
- Relay deactivates (HIGH signal) → Pump turns OFF
- System continues monitoring every 1 second

### Safety Features

- **Initial State:** Relay starts in OFF position to prevent accidental pump activation during startup
- **Continuous Monitoring:** System checks moisture every second for responsive control
- **Active-LOW Relay:** Most relay modules use LOW signal for activation, preventing false triggers

## Troubleshooting

**Problem: Pump doesn't turn on when soil is dry**
- Check relay connections (VCC, GND, Pin 7)
- Verify relay LED lights up when soil is dry
- Confirm pump power supply is connected properly
- Test relay independently to ensure it's functioning

**Problem: Incorrect moisture readings**
- Calibrate sensor in your specific soil type
- Clean sensor probes if corroded or dirty
- Adjust threshold value in code
- Ensure sensor has good contact with soil (2-3 inch depth)

**Problem: Pump runs continuously**
- Threshold may be too high - lower the value
- Check if sensor is properly inserted in soil
- Verify sensor is reading correctly via Serial Monitor
- Ensure water is actually reaching the soil around sensor

**Problem: Serial Monitor shows no output**
- Check baud rate is set to 9600
- Verify USB cable connection
- Ensure correct COM port is selected
- Try pressing Arduino reset button

## Applications

- **Home Gardens:** Automate watering for vegetable gardens, flower beds, or lawn areas
- **Potted Plants:** Maintain optimal moisture for indoor/outdoor container plants
- **Greenhouses:** Scale to multiple zones for commercial growing operations
- **Terrace/Balcony Gardens:** Ideal for urban gardening with limited space
- **Vacation Automation:** Keep plants alive during travel without manual watering

## Future Enhancements

The current system can be extended with:

- **IoT Connectivity:** Add ESP8266/ESP32 for remote monitoring via mobile app
- **Solar Power:** Integrate solar panel and battery for off-grid operation
- **Multiple Sensors:** Monitor different zones independently with multiple sensor-relay pairs
- **LCD Display:** Add local display for moisture readings without computer
- **Data Logging:** Store moisture history on SD card for analysis
- **Weather Integration:** Adjust watering based on rainfall forecasts
- **Soil pH Monitoring:** Add pH sensor for comprehensive soil health tracking

---

## License

This project is open-source and available for educational and personal use. Feel free to modify and adapt for your specific needs.

## Support

For questions or issues, refer to the Serial Monitor output for debugging information. Adjust threshold values based on your specific soil type and moisture requirements.

---

**Happy Automated Gardening!**
