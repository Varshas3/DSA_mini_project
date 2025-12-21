#include "triage.h"


Patient waitingRoom[MAX_PATIENTS];
int patientCount = 0;
int totalPatientsTreated = 0;


void swap(int i, int j) {
    Patient temp = waitingRoom[i];
    waitingRoom[i] = waitingRoom[j];
    waitingRoom[j] = temp;
}


void heapifyUp(int index) {
    if (index == 0) return;
    
    int parentIndex = (index - 1) / 2;
    
    
    if (waitingRoom[index].severity < waitingRoom[parentIndex].severity) {
        swap(index, parentIndex);
        heapifyUp(parentIndex);
    }
    
    else if (waitingRoom[index].severity == waitingRoom[parentIndex].severity) {
        if (waitingRoom[index].arrivalTime < waitingRoom[parentIndex].arrivalTime) {
            swap(index, parentIndex);
            heapifyUp(parentIndex);
        }
    }
}


void heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < patientCount && 
        waitingRoom[leftChild].severity < waitingRoom[smallest].severity) {
        smallest = leftChild;
    }

    if (rightChild < patientCount && 
        waitingRoom[rightChild].severity < waitingRoom[smallest].severity) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(index, smallest);
        heapifyDown(smallest);
    }
}


void addPatient(char* name, int severity) {
    if (patientCount >= MAX_PATIENTS) {
        printf("!! ER is Full. Cannot accept patient.\n");
        return;
    }

    Patient newP;
    newP.id = totalPatientsTreated + patientCount + 1;
    strcpy(newP.name, name);
    newP.severity = severity;
    newP.arrivalTime = time(NULL); 

    waitingRoom[patientCount] = newP;
    heapifyUp(patientCount); 
    patientCount++;
    
    printf(">> Patient %s added to Triage (Severity %d).\n", name, severity);
}


Patient treatNextPatient() {
    Patient empty = {0, "", 0, 0};
    
    if (patientCount == 0) return empty;

    Patient root = waitingRoom[0];


    waitingRoom[0] = waitingRoom[patientCount - 1];
    patientCount--;

    
    heapifyDown(0);

    return root;
}


void checkWaitingTimes() {
    time_t now = time(NULL);
    int changes = 0;

    for (int i = 0; i < patientCount; i++) {
        double secondsWaited = difftime(now, waitingRoom[i].arrivalTime);
        
        
        if (waitingRoom[i].severity > 1 && secondsWaited > 30.0) {
            printf("!! ALERT: Patient %s has waited too long. Priority Upgraded!\n", waitingRoom[i].name);
            waitingRoom[i].severity--; 
            waitingRoom[i].arrivalTime = now;
            

            heapifyUp(i);
            changes++;
        }
    }
    if (changes == 0) {
        printf(">> No priority adjustments needed at this time.\n");
    }
}