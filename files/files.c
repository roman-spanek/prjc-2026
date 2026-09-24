#include <stdio.h>
#include <stdlib.h>

// ======================
// Function Prototypes
// ======================
void readTextAndWriteBinary();
void readBinaryAndPrint();
void testCompareTxtAndBin();


int main() {
    printf("Program started \n");
    readTextAndWriteBinary();
    readBinaryAndPrint();

    printf("Program finished \n");
    return 0;
}

// ======================
// Read from text file and write to binary file
// ======================
void readTextAndWriteBinary() {
    FILE* file_txt = fopen("../files/students.txt", "r");
    if (!file_txt) {
        printf("Error opening text file \n");
        exit(1);
    }

    FILE* file_bin = fopen("../files/students.bin", "wb");
    if (!file_bin) {
        printf("Error opening binary file \n");
        fclose(file_txt);
        exit(1);
    }

    int id;
    char symbol;
    float grade;

    while (fscanf(file_txt, "%d %49s %f", &id, &symbol, &grade) == 3) {
        //reads until a triple is read == to the end of txt file
        fwrite(&id, sizeof(int), 1, file_bin);
        fwrite(&symbol, sizeof(char), 1, file_bin);
        fwrite(&grade, sizeof(float), 1, file_bin);
        printf("Wrote one student to binary file \n");
    }
    fclose(file_txt);
    fclose(file_bin);
}

// ======================
// Read from binary file and print content
// ======================
void readBinaryAndPrint() {
    FILE* file_bin = fopen("../files/students.bin", "rb");
    if (!file_bin) {
        printf("Error opening binary file \n");
        exit(1);
    }

    int id;
    char symbol;
    float grade;

    printf("Students loaded from binary file:\n");
    while (fread(&id, sizeof(int), 1, file_bin) == 1) {
        //reads until an int read == to the end of file
        fread(&symbol, sizeof(char), 1, file_bin);
        fread(&grade, sizeof(float), 1, file_bin);
        printf("ID: %d, Name: %c, Grade: %.2f\n", id, symbol, grade);
    }

    fclose(file_bin);
}

