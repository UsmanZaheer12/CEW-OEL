#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

// Struct to hold the response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to handle the response data
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t total_size = size * nmemb;
    char *ptr_new = realloc(data->memory, data->size + total_size + 1);
    
    if (ptr_new == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        return 0;
    }

    data->memory = ptr_new;
    memcpy(&(data->memory[data->size]), ptr, total_size);
    data->size += total_size;
    data->memory[data->size] = '\0';

    return total_size;
}

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
            FILE *file = fopen("weather_data.txt", "a"); // Open in append mode
            if (file) {
                fprintf(file, "Date: %s\n", date);
                fprintf(file, "Temperature: %.1f\n", temp);
                fprintf(file, "Humidity: %.1f\n", humidity);
                fprintf(file, "Pressure: %.1f\n", pressure);
                fprintf(file, "Wind Speed: %.1f\n\n", windspeed); // Extra newline for separation
                fclose(file);
                printf("Parsed data written to weather_data.txt\n");
            } else {
                fprintf(stderr, "Error: Unable to open weather_data.txt for writing.\n");
            }
        }
    }

    cJSON_Delete(json); // Clean up
}

int main(void) {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct response;
    response.memory = malloc(1);
    response.memory[0] = '\0';
    response.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/karachi?unitGroup=us&key=9WSZRARWEQDU2NMB3STHA66Y9&contentType=json");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response.memory);
            parse_weather_data(response.memory); // Parse the JSON data
        }

        free(response.memory);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
