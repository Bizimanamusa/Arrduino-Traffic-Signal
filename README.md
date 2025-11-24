# Arrduino-Traffic-Signal
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

