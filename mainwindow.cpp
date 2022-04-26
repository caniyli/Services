#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	networkRequest = new NetworkRequest;
	networkRequest->request("http://qt-project.org");
}

MainWindow::~MainWindow()
{
	delete ui;
}

