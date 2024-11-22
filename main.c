#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "memory_struct.h"
#include "write_callback.h"
#include "weather_parser.h"
#include "curl_utils.h"
#include "json_utils.h"
#include "file_utils.h"

int main(void) {
    CURL *curl;
    CURLcode res;

    // Initialize response struct
    struct MemoryStruct response;
    response.memory = malloc(1);
    response.memory[0] = '\0';
    response.size = 0;

    // Initialize CURL
    initialize_curl(&curl);
    
    if (curl) {
        // Set up CURL options
        const char *url = "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/karachi?unitGroup=us&key=9WSZRARWEQDU2NMB3STHA66Y9&contentType=json";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        // Perform the CURL request
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response.memory);
            
            // Write the raw API response to a file
            write_raw_data_to_file("raw_data.txt", response.memory);

            // Parse JSON data
            cJSON *json = parse_json(response.memory);
            if (json) {
                // Parse and save the weather data
                parse_weather_data(response.memory);

                // Clean up JSON object
                cleanup_json(json);
            }
        }

        // Free the response memory
        free(response.memory);

        // Clean up CURL resources
        cleanup_curl(curl);
    }

    return 0;
}
