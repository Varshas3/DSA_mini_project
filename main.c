#include "triage.h"

int main() {
    int choice;
    char name[MAX_NAME];
    int severity;
    Patient p;

    printf("==========================================\n");
    printf("   EMERGENCY ROOM TRIAGE SYSTEM (V1.0)    \n");
    printf("==========================================\n");

    while (1) {
        printf("\n1. Register New Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. View Waiting Room\n");
        printf("4. Check Waiting Times (System Update)\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                scanf("%s", name);
                printf("Enter Severity (1-Critical, 2-Urgent, 3-Stable): ");
                scanf("%d", &severity);
                if (severity < 1 || severity > 3) {
                    printf("Invalid Severity. Try again.\n");
                } else {
                    addPatient(name, severity);
                }
                break;

            case 2:
                p = treatNextPatient();
                if (p.id != 0) {
                    printf("\n>>> DOCTOR IS NOW TREATING: %s (Severity %d)\n", p.name, p.severity);
                    logTreatedPatient(p);
                } else {
                    printf("\n[!] No patients waiting.\n");
                }
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                checkWaitingTimes(); 
                break;

            case 5:
                printf("Exiting System...\n");
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}