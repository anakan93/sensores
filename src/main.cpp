#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include<Wire.h>
#include <SoftwareSerial.h>
#define yellowled D9
#define redled D10
#define greenled D11

void task_LED1(void *param);
void task_LED2(void *param);

void setup(){
  Serial.begin(9600);
  xTaskCreate(task_LED1,"task1",1024*2,NULL,3,NULL);
  xTaskCreate(task_LED2,"task1",1024*2,NULL,3,NULL);
 vTaskStartScheduler();
}
/*void main(){
  setup();

 while (1)
 {

 }

}*/

void task_LED1(void *param)
{
  while(1)
  {
    const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
    printf("this is task 1 ");
    vTaskDelay( xDelay );
  }
  vTaskDelete(NULL);
}

void task_LED2(void *param)
{
  while(1)
  {
    printf("this is task 2");
  }
  vTaskDelete(NULL);
}
void loop (){}