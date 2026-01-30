#include <stdio.h>
#include <string.h>

#define MAX_DOCTORS 3
#define MAX_SLOTS 5
#define FEE 100 // in ₹

typedef struct {
    char name[50];
    char specialty[50];
    char slots[MAX_SLOTS][10];
    int totalSlots;
    int earnings;
} Doctor;

typedef struct {
    char patient[50];
    int doctorIndex;
    char slot[10];
    int booked; // 1 = booked, 0 = cancelled
} Appointment;

Doctor doctors[MAX_DOCTORS];
Appointment appointments[50];
int appointmentCount = 0;

void initializeDoctors() {
    strcpy(doctors[0].name, "Dr. Ayesha Khan");
    strcpy(doctors[0].specialty, "Cardiologist");
    strcpy(doctors[0].slots[0], "10AM");
    strcpy(doctors[0].slots[1], "2PM");
    doctors[0].totalSlots = 2;
    doctors[0].earnings = 0;

    strcpy(doctors[1].name, "Dr. Ravi Singh");
    strcpy(doctors[1].specialty, "Dermatologist");
    strcpy(doctors[1].slots[0], "11AM");
    strcpy(doctors[1].slots[1], "4PM");
    doctors[1].totalSlots = 2;
    doctors[1].earnings = 0;

    strcpy(doctors[2].name, "Dr. Meera Patel");
    strcpy(doctors[2].specialty, "Dentist");
    strcpy(doctors[2].slots[0], "9AM");
    strcpy(doctors[2].slots[1], "1PM");
    doctors[2].totalSlots = 2;
    doctors[2].earnings = 0;
}

void viewDoctors() {
    printf("Doctors and Slots:\n");
    for(int i=0;i<MAX_DOCTORS;i++){
        printf("%d. %s (%s) - Earnings: ₹%d\n", i+1, doctors[i].name, doctors[i].specialty, doctors[i].earnings);
        printf("   Slots: ");
        for(int j=0;j<doctors[i].totalSlots;j++){
            if(strcmp(doctors[i].slots[j],"") != 0)
                printf("%s ", doctors[i].slots[j]);
        }
        printf("\n");
    }
}

void bookAppointment() {
    char patientName[50];
    int docIndex, slotIndex;

    printf("Enter your name: ");
    scanf("%s", patientName);

    viewDoctors();
    printf("Choose doctor number to book: ");
    scanf("%d", &docIndex);
    docIndex--;

    if(docIndex<0 || docIndex>=MAX_DOCTORS) { printf("Invalid doctor\n"); return; }

    printf("Available slots:\n");
    for(int i=0;i<doctors[docIndex].totalSlots;i++){
        if(strcmp(doctors[docIndex].slots[i],"") !=0)
            printf("%d. %s\n", i+1, doctors[docIndex].slots[i]);
    }

    printf("Choose slot number: ");
    scanf("%d", &slotIndex);
    slotIndex--;

    if(slotIndex<0 || slotIndex>=doctors[docIndex].totalSlots || strcmp(doctors[docIndex].slots[slotIndex],"")==0){
        printf("Invalid slot\n"); return;
    }

    // Book appointment
    appointments[appointmentCount].doctorIndex = docIndex;
    strcpy(appointments[appointmentCount].patient, patientName);
    strcpy(appointments[appointmentCount].slot, doctors[docIndex].slots[slotIndex]);
    appointments[appointmentCount].booked = 1;
    appointmentCount++;

    // Remove slot
    strcpy(doctors[docIndex].slots[slotIndex], "");

    // Add earnings
    doctors[docIndex].earnings += FEE;

    printf("Appointment booked! Doctor earns ₹%d\n", FEE);
}

void cancelAppointment() {
    char patientName[50];
    printf("Enter your name to cancel appointment: ");
    scanf("%s", patientName);

    for(int i=0;i<appointmentCount;i++){
        if(appointments[i].booked && strcmp(appointments[i].patient,patientName)==0){
            appointments[i].booked = 0;
            int docIndex = appointments[i].doctorIndex;
            // Return slot
            for(int j=0;j<doctors[docIndex].totalSlots;j++){
                if(strcmp(doctors[docIndex].slots[j],"")==0){
                    strcpy(doctors[docIndex].slots[j], appointments[i].slot);
                    break;
                }
            }
            doctors[docIndex].earnings -= FEE;
            printf("Appointment cancelled. Doctor loses ₹%d\n", FEE);
            return;
        }
    }
    printf("No active appointment found for %s\n", patientName);
}

void mainMenu() {
    int choice;
    while(1){
        printf("\n--- Mini Zocdoc Backend ---\n");
        printf("1. View Doctors\n2. Book Appointment\n3. Cancel Appointment\n4. Exit\nChoose option: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: viewDoctors(); break;
            case 2: bookAppointment(); break;
            case 3: cancelAppointment(); break;
            case 4: return;
            default: printf("Invalid choice\n");
        }
    }
}

int main() {
    initializeDoctors();
    mainMenu();
    return 0;
}
