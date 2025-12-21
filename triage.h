#ifndef TRIAGE_H
#define TRIAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATIENTS 100
#define MAX_NAME 50


typedef struct {
    int id;
    char name[MAX_NAME];
    int severity;      
    time_t arrivalTime;
} Patient;


extern Patient waitingRoom[MAX_PATIENTS];
extern int patientCount;
extern int totalPatientsTreated;


void addPatient(char* name, int severity);
Patient treatNextPatient();
void checkWaitingTimes();
void logTreatedPatient(Patient p);
void loadBacklog();
void displayQueue();

#endif