#connect_both_mcu
connect_mcu1_only
#run_mcu 1

# Выполняем сброс удалённого микроконтроллера.
monitor reset

# Запускаем программу.
break main
continue

disconnect
quit
