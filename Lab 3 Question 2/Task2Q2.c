#include <stdio.h> 
#include <stdbool.h>
#include <string.h> //All Necessary Libraries Included

#define numOfStudents 5 // Maximum number of students(Placeholder)
#define numOfSubjects 3 // Maximum number of subjects(Placeholder)

// Structure to hold student record
typedef struct {
    char f_name[10]; // First Name (Number of characters limited to 10 for convenience, can be changed as needed)
    char l_name[10]; // Last Name (Number of characters limited to 10 for convenience, can be changed as needed)
    int std_ID; 
    float marks[numOfSubjects];
    int Aggregate;
    char grade[20];
} Std_Record;

Std_Record students[numOfStudents]; // Array to hold student records

// Function Definitions
//Made a function to safely scan input, to avoid repeating the invalid scan check
void safeScan(const char *format, void *var, const char *prompt) { //Format safeScan("%d",&var,"Enter Integer: ");
    // Function to safely scan input, re-prompting on invalid input. Code Taken from AI
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf(format, var);

        if (result == 1) {
            // Valid input
            break;
        } else {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n' && getchar() != EOF);
        }
    }
}

void enroll_student(Std_Record student[], int index){ // Function to enroll a new student
    safeScan("%d", &student[index].std_ID, "Enter Student ID: "); // Safely scan Student ID
    printf("Enrolling Student No %d\n", student[index].std_ID); 
    printf("Enter First Name: "); // Scan First Name
    scanf("%9s", &student[index].f_name); // Limit input to avoid buffer overflow
    printf("Enter Last Name: ");
    scanf("%9s", &student[index].l_name);
    printf("Enrollment Complete\n"); //Enrollment Steps Complete
    char choice;
    bool allMarksEntered = true; // Flag to check if all marks are entered
    for(int i=0; i<numOfSubjects; i++){ // Loop to enter marks for each subject
        printf("Do you want to enter mark for Subject %d? (y/n): ", i); // Prompt to enter mark, if not entered, remaining marks set to -1
        scanf(" %c", &choice);
        if(choice == 'y' || choice == 'Y'){
            printf("Enter mark for Subject %d\n", i);
            safeScan("%f", &student[index].marks[i], "Enter mark (0-100): ");
        } else {
            for(int j=i; j<numOfSubjects; j++){ // Set remaining marks to -1 if not entered
                student[index].marks[j] = -1;
            }
            allMarksEntered = false; // Set flag to false if not all marks entered
            break;
        }
    }
    // Calculate Aggregate and Grade
    if(allMarksEntered){ // Only calculate if all marks are entered
        float total = 0;
        for(int i=0; i<numOfSubjects; i++){ // Sum up marks
            total += student[index].marks[i]; // Calculate aggregate
        }
        student[index].Aggregate = total / numOfSubjects;
        if(student[index].Aggregate >= 85)
            strcpy(student[index].grade, "HD");
        else if(student[index].Aggregate >= 75)
            strcpy(student[index].grade, "D");
        else if(student[index].Aggregate >= 65)
            strcpy(student[index].grade, "C");
        else if(student[index].Aggregate >= 50)
            strcpy(student[index].grade, "P");
        else
            strcpy(student[index].grade, "F");
    } else {
        student[index].Aggregate = -1;
        strcpy(student[index].grade, "undefined"); // Grade undefined if not all marks entered
    }
    printf("Student No %d Enrolled Successfully\n", student[index].std_ID); //Final Confirmation Message
}

