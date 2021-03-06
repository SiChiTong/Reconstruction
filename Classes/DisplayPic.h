#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include "ui_DisplayPic.h"

class DisplayPic : public QWidget
{
	Q_OBJECT

public:
	DisplayPic(QWidget *parent = Q_NULLPTR);
	~DisplayPic();
	void setPicPath(QString pic);

private:
	Ui::DisplayPic ui;
	QString picUrl;

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

signals:
	void getPicAction(QString action);
};
