# Embedded IMU Telemetry and Orientation Estimation System

## Overview

This project focuses on designing a real-time embedded inertial sensing and telemetry system using an MPU-6050 IMU and an Elegoo Uno R3.

The system performs:

* raw IMU acquisition over I2C
* gyro bias calibration
* moving average filtering
* accelerometer-based pitch estimation
* gyro angle integration
* complementary-filter sensor fusion
* structured telemetry streaming and CSV logging

The long-term goal is to develop a compact embedded telemetry module capable of:

* onboard filtering and state estimation
* wireless telemetry transmission
* API-compatible data logging
* deployment onto a mobile platform such as an RC car

---

## Current System Pipeline

Physical motion
→ MPU-6050 sensor acquisition
→ gyro offset correction
→ moving average filtering
→ accelerometer pitch estimation
→ gyro angle integration
→ complementary filter fusion
→ serial telemetry output
→ external CSV logging

---

## Hardware

* Elegoo Uno R3
* MPU-6050 IMU
* Moving average filtering architecture
* Structured telemetry output pipeline
* CSV logging through serial gateway

---

## Current Progress

### Completed

* Non-blocking real-time sampling loop using `millis()`
* Structured IMU sample architecture
* Real MPU-6050 integration over I2C
* Register-level sensor acquisition
* Gyroscope bias calibration
* Moving average filtering for gyro and accelerometer data
* Accelerometer-based pitch estimation using `atan2()`
* Gyroscope angle integration
* Complementary filter implementation
* Disturbance and vibration validation testing
* Serial telemetry gateway with CSV logging

### Current Focus

* Telemetry architecture refinement
* Experimental validation and dataset collection
* Orientation stability analysis
* Preparation for wireless telemetry migration

---

## Key Engineering Concepts Explored

* Sensor noise and drift
* Real-time embedded timing
* Ring buffer filtering architectures
* State estimation
* Complementary filtering
* Sensor fusion tradeoffs
* Disturbance rejection
* Telemetry pipeline design

---

## Planned Future Work

* ESP32 migration for wireless telemetry
* API-based telemetry interface
* Live telemetry visualization
* RC car integration
* Compact soldered embedded payload
* Advanced orientation tracking and fusion refinement
