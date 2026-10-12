# 🚗 Wireless RC Car using ESP32

A wireless remote-controlled car built from scratch using a  ESP32 microcontroller, an L298N dual H-bridge motor driver, and  Wi-Fi  for control. The car can move forward, backward, left and right in real time using  smartphone browser

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
|  ESP32| Main controller |
| L298N Motor Driver | Drives the DC motors |
| 2x / 4x DC Gear Motors | Wheel drive |
|  built-in Wi-Fi | Wireless communication |
|Battery7.4v | Power supply |
| Chassis, wheels, jumper wires | Mechanical build |

## 🔌 Circuit Overview
The controller sends direction signals to the L298N input pins (IN1-IN4) and PWM signals to the enable pins (ENA/ENB) to control motor speed. The wireless module receives commands and passes them to the controller over  Wi-Fi].

See `circuit/circuit-diagram.png` for the full wiring.

## ⚙️ How It Works
1. The user sends a command from the phone browser.
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
4. Connect the phone browser and drive the car.

## 📚 What I Learned
- Interfacing a motor driver (H-bridge) with a microcontroller
- PWM-based speed control
- Wireless communication using  Wi-Fi
- Debugging hardware and power-supply issues in a real build

## 🚀 Future Improvements
- Add ultrasonic sensor for obstacle avoidance
- Add speed control from the app
- Add a camera module for live video


## 👤 Author
**Vishal Singh** | ECE Undergrad | Embedded Systems & IoT
LinkedIn: www.linkedin.com/in/vishal-singh-9a3074376
