#include "common.hpp"
#include "tablero.hpp"

int main (void){
    Tablero tablero (8, 8);
    
    tablero.print();
    
    tablero.set_val(4,4,'A');
    
    tablero.print();
}