#ifndef NETWORK_H
#define NETWORK_H
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class Network
{
public:
    Network();
    QString API_Request( QString city,const QString &status);

private:
    QNetworkAccessManager *manager;
     std::string API_KEY;
     QString dataFetched;

};

#endif // NETWORK_H
