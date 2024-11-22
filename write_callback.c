#include "write_callback.h"

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
