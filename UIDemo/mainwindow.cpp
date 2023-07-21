#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui =new Ui::MainWindow();
    ui->setupUi(this);

    ui->input->setFont(QFont("Times New Roman", 50));

    connect(ui->input, &QLineEdit::textChanged, ui->output, &QLabel::setText);
    connect(ui->input, &QLineEdit::textChanged, this, &MainWindow::setLength);
    connect(this, &MainWindow::customSignal, this, &MainWindow::customSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLength(QString text){
    int s = text.length();
    if (s >= 10){
        emit this->customSignal(text);
    }

}

void MainWindow::customSlot(QString text){
    ui->finalOutput->setText(QString::number(text.length()));
}

