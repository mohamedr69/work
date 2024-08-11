#ifndef JSON_H
#define JSON_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>


class Json
{
public:
    Json();

    QString parseWeatherData(const QString &data,QString city);
};

#endif // JSON_H
