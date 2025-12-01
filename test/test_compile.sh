#!/bin/bash

echo "[TEST] Compilando proyecto..."

gcc src/main.c src/brick.c -o juego 2> compile_errors.txt

if [ $? -ne 0 ]; then
    echo "[ERROR] No compila. Revisa syntax."
    cat compile_errors.txt
    exit 1
fi

echo "[PASS] Compilación exitosa."
