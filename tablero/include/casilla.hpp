#pragma once
#include "common.hpp"


class Casilla{
    char val;
    int posx; //la posicion es fija
    int posy;
    
    public:
        //Constructor y destructor
        Casilla (int=0, int=0, char = '_');
        Casilla (const Casilla&);
        ~Casilla (void);
        
        //getters
        const char get_val (void) const;
        const int get_posx (void) const;
        const int get_posy (void) const;
        
        //setters
        void set_val (const char);
        void set_posx (const int);
        void set_posy (const int);
};