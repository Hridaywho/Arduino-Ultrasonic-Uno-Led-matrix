# 🔴 Arduino Ultrasonic Distance Bar on 8×8 Red LED Matrix

Measure distance with an **HC-SR04 ultrasonic sensor** and watch a  
**glowing RED bar** 🌡️ climb **row by row** on a **MAX7219 8×8 LED matrix**.  
Default range: **0 – 30 cm** — the closer the object, the taller (and redder!) the bar.

---

## ✨ Features
- 📏 Real-time distance measurement (default 0–30 cm)  
- 🔴 LED matrix fills **one red row at a time** as objects move closer  
- 🔧 Adjustable upper range right in the Arduino code

---

## 🔩 Hardware
- 🟠 **Arduino Uno R3**  
- 🌊 **HC-SR04** ultrasonic distance sensor  
- 🔴 **MAX7219 8×8 Red LED matrix** module  
- 🧵 Jumper wires  
- 🔌 USB cable for power & programming  

---

## 🛠️ Circuit & Wiring  
⚡ **All grounds must be common!**

### 🌊 HC-SR04  
| Pin   | Arduino |
|-------|---------|
| **VCC**  | 5V  |
| **GND**  | GND |
| **Trig** | D7  |
| **Echo** | D6  |

### 🔴 MAX7219 Red LED Matrix  
| Pin  | Arduino |
|------|---------|
| **VCC** | 5V  |
| **GND** | GND |
| **DIN** | D11 |
| **CS**  | D10 |
| **CLK** | D13 |

📁 Wiring Diagram is present in the root repo 

## ▶️ Usage

1.  **Clone this repository:**

    ``` bash
    git clone https://github.com/Hridaywho/Arduino-Ultrasonic-Uno-Led-matrix.git
    ```

2.  Open **DistanceMatrix.ino** in the Arduino IDE.

3.  Select **Arduino Uno** board and correct COM port.

4.  🔼 Upload the sketch.

5.  🟥 Move an object toward the sensor and watch the **red LED rows**
    light up one by one.

6.  🛠 Want a different range? Edit `MAX_RANGE_CM` in the code and
    re‑upload.

 ## 🔌 Finding Your Arduino COM Port

If you want to know which COM port your Arduino Uno is connected to:

1. Open **Device Manager** on your PC.  
2. Expand **Ports (COM & LPT)**.  
3. Look for **Arduino Uno (COMx)** — the number `x` is the COM port your board is using.  

Make sure to use this COM port number when uploading your code! 🚀


---

Key constant to tweak the active distance range:
```cpp
const int MAX_RANGE_CM = 30;   // 🔄 Change this to set a different upper limit
---
