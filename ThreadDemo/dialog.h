#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void startDownload();
    void downloadCompleted(QNetworkReply *reply);

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QNetworkAccessManager *manager;
};
#endif // DIALOG_H
