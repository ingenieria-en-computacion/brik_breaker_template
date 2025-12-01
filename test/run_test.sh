#!/bin/bash
echo "=== Ejecutando pruebas automáticas ==="

bash tests/test_files.sh
bash tests/test_compile.sh
bash tests/test_menu.sh

echo "=== Fin de pruebas ==="
