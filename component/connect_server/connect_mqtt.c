#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "nvs_flash.h"
#include "mqtt_client.h"
#include "esp_log.h"
#include "esp_wifi.h"
//#include "esp_wpa2.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
//#include "esp_smartconfig.h"
//#include "esp_eap_client.h"

char *TAG1 = "MQTT";

 void mqtt_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
//static void test_send_messages(void *param);
 esp_mqtt_client_handle_t client;

 void publish_message(esp_mqtt_client_handle_t client, const char *topic, const char *message)
{
    int msg_id = esp_mqtt_client_publish(client, topic, message, 0, 1, 0);
    ESP_LOGI(TAG1, "Published to topic %s, message ID: %d", topic, msg_id);
}


void  mqtt_app_start(void)
{
    // MQTT client configuration
    esp_mqtt_client_config_t esp_mqtt_client_config = {
        .broker.address.uri = "mqtt://mqtt.chargebots.in:1883",
        .credentials.username = "dev",
        .credentials.authentication.password = "dev@1234"
        };

    client = esp_mqtt_client_init(&esp_mqtt_client_config);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(client);
}

void mqtt_event_handler(void *event_handler_arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;

    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG1, "MQTT_EVENT_CONNECTED");
        esp_mqtt_client_subscribe(client, "hiii", 1);
        publish_message(client, "hiii", "Welcome to Chargebots..");
        //esp_mqtt_client_subscribe(client, "hiii", 1);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG1, "MQTT_EVENT_DISCONNECTED");
        break;
    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG1, "MQTT_EVENT_SUBSCRIBED");  
    //ESP_LOGI(TAG, "Successfully subscribed to topic: %.*s", event->topic_len, event->topic);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG1, "MQTT_EVENT_UNSUBSCRIBED");
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG1, "MQTT_EVENT_PUBLISHED");
        //ESP_LOGI(TAG, "Message published successfully to topic: %.*s", event->topic_len, event->topic);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG1, "MQTT_EVENT_DATA");
        printf("topic: %.*s\n", event->topic_len, event->topic);
        printf("message: %.*s\n", event->data_len, event->data);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGE(TAG1, "ERROR %s", strerror(event->error_handle->esp_transport_sock_errno));
        break;
    default:
        break;
    }
}