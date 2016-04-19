#!/bin/bash
clear
echo "Primer Prueba sin errores"
./G5E8 -Una Opcion dos parametros
echo "Segunda Prueba sin errores"
./G5E8 Se puede -pasar opciones -y parametros 

echo "Tercera Prueba, error en el pasaje de opciones"
./G5E8 -Esto -Es Erroneo
echo "Cuarta Prueba error en el pasaje de ultima opcion"
./G5E8 La -ultima opcion es invalida -

