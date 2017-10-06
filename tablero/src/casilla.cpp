#include "casilla.hpp"

//Constructor y destructor
Casilla::Casilla (int posx_, int posy_, char val_){
    val = val_;
    posx = posx_;
    posy = posy_;
}


Casilla::Casilla (const Casilla& rhs){
    val = rhs.val;
    posx = rhs.posx;
    posy = rhs.posy;
}

Casilla::~Casilla (void){
    
}

//getters
const char Casilla::get_val (void) const{
    return val;
}
const int Casilla::get_posx (void) const{
    return posx;
}
const int Casilla::get_posy (void) const{
    return posy;
}


//setters
void Casilla::set_val (const char val_){
    val = val_;
}

void Casilla::set_posx (const int posx_){
    posx = posx_;
}

void Casilla::set_posy (const int posy_){
    posy = posy_;
}

