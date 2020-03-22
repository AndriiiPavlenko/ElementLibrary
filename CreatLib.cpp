#include "CreatLib.h"
#include "ui_CreatLib.h"

CreatLib::CreatLib(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreatLib)
{
    ui->setupUi(this);

    /* Инициализируем графическую сцену с точку с которой будем работать */
    scene = new QGraphicsScene();
    point = new MyPoint();

    /* Подключаем сигнал из точки к СЛОТу в главном классе */
    connect(point,SIGNAL(signal1()),this, SLOT(slotFromPoint()));

    /* Устанавливаем графическую сцену в виджет */
    ui->graphicsView->setScene(scene);
    scene->addItem(point);  // И добавляем на сцену точку

}

CreatLib::~CreatLib()
{
    delete ui;
}





void CreatLib::slotFromPoint()
{
   /*
    QMessageBox::information(this,
                             "Зафиксировано нажатие",
                             "Вы нажали на точку!!!"
                             "\n"
                             "\n"
                             "\n      С Уважением, Ваш КЭП!!!");
                             */
}
