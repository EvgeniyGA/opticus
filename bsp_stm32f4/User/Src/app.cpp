#include <stdio.h>
#include <string.h>
#include "main.h"

extern "C" void initialise_monitor_handles( void );

void init( void ){
	//initialise_monitor_handles();
}

void setup( void ){
	  char buffer[100];
	  FILE * fd = fopen ("C:\\Data\\data.csv", "w+" );
	  int n = 2, SensorValue = 555;
	  if(fd != NULL){
	    sprintf ( buffer, "%i, %.1f\n", n, (double)SensorValue);
	    fwrite ( buffer, sizeof(char), strlen( buffer ), fd );
	  }
	  fclose(fd);
}

void loop( void ){
	HAL_GPIO_TogglePin(led_status_GPIO_Port, led_status_Pin);
	HAL_Delay(1000);
	//printf("hello\n\r");
}
