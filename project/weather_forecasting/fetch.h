#ifndef FETCH_H
#define FETCH_H
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
class Fetch
{
public:
    Fetch();
    ~Fetch();
    QString fetchWeather(Ui::MainWindow*,QString city,const QString &status);
    QString parseWeatherData(const QString &data,Ui::MainWindow* ui,const QString &status,QString city);

private:
    QNetworkAccessManager *manager;
    QString dataFetched;
};

#endif // FETCH_H
