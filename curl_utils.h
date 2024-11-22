#ifndef CURL_UTILS_H
#define CURL_UTILS_H

#include <curl/curl.h>

// Function to initialize CURL
void initialize_curl(CURL **curl);

// Function to clean up CURL resources
void cleanup_curl(CURL *curl);

#endif // CURL_UTILS_H
