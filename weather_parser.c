#include "weather_parser.h"

void parse_weather_data(const char *json_data) {
    cJSON *json = cJSON_Parse(json_data);
    if (!json) {
        fprintf(stderr, "Error parsing JSON\n");
        return;
    }

    cJSON *days = cJSON_GetObjectItem(json, "days");
    if (days && cJSON_IsArray(days)) {
        cJSON *recent_day = cJSON_GetArrayItem(days, 0); // Get the first item (recent day)
        if (recent_day) {
            const char *date = cJSON_GetObjectItem(recent_day, "datetime")->valuestring;
            double temp = cJSON_GetObjectItem(recent_day, "temp")->valuedouble;
            double humidity = cJSON_GetObjectItem(recent_day, "humidity")->valuedouble;
            double pressure = cJSON_GetObjectItem(recent_day, "pressure")->valuedouble;
            double windspeed = cJSON_GetObjectItem(recent_day, "windspeed")->valuedouble;

            // Print to console
            printf("Date: %s\n", date);
            printf("Temperature: %.1f\n", temp);
            printf("Humidity: %.1f\n", humidity);
            printf("Pressure: %.1f\n", pressure);
            printf("Wind Speed: %.1f\n", windspeed);

            // Save to file
            FILE *file = fopen("processed_weather_data.txt", "a"); // Open in append mode
            if (file) {
                fprintf(file, "Date: %s\n", date);
                fprintf(file, "Temperature: %.1f\n", temp);
                fprintf(file, "Humidity: %.1f\n", humidity);
                fprintf(file, "Pressure: %.1f\n", pressure);
                fprintf(file, "Wind Speed: %.1f\n\n", windspeed); // Extra newline for separation
                fclose(file);
                printf("Parsed data written to processed_weather_data.txt\n");
            } else {
                fprintf(stderr, "Error: Unable to open processed_weather_data.txt for writing.\n");
            }
        }
    }

    cJSON_Delete(json); // Clean up
}
