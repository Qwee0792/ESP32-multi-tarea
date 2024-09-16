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

#include <Arduino.h>

// Definición del pin del LED integrado en el ESP32
const int LedStatusESP = 2;

// Declaración de los manejadores de las tareas
TaskHandle_t Task2, Task3;

// Función de la tarea para el procesador 2 (más rápido)
void loop2(void *parameter) {
  for (;;) {
    // Código para el procesador 2 (más rápido)
    
  }
    vTaskDelay(10); // Retardo en milisegundos
}

// Función de la tarea para el procesador 3 (bajo consumo, más lento)
void loop3(void *parameter) {
  for (;;) {
    // Código para el procesador 3 (bajo consumo, más lento)
    // Recomendación: usar para el control de LEDs o para comunicación serial, no para otros dispositivos
    digitalWrite(LedStatusESP, HIGH);
    delay(500);
    digitalWrite(LedStatusESP, LOW);
    delay(500);
    
  }
    vTaskDelay(10); // Retardo en milisegundos
}

void setup() {
  // Configuración del pin del LED como salida
  pinMode(LedStatusESP, OUTPUT);

  // Creación de la tarea para el procesador 2
  xTaskCreatePinnedToCore(
    loop2,       // Función de la tarea
    "Task_2",    // Nombre de la tarea
    1000,        // Tamaño de la pila
    NULL,        // Parámetros de ejecución
    1,           // Prioridad
    &Task2,      // Manejador de la tarea
    1            // Procesador (procesador 1)
  );

  // Creación de la tarea para el procesador 3
  xTaskCreatePinnedToCore(
    loop3,       // Función de la tarea
    "Task_3",    // Nombre de la tarea
    1000,        // Tamaño de la pila
    NULL,        // Parámetros de ejecución
    1,           // Prioridad
    &Task3,      // Manejador de la tarea
    0            // Procesador (procesador 0)
  );
}

void loop() {
  // Código para el procesador principal (más rápido)
  
}