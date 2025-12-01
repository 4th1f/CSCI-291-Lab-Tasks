#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isValidName(char *name) {
    if (name == NULL || strlen(name) == 0) return 0;

    for (int i = 0; name[i]; i++) {
        if (!isprint(name[i])) return 0;      // non-printable iscorrupted
        if (isdigit(name[i])) return 0;       // name cannot contain numbers
    }
    return 1;
}

int main() {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Error: Could not open students.txt\n");
        return 1;
    }

    char line[500];
    char name[100];
    int mark;

    int vCount = 0, cCount = 0;
    int totalMarks = 0;

    while (fgets(line, sizeof(line), f)) {
        // extract name and mark
        if (sscanf(line, "%99s %d", name, &mark) != 2) {
            // Not enough valid tokens → corrupted
            cCount++;
            continue;
        }

        // Validate name
        if (!isValidName(name)) {
            cCount++;
            continue;
        }

        // VALID RECORD
        printf("Valid: Name = %s, Mark = %d\n", name, mark);
        vCount++;
        totalMarks += mark;
    }

    fclose(f);

    printf("\nTotal valid records: %d\n", vCount);
    printf("Total corrupted records: %d\n", cCount);

    if (vCount > 0)
        printf("Average mark: %.2f\n", (float)totalMarks / vCount);
    else
        printf("Average mark: N/A (no valid records)\n");

    return 0;
}
