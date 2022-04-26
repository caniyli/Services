#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QDebug>

class NetworkRequest : public QObject
{
	Q_OBJECT
public:
	explicit NetworkRequest(QObject *parent = nullptr);
	~NetworkRequest();
	//void request(const QUrl &url);
	void request(const QString &url);
	private slots:
	void replyFinished(QNetworkReply *reply);
	private:
	QNetworkAccessManager *manager;
	QJsonDocument json;


signals:

};

#endif // NETWORKREQUEST_H
