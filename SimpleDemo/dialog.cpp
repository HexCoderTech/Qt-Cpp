#include "dialog.h"
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    layout = new QHBoxLayout();
    btn = new QPushButton("Ok");

    btn->setText("Cancel");
    layout->addWidget(btn);


    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete layout;
    delete btn;
}

