#ifndef ELEMENT_H
#define ELEMENT_H



#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPainter>
#include <Type.h>
#include "elemtext.h"





// Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
class Element : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit Element(QObject *parent = 0, Element_type ElementParam = {});
    ~Element();

signals:
    /* Сигнал, который будет посылаться в том случае,
     * если произошел клик мышью по объекту
     * */
    void signal1();

protected:
    /* Перегружаем метод нажатия мышью, для его перехвата
     * */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    /* Данные методы виртуальные, поэтому их необходимо реализовать
     * в случае наследования от QGraphicsItem
     * */
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;



    ElemText        *pElementText;



    Element_type ElementParam;
    void CreatText(QPainter *painter);                 // Создать тексты компонента

};

#endif // ELEMENT_H
