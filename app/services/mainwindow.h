#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "networkrequest.h"
#include "lib/3rdparty/json/json.hpp"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void Parser();

private:
	Ui::MainWindow *ui;
	NetworkRequest *networkRequest;
	nlohmann::json js;
};
#endif // MAINWINDOW_H
