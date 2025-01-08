# Ultrasonic Counter with 7-Segment Display and LED Feedback

---

## **Overview**
This project implements an ultrasonic sensor-based counter system that uses a 7-segment display to show the count of detected objects within a specified range. An LED blinks for each count as visual feedback. The system utilizes an ultrasonic sensor to measure distances and increments the counter when an object is detected within a 2-meter range.

---

## **Features**
1. **Object Detection**:
   - Uses an ultrasonic sensor (HC-SR04 or equivalent) to measure the distance to objects.
   - Detects objects within a range of 2 meters.

2. **Count Display**:
   - Displays the count of detected objects on a 7-segment display.

3. **LED Feedback**:
   - LED blinks the number of times equal to the current count as visual feedback.

4. **Real-Time Updates**:
   - Continuously updates the count and display in real time.

---

## **Components Required**
1. **Microcontroller**:
   - Arduino board (e.g., Uno, Mega, etc.).
2. **Ultrasonic Sensor**:
   - HC-SR04 (or similar).
3. **7-Segment Display**:
   - Common Cathode 7-segment display.
4. **LED**:
   - Standard LED for feedback.
5. **Resistors**:
   - Current-limiting resistors for the 7-segment display and LED.
6. **Connecting Wires**:
   - Jumper wires for connections.
7. **Breadboard**:
   - For prototyping.

---

## **Circuit Diagram**
### **Connections**:

#### **Ultrasonic Sensor**:
- **Trig Pin** → Digital Pin `12`
- **Echo Pin** → Digital Pin `11`
- **VCC** → 5V
- **GND** → GND

#### **7-Segment Display**:
- **Segment Pins** → Digital Pins `2, 3, 4, 5, 6, 7, 8, 9` (as defined in `segpins` array).
- **Common Cathode Pin** → GND (through resistor if needed).

#### **LED**:
- **Anode** → Digital Pin `13` (through resistor).
- **Cathode** → GND.

---

## **Setup**
1. **Install Libraries**:
   - Install the `SevSeg` library in the Arduino IDE:
     - Navigate to **Sketch > Include Library > Manage Libraries...**.
     - Search for "SevSeg" and install it.

2. **Code Upload**:
   - Connect the Arduino board to your computer.
   - Upload the provided code to the board using the Arduino IDE.

3. **Power Up**:
   - Power the Arduino board and ensure all connections are secure.

---

## **How It Works**
1. **Ultrasonic Sensor**:
   - The sensor emits an ultrasonic pulse and calculates the time taken for the echo to return.
   - Distance is calculated using the formula:
     \[
     \text{Distance} = \frac{\text{Time} \times \text{Speed of Sound}}{2}
     \]
   - If the distance is less than or equal to 2 meters, the system considers an object detected.

2. **Counting Logic**:
   - The counter increments when an object is detected and the detection status changes (from no object to object detected).

3. **LED Feedback**:
   - The LED blinks for the number of times equal to the current count.

4. **7-Segment Display**:
   - Displays the current count.
   - Resets the counter to 0 after reaching 9.

---

## **Code Highlights**
1. **Ultrasonic Measurement**:
   - `pulseIn()` function measures the duration of the ultrasonic pulse.
   - Distance is computed based on the speed of sound.

2. **Display Handling**:
   - `SevSeg` library is used to drive the 7-segment display with ease.
   - The `setNumber()` and `refreshDisplay()` methods handle display updates.

3. **LED Feedback**:
   - `digitalWrite()` toggles the LED state for visual feedback.

4. **State Change Detection**:
   - Compares the current and previous detection states to ensure the counter increments only when the state changes.

---

## **Expected Behavior**
1. When an object comes within 2 meters of the ultrasonic sensor:
   - The counter increments.
   - The LED blinks to match the current count.
   - The count is displayed on the 7-segment display.
2. If no object is detected or the object moves out of range:
   - The system maintains its current state until a new object is detected.

---

## **Troubleshooting**
1. **No Display on 7-Segment**:
   - Check connections to the 7-segment display.
   - Verify that the `SevSeg` library is correctly installed.

2. **Incorrect Distance Measurements**:
   - Ensure proper wiring of the ultrasonic sensor.
   - Verify that the sensor is correctly aligned.

3. **LED Not Blinking**:
   - Check the LED and resistor connections.
   - Verify the pin assignments in the code.

---

## **Improvements**
1. Add support for **multiple digit displays** for higher count values.
2. Integrate a **reset button** to manually reset the counter.
3. Add **buzzer feedback** for auditory alerts.
4. Optimize the `delay()` logic for smoother real-time operation.

---

## **Acknowledgments**
This project utilizes:
- **SevSeg Library** for simplifying 7-segment display control.
- **HC-SR04 Ultrasonic Sensor** for reliable distance measurement.
