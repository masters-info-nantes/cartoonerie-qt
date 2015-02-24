#include "draw.h"
#include <QCursor>
#include <QMouseEvent>
#include <iostream>
Draw::Draw(int longueur, int largeur, QWidget * parent):QLabel(parent), dessin(longueur, largeur), crayon(Qt::blue)
{

    dessin.fill(Qt::transparent);
    crayon.setCapStyle(Qt::RoundCap);

    tracer_ligne = false;
    utiliser_crayon = true;

    setStyleSheet("background: transparent");
    setPixmap(dessin);

    path_souris = ":/images/pen-icon.png";
    QPixmap crayon_souris(path_souris.c_str());
    image_souris = crayon_souris.scaledToWidth(15);
    curseur = QCursor(image_souris, 0, 15);
    setCursor(curseur);
}

Draw::~Draw()
{

}

void Draw::mousePressEvent ( QMouseEvent * event ){

        historique.clear();

        QPainter paint(&dessin);

        if(!utiliser_crayon){
            crayon.setColor(Qt::transparent);
            paint.setCompositionMode(QPainter::CompositionMode_SourceIn);
        }

        paint.setPen(crayon);
        x = event->x();
        y = event->y();
        tracer_ligne = true;
        paint.drawPoint(event->x(), event->y());
        setPixmap(dessin);

        Histo point(x, y, 0, 0, crayon.width(), true);
        historique.push_back(point);
}

void Draw::mouseMoveEvent( QMouseEvent * event ){

    QPainter paint(&dessin);

    if(!utiliser_crayon){
        crayon.setColor(Qt::transparent);
        paint.setCompositionMode(QPainter::CompositionMode_SourceIn);

    }

    paint.setPen(crayon);
    paint.drawLine(x, y, event->x(), event->y());
    paint.end();

    Histo ligne(x, y, event->x(), event->y(), crayon.width(), false);
    historique.push_back(ligne);

    x = event->x();
    y = event->y();

    setPixmap(dessin);
}

void Draw::mouseReleaseEvent(){
    tracer_ligne = false;
}

void Draw::set_color(QColor couleur){
    crayon.setColor(couleur);
}

QColor Draw::get_color(){
    return crayon.color();
}

void Draw::changer_taille_crayon(int nouvelle_taille){
    QPixmap crayon_souris(path_souris.c_str());

    image_souris = crayon_souris.scaledToWidth(nouvelle_taille*3.75);
    curseur = QCursor(image_souris, 0, nouvelle_taille*3.75);
    setCursor(curseur);

    crayon.setWidth(nouvelle_taille);
}

void Draw::set_utiliser_crayon(bool choix){
    utiliser_crayon = choix;
    if(choix){
        path_souris = ":/images/pen-icon.png";
    }
    else{
        path_souris = ":/images/eraser-20.png";
    }

    QPixmap crayon_souris(path_souris.c_str());

    image_souris = crayon_souris.scaledToWidth(image_souris.width());
    curseur = QCursor(image_souris, 0, image_souris.width());
    setCursor(curseur);
}

void Draw::save(QString chemin_dessin, QString chemin_calque, std::string chemin_image_film, std::string chemin_dessin_film){
    QPixmap temp(dessin.width(), dessin.height());
    temp.fill(Qt::white);
    QPainter paint(&temp);
    paint.drawPixmap(temp.rect(), dessin, dessin.rect());
    temp.save(chemin_dessin, "PNG");
    dessin.save(chemin_calque, "PNG");

    QPixmap temp2(chemin_image_film.c_str());
    QPainter paint2(&temp2);
    paint2.drawPixmap(temp.rect(), dessin, dessin.rect());
    temp2.save(chemin_dessin_film.c_str(), "PNG");
}

QPixmap Draw::get_image(){
    return dessin;
}

void Draw::set_dessin(QPixmap image){
    dessin = image;
    setPixmap(dessin);
}

void Draw::undo(){
    for(int i = 0; i<historique.size(); i++){
        if(historique.at(i).is_point()){
            QPainter paint(&dessin);
            QPen crayon_temp(Qt::transparent);
            crayon_temp.setWidth(historique.at(i).get_taille());
            crayon_temp.setColor(Qt::transparent);
            crayon_temp.setCapStyle(Qt::RoundCap);

            paint.setCompositionMode(QPainter::CompositionMode_SourceIn);


            paint.setPen(crayon_temp);
            paint.drawPoint(historique.at(i).get_x(), historique.at(i).get_y());
            setPixmap(dessin);
        }
        else{

            QPainter paint(&dessin);
            QPen crayon_temp(Qt::transparent);
            crayon_temp.setWidth(historique.at(i).get_taille());
            crayon_temp.setColor(Qt::transparent);
            crayon_temp.setCapStyle(Qt::RoundCap);

            paint.setCompositionMode(QPainter::CompositionMode_SourceIn);
            paint.setPen(crayon_temp);

            paint.drawLine(historique.at(i).get_x(), historique.at(i).get_y(), historique.at(i).get_xx(), historique.at(i).get_yy());

            setPixmap(dessin);
        }
    }
    historique.clear();
}


