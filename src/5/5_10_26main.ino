unsigned long lastTime = 0;
const unsigned long interval = 1000;

unsigned long lastSample = 0;
const unsigned long samplePeriod = 1000;

struct IMUSample { unsigned long time_ms; float ax; float ay; float az; };


void setup() {
Serial.begin(9600);
Serial.println("arduino is running");



}

void loop() {
unsigned long currentTime = millis();
if(currentTime - lastTime >= interval) {
  lastTime = currentTime;
  Serial.println("1 second passed");
}
unsigned long now = millis();
if(now - lastSample >= samplePeriod){
  lastSample = now;
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

}
}

//- Created IMUSample struct to organize data
// Generated fake IMU data and printed in CSV format
//Verified consistent sampling behavior
//





