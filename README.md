# Arduino-Traffic-Signal
An Arduino-based pedestrian traffic signal system featuring car light control, push-button activation, and a dynamic 5–0 countdown on a 7-segment display. Includes full walk cycle logic, state transitions, and real-time hardware control using LEDs, resistors, and breadboard wiring.

# Pedestrian Traffic Signal System (Arduino Project)

This project is a fully functioning **pedestrian traffic light system** built using an **Arduino Uno**, LEDs, a **push button**, and a **7-segment display**.  
It simulates a real crosswalk: cars get green normally, a pedestrian presses a button to request crossing, and the system handles the entire sequence — including a **5-to-0 countdown**.

---

## 🚦 Features

- Complete **car traffic light cycle** (Green → Yellow → Red)
- **Push-button triggered** pedestrian crossing
- Pedestrian **WALK** LED with a final safety blink phase
- **7-segment display countdown** showing: `5 → 4 → 3 → 2 → 1 → 0`
- Uses a **common-cathode 7-segment display**
- Fully debounced button input and safe timing delays
- Clean, modular Arduino code

---

## 🧰 Hardware Used

- Arduino Uno R3 (Elegoo / Arduino compatible)
- Breadboard + jumper wires
- (3) LEDs for car lights (Red, Yellow, Green)
- (2) LEDs for pedestrian lights (Red, White/Walk)
- (1) Push button
- (1) 7-segment display (5161AS, common cathode)
- Assorted **220Ω resistors**

---

## 🗂 Project Structure


---

## 🔌 Wiring Summary

### **Traffic Light Pins**
| Signal | Arduino Pin |
|--------|-------------|
| Car Green  | 9 |
| Car Yellow | 10 |
| Car Red    | 11 |
| Pedestrian White (Walk) | 12 |
| Pedestrian Red | 13 |
| Push Button | 2 (INPUT_PULLUP → other leg to GND) |

---

### **7-Segment (Common Cathode 5161AS) → Arduino Pin Mapping**

| Segment | Bar Location     | Arduino Pin |
|---------|-------------------|-------------|
| **a**   | top               | 5   |
| **b**   | top-right         | A1  |
| **c**   | bottom-right      | 8   |
| **d**   | bottom            | 3   |
| **e**   | bottom-left       | 4   |
| **f**   | top-left          | 6   |
| **g**   | middle            | 7   |
| **dp**  | decimal point     | A0 (unused) |

**Commons:**  
Digit pins **3** and **8** → GND

Every segment uses its own **220Ω resistor**.

---

## 🧠 How It Works

1. System starts with **cars → GREEN**, **pedestrians → RED**.  
2. When the button is pressed, the system:
   - Switches cars to **yellow**, then **red**
   - Activates the **WALK** signal
3. The 7-segment displays a **5-0 countdown**, one number per second.
4. WALK light blinks as a final warning.
5. Pedestrian light returns to RED.
6. Cars get GREEN again.
7. System resets and waits for next button press.

---

## ▶️ Running the Project

Upload the `.ino` file to your Arduino using the Arduino IDE.

Press the push button to trigger the crossing sequence.

---

## 📸 Images

![Traffic Light Project](images/IMG_1614.jpg)
!Birds Eye View (images/IMG_1617.jpg)
!R3 Angle View (images/IMG_1618.jpg)


---

## 🧩 Future Improvements

- Add buzzer for audible crossing signal
- Add LDR (light sensor) for night-mode dimming
- Replace 1-digit display with TM1637 4-digit (cleaner wiring)
- Add second crosswalk or signal synchronization

---

## 🛠 Skills Demonstrated

- Arduino C++ programming  
- Digital logic & state machine design  
- Breadboard wiring & circuit debugging  
- 7-segment display control  
- Push-button debouncing  
- Embedded system troubleshooting

---

## 📜 License

MIT License  
