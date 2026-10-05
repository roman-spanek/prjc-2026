#include <stdio.h>

/*
 * Reads measurements from the input file, prints each one to the console
 * and writes it to the binary file.
 * Returns the number of processed measurements.
 */
int process_file(FILE *input, FILE *output)
{
    long timestamp;
    float value;
    char point_id;
    int error;
    int count = 0;

    /* fscanf returns the number of successfully read values; we want all 4 */
    while (fscanf(input, "%ld;%f;%c;%d",
                  &timestamp, &value, &point_id, &error) == 4) {

        /* 3.1 print to the console */
        printf("timestamp=%ld value=%.2f point_id=%c error=%d\n",
               timestamp, value, point_id, error);

        /* 3.2 write to the binary file (value by value) */
        fwrite(&timestamp, sizeof(timestamp), 1, output);
        fwrite(&value,     sizeof(value),     1, output);
        fwrite(&point_id,  sizeof(point_id),  1, output);
        fwrite(&error,     sizeof(error),     1, output);

        count++;
    }

    return count;
}

/*
 * Test helper: reads one record from the binary file and compares it
 * with the expected values. Returns 1 = match, 0 = mismatch.
 */
int check_record(FILE *f, long expected_timestamp, float expected_value,
                 char expected_id, int expected_error)
{
    long timestamp;
    float value;
    char point_id;
    int error;

    fread(&timestamp, sizeof(timestamp), 1, f);
    fread(&value,     sizeof(value),     1, f);
    fread(&point_id,  sizeof(point_id),  1, f);
    fread(&error,     sizeof(error),     1, f);

    if (timestamp == expected_timestamp && value == expected_value &&
        point_id == expected_id && error == expected_error) {
        return 1;
    }
    return 0;
}

/*
 * 4. Test: creates a test TXT file, processes it, reads the binary file
 * back and compares it with the expected values.
 * Returns 1 = test passed, 0 = test failed.
 */
int test(void) {
    /* 1) create a test input with 3 measurements */
    FILE *f = fopen("test.txt", "w");
    if (f == NULL) {
        return 0;
    }
    fprintf(f, "1000;1.5;A;0\n");
    fprintf(f, "2000;2.5;B;1\n");
    fprintf(f, "3000;3.5;C;2\n");
    fclose(f);

    /* 2) processing */
    FILE *input = fopen("test.txt", "r");
    FILE *output = fopen("test.bin", "wb");
    if (input == NULL || output == NULL) {
        return 0;
    }
    int count = process_file(input, output);
    fclose(input);
    fclose(output);

    if (count != 3) {
        printf("TEST FAILED: expected 3 measurements, read %d\n", count);
        return 0;
    }

    /* 3) check the binary file record by record */
    f = fopen("test.bin", "rb");
    if (f == NULL) {
        return 0;
    }

    int ok = 1;
    if (!check_record(f, 1000, 1.5f, 'A', 0)) ok = 0;
    if (!check_record(f, 2000, 2.5f, 'B', 1)) ok = 0;
    if (!check_record(f, 3000, 3.5f, 'C', 2)) ok = 0;
    fclose(f);

    if (ok) {
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED: binary file content does not match\n");
    }
    return ok;
}

int main(void) {
    /* first verify that the program works */
    test();

    /* the actual processing */
    printf("\n--- processing measurements.txt ---\n");
    FILE *input = fopen("measurements.txt", "r");
    if (input == NULL) {
        printf("Cannot open measurements.txt\n");
        return 1;
    }
    FILE *output = fopen("measurements.bin", "wb");
    if (output == NULL) {
        printf("Cannot create measurements.bin\n");
        fclose(input);
        return 1;
    }

    int count = process_file(input, output);
    printf("Measurements processed: %d\n", count);

    fclose(input);
    fclose(output);
    return 0;
}