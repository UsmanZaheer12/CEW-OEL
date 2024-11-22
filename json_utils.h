#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <cjson/cJSON.h>
#include <stdio.h>

// Function to parse JSON data from a string
cJSON* parse_json(const char *json_data);

// Function to clean up JSON object
void cleanup_json(cJSON *json);

#endif // JSON_UTILS_H
