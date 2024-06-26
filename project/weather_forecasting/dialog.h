#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <fetch.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    Fetch<Ui::Dialog>* f;
};

#endif // DIALOG_H
