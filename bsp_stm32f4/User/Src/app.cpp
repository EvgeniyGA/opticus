#include <stdio.h>
#include <string.h>
#include "main.h"
#include "SEGGER_RTT.h"

// SEGGER RTT: IP: localhost, PORT: 19021.
#define print(s)                        SEGGER_RTT_WriteString( 0, s ); HAL_Delay(1)
#define println(s)                      print( s "\n" )
#define printf( format, ... )           SEGGER_RTT_printf( 0, ( const char * ) ( format ), ##__VA_ARGS__ ); HAL_Delay(1)

extern "C" void initialise_monitor_handles( void );

void init( void ){
	//initialise_monitor_handles();
	
	// Настройка терминала 0 для работы в неблокирующем режиме.
    SEGGER_RTT_ConfigUpBuffer( 0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_TRIM );
    SEGGER_RTT_WriteString( 0, "SEGGER Real-Time-Terminal Sample\n" );
}

void setup( void ){
	//   char buffer[100];
	//   FILE * fd = fopen ("C:\\Data\\data.csv", "w+" );
	//   int n = 2, SensorValue = 555;
	//   if(fd != NULL){
	//     sprintf ( buffer, "%i, %.1f\n", n, (double)SensorValue);
	//     fwrite ( buffer, sizeof(char), strlen( buffer ), fd );
	//   }
	//   fclose(fd);
}

void loop( void ){
	static int cnt = 0;
	HAL_GPIO_TogglePin(led_status_GPIO_Port, led_status_Pin);
	HAL_Delay(1000);
	printf("hello %d\n\r", cnt);
	cnt++;
}
