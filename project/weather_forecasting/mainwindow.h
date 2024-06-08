#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <memory>
#include <fetch.h>
#include "location.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setSearchData(QString);
    void Update();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionCelsius_triggered();

    void on_actionFehrenheit_triggered();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void innerButtonClicked();

private:
    Ui::MainWindow *ui;
    Fetch *f;
    Location *l;
    QTimer *timer;
    QString city;
    QVector<QPushButton*> buttons;
    //QVector<std::unique_ptr<QPushButton>> buttons;// Vector to store QPushButton pointers
    QVBoxLayout *containerLayout;
    QString searchData;
    QString searchCity;
};
#endif // MAINWINDOW_H
