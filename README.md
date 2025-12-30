# Arduino Battery Voltage Tester with LCD Display

## 📌 Project Overview
This project is an **Arduino-based battery voltage tester** that measures the voltage of a battery and displays the result in real time on a **16×2 LCD screen**. It demonstrates fundamental embedded systems concepts such as analog voltage measurement, voltage dividers, and LCD interfacing.

The system can be used to test common batteries (AA, AAA, etc.) safely within the Arduino’s input voltage limits.

---

## 🔧 Hardware Components
- Arduino Uno  
- 16×2 LCD Display  
- Breadboard  
- Resistors (voltage divider)  
- Potentiometer (LCD contrast)  
- LED indicator  
- 9V battery (Arduino power supply)  
- AA battery (battery under test)  
- Jumper wires  

---

## 📸 Built Circuit
Below is the physical implementation of the circuit used in this project:

![Built Circuit](images/circuit.png)

> **Note:** The battery under test is connected through a voltage divider to protect the Arduino’s analog input.

---

## ⚡ How It Works
1. The battery voltage is passed through a **voltage divider** to ensure it stays below 5V.
2. The Arduino reads the scaled voltage using `analogRead()`.
3. The raw ADC value is converted into a real voltage.
4. The voltage is mapped to an estimated **percentage charge**.
5. The LCD displays:
   - Battery voltage
   - Charge percentage
   - A visual bar indicator

---

## 📟 LCD Output Example
