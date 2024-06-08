#include "fetch.h"
#include <iostream>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>

#include <QPushButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>


Fetch::Fetch():manager(new QNetworkAccessManager){}

Fetch::~Fetch(){
    delete manager;
}

QString Fetch::fetchWeather( Ui::MainWindow* ui, QString city,const QString &status)
{
    //Ui::MainWindow *ui = MainWindow::getUI();


       /*if (ui->cityLineEdit->text() == "") {
         //city = "Cairo";
       } else {
         city = ui->cityLineEdit->text();
       }*/
       /*if(status == "YES"){
           city = ui->cityLineEdit->text();

       }else if(status == "NO"){

       }*/
    static int c = 0;

       std::string apiKey = "bc3db57652d5442eaae121936242805";
       QString apiUrl =
           "http://api.weatherapi.com/v1/"
           "current.json?key=bc3db57652d5442eaae121936242805&q=" +
           city;

        QNetworkRequest request(apiUrl);
        QNetworkReply *reply = Fetch::manager->get(request);

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
            dataFetched = parseWeatherData(responseData, ui, status, city);
            qDebug() << "1" << dataFetched;
        } else {
            // If there was an error during the network request
            qDebug() << "Error fetching weather data: " << reply->errorString();

            // Set an error message on a label
            ui->label_4->setText("No Internet Connection");
        }

        // Clean up the network reply object
        reply->deleteLater();
    return dataFetched;

 }



QString Fetch::parseWeatherData(const QString &data,Ui::MainWindow* ui,const QString &status,QString city) {
  QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
  QJsonObject obj = doc.object();
    QString weatherStr;
  if (obj.contains("current") && obj["current"].isObject()) {
    QJsonObject currentObj = obj["current"].toObject();
    double temperature = currentObj["temp_c"].toDouble();
    QString cityName = obj["name"].toString();
    QString condition = currentObj["condition"].toObject()["text"].toString();
    QJsonObject windObj = obj["wind"].toObject();
    double windSpeed = windObj["speed"].toDouble();
    double temperatureFahrenheit = temperature*9/5 + 32;

    if(ui->actionCelsius->isChecked()){

        weatherStr = QString("%1°C\n %2")
                                 .arg(temperature)
                                 .arg(condition);
    }else{
        weatherStr = QString("%1°F\n %2")
                                 .arg(temperatureFahrenheit)
                                 .arg(condition);
    }

    if(status == "YES"){
        if(condition == "Sunny"){
            ui->label_7->setStyleSheet("QLabel { background-image: url(:/img/images/sunny.jpg); background-color: transparent; color: black;}");
        }else{
            ui->label_7->setStyleSheet("QLabel { background-image: url(:/img/images/night.jpg); color:white;}");

        }
        ui->label_7->setText(city + "\n" + weatherStr);
        ui->label_7->setAlignment(Qt::AlignCenter); // Center-align the label text
    }else if(status == "NO"){
        if(condition == "Sunny"){
            ui->pushButton_2->setStyleSheet("QPushButton { background-image: url(:/img/images/sunny.jpg); color:black;}");
            ui->label_4->setStyleSheet("background-color: transparent; color: black;");
            ui->label_5->setStyleSheet("background-color: transparent; color: black;");
            ui->label_6->setStyleSheet("background-color: transparent; color: black;");
            //ui->label_4->setText(weatherStr);


        }else{
            ui->pushButton_2->setStyleSheet("QPushButton { background-image: url(:/img/images/night.jpg); color:white;}");
            ui->label_4->setStyleSheet("background-color: transparent; color: white;");
            ui->label_5->setStyleSheet("background-color: transparent; color: white;");
            ui->label_6->setStyleSheet("background-color: transparent; color: white;");
            ui->label_4->setText(weatherStr);


        }
        //ui->pushButton_2->setStyleSheet("QPushButton { background-image: url(:/img/images/night.jpg); }");
        ui->label_4->setText(weatherStr);
        ui->label_6->setText(city);

    }
    //ui->label_6->setText("n");
  } else {
    ui->label_4->setText("Weather data not available.");

  }
  //qDebug() << weatherStr;

  return weatherStr;
}
