#ifndef CURL_REQUEST_H
#define CURL_REQUEST_H

#include <curl/curl.h>
#include "memory_struct.h"
#include "write_callback.h"

// Function to initialize and perform a CURL request
void perform_curl_request(const char *url);

#endif // CURL_REQUEST_H
