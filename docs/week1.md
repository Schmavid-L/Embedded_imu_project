# Week 1

## Goal
Learn Arduino basics and understand serial communication.

## What I did
- Set up GitHub repository
- Created README file
- Began learning Arduino fundamentals

## What I learned
- Arduino programs use setup() and loop()
- Serial communication allows data to be sent to a computer
- millis() can be used for timing instead of delay()

## Questions / Confusion
- (write anything that confused you here)

## Next Step
- Get Arduino to print timed output
- Begin wiring MPU-6050

## Code basics 
## basic Serial output
  -void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Arduino is running");
  delay(1000);
}
## Timing with millis() (IMPORTANT)
unsigned long lastTime = 0;
const unsigned long interval = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;
    Serial.println("1 second passed");
  }
}
## Fixed Sampling Loop (VERY IMPORTANT)
unsigned long lastSample = 0;
const unsigned long samplePeriod = 10; // 10 ms = 100 Hz

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  if (now - lastSample >= samplePeriod) {
    lastSample = now;

    Serial.println("Taking sample...");
  }
}
## Struct practice 
struct IMUSample {
  unsigned long time_ms;
  float ax;
  float ay;
  float az;
};
## fake sensor data practice 
#struct IMUSample {
  unsigned long time_ms;
  float ax;
  float ay;
  float az;
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  IMUSample sample;

  sample.time_ms = millis();
  sample.ax = 0.1;
  sample.ay = 0.0;
  sample.az = 9.8;

  Serial.print(sample.time_ms);
  Serial.print(",");
  Serial.print(sample.ax);
  Serial.print(",");
  Serial.print(sample.ay);
  Serial.print(",");
  Serial.println(sample.az);

  delay(100);
}
## What I accomplished today
- Implemented non-blocking timing using millis()
- Created IMUSample struct to organize data
- Generated fake IMU data and printed in CSV format
- Verified consistent sampling behavior

## Observations
- Serial output works reliably
- Timing logic is consistent
- Data formatting is correct for future logging

## Next step
- Introduce changing data (simulate real sensor behavior)
- Prepare for real MPU-6050 integration




## Session: Dynamic Data Simulation

### What I implemented
- Created structured IMU data using `IMUSample`
- Implemented non-blocking timing using `millis()`
- Built oscillating signal for `ay` using directional state logic
- Added linear trend for `ax`
- Introduced pseudo-random noise for `az`
- Began implementing a ring buffer structure

### Key concepts learned
- Difference between static vs dynamic data
- How to simulate sensor behavior using patterns (oscillation, trend, noise)
- Importance of separating signal vs noise
- Managing state (direction, counters) across loop iterations

### Observations
- Oscillating data creates predictable motion patterns
- Noise must be small and uncorrelated to simulate real sensors
- Timing using `millis()` is reliable and non-blocking
- Serial output format (CSV) is useful for future logging

### Next focus
- Improve realism of simulated data
- Finalize ring buffer logic
- Prepare for real IMU integration





# MPU-6050 IMU Bring-Up

## Objective
Integrate the MPU-6050 with the Elegoo Uno R3 and establish I2C communication to retrieve raw accelerometer and gyroscope data.

---

## Hardware Setup

### Components
- Elegoo Uno R3
- MPU-6050 IMU module
- Jumper wires

### Wiring
- VCC → 5V
- GND → GND
- SDA → A4
- SCL → A5

---

## Communication Protocol

The MPU-6050 communicates using the I2C protocol.

### Key Concepts
- Arduino acts as **I2C master**
- MPU-6050 acts as **I2C slave**
- Communication occurs over:
  - SDA (data line)
  - SCL (clock line)

### Device Address
- Primary address used: `0x68`
- Alternative address: `0x69` (depends on AD0 pin)

---

## Sensor Initialization

The MPU-6050 starts in a **sleep state** by default.

To enable data output:
- The Arduino writes to the **Power Management Register (0x6B)**
- Writing `0` wakes the sensor

### Conceptual Flow
1. Begin I2C communication
2. Send device address
3. Write to register `0x6B`
4. Send wake command (`0`)

---

## Data Acquisition

### Register Layout

Sensor data is stored in sequential registers starting at:

```text
0x3B → accelerometer data block
