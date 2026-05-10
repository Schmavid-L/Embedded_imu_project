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
