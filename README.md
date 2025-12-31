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

![Built Circuit](circuit.jpg)

> **Note:** The battery under test is connected through a voltage divider to protect the Arduino’s analog input.

---

## ❗ The Problem with Standard Multimeters

Many people use a standard multimeter to check battery health, but this method is often **misleading**.

A multimeter measures battery voltage under **no-load conditions**. In this state, even a nearly depleted battery can still show a relatively high voltage, giving the false impression that it is healthy.

For a **reliable assessment**, a battery must be measured **while it is supplying current (under load)**. Only then does the voltage drop reveal the true condition of the battery.

---

## ⚙️ How the Circuit Works

The core of this battery tester is a **constant current load circuit**, which ensures that the battery is tested under consistent and repeatable conditions, regardless of its voltage level.

### Constant Current Load

#### Operational Amplifier (LM358)
One amplifier inside the **LM358** op-amp is used to regulate the load current.  
It continuously adjusts the transistor drive to keep the current constant as the battery voltage changes.

#### Voltage Divider (R1 & R2)
Resistors **R1** and **R2** form a voltage divider that sets a reference voltage of approximately **450 mV** at the op-amp’s non-inverting input.

This reference voltage determines the target current flowing through the load.

#### Transistor (BD139)
The op-amp controls the base of an **NPN transistor (BD139)**.  
By increasing or decreasing the base current, the op-amp regulates how much current flows from the battery through the load resistor.

#### Load Resistor (R3)
The load resistor sets the test current according to Ohm’s Law: I = V / R

- With a **3.9 Ω** resistor, the test current is approximately **116 mA**
- Replacing it with a **1.8 Ω** resistor increases the current to roughly **250 mA**

This allows the tester to simulate different load conditions depending on the battery type.

#### Transistor Options
While the prototype uses a **BD139**, other NPN transistors such as:
- **BC337**
- **2N2222**

can also be used, provided they can safely handle the test current.

---

## 🧠 Arduino Integration and Display

### Voltage Measurement
The Arduino measures the battery voltage using **analog pin A0** while the battery is under load, providing a much more realistic reading than a multimeter.

### Increased ADC Resolution
To improve measurement accuracy at low voltages, the Arduino’s **3.3V pin is connected to the AREF pin**.  
This configures the ADC to use **3.3V as the reference voltage** instead of the default 5V, increasing resolution for single-cell batteries.

### LCD Display
A **16×2 LCD** connected via **I2C** displays:
- The measured battery voltage
- A graphical progress bar representing battery health

This makes the tester easy to read and user-friendly.

---

## 🧪 Software and Customization

The firmware can be uploaded using the **Arduino IDE** and is designed to be easily customizable.

### Adjustable Parameters
- **I2C Address**  
  The LCD I2C address can be changed in the code (commonly `0x27` or `0x3F`).

- **Discharge Voltage Threshold**  
  The default voltage threshold for a “discharged” battery is set to **1.1V**, but this value can be modified to suit different battery chemistries.

---

## 🧪 Calibration Notes
- Voltage divider resistor values must match those used in the code
- ADC reference voltage is assumed to be **5.0V**
- Battery percentage is an **approximation**, intended for learning purposes

---

## 🚀 Possible Improvements
- Automatic battery type detection
- OLED display support
- EEPROM-based calibration storage
- Battery health and discharge curve tracking
- Over-voltage protection circuitry

---

## 🎓 Educational Value
This project is ideal for:
- Learning Arduino analog inputs
- Understanding voltage dividers
- Practicing LCD interfacing
- Introductory embedded systems projects

---

## 📄 License
This project is open-source and available under the **MIT License**.

