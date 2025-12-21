# Hospital Emergency Room Triage System

## Problem Statement
In hospital emergency rooms, patients cannot be treated on a "First Come, First Served" basis. Critical patients (heart attacks, trauma) must be prioritized over stable patients (fevers, sprains). However, stable patients should not be ignored indefinitely.

## Solution
This project implements a Priority Queue using a **Min-Heap** data structure to ensure critical patients are treated first. It includes an **Dynamic Aging Algorithm** to prevent starvation of low-priority patients.

## Features
- **Min-Heap Implementation:** Efficiently retrieves the patient with the highest severity (O(log n)).
- **Real-time Triage:** Supports 3 severity levels (1=Critical, 2=Urgent, 3=Stable).
- **Starvation Prevention (Innovation):** Automatically upgrades a patient's priority if they wait longer than a specific threshold.
- **File Persistence:** Automatically logs treated patients to `hospital_log.txt`.

## Technical Details
- **Language:** C
- **Data Structure:** Array-based Min-Heap
- **Complexity:** Enqueue O(log n), Dequeue O(log n)

## How to Run
1. Compile the code: `gcc main.c heap_logic.c file_ops.c -o hospital`
2. Run the executable: `./hospital`
