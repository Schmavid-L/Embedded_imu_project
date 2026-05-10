

# Embedded IMU project
## Overview 
This project focuses on designing a real time data acquisition system using an IMU (MPU-6050) The system will handle noisy sensor data, apply filtering techniques, and log structured data for analysis.
## Goal
Build a real-time system using an MPU-6050 to read, process, and log inertial motion data under noisy conditions.

## Hardware
- Elegoo Uno R3
- MPU-6050
- microSD module

## Current Progress
- Repository initialized with project structure
- Beginning Arduino fundamentals (Serial communication, timing)

## System Architecture (Planned)
- Sensor (MPU-6050) → I2C → Microcontroller (Elegoo Uno R3)
- Data processing (filtering, buffering)
- Data logging → SPI → microSD card
