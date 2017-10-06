#pragma once
#include "common.hpp"
#include "casilla.hpp"


class Tablero{
    //dimensiones
    int alto;
    int ancho;
    //tablero
    vector <Casilla> tablero;
    //elemento (x, y)
    //es equivalente a tabla[(x+(y*ancho))]
    //implentado en metodo const int xytoi (const int,const int) const;
    
    public:
        //Constructor: crear vector con todos los elementos blancos
        //y sus respectivas posiciones x e y dados un ancho y altura
        Tablero (const int = 0, const int = 0);
        //Constructor de copia: por si a acaso
        Tablero (const Tablero&);
        //Destructor
        ~Tablero (void);
        //Método para convertir coordenadas en índice de vector
        const int xytoi (const int, const int) const;
        //Método para modificar el contenido de una casilla
        void set_val (const int, const int, const char);
        //Método para leer el contenido de una casilla
        const char get_val (const int, const int);
        //Método para imprimir por pantalla el tablero
        void print (void);
        //Operador de comparación
        bool operator== (const Tablero&);
        
};