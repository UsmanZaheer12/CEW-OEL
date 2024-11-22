#ifndef WRITE_CALLBACK_H
#define WRITE_CALLBACK_H

#include "memory_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Callback function to handle the response data
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data);

#endif // WRITE_CALLBACK_H
