#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

// Structures for Patient and Doctor Data
typedef struct {
    char name[50];
    char address[100];
    char disease[50];
    int admissionDate;
    int id;
} Patient;

typedef struct {
    char name[50];
    char address[100];
    char specialization[50];
    int id;
} Doctor;

// Global Variables
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0, doctorCount = 0;

// Function Prototypes
void patient_read();
void patient_display();
void doctor_read();
void doctor_display();
void display();
void Display();

// Main Function
int main() {
    char username[20], password[20];
    char correctUsername[] = "batch7";
    char correctPassword[] = "bca@123";
    int choice;

    printf("Enter the Username: ");
    scanf("%s", username);
    printf("Enter the Password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        printf("\n-------------------------------------------------------------\n");
        printf("\t\t----WELCOME TO HOSPITAL MANAGEMENT SYSTEM----\n");
        printf("-------------------------------------------------------------\n");

        while (1) {
            display();
            printf("\n<<<--- Hospital Management System --->>>\n");
            display();

            printf("\n1. Admit Patient");
            printf("\n2. View Patient Details");
            printf("\n3. Add New Patient");
            printf("\n4. List All Patients");
            printf("\n5. Add Doctor");
            printf("\n6. View Doctor Details");
            printf("\n7. Add New Doctor");
            printf("\n8. List All Doctors");
            printf("\n0. Exit");
            printf("\n\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\n**** Admit Patient ****\n");
                    patient_read();
                    break;
                case 2:
                    printf("\n**** Patient Details ****\n");
                    patient_display();
                    break;
                case 3:
                    printf("\n**** Add New Patient ****\n");
                    patient_read();
                    break;
                case 4:
                    printf("\n**** Patient List ****\n");
                    patient_display();
                    break;
                case 5:
                    printf("\n**** Add Doctor ****\n");
                    doctor_read();
                    break;
                case 6:
                    printf("\n**** Doctor Details ****\n");
                    doctor_display();
                    break;
                case 7:
                    printf("\n**** Add New Doctor ****\n");
                    doctor_read();
                    break;
                case 8:
                    printf("\n**** Doctor List ****\n");
                    doctor_display();
                    break;
                case 0:
                    printf("\nExiting Program...\n");
                    exit(0);
                default:
                    printf("\nInvalid choice, please try again.\n");
            }
        }
    } else {
        printf("\nIncorrect Username or Password. Access Denied.\n");
    }
    return 0;
}

// Display Function for UI
void display() {
    for (int i = 0; i < 40; i++)
        printf("=");
    printf("\n");
}

// Display Alternative UI Function
void Display() {
    for (int i = 0; i < 40; i++)
        printf("*");
    printf("\n");
}

// Function to Read Patient Data
void patient_read() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full!\n");
        return;
    }
    printf("Enter Patient Name: ");
    scanf("%s", patients[patientCount].name);
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    printf("Enter Address: ");
    scanf("%s", patients[patientCount].address);
    printf("Enter Disease: ");
    scanf("%s", patients[patientCount].disease);
    printf("Enter Admission Date (DDMMYYYY): ");
    scanf("%d", &patients[patientCount].admissionDate);
    
    patientCount++;
    printf("Patient Admitted Successfully!\n");
}

// Function to Display Patient Data
void patient_display() {
    if (patientCount == 0) {
        printf("No patients found!\n");
        return;
    }
    for (int i = 0; i < patientCount; i++) {
        printf("\n----------------------------\n");
        printf("Patient #%d\n", i + 1);
        printf("Name: %s\n", patients[i].name);
        printf("ID: %d\n", patients[i].id);
        printf("Address: %s\n", patients[i].address);
        printf("Disease: %s\n", patients[i].disease);
        printf("Admission Date: %d\n", patients[i].admissionDate);
        printf("----------------------------\n");
    }
}

// Function to Read Doctor Data
void doctor_read() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor list is full!\n");
        return;
    }
    printf("Enter Doctor Name: ");
    scanf("%s", doctors[doctorCount].name);
    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);
    printf("Enter Address: ");
    scanf("%s", doctors[doctorCount].address);
    printf("Enter Specialization: ");
    scanf("%s", doctors[doctorCount].specialization);
    
    doctorCount++;
    printf("Doctor Added Successfully!\n");
}

// Function to Display Doctor Data
void doctor_display() {
    if (doctorCount == 0) {
        printf("No doctors found!\n");
        return;
    }
    for (int i = 0; i < doctorCount; i++) {
        printf("\n----------------------------\n");
        printf("Doctor #%d\n", i + 1);
        printf("Name: %s\n", doctors[i].name);
        printf("ID: %d\n", doctors[i].id);
        printf("Address: %s\n", doctors[i].address);
        printf("Specialization: %s\n", doctors[i].specialization);
        printf("----------------------------\n");
    }
}