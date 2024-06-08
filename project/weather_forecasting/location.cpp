#include "location.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>


#include <QPushButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Location::Location(QObject *parent):QObject(parent),manager(new QNetworkAccessManager){

}

Location::~Location(){
    delete manager;
}

QString Location::getMyCity(Ui::MainWindow* ui){
    QString apiUrl = "https://ipapi.co/json/";

    QNetworkRequest request(apiUrl);
    QNetworkReply *reply = Location::manager->get(request);

    QString responseData= reply->readAll();

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
          if (reply->error() == QNetworkReply::NoError) {
            QString responseData = reply->readAll();

            QString  s = parseData(responseData,ui);
            return s;
          } else {
            qDebug() << "Error fetching weather data: " << reply->errorString();
            ui->label_4->setText("No Internet Connection");

          }

          reply->deleteLater();

        });

    QString  s = "";
    return s;
}
QString Location::parseData(const QString &data,Ui::MainWindow* ui){
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject obj = doc.object();
    QString city = obj["city"].toString();
    ui->label_6->setText(city);
    return city;

}
