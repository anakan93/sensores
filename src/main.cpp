#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include<Wire.h>
#include <SoftwareSerial.h>
#define yellowled D9
#define redled D10
#define greenled D11
#define mainDELAY_LOOP_COUNT  100E6


void task_LED1(void *param);
void task_LED2(void *param);

void setup(){
  Serial.begin(9600);
  xTaskCreate(task_LED1,"task1",1024*2,NULL,3,NULL);
  xTaskCreate(task_LED2,"task2",1024*2,NULL,3,NULL);
  vTaskStartScheduler();
}


void task_LED1(void *param)
{
  const char *pcTaskName="Task 1 is running";
  volatile unsigned long ul; 
  for(;;)
  {
    Serial.println( pcTaskName );
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ ) {}
   /*const TickType_t xDelay = 100 / portTICK_PERIOD_MS;
    printf("this is task 1 ");
    vTaskDelay( xDelay );*/
  }
  vTaskDelete(NULL);
}

void task_LED2(void *param)
{
  const char *pcTaskName="Task 2 is running";
  volatile unsigned long ul; 
  for(;;)
  {
    Serial.println( pcTaskName );
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ ) {}
    /*const TickType_t xDelay = 100 / portTICK_PERIOD_MS;
    printf("this is task 2 ");
     vTaskDelay( xDelay );*/
  }
  vTaskDelete(NULL);
}
void loop (){
  

}