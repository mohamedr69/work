#include "network.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QEventLoop>
#include <QPushButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
Network::Network():manager(new QNetworkAccessManager)
{

}


QString Network::API_Request( QString city,const QString &status){

        static int c = 0;

       std::string apiKey = "bc3db57652d5442eaae121936242805";
       QString apiUrl =
           "http://api.weatherapi.com/v1/"
           "current.json?key=bc3db57652d5442eaae121936242805&q=" +
           city;

        QNetworkRequest request(apiUrl);
        QNetworkReply *reply = Network::manager->get(request);

        QString responseData= reply->readAll();

        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        if (reply->error() == QNetworkReply::NoError) {
            // If there was no error during the network request
            qDebug() << ++c; // Increment and print the value of `c`

            // Read the response data
            QString responseData = reply->readAll();

            // Parse the weather data and store the result in `dataFetched`
            //dataFetched = parseWeatherData(responseData, status, city);
            qDebug() << "1" << dataFetched;
        } else {
            // If there was an error during the network request
            qDebug() << "Error fetching weather data: " << reply->errorString();

            // Set an error message on a label
        }

        // Clean up the network reply object
        reply->deleteLater();
        return dataFetched;
}
