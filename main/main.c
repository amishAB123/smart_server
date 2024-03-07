#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nvs_flash.h"
//#include "wifi_connect.h"
//#include "mqtt_client.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_wpa2.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_smartconfig.h"
#include "esp_eap_client.h"
#include "connect_smart.h"
#include "connect_mqtt.h"

 

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    //wifi_connect_init();
    initialise_wifi();
    mqtt_app_start();

    //ESP_ERROR_CHECK(wifi_connect_sta("Chargebots", "9082388525", 10000));

    
}

 
