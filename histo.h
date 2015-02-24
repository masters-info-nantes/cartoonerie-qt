#ifndef HISTO_H
#define HISTO_H


class Histo
{
public:
    Histo(int new_x, int new_y, int new_xx, int new_yy, int new_taille, bool new_point);
    ~Histo();
    int get_x();
    int get_y();
    int get_xx();
    int get_yy();
    int get_taille();
    bool is_point();

private:
    int x;
    int y;
    int xx;
    int yy;
    int taille;

    bool point;
};

#endif // HISTO_H
