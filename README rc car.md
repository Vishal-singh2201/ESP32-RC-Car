# ESP32 WiFi Controlled RC Car 🚗📶

A phone-controlled RC car built using **ESP32**, **L298N motor driver**, and **gear motors**. The car creates its own WiFi hotspot — no internet or app installation needed. Just connect your phone to the ESP32's WiFi and control the car from any web browser.

## 🎯 Features

- Fully wireless control via phone browser (no app required)
- Forward / Backward / Left / Right / Stop controls
- Real-time **speed control** using an on-screen slider
- Works as a standalone WiFi Access Point (ESP32 creates its own network)
- Simple, beginner-friendly code — easy to modify and extend

## 🛠️ Hardware Required

| Component | Quantity |
|---|---|
| ESP32 Dev Board (WROOM-32) | 1 |
| L298N Motor Driver Module | 1 |
| BO Gear Motors | 2 or 4 |
| Wheels | 2 or 4 |
| Robot Car Chassis (2WD/4WD) | 1 |
| Caster/support wheel (for 2WD) | 1 |
| Li-ion Battery pack (7.4V) or 9V battery | 1 |
| Battery holder + ON/OFF switch | 1 |
| Jumper wires | As needed |
| Buck converter / voltage regulator (optional, for powering ESP32 separately) | 1 |

## 🔌 Circuit / Wiring

| L298N Pin | ESP32 Pin | Purpose |
|---|---|---|
| IN1 | GPIO 14 | Motor A direction |
| IN2 | GPIO 27 | Motor A direction |
| IN3 | GPIO 26 | Motor B direction |
| IN4 | GPIO 25 | Motor B direction |
| ENA | GPIO 32 | Motor A speed (PWM) |
| ENB | GPIO 33 | Motor B speed (PWM) |
| GND | GND | Common ground (required) |

- **OUT1, OUT2** → Motor A (both wires)
- **OUT3, OUT4** → Motor B (both wires)
- **Battery (+)** → L298N `+12V` pin
- **Battery (−)** → L298N `GND` pin

> ⚠️ It is recommended to power the ESP32 from a separate 5V source (not directly from the motor battery) to avoid voltage drops/resets while the motors are running. Keep the grounds of both power sources common.

Add your own circuit diagram/photo here: `images/circuit_diagram.jpg`

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (2.x recommended)
- ESP32 board package installed via Arduino Boards Manager (search "esp32" by Espressif Systems)

## 🚀 How to Use

1. Open `ESP32_RC_Car.ino` in Arduino IDE.
2. Select **Board: ESP32 Dev Module** and the correct COM port under `Tools`.
3. Click **Upload**.
4. Once uploaded, on your phone connect to WiFi network:
   - **SSID:** `ESP32_RC_Car`
   - **Password:** `12345678`
5. Open any browser and go to: `192.168.4.1`
6. Control the car using the on-screen direction buttons and the speed slider.

## 📂 Project Structure

```
ESP32_RC_Car/
├── ESP32_RC_Car.ino     # Main Arduino sketch
├── README.md            # Project documentation
└── images/              # Circuit diagrams / project photos
```

## 🙋 Author www.linkedin.com/in/vishal-singh-9a3074376 
 

Built as a personal embedded systems project — ECE student project exploring ESP32, WiFi-based control systems, and motor driver interfacing.

## 📄 License

This project is open-source and free to use for learning purposes.
