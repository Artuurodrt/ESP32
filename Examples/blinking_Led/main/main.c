#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define GPIO_LED 2

void blinking_Led(void *pvParams) {
    gpio_pad_select_gpio(GPIO_LED);
    gpio_set_direction (GPIO_LED,GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(GPIO_LED,0);
        vTaskDelay(1000/portTICK_RATE_MS);
        gpio_set_level(GPIO_LED,1);
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void app_main() {
    xTaskCreate(&blinking_Led,"LED_BLINK",512,NULL,5,NULL);
}