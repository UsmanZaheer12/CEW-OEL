#ifndef WEATHER_PARSER_H
#define WEATHER_PARSER_H

#include <cjson/cJSON.h>
#include <stdio.h>

// Function to parse weather data from JSON
void parse_weather_data(const char *json_data);

#endif // WEATHER_PARSER_H
