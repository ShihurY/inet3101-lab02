#include <stdio.h>
#include <stdlib.h>

struct part {
    int partNumber;
    char partName[100];
    float partSize;
    char partSizeMetric[50];
    float partCost;
};

void printRecords(const struct part *database, int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records saved.\n");
        return;
    }

    for (int i = 0; i < numRecords; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Part Number: %d\n", database[i].partNumber);
        printf("Part Name: %s\n", database[i].partName);
        printf("Part Size: %.2f\n", database[i].partSize);
        printf("Metric: %s\n", database[i].partSizeMetric);
        printf("Part Cost: %.2f\n", database[i].partCost);
    }
}

void addRecords(struct part **database, int *numRecords) {
    int newCount = *numRecords + 1; // Add 1 to record count

    // Using malloc() to allocate new memory block
    struct part *newDatabase = (struct part *)malloc(newCount * sizeof(struct part));
    if (newDatabase == NULL) {
        printf("Could not add new record.\n");
        return;
    }

    // Copy old records to new memory block
    for (int i = 0; i < *numRecords; i++) {
        newDatabase[i] = (*database)[i];
    }

    // Free up the old memory block
    free(*database);

    // Update the database pointer
    *database = newDatabase;
    *numRecords = newCount;

    // Gather new record's specifications
    struct part *newPart = &((*database)[newCount - 1]);

    printf("Enter the part number: ");
    scanf("%d", &newPart->partNumber);
    getchar(); // Consumes new line from buffer

    printf("Enter the part name: ");
    scanf(" %[^\n]%*c", newPart->partName);

    printf("Enter the part size: ");
    scanf("%f", &newPart->partSize);
    getchar();

    printf("Enter the part size metric: ");
    scanf(" %[^\n]%*c", newPart->partSizeMetric);

    printf("Enter the part cost: ");
    scanf("%f", &newPart->partCost);
    getchar();

    printf("\nRecord added successfully.\n");
}

void deleteRecord(struct part **database, int *numRecords) {
    if (*numRecords == 0) {
        printf("No records to delete.\n");
        return;
    }

    int newCount = *numRecords - 1; // Reduce record count by 1

    // Using malloc() to allocate new memory block with a reduced database
    struct part *newDatabase = NULL;
    if (newCount > 0) {
        newDatabase = (struct part *)malloc(newCount * sizeof(struct part));
        if (newDatabase == NULL) { 
            printf("Could not delete record.\n");
            return;
        }

        // Copy existing records except for the last one
        for (int i = 0; i < newCount; i++) {
            newDatabase[i] = (*database)[i];
        }
    }

    free(*database);

    *database = newDatabase;
    *numRecords = newCount;

    printf("\nLast record was deleted. New total is now: %d\n", newCount);
}

int main(void) {
    struct part *database = NULL; // Pointer to dynamic array of Part struct
    int numRecords = 0;
    int selection = 0;
    int running = 1; //Program runs until user exits

    while (running) { 
        printf("\nMENU\n=======\n");
        printf("1. Print all records\n");
        printf("2. Print number of records\n");
        printf("3. Print size of database\n");
        printf("4. Add record\n");
        printf("5. Delete last record\n");
        printf("6. Exit\n\n");

        printf("Please enter your selection: ");
        scanf("%d", &selection);
        getchar();

        switch (selection) {
            case 1:
                printRecords(database, numRecords);
                break;
            case 2:
                printf("\nNumber of records: %d\n", numRecords);
                break;
            case 3:
                printf("\nSize of database: %lu\n",
                       (unsigned long)(numRecords * sizeof(struct part)));
                break;
            case 4:
                addRecords(&database, &numRecords);
                break;
            case 5:
                deleteRecord(&database, &numRecords);
                break;
            case 6:
                running = 0;
                printf("\n\nExiting Now...\n\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    // Frees up any unallocated memory in memory block
    free(database);
    database = NULL;

    return 0;
}