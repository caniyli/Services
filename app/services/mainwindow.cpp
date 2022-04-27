#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	networkRequest = new NetworkRequest;
	networkRequest->request("http://10.5.5.0:30555/v1/agent/services");
	connect(networkRequest, &NetworkRequest::finished, this,
			&MainWindow::Parser);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::Parser(QByteArray &data)
{
	QMap<QString, QVector<QString>> datas;
	       js = nlohmann::json::parse(data);
	for (nlohmann::json::iterator it = js.begin(); it != js.end(); ++it) {
		nlohmann::json a = it.value();
		QString ip = QString::fromStdString(a["Address"]);
		QString serviceName = QString::fromStdString(a["Service"]);
		if (!datas[ip].contains(serviceName))
			datas[ip].append(serviceName);
	}
	for (int i = 0; i < datas.keys().size(); ++i) {
		qDebug() << "----";
		qDebug() << datas.keys()[i] << datas[datas.keys()[i]];
	}
}
