#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qApp->setStyle("fusion");

    ui->setupUi(this);

    ui->widget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    ui->widget->setMaximumHeight(800);
    ui->widget->setMaximumWidth(1000);

    QRect screenSize = centralWidget()->setGeometry(this);
    this->setFixedSize(QSize(screenSize.width() * 0.7, screenSize.height() * 0.7));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::connectToSlider(QRoundProgressBar *bar)
//{
//    //    bar->setRange(ui->Slider->minimum(), ui->Slider->maximum());
//    //    bar->setValue(ui->Slider->value());
//    //    connect(ui->Slider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
//}




