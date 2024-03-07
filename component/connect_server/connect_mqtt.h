#ifndef CONNECT_MQTT_H
#define CONNECT_MQTT_H

#include "mqtt_client.h"
void  mqtt_app_start(void);
void publish_message(esp_mqtt_client_handle_t client, const char *topic, const char *message);
void mqtt_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
#endif