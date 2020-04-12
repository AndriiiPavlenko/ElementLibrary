#include "Element.h"

Element::Element(QObject *parent, Element_type ElementParam) : QObject(parent), QGraphicsItemGroup()
{

    this->ElementParam = ElementParam;

    ElementText_type Text;
    Text.Text = "Я Текст!!!!";
    Text.Coordinates = QPoint(0, 0);
    pElementText = new ElemText(this, Text);
    pElementText->setFlags(QGraphicsItem::ItemIsMovable);// передается значение QGraphicsitem:: ItemisMovaЫe.
    this->addToGroup(pElementText);

    ElementText_type Text1;
    Text1.Text = "Я Текст1";
    Text1.Coordinates = QPoint(100, 100);
    pElementText = new ElemText(this, Text1);
    pElementText->setFlags(QGraphicsItem::ItemIsMovable);
    this->addToGroup(pElementText);

    ElementText_type Text2;
    Text2.Text = "Я Текст2";
    Text2.Coordinates = QPoint(200, 200);
    pElementText = new ElemText(this, Text2);
    pElementText->setFlags(QGraphicsItem::ItemIsMovable);
    this->addToGroup(pElementText);
}

// Деструктор
Element::~Element(){

}

QRectF Element::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(-20, -20, 300, 300);
}

// Нарисовать компонент
void Element::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//     QPen pen;  // создаёт перо по умолчанию

 //    pen.setStyle(Qt::SolidLine);               // Сплошная линия
 //    pen.setWidth(3);                           // Толщина линии
 //    pen.setBrush(Qt::black);                   // Цвет
 //    pen.setCapStyle(Qt::FlatCap);
 //    pen.setJoinStyle(Qt::RoundJoin);
 //    painter->setPen(pen);

 //    painter->drawLine(0, 0, 200, 200);

 //    painter->drawText(0, 100, "Просто текст");

//   CreatText(painter);

//     QPoint Point(10, 36);
//     QFont font = painter->font();




         //font.is


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
void Element::CreatText(QPainter *painter){                 // Создать тексты компонента

    // Имя компонента
    if(ElementParam.NameElemet.Visible == true){            // Отобразить текст если это нужно
        painter->drawText(ElementParam.NameElemet.Coordinates, ElementParam.NameElemet.Text);
        painter->setFont(ElementParam.NameElemet.Font);
    }

}





/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
void Element::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signal1();
    // Вызываем родительскую функцию события нажатия кнопки мыши
    QGraphicsItem::mousePressEvent(event);
}
