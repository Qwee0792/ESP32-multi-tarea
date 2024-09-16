# ESP32-multi-tarea
uso de los 2 procesadores del esp32

/*
 * Script para la utilización de tres procesadores del ESP32
 * Este script crea tres tareas en procesadores diferentes para simular un balanceador de carga
 * 
 * Tarea 1: Procesador 1 (más rápido)
 * Tarea 2: Procesador 2 (más rápido)
 * Tarea 3: Procesador 3 (bajo consumo, más lento)
 * 
 * Led conectado al pin 2 (LedStatusESP azul integrado en el ESP32)
 * 
 * -------------------------------------------------------------------------------------------------
 * Nota: No inicializar comunicación Serial cuando no es requerido, de lo contrario el 
 * código no se ejecutará si no detecta el otro dispositivo.
 * -------------------------------------------------------------------------------------------------
 * 
 * Creador del código en C++: Leonardo Dominguez
 
 */
