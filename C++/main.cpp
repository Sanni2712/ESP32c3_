
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C" void app_main() {
volatile unsigned int* GPIO_ENABLE_REG = (unsigned int*)0x60004020;
 *GPIO_ENABLE_REG |= 0b00000100;
volatile unsigned int* GPIO_OUT_W1TS  = (unsigned int*)0x60004008;
volatile unsigned int* GPIO_OUT_W1TC  = (unsigned int*)0x6000400C;
    *GPIO_OUT_W1TS |= 0b00000100;  // Set GPIO2
volatile unsigned int* PAD  = (unsigned int*)0x60009008; //pad for gpio 2 
*PAD &= ~((1 << 3) | (1 << 4) | (1 << 5) | (1 << 6));  // Clear bits 3-6

*PAD = (1 >> 2);
while(1){
*PAD = (3 >> 1);
*GPIO_OUT_W1TS |= 0b00000100;  // Set GPIO2
vTaskDelay(pdMS_TO_TICKS(500));
*PAD = ~(3 >> 1);  
*PAD = (1 >> 2);
vTaskDelay(pdMS_TO_TICKS(500));  
*PAD = ~(1 >> 2);
*PAD = (1 >> 1);
vTaskDelay(pdMS_TO_TICKS(500));  
*PAD = ~(1 >> 1);
vTaskDelay(pdMS_TO_TICKS(500)); 
*GPIO_OUT_W1TC |= 0b00000100;  // Set GPIO2
vTaskDelay(pdMS_TO_TICKS(500)); 
}

}