void searchUpdate(Std_Record student[]){ // Function to search and update student records
    int ID_to_search=0; //Default Value if searching by Last Name
    char choice;
    char lastName[10]="Temporary"; //Default Value if searching by ID
    bool found = false; // Flag to check if student is found
    int Student_Index=0;
    printf("Enter (L,case sensitive) to search by Last Name or (I,case sensitive) to search by Student ID: "); // Prompt for search method
    scanf(" %c", &choice);
    if(choice == 'L'){ // Search by Last Name
        printf("Enter Last Name to search: ");
        scanf("%9s", lastName);
    }
    else if(choice == 'I'){ // Search by Student ID
        safeScan("%d", &ID_to_search, "Enter Student ID to search: ");
    }
     else {
        printf("Invalid Selection\n");
        return;
    }
    for (int i=0;i<numOfStudents && !found;i++){ // Loop to search for student
        if (strcasecmp(student[i].l_name, lastName) == 0 || student[i].std_ID == ID_to_search){ // Case insensitive comparison for last name & exact match for ID
            found = true; 
            Student_Index = i; // Store index of found student
        }
    }
    if(!found){ // If student not found
        printf("unfound\n");
        return;
    }
    if (found){
        printf("Student Found:\nFirst Name: %s\nLast Name: %s\nStudent ID: %d\n", student[Student_Index].f_name, student[Student_Index].l_name, student[Student_Index].std_ID); // Display student details
        printf("Marks:\n");
        for(int j=0; j<numOfSubjects; j++){
            if(student[Student_Index].marks[j] != -1)
                printf("Subject %d: %.2f\n", j, student[Student_Index].marks[j]);
            else
                printf("Subject %d: Not Entered\n", j);
        }
        printf("Aggregate: ");
        if(student[Student_Index].Aggregate != -1)
            printf("%d\n", student[Student_Index].Aggregate);
        else
            printf("Not Calculated\n");
        printf("Grade: %s\n", student[Student_Index].grade);
        printf("Operations:\n1)Update First Name\n2)Update Last Name\n3)Update Student ID\n4)Update Marks\n5)Exit\nMake Your Selection(Enter Operation Number): "); // Prompt for operation
        int operation;
        safeScan("%d", &operation, "Enter Operation Number: ");
        switch(operation){
            case 1: // Update First Name
                printf("Enter New First Name: ");
                scanf("%9s", student[Student_Index].f_name);
                printf("First Name Updated Successfully\n");
                break;
            case 2: // Update Last Name
                printf("Enter New Last Name: ");
                scanf("%9s", student[Student_Index].l_name);
                printf("Last Name Updated Successfully\n");
                break;
            case 3: // Update Student ID
                safeScan("%d", &student[Student_Index].std_ID, "Enter New Student ID: ");
                printf("Student ID Updated Successfully\n");
                break;
            case 4: // Update Marks, recalculate Aggregate and Grade, Since it is not specified, all marks are updated and the user is not given the option to update specific subjects
                for(int j=0; j<numOfSubjects; j++){
                    printf("Enter mark for Subject %d\n", j);
                    safeScan("%f", &student[Student_Index].marks[j], "Enter mark (0-100): ");
                }
                // Recalculate Aggregate and Grade
                float total = 0;
                for(int j=0; j<numOfSubjects; j++){
                    total += student[Student_Index].marks[j];
                }
                student[Student_Index].Aggregate = total / numOfSubjects;
                if(student[Student_Index].Aggregate >= 85)
                    strcpy(student[Student_Index].grade, "HD");
                else if(student[Student_Index].Aggregate >= 75)
                    strcpy(student[Student_Index].grade, "D");
                else if(student[Student_Index].Aggregate >= 65)
                    strcpy(student[Student_Index].grade, "C");
                else if(student[Student_Index].Aggregate >= 50)
                    strcpy(student[Student_Index].grade, "P");
                else
                    strcpy(student[Student_Index].grade, "F");
                printf("Marks Updated Successfully\n");
                break;
            case 5: // Exit
                printf("Exiting Update Menu\n");
                return;
            default:
                printf("Invalid Selection\n");
        }
    }
}

void TopStudents(Std_Record student[]){ // Function to display top students
    //Function Implementation Here
    int topCount=0; // Count of top students
    Std_Record topStudents[numOfStudents]; // Array to hold top students
    for (int i=0;i<numOfStudents;i++){ // Loop to find top students with HD grade
        if (strcmp(student[i].grade,"HD")==0){
            topStudents[topCount]=student[i]; // Add to top students array
            topCount++; // Increment top student count if HD grade
        }
    }
    for (int i=0;i<topCount;i++){ // Loop to display top students
        printf("Top Student %d:\nFirst Name: %s\nLast Name: %s\nStudent ID: %d\nAggregate: %d\nGrade: %s\n", i+1, topStudents[i].f_name, topStudents[i].l_name, topStudents[i].std_ID, topStudents[i].Aggregate, topStudents[i].grade);
        // Display details of top students
    }
}

int main(){
    char c; // Variable to hold user choice
    int id=0; // Student ID counter, if exceeds numOfStudents, enrollment stops
    while (true){
        printf("Main Functions\n1)Enroll(E,case sensitive)\n2)SearchUpdate(S,case sensitive)\n3)TopStudents(T,case sensitive)\n4)Exit(e,case sensitive)\nMake Your Selection: "); // Main Menu
        scanf(" %c",&c);
        switch(c){
            case 'E': // Enroll Student and Function Call
                if (id >= numOfStudents) {
                    printf("Maximum number of students enrolled.\n");
                    break;
                }
                enroll_student(students, id);
                id++;
                break;
            case 'S': // Search and Update Student Records Function Call
                searchUpdate(students);
                break;
            case 'T': // Display Top Students Function Call
                TopStudents(students);
                break;
            case 'e': // Exit Program
                return 0;
            default:
                printf("Invalid Selection\n");
            }
    }
}

