# SortingAlgorithmsTest

# Configuración de C++ en Code::Blocks para Windows

Esta guía paso a paso muestra cómo configurar el entorno de desarrollo Code::Blocks para compilar y ejecutar programas C++ en Windows. Luego de este encontrarás uno para Visual Studio Code

## Pasos para la Configuración

### 1. Instalar Code::Blocks
Descarga e instala Code::Blocks con el compilador de MinGW incluido desde el [sitio oficial de Code::Blocks](http://www.codeblocks.org/downloads/26).

### 2. Crear un Proyecto Nuevo
- Abre Code::Blocks y selecciona 'Create a new project'.
- Elige 'Console application' y luego 'C++'.
- Sigue las instrucciones para nombrar y guardar tu proyecto.

### 3. Configurar el Proyecto
- En el gestor de proyectos, haz clic derecho en tu proyecto y selecciona 'Build options'.
- Asegúrate de que la opción 'Have g++ follow the C++11 ISO C++ language standard' esté seleccionada si tu código lo requiere.

### 4. Importar Archivos `.cpp`
- Con el proyecto abierto, puedes añadir tu archivo `main.cpp` utilizando 'File' -> 'Add files...' y seleccionando tu archivo.

### 5. Compilar y Ejecutar
- Haz clic en el ícono de 'Build' (martillo) para compilar tu proyecto.
- Una vez compilado, puedes ejecutarlo haciendo clic en el ícono de 'Run' (triángulo verde).

### 6. Depuración
- Si necesitas depurar tu programa, puedes utilizar las herramientas de depuración integradas en Code::Blocks.
- Establece puntos de interrupción y observa el flujo de ejecución y las variables.

### 7. Solución de Problemas
- Si encuentras errores, revisa tu código y las opciones de compilación.
- Asegúrate de que todas las dependencias y librerías estén correctamente configuradas en las 'Build options'.

## Soporte

Si necesitas más asistencia, consulta la [documentación de Code::Blocks](http://www.codeblocks.org/docs/main_codeblocks_en.html) o participa en los [foros de la comunidad](http://forums.codeblocks.org/).



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
