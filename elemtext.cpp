#include "elemtext.h"

ElemText::ElemText(QObject *parent, ElementText_type ElementText) : QObject(parent), QGraphicsItem()
{

    this->ElementText = ElementText;


}

// Деструктор
ElemText::~ElemText(){

}

QRectF ElemText::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(-50, -50, 120, 120);
}

// Нарисовать компонент
void ElemText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;  // создаёт перо по умолчанию

     pen.setStyle(Qt::SolidLine);               // Сплошная линия
     pen.setWidth(3);                           // Толщина линии
     pen.setBrush(Qt::black);                   // Цвет
     pen.setCapStyle(Qt::FlatCap);
     pen.setJoinStyle(Qt::RoundJoin);
     painter->setPen(pen);

     painter->drawText(ElementText.Coordinates, ElementText.Text);


    //QPolygon polygon;   // Используем класс полигона, чтобы отрисовать треугольник
    // Помещаем координаты точек в полигональную модель
    //polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
    //painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
    //painter->drawPolygon(polygon);  // Рисуем треугольник по полигональной модели
    //painter->set
    //painter->drawLine(0, 0, 100, 100);


    // Устанавливаем кисть в QPainter и отрисовываем круг, то есть ТОЧКУ
    //painter->setBrush(Qt::black);
    //painter->drawEllipse(QRectF(0, 0, 100, 100));
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

// Создать тексты компонента
void ElemText::CreatText(QPainter *painter){                 // Создать тексты компонента

    // Имя компонента
   // if(ElementParam.NameElemet.Visible == true){            // Отобразить текст если это нужно
   //     painter->drawText(ElementParam.NameElemet.Coordinates, ElementParam.NameElemet.Text);
   //     painter->setFont(ElementParam.NameElemet.Font);
   // }

}





void ElemText::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void ElemText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void ElemText::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

