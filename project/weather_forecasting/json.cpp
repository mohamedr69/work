#include "json.h"

Json::Json()
{

}

QString Json::parseWeatherData(const QString &data,QString city){
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject obj = doc.object();
    QString cityName;
      QString weatherStr;
    if (obj.contains("current") && obj["current"].isObject()) {
      QJsonObject currentObj = obj["current"].toObject();
      double temperature = currentObj["temp_c"].toDouble();
      cityName = obj["name"].toString();
      QString condition = currentObj["condition"].toObject()["text"].toString();
      QJsonObject windObj = obj["wind"].toObject();
      double windSpeed = windObj["speed"].toDouble();
      double temperatureFahrenheit = temperature*9/5 + 32;
     }

    return cityName;

}
