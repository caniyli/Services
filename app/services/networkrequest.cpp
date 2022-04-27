#include "networkrequest.h"
#include <iostream>
NetworkRequest::NetworkRequest(QObject *parent) : QObject {parent}
{
}

NetworkRequest::~NetworkRequest()
{
	delete manager;
}

void NetworkRequest::request(const QString &url)
{
	QUrl qrl(url);							   // QUrl has network adress
	manager = new QNetworkAccessManager(this); // create manager
	connect(manager, SIGNAL(finished(QNetworkReply *)), this,
			SLOT(replyFinished(
				QNetworkReply *))); // do connection with nededed signal and
									// slot which we alredy wrote
	manager->get(QNetworkRequest(qrl)); // send get request
}

void NetworkRequest::replyFinished(QNetworkReply *reply)
{
	data = reply->readAll();
	emit finished(data);
}

const QByteArray &NetworkRequest::getData() const
{
	return data;
}

void NetworkRequest::setData(const QByteArray &newData)
{
	data = newData;
}
