# Real-Time Soil Moisture Monitoring System

# Overview

This project monitors soil moisture using ESP32 and sends data to Firebase in real time. The data is visualized using a Node-RED dashboard.

# Technologies Used

* ESP32 (Wokwi simulation)
* Firebase Realtime Database
* Node-RED Dashboard

# Working Principle

1. Soil moisture sensor (simulated using a potentiometer) reads the moisture level
2. ESP32 converts analog value into a percentage
3. Data is sent to the Firebase database
4. Node-RED fetches and displays data in real-time

# Output

* Moisture percentage displayed using a gauge
* Real-time graph visualization

# Screenshots
<img width="416" height="612" alt="image" src="https://github.com/user-attachments/assets/7904a968-12d9-454d-89c2-f58820679667" />

<img width="1476" height="222" alt="image" src="https://github.com/user-attachments/assets/0205efca-b693-42c5-8d23-87c5c1eb3f2d" />

<img width="1919" height="774" alt="image" src="https://github.com/user-attachments/assets/727b71cc-cf53-45c1-8618-1d1d4e0d8d05" />

# Future Scope

* Automatic irrigation system
* Mobile app integration
