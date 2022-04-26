#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	networkRequest = new NetworkRequest;
	networkRequest->request("http://10.5.5.0:30555/v1/agent/services");
	connect(networkRequest, &NetworkRequest::finished,this,&MainWindow::Parser);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::Parser()
{

	js = nlohmann::json::parse(networkRequest->getData().toStdString());
	for (nlohmann::json::iterator it = js.begin(); it != js.end(); ++it) {
		//std::cout << *it << std::endl << std::endl;
		nlohmann::json a = it.value();
		std::cout << a["Address"] << "                ";
		std::cout << a["Service"] << std::endl << std::endl;
	}
}

