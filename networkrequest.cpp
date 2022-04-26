#include "networkrequest.h"

NetworkRequest::NetworkRequest(QObject *parent)
	: QObject{parent}
{

}

NetworkRequest::~NetworkRequest()
{
	delete manager;
}

void NetworkRequest::request(const QString &url)
{
	QUrl qrl(url);//QUrl has network adress
	  manager = new QNetworkAccessManager(this);//create manager
	  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));//do connection with nededed signal and slot which we alredy wrote
	  manager->get(QNetworkRequest(qrl));//send get request
}

void NetworkRequest::replyFinished(QNetworkReply *reply)
{
	qDebug() << reply->readAll();
}
