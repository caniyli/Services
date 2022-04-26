#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QUrl>

class NetworkRequest : public QObject
{
	Q_OBJECT
public:
	explicit NetworkRequest(QObject *parent = nullptr);
	~NetworkRequest();
	void request(const QString &url);
	const QByteArray &getData() const;
	void setData(const QByteArray &newData);

private slots:
	void replyFinished(QNetworkReply *reply);

private:
	QNetworkAccessManager *manager;
	QByteArray data;

signals:
	void finished();
};

#endif // NETWORKREQUEST_H
