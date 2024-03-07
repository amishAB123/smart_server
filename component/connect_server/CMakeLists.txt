idf_component_register(
    SRCS
    "connect_smart.c"
    "connect_mqtt.c"
    INCLUDE_DIRS
    "."
    REQUIRES
    mqtt
    esp_netif
    esp_wifi
    log
    
)