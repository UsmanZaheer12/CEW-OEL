ENVIRONMENTAL MONITORING SYSTEM

This project is a simple weather data fetching application built in C. It uses the cURL library to retrieve weather data from the Visual Crossing Weather API and processes the data using custom utilities and JSON parsing,
periodically fetches weather data based on a user-defined schedule using a script.
Alert System: Sends notifications or logs alerts when specific weather conditions (e.g., extreme temperatures, storms) are detected.
Modular structure for maintainable and extensible code.

FEATURES
Fetches weather data for a specific location (Karachi in this case).
Saves the raw weather data response to a text file (raw_data.txt).
Parses and processes JSON weather data for further usage.
Includes modular functions for better maintainability (e.g., CURL initialization, memory management, JSON parsing).

The raw API response will be saved in a file named raw_data.txt.
Parsed weather data will be displayed on the console as well as saved in a file named processed_weather_data.txt.

FILE STRUCTURE
main.c: The main program file containing the core logic for fetching and processing weather data.
memory_struct.h: Defines the MemoryStruct used for managing API response memory.
write_callback.h: Contains the callback function for writing API responses.
weather_parser.h: Functions to parse and handle weather data.
curl_utils.h: Helper functions for setting up and cleaning up cURL resources.
json_utils.h: Functions for handling JSON data.
file_utils.h: Functions for file operations (like writing raw data to a file).

API Integration
The program fetches weather data using the Visual Crossing Weather API. The default endpoint is set to fetch weather data for Karachi, using the API key embedded in the code.
