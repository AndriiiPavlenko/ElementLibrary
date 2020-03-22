#ifndef CREATLIB_H
#define CREATLIB_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>

#include <mypoint.h>


QT_BEGIN_NAMESPACE
namespace Ui { class CreatLib; }
QT_END_NAMESPACE

class CreatLib : public QMainWindow
{
    Q_OBJECT

public:
    CreatLib(QWidget *parent = nullptr);
    ~CreatLib();

private slots:
    void slotFromPoint();        // Слот для обработки сигнала из точки

private:
    Ui::CreatLib *ui;

    QGraphicsScene  *scene;      // Объявляем графическую сцену и Точку с которой будем работать
    MyPoint         *point;


};
#endif // CREATLIB_H
