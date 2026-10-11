/*
  Project: ESP32 WiFi Controlled RC Car (with Speed Control)
  Author : [Your Name]
  Motor Driver: L298N
  Control: WiFi (Access Point) + Web Page (mobile browser)

  NOTE: Uses analogWrite() for PWM speed control (not ledcSetup/ledcAttachPin),
  so it compiles correctly on both older and newer ESP32 Arduino core versions.

  ----------------------------------------------------------
  WIRING
  ----------------------------------------------------------
  Driver IN1 -> ESP32 GPIO 14
  Driver IN2 -> ESP32 GPIO 27
  Driver IN3 -> ESP32 GPIO 26
  Driver IN4 -> ESP32 GPIO 25
  Driver ENA -> ESP32 GPIO 32 (PWM - Motor A speed)
  Driver ENB -> ESP32 GPIO 33 (PWM - Motor B speed)
  Driver GND -> ESP32 GND (common ground is required)

  OUT1, OUT2 -> Motor A (both wires)
  OUT3, OUT4 -> Motor B (both wires)
  Battery (+) -> Driver +12V pin
  Battery (-) -> Driver GND pin

  ----------------------------------------------------------
  HOW TO USE
  ----------------------------------------------------------
  1. Upload this code to the ESP32 using Arduino IDE.
  2. On your phone, connect to WiFi network: "ESP32_RC_Car" (password: 12345678)
  3. Open a browser and go to: 192.168.4.1
  4. Use the on-screen buttons to control direction and the slider for speed.
*/

#include <WiFi.h>
#include <WebServer.h>

// ---------- WiFi Access Point settings ----------
const char* ssid = "ESP32_RC_Car";
const char* password = "12345678";

WebServer server(80);

// ---------- Motor direction pins ----------
#define IN1 14
#define IN2 27
#define IN3 26
#define IN4 25

// ---------- Motor speed (PWM) pins ----------
#define ENA 32
#define ENB 33

int carSpeed = 200;   // Default speed (0-255), changeable from phone

// ---------- Motor control functions ----------
void setSpeed(int speedValue) {
  carSpeed = constrain(speedValue, 0, 255);
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ---------- Web page (HTML shown on phone) ----------
String htmlPage() {
  String page = "<!DOCTYPE html><html><head><title>ESP32 RC Car</title>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  page += "<style>";
  page += "body{text-align:center;font-family:Arial;background:#111;color:#fff;}";
  page += "h1{color:#0f0;}";
  page += "button{width:90px;height:90px;font-size:18px;margin:6px;border-radius:12px;border:none;background:#0f0;color:#000;font-weight:bold;}";
  page += "button:active{background:#0a0;}";
  page += ".row{display:flex;justify-content:center;}";
  page += ".speedBox{margin-top:25px;}";
  page += "input[type=range]{width:80%;}";
  page += "</style></head><body>";
  page += "<h1>ESP32 RC Car</h1>";

  page += "<div class='row'><button ontouchstart=\"fetch('/forward')\" ontouchend=\"fetch('/stop')\" onmousedown=\"fetch('/forward')\" onmouseup=\"fetch('/stop')\">Forward</button></div>";
  page += "<div class='row'>";
  page += "<button ontouchstart=\"fetch('/left')\" ontouchend=\"fetch('/stop')\" onmousedown=\"fetch('/left')\" onmouseup=\"fetch('/stop')\">Left</button>";
  page += "<button onclick=\"fetch('/stop')\">Stop</button>";
  page += "<button ontouchstart=\"fetch('/right')\" ontouchend=\"fetch('/stop')\" onmousedown=\"fetch('/right')\" onmouseup=\"fetch('/stop')\">Right</button>";
  page += "</div>";
  page += "<div class='row'><button ontouchstart=\"fetch('/backward')\" ontouchend=\"fetch('/stop')\" onmousedown=\"fetch('/backward')\" onmouseup=\"fetch('/stop')\">Backward</button></div>";

  page += "<div class='speedBox'>";
  page += "<p>Speed: <span id='speedVal'>200</span></p>";
  page += "<input type='range' min='0' max='255' value='200' id='speedSlider' ";
  page += "oninput=\"document.getElementById('speedVal').innerText=this.value; fetch('/speed?value='+this.value)\">";
  page += "</div>";

  page += "</body></html>";
  return page;
}

// ---------- Web server route handlers ----------
void handleRoot()     { server.send(200, "text/html", htmlPage()); }
void handleForward()  { moveForward();  server.send(200, "text/plain", "Forward");  }
void handleBackward() { moveBackward(); server.send(200, "text/plain", "Backward"); }
void handleLeft()     { turnLeft();     server.send(200, "text/plain", "Left");     }
void handleRight()    { turnRight();    server.send(200, "text/plain", "Right");    }
void handleStop()     { stopCar();      server.send(200, "text/plain", "Stop");     }

void handleSpeed() {
  if (server.hasArg("value")) {
    int val = server.arg("value").toInt();
    setSpeed(val);
    server.send(200, "text/plain", "Speed set to " + String(val));
  } else {
    server.send(400, "text/plain", "Missing value");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  setSpeed(carSpeed);   // Set default speed
  stopCar();

  // Start WiFi Access Point
  WiFi.softAP(ssid, password);
  WiFi.setSleep(false);   // Disable power-save mode for a more stable connection
  Serial.println("WiFi AP Started");
  Serial.print("Connect to WiFi: ");
  Serial.println(ssid);
  Serial.print("Open browser at: ");
  Serial.println(WiFi.softAPIP());

  // Web server routes
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);
  server.on("/speed", handleSpeed);

  server.begin();
}

void loop() {
  server.handleClient();
}
