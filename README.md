# SortingAlgorithmsTest

# Configuración de C++ en Visual Studio Code para Windows

Esta guía explica cómo configurar Visual Studio Code para compilar y ejecutar programas C++ en Windows, utilizando MinGW como compilador.

## Pasos para la Configuración

### 1. Instalar Visual Studio Code
Descarga e instala Visual Studio Code desde el [sitio oficial de VS Code](https://code.visualstudio.com/).

### 2. Instalar MinGW
- Descarga MinGW desde [SourceForge](https://sourceforge.net/projects/mingw/).
- Sigue el proceso de instalación seleccionando los paquetes para `gcc`, `g++`, y `make`.
- Asegúrate de que el directorio `bin` de MinGW está añadido a la variable de entorno `PATH`.

### 3. Instalar la Extensión de C/C++ para VS Code
- En VS Code, ve al ícono de extensiones o presiona `Ctrl+Shift+X`.
- Busca "C/C++" y selecciona la extensión oficial de Microsoft.
- Haz clic en "Instalar".

### 4. Configurar el Compilador de C++ en VS Code
- Abre la carpeta que contiene tu archivo `main.cpp` en VS Code.
- Abre la paleta de comandos con `Ctrl+Shift+P` y escribe "C/C++: Edit Configurations (JSON)".
- Asegúrate de que el campo `command` en el archivo `tasks.json` apunte a `g++.exe`.

### 5. Compilar el Archivo C++
- Con el archivo `main.cpp` abierto, presiona `Ctrl+Shift+B` para compilar.
- Verifica que se genere el archivo ejecutable sin errores.

### 6. Ejecutar el Programa
- Abre el terminal integrado con ``Ctrl+` `` y ejecuta `.\main.exe` para ver la salida del programa.

### 7. Solución de Problemas
- Verifica el código fuente y la configuración del compilador si encuentras errores.
- Confirma que la ruta de MinGW esté en el `PATH`.

### 8. Depuración
- Utiliza la extensión de C/C++ de VS Code para depurar tu programa.

## Soporte

Para obtener más ayuda, consulta la [documentación oficial de VS Code](https://code.visualstudio.com/docs) o busca asistencia en la comunidad de desarrolladores.
