#ifndef TYPE_H
#define TYPE_H

#include <QPoint>
#include <QFont>


// Тип для хранения текста в компоненте
typedef struct{
    QPoint Coordinates;
    QFont Font;
    QString Text;
    bool Visible;
}ElementText_type;

// Структура описывающая
typedef struct{



    ElementText_type NameElemet;
}Element_type;




#endif // TYPE_H
