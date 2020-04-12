#include "CreatLib.h"
#include "ui_CreatLib.h"

CreatLib::CreatLib(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreatLib)
{
    ui->setupUi(this);

    /* Инициализируем графическую сцену с точку с которой будем работать */
    scene = new QGraphicsScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов


    Element_type  ElementTest;
    ElementTest.NameElemet.Visible = true;
    ElementTest.NameElemet.Text = "Test";
    ElementTest.NameElemet.Coordinates = QPoint(0, 0);
    pElement = new Element(this, ElementTest);

    //connect(point,SIGNAL(signal1()),this, SLOT(slotFromPoint()));                     // Подключаем сигнал из точки к СЛОТу в главном классе

    ElementText_type Text;
    Text.Text = "Я Текст!!!!";
    Text.Coordinates = QPoint(0, 0);
    pElementText = new ElemText(this, Text);

/*
    ElementText_type Text1;
    Text1.Text = "Я Текст1";
    Text1.Coordinates = QPoint(100, 100);
    pElementText1 = new ElemText(this, Text1);


    ElementText_type Text2;
    Text2.Text = "Я Текст2";
    Text2.Coordinates = QPoint(200, 200);
    pElementText2 = new ElemText(this, Text2);
*/



pElement->setFlags(QGraphicsItem::ItemIsMovable);

//pElementText->setFlags(QGraphicsItem::ItemIsMovable);
//pElementText->setFlag(QGraphicsItem::ItemIsMovable, true);
  //  pElementText->setFlag(QGraphicsItem::ItemIsSelectable, true);


    // Устанавливаем графическую сцену в виджет
    ui->graphicsView->setScene(scene);
   // ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    scene->addItem(pElement);  // И добавляем на сцену Текст
    //scene->addItem(pElementText1);  // И добавляем на сцену Текст
    //scene->addItem(pElementText2);  // И добавляем на сцену Текст






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
