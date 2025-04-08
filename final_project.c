#include <stdio.h>
#include <string.h>

void main()
{
    char excel_file[60];
    printf("ENTER THE NAME OF THE EXCEL FILE YOU WANT (WITHOUT EXTENSION): ");
    scanf("%s", excel_file);

    // Create the full file name by appending ".csv" to the input
    strcat(excel_file, ".csv");

    int n;
    printf("ENTER THE NUMBER OF STUDENTS: ");
    scanf("%d", &n);

    char names[n][100];
    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE NAME OF STUDENT %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // File pointer
    FILE *file;

    // Open the file with the user-defined name in write mode
    file = fopen(excel_file, "w");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Writing the header
    fprintf(file, "Student Name,Maths,Electrical Science,PHYSICS,MECHANIC,CHEMISTRY,English\n");

    float maths[n], e_s[n], phy[n], mech[n], chem[n], eng[n];

    for (int k = 0; k < n; k++)
    {

        printf("ENTER MARKS IN MATHS of STUDENT  %d : ", k + 1);
        scanf("%f", &maths[k]);

        printf("ENTER MARKS IN ELECTRICAL SCIENCE of STUDENT %d : ", k + 1);
        scanf("%f", &e_s[k]);

        printf("ENTER MARKS IN PHYSICS of STUDENT %d : ", k + 1);
        scanf("%f", &phy[k]);

        printf("ENTER MARKS IN MECHANICS of STUDENT %d : ", k + 1);
        scanf("%f", &mech[k]);

        printf("ENTER MARKS IN CHEMISTRY of STUDENT %d : ", k + 1);
        scanf("%f", &chem[k]);

        printf("ENTER MARKS IN ENGLISH of STUDENT %d : ", k + 1);
        scanf("%f", &eng[k]);

        // Corrected: using %f for floating-point values
        fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n", names[k], maths[k], e_s[k], phy[k], mech[k], chem[k], eng[k]);
    }

    // Close the file
    fclose(file);

    printf("Data successfully written to %s.csv\n", excel_file);
}
