#include "curl_utils.h"

void initialize_curl(CURL **curl) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    *curl = curl_easy_init();
}

void cleanup_curl(CURL *curl) {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}
