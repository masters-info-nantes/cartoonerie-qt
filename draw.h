#ifndef DRAW_H
#define DRAW_H

#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include "histo.h"

class Draw: public QLabel
{
    Q_OBJECT

public:
    explicit Draw(int longueur, int largeur, QWidget * parent = 0);
    ~Draw();
    QColor get_color();
    QPixmap get_image();
    void set_color(QColor couleur);
    void set_utiliser_crayon(bool choix);
    void set_dessin(QPixmap image);
    void changer_taille_crayon(int nouvelle_taille);
    void save(QString chemin_dessin, QString chemin_calque, std::string chemin_image_film, std::string chemin_dessin_film);
    void undo();

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent();

private:
    QPen crayon;
    QPixmap dessin;
    QCursor curseur;
    QPixmap image_souris;

    std::string path_souris;

    bool tracer_ligne;
    bool utiliser_crayon;

    std::vector<Histo> historique;

    int x;
    int y;
};

#endif // DRAW_H
