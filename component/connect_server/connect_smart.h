#ifndef CONNECT_SMART_H
#define CONNECT_SMART_H

#include "esp_event.h"
void smartconfig_example_task(void * parm);
void initialise_wifi(void);
void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data);
#endif