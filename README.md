# Assembly-Bitmap-Filters
Assembly program that adds a blur or negative filter to a bitmap file.

	Ejecución del programa
Para ejecutar este programa simplemente debe de ejecutar en su terminal "make" y seguidamente "make run".

El programa le pedirá que escriba el nombre del BMP que desea trabajar, hay tres bitmap que puede probar: "TheGodfather.bmp", "TaxiDriver.bmp" o "Leon.bmp". Tambien podría utilizar su propia imagen .bmp (considere que esta debe ser de 24-bits por pixel).

Seguidamente le mostrará dos opciones de filtros que puede elegir: un efecto negativo (colores invertidos) o un blur (borroso). Solo debe escribir el número que corresponde al filtro (0 para negativo y 1 para blur).

Una vez finalizado, el programa descargará una imagen BMP de nombre "bitmap_neg.bmp" o "bitmap_blur.bmp", dependiendo del filtro que elija, que se encontrará en el mismo archivo que se encuentra el programa.

Si desea eliminar las imagenes con el filtro aplicado puede hacer un "make delete".

Este programa utiliza una biblioteca de bitmap de 24-bits creada por Arash Partow (2002)
https://www.partow.net/programming/bitmap/index.html

2021-II
