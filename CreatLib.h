#ifndef CREATLIB_H
#define CREATLIB_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>

#include "Element.h"
#include "elemtext.h"


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
    Element         *pElement;
    ElemText        *pElementText;
    //ElemText        *pElementText1;
    //ElemText        *pElementText2;

};
#endif // CREATLIB_H
