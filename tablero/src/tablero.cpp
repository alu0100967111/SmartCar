#include "tablero.hpp"

//Constructor: crear vector con todos los elementos blancos
//y sus respectivas posiciones x e y dados un ancho y altura
Tablero::Tablero (const int alto_, const int ancho_){
    cout << "Tablero::Tablero (const int alto_, const int ancho_)" << endl;
    alto = alto_;
    ancho = ancho_;
    
    int n = alto*ancho;
    
    tablero.resize(n);
    
    for (int y = 0; y < alto; y++){ //Recorrido en matriz por filas
        for (int x = 0; x < ancho; x++){
            //Poner todos los elementos en blanco y guardar su posición
            tablero[x+(y*ancho)].set_val('_');
            tablero[x+(y*ancho)].set_posx(x);
            tablero[x+(y*ancho)].set_posy(y);
        }
    }
    
}
//Constructor de copia: por si a acaso
Tablero::Tablero (const Tablero& rhs){
    alto = rhs.alto;
    ancho = rhs.ancho;
    tablero = rhs.tablero;
}
//Destructor
Tablero::~Tablero (void){}
//Método para convertir coordenadas en índice de vector
const int Tablero::xytoi (const int x, const int y) const{
    return x+(y*ancho);
}
//Método para modificar el contenido de una casilla
void Tablero::set_val (const int x, const int y, const char val){
    tablero[xytoi(x,y)].set_val(val);
}
//Método para leer el contenido de una casilla
const char Tablero::get_val (const int x, const int y){
    return tablero[xytoi(x,y)].get_val();
}
//Método para imprimir por pantalla el tablero
void Tablero::print (void){
    for (int y = 0; y < alto; y++){//Recorrido en matriz por filas
        for (int x = 0; x < ancho; x++){
            cout << tablero[xytoi(x,y)].get_val() << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

//Operador de comparación
bool Tablero::operator== (const Tablero& rhs){
    if (tablero.size() != rhs.tablero.size()) 
        return false;
        
    for (int i = 0; i < tablero.size(); i++)
        if (tablero[i].get_val() != rhs.tablero[i].get_val())
            return false;
            
    return true;
};