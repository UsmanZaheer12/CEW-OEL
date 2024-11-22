#include "file_utils.h"

void write_raw_data_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", data);
        fclose(file);
        printf("Raw data written to %s\n", filename);
    } else {
        fprintf(stderr, "Error: Unable to open %s for writing.\n", filename);
    }
}

void write_parsed_data_to_file(const char *filename, const char *date, double temp, double humidity, double pressure, double windspeed) {
    FILE *file = fopen(filename, "a"); // Open in append mode
    if (file) {
        fprintf(file, "Date: %s\n", date);
        fprintf(file, "Temperature: %.1f\n", temp);
        fprintf(file, "Humidity: %.1f\n", humidity);
        fprintf(file, "Pressure: %.1f\n", pressure);
        fprintf(file, "Wind Speed: %.1f\n\n", windspeed); // Extra newline for separation
        fclose(file);
        printf("Parsed data written to %s\n", filename);
    } else {
        fprintf(stderr, "Error: Unable to open %s for writing.\n", filename);
    }
}
