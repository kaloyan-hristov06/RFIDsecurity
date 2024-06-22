# RFID-Security System
## Members:
	-Nikola Stoyanov
	-Kaloyan Hristov
	-Petar Tiholov
	-Kliment Iliev
# REQUIRED DEVICES
- **Arduino Uno**
- **MFRC522 RFID Reader**
- **LEDs (Green and Red)**
- **Resistors (for LEDs)**
- **16x2 I2C LCD Display (optional)**
- **Breadboard and Jumper Wires**

## WIRING
### RFID Reader (MFRC522):

- **SDA** (SS_PIN): Connect to digital pin 10 on Arduino
- **SCK**: Connect to digital pin 13
- **MOSI**: Connect to digital pin 11
- **MISO**: Connect to digital pin 12
- **IRQ**: Not connected
- **GND**: Connect to GND
- **RST**: Connect to digital pin 9
- **3.3V**: Connect to 3.3V on Arduino

### LEDs:

- **Green LED**:
  - Anode: Connect to digital pin 2
  - Cathode: Connect to GND (through a resistor)

- **Red LED**:
  - Anode: Connect to digital pin 3
  - Cathode: Connect to GND (through a resistor)

### I2C LCD:

- **SDA**: Connect to A4
- **SCL**: Connect to A5
- **VCC**: Connect to 5V
- **GND**: Connect to GND



## HOW TO USE CODE
-Download .zip file
-Extract the .ino file
-Open the .ino file with Arduino IDE
-Ensure MFRC522 and LiquidCrystal_I2C libraries are downloaded
-Connect Arduino UNO to Laptop/Computer
-Ensure every component is wired correctly
-Verify code
-Upload code
