#ifndef ELEMTEXT_H
#define ELEMTEXT_H



#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <Type.h>


#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>


// Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
class ElemText : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ElemText(QObject *parent = 0, ElementText_type ElementText = {});
    ~ElemText();

signals:
    /* Сигнал, который будет посылаться в том случае,
     * если произошел клик мышью по объекту
     * */
    void signal1();

protected:
    /* Перегружаем метод нажатия мышью, для его перехвата
     * */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    /* Данные методы виртуальные, поэтому их необходимо реализовать
     * в случае наследования от QGraphicsItem
     * */
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    ElementText_type ElementText;
    void CreatText(QPainter *painter);                 // Создать тексты компонента

};

#endif // ELEMTEXT_H
