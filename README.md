# Proyecto Integrador

Este proyecto consiste en un sistema digital para administrar y simular el rendimiento y simular posibles procesos realizados durante la venta de estos.
El programa permite registrar sus especificaciones técnicas, calcular con su autonomía real,y realizar cambios a ciertso aspectos de estos;
evaluando cómo afectan factores como el tipo de cadena o el uso del aire acondicionado.

## Funcionalidad 
El programa permite registrar tanto motos como carros y se ajusta ligermanete a el tipo de vehiculo elegido, permitiendo principalmente calcular su eficiencia o mostrar los datos de los vehiculos guardados

## Consideraciones
El programa fue desarrollado usando código que compila en c++ estandar.
  
  compilar con: "g++ Sistema-Vehiculos.h Sistema-Vehiculos.cpp".
  
  Correr en Linux / macOS: ./Sistema-Vehiculos 
  
  Correr en Windows:  Sistema-Vehiculos.exe

## Casos de fallo
El programa es suceptible a fallar en ciertas situaciones, la más compun sería que se insertara un tipo de variable distinto al que se espera. Por ejemplo que en el menu principal en lugar de colocar un número se insertara un caracter, o que al crear un nuevo carro en el tanque se inserte un string. Fuera de eso el programa responde como debería y tiene avisos de advertencia para cuando se inserta un valor del tipo de variable correcta pero el valor en si esta mal.
