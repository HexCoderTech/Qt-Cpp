#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets>
#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QHBoxLayout *layout;
    QPushButton* btn;
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
