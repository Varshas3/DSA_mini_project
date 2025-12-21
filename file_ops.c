#include "triage.h"

void logTreatedPatient(Patient p) {
    FILE *file = fopen("hospital_log.txt", "a"); 
    if (file == NULL) {
        printf("Error opening log file.\n");
        return;
    }

    
    time_t now = time(NULL);
    char *timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0';

    fprintf(file, "ID: %d | Name: %-15s | Severity: %d | Discharged: %s\n", 
            p.id, p.name, p.severity, timeStr);
    
    fclose(file);
    printf(">> Patient record saved to hospital_log.txt\n");
}

void displayQueue() {
    if (patientCount == 0) {
        printf("\n[ Waiting Room is Empty ]\n");
        return;
    }

    printf("\n=== Current Waiting Room (Priority Order) ===\n");
    printf("%-5s %-15s %-10s %-10s\n", "ID", "Name", "Severity", "Waited(s)");
    printf("------------------------------------------------\n");
    
    time_t now = time(NULL);

    
    for (int i = 0; i < patientCount; i++) {
        double waited = difftime(now, waitingRoom[i].arrivalTime);
        printf("%-5d %-15s %-10d %-10.0f\n", 
            waitingRoom[i].id, 
            waitingRoom[i].name, 
            waitingRoom[i].severity, 
            waited);
    }
    printf("------------------------------------------------\n");
}