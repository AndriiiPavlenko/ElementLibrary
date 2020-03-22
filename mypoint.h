#ifndef MYPOINT_H
#define MYPOINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

/* Чтобы работали СЛОТЫ и СИГНАЛЫ, наследуемся от QOBJECT,
 * */
class MyPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MyPoint(QObject *parent = 0);
    ~MyPoint();

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
};

#endif // MYPOINT_H
