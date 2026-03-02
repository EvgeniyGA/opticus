# LLR IDs: OPT_SW_LLR_BOARD_TEST_01_01

# Подключаемся и делаем сброс.
#connect_mcu1_only
target remote localhost:2331
monitor reset

# Значение $result: true - тест пройден, false - не пройден.
set $result = false

# Последовательность действий (см. описание требования).

# Устанавливаем ограничение по времени.
break_main_and_set_timeout 5

# Выполняем функцию MX_ADC1_Init().
break MX_USART1_UART_Init
continue
finish

# Проверяем настройки АЦП после инициализации.    
set $result = ( huart1.Instance == USART1 )

#set $result = ( hadc1.Instance == ADC1 )

#set $init = hadc1.Init

#set $result = $result \
#    && $init.ClockPrescaler == ADC_CLOCK_SYNC_PCLK_DIV4 \
#    && $init.Resolution == ADC_RESOLUTION_12B \
#    && $init.ScanConvMode == ADC_SCAN_ENABLE \
#    && $init.ContinuousConvMode == DISABLE \
#    && $init.DiscontinuousConvMode == DISABLE \
#    && $init.ExternalTrigConvEdge == ADC_EXTERNALTRIGCONVEDGE_RISING \
#    && $init.ExternalTrigConv == ADC_EXTERNALTRIGCONVHRTIM_TRG1 \
#    && $init.DataAlign == ADC_DATAALIGN_RIGHT \
#    && $init.NbrOfConversion == 4 \
#    && $init.DMAContinuousRequests == ENABLE \
#    && $init.EOCSelection == ADC_EOC_SEQ_CONV \
#    && $init.LowPowerAutoWait == DISABLE \
#    && $init.Overrun == ADC_OVR_DATA_OVERWRITTEN

# Выполняем тест и отключаемся.
disconnect_and_quit
