#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>

// Function to write raw API response to a file
void write_raw_data_to_file(const char *filename, const char *data);

// Function to write parsed weather data to a file
void write_parsed_data_to_file(const char *filename, const char *date, double temp, double humidity, double pressure, double windspeed);

#endif // FILE_UTILS_H
