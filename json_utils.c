#include "json_utils.h"

cJSON* parse_json(const char *json_data) {
    return cJSON_Parse(json_data);
}

void cleanup_json(cJSON *json) {
    cJSON_Delete(json);
}
