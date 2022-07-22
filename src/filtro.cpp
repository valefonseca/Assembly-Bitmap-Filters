/*  
    Valeria Fonseca Rodríguez B93061
    Marco Antonio Piedra Venegas A64397
    José Andrey Pereira Zúñiga C05869
    Diciembre, 2021
*/
#include <iostream>
#include "bitmap_image.hpp" //  recuperado de https://www.partow.net/programming/bitmap/index.html
using namespace std;

extern "C" void negativo (const int* rgb, int rgb_neg[4]);
extern "C" void blur (const float* rgb, float rgb_blur[4]);

int main () {

    cout << "Escriba el nombre de la imagen BMP: \n(ejemplo: 'TaxiDriver.bmp') \n";
    string nombre_BMP;
    cin >> nombre_BMP;

    bitmap_image img_original(nombre_BMP);  //  Bitmap debe ser de 24-bits por pixel

    if (!img_original)  //  caso error al abrir imagen
    {
        printf("Error - fallo al abrir BMP \n");
        return 1;
    }

    bitmap_image img_nueva(img_original.width(), img_original.height());    //  crea nuevo BMP

    cout << "Elija el filtro que desea aplicar (0 o 1): \n 0. Negativo \n 1. Blur \n";

    bool filtro;
    cin >> filtro;

    switch (filtro) //  usuario elije el filtro que se desee aplicar
    {
    case 0:
        for (int x = 0; x < img_original.width(); ++x)  //  recorre el BMP por pixeles
        {
            for (int y = 0; y < img_original.height(); ++y) 
            {
                rgb_t colour;
                img_original.get_pixel(x,y,colour);
                alignas (16) int rgb[4] = {(int) colour.red, (int) colour.green, (int) colour.blue, 0}; //  RGB del pixel como parametros
                alignas (16) int rgb_neg[4];    //  se guardará el RGB en negativo del pixel
                negativo(rgb, rgb_neg); //  llama a la función en negativo.asm
                img_nueva.set_pixel(x,y,(unsigned char) rgb_neg[0],(unsigned char) rgb_neg[1],(unsigned char) rgb_neg[2]);
            }
        }
        img_nueva.save_image("bitmap_neg.bmp");
        break;
    
    case 1:
        for (int x = 0; x < img_original.width()-2; ++x)    //  recorre el BMP por regiones de pixeles de 3x3
        {
            for (int y = 0; y < img_original.height()-2; ++y)
            {
                rgb_t colour;
                alignas (16) float region[36];  //  vector de los RGB de cada uno de los pixeles de la región
                alignas (16) float rgb_blur[4]; //  guarda el promedio de todos los pixeles de la región

                for (int i = 0; i < 9; i++) //  recorre la región 3x3 de pixeles
                {
                    for (int j = 0; j < 3; j++)
                    {
                        img_original.get_pixel(x+i,y+j,colour);
                    }
                    region[i*4+0]= (float)colour.red;
                    region[i*4+1]= (float)colour.green;
                    region[i*4+2]= (float)colour.blue;
                    region[i*4+3]= 0;
                }

                blur(region, rgb_blur); //  llama a la función en blur.asm

                for (int i = 0; i < 3; i++) //  recorre la región 3x3 de pixeles
                {
                    for (int j = 0; j < 3; j++)
                    {
                        img_nueva.set_pixel(x+i,y+j,(unsigned char) rgb_blur[0],(unsigned char) rgb_blur[1],(unsigned char) rgb_blur[2]);
                    }
                } 
            }
        }
        img_nueva.save_image("bitmap_blur.bmp");
        break;
    }

    return 0;

}