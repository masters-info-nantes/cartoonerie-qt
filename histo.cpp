#include "histo.h"

Histo::Histo(int new_x, int new_y, int new_xx, int new_yy, int new_taille, bool new_point)
{
    x = new_x;
    y = new_y;
    xx = new_xx;
    yy = new_yy;
    taille = new_taille;
    point = new_point;
}

Histo::~Histo()
{

}

int Histo::get_x(){
    return x;
}

int Histo::get_y(){
    return y;
}

int Histo::get_xx(){
    return xx;
}

int Histo::get_yy(){
    return yy;
}

bool Histo::is_point(){
    return point;
}

int Histo::get_taille(){
    return taille;
}
