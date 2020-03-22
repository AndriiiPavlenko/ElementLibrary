#include "mypoint.h"

MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

MyPoint::~MyPoint()
{

}

QRectF MyPoint::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(0,0,100,100);
}

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     QPen pen;  // создаёт перо по умолчанию

     pen.setStyle(Qt::SolidLine);               // Сплошная линия
     pen.setWidth(3);                           // Толщина линии
     pen.setBrush(Qt::green);                   // Цвет
     pen.setCapStyle(Qt::FlatCap);
     pen.setJoinStyle(Qt::RoundJoin);
     painter->setPen(pen);

     painter->drawLine(0, 0, 100, 100);



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

/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signal1();
    // Вызываем родительскую функцию события нажатия кнопки мыши
    QGraphicsItem::mousePressEvent(event);
}
