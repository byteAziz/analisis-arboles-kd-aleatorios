# Proyecto Algoritmica - Análisis de árboles k-dimensionales aleatorios

## Descripción

Este proyecto implementa variantes de árboles k-dimensionales aleatorios 
y un algoritmo para consultas del vecino más cercano en estos árboles. Se 
ha analizado experimentalmente el costo medio de las consultas y concluído 
qué variante es mejor que las demás dependiendo del caso.

## Intrucciones de ejecución

Este manual de ejecución es solo compatible con las distribuciones de 
Linux. Por ello, se recomienda el uso de Linux para ejecutar los archivos. 

Cualquier comando que se indique está pensado para ser ejecutado en una consola
de Linux (bash por ejemplo) dentro de la carpeta del repositorio clonada.

## Requisitos

En este proyecto ha utilitzado C++ y Python como lenguajes de programación. 
Por ello, es necesario tener instalada alguna versión de **g++** compatible y 
alguna versión de **python3**. Además se necesitara tener instalado también 
**_make_**, para poder ejecutar dicho comando. Finalmente, si quiere 
visualizar el [documento de resultados](resultados.ipynb), donde se han 
creado las gráficas y se han hecho los cáculos, será necesario disponer 
de **Jupyter Notebook** o, alternativamente, hacerlo mediante google collab.

### Opción 1 (Instalando todo):

1. Instala los paquetes necesarios:
```bash
sudo apt install g++, python3, make, jupyter, python3-pip
```

2. Instala las librerias de python necesarias:
``` bash
pip install numpy, matplotlib, pandas
```

### Opción 2 (Instalando solo lo necesario para ejecutar el código):

En caso de optar por esto, solo necesitara tener instalado g++ y make:
```bash
sudo apt install g++, make
```
De esta forma, sin tener instalado Jupyter Notebook, se podrá ejecutar el
código y ver los resultados en la consola. Para ver el archivo
[resultados.ipynb](resultados.ipynb) se puede subir a un Google Collab.
[Google Collab](https://colab.research.google.com).

## Uso

1. Compilar el código:
    ```bash
    make
    ```
    De esta forma se generan los archivos Tree.o, main.o y main.exe.

2. Ejecutar el código:
    ```bash
    ./main.exe
    ```
    De esta forma se ejecutará el programa y se pedirán los datos necesarios:

    - El tipo de árbol: 0 - Standar, 1 - Relaxed, 2 - Squarish
    - La dimensión del árbol
    - El número de nodos que tendrá el árbol
    - El número de árboles de n nodos que se crearan
    - El número de consultas a cada árbol

    Como resultado se escribirá el número medio de nodos visitados por consulta.

3. Generar las gráficas y resultados:

    #### OPCIÓN 1: Usando jupyter notebook 

    ```bash
    jupyter notebook 
    ```

    Una vez se abra el navegador (se recomienda usar Firefox o Chrome) se debe
    abrir el archivo mencionado. En esta notebook se puede ver como se 
    han generadoa las gráficas y al final de la libreta se visualiza cómo 
    se han obtenido los valores de *Z* para las distintas dimensiones
    y en los distintos árboles.

    #### OPCIÓN 2: Usando google collab

    Entrando en la [web oficial](https://colab.research.google.com) 
    y una vez iniciada sesión con el correo electrónico, se puede subir
    el archivo para visualizarlo.

## Tabla de miembros

|     Nombre     | Usuario GitHub |
| -------------- | -------------- |
| Pol Fonoyet González | Polfono  |
| Yassin El Kaisi Rahmoun | ElKaisi |
| Gorka Parra Ordorica | gorkatr  |
| Tahir Muhammad Aziz  | byteAziz |