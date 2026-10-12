# 🚗 Wireless RC Car using [Arduino Uno / ESP32]

A wireless remote-controlled car built from scratch using a [Arduino Uno / ESP32] microcontroller, an L298N dual H-bridge motor driver, and [Bluetooth (HC-05) / Wi-Fi / NRF24L01] for control. The car can move forward, backward, left and right in real time using [a smartphone app / a custom transmitter].

## 🎯 Objective
To design and build a low-cost, reliable RC car and understand motor control, wireless communication and embedded firmware development end to end.

## ✨ Features
- Real-time wireless control of direction (forward, backward, left, right, stop)
- Differential drive steering using two DC motors
- Motor direction and speed control via L298N driver and PWM
- Modular code structure that is easy to extend (obstacle avoidance, speed control)
- Powered by a [7.4V Li-ion / 9V] battery pack

## 🧰 Components Used
| Component | Purpose |
|---|---|
| [Arduino Uno / ESP32] | Main controller |
| L298N Motor Driver | Drives the DC motors |
| 2x / 4x DC Gear Motors | Wheel drive |
| [HC-05 / NRF24L01 / built-in Wi-Fi] | Wireless communication |
| [Battery pack] | Power supply |
| Chassis, wheels, jumper wires | Mechanical build |

## 🔌 Circuit Overview
The controller sends direction signals to the L298N input pins (IN1-IN4) and PWM signals to the enable pins (ENA/ENB) to control motor speed. The wireless module receives commands and passes them to the controller over [UART / SPI / Wi-Fi].

See `circuit/circuit-diagram.png` for the full wiring.

## ⚙️ How It Works
1. The user sends a command from [the phone app / transmitter].
2. The wireless module receives it and forwards it to the microcontroller.
3. The firmware decodes the command and sets the L298N input pins accordingly.
4. The motors rotate in the required direction to move or turn the car.

## 💻 Code
Firmware is written in Embedded C/C++ using the Arduino IDE.
Main file: `code/rc_car.ino`

### How to run
1. Open `rc_car.ino` in the Arduino IDE.
2. Select the correct board and COM port.
3. Upload the code.
4. Connect the [phone app / transmitter] and drive the car.

## 🎥 Demo
Watch the demo: [paste YouTube link here]

## 📚 What I Learned
- Interfacing a motor driver (H-bridge) with a microcontroller
- PWM-based speed control
- Wireless communication using [Bluetooth / Wi-Fi / RF]
- Debugging hardware and power-supply issues in a real build

## 🚀 Future Improvements
- Add ultrasonic sensor for obstacle avoidance
- Add speed control from the app
- Add a camera module for live video

## 🙏 Credits
[If you used any tutorial or library, add its link here.]

## 👤 Author
**Vishal Singh** | ECE Undergrad | Embedded Systems & IoT
LinkedIn: [paste your LinkedIn URL]
