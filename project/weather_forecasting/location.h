#ifndef LOCATION_H
#define LOCATION_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QDebug>
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class Location : public QObject
{
public:

    ~Location();

    Location(QObject *parent = nullptr);

    QString getMyCity(Ui::MainWindow* ui);

    QString parseData(const QString &data,Ui::MainWindow* ui);


private:
    QNetworkAccessManager *manager;
};

#endif // LOCATION_H
