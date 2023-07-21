#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

#include <QtCore>

void Dialog::startDownload()
{
    qDebug() << "starting";
    QString url = ui->txtURL->text();
    if(url.length() == 0){
        return;
    }

    manager->get(QNetworkRequest(QUrl(url)));
}

void Dialog::downloadCompleted(QNetworkReply *reply)
{
    qDebug() << "Download completed";
    qDebug()<< QString(reply->readAll());
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(ui->btnDownload, &QPushButton::clicked,
            this, &Dialog::startDownload, QT:);
    connect(manager, &QNetworkAccessManager::finished,
            this, &Dialog::downloadCompleted);
}

Dialog::~Dialog()
{
    delete ui;
}

