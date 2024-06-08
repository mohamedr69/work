#include "dialog.h"
#include "ui_dialog.h"
#include <fetch.h>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
  f(new Fetch<Ui::Dialog>)
{
    ui->setupUi(this);
    ui->label_4->setText("Loading....");
    f->fetchWeather(ui,"");
}

Dialog::~Dialog()
{
    delete ui;
}
