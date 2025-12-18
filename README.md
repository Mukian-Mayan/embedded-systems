# embedded-systems
avr programming and arduino programming


## Hardware Connections

### 1. BUZZER

| Component       | Pin on ATmega328P | Arduino Pin | Connection |
|-----------------|-----------------|------------|---------------|
| Passive Buzzer + | PB0             | D8         | Connect here |
| Passive Buzzer − | GND             | GND        | Ground       |


## AVR ports 

| Arduino Pin | AVR Port | AVR Pin | Function / Notes            |
| ----------- | -------- | ------- | --------------------------- |
| D0          | PD0      | Pin 2   | RX (UART)                   |
| D1          | PD1      | Pin 3   | TX (UART)                   |
| D2          | PD2      | Pin 4   | External Interrupt 0 (INT0) |
| D3          | PD3      | Pin 5   | PWM (OC2B)                  |
| D4          | PD4      | Pin 6   |                             |
| D5          | PD5      | Pin 11  | PWM (OC0B)                  |
| D6          | PD6      | Pin 12  | PWM (OC0A)                  |
| D7          | PD7      | Pin 13  |                             |
| D8          | PB0      | Pin 14  |                             |
| D9          | PB1      | Pin 15  | PWM (OC1A)                  |
| D10         | PB2      | Pin 16  | PWM (OC1B), SS (SPI)        |
| D11         | PB3      | Pin 17  | PWM (OC2A), MOSI (SPI)      |
| D12         | PB4      | Pin 18  | MISO (SPI)                  |
| D13         | PB5      | Pin 19  | SCK (SPI), onboard LED      |
| A0          | PC0      | Pin 23  | Analog input                |
| A1          | PC1      | Pin 24  | Analog input                |
| A2          | PC2      | Pin 25  | Analog input                |
| A3          | PC3      | Pin 26  | Analog input                |
| A4          | PC4      | Pin 27  | Analog input, SDA (I2C)     |
| A5          | PC5      | Pin 28  | Analog input, SCL (I2C)     |


## END
