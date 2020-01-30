#include "Reconstruction.h"
#include <QMessageBox>
#include <QFileDialog>

Reconstruction::Reconstruction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_7_clicked()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_8_clicked()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_9_clicked()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(on_pushButton_10_clicked()));
}

#pragma region ����궨��ť
void Reconstruction::on_pushButton_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void Reconstruction::on_pushButton_2_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}

void Reconstruction::on_pushButton_3_clicked()
{
	ui.stackedWidget->setCurrentIndex(2);
}

void Reconstruction::on_pushButton_5_clicked()
{
	// todo ���ͼ��
}

void Reconstruction::on_pushButton_6_clicked()
{
	// todo �������
}

void Reconstruction::on_pushButton_7_clicked()
{
	// todo ����궨
}

void Reconstruction::on_pushButton_8_clicked()
{
	// todo ������
}
#pragma endregion 

#pragma region ͼ��ͶӰ��ť
void Reconstruction::on_pushButton_4_clicked()
{
	// ѡ��ͶӰͼ�� todo ΪʲôҪѡ���Σ�
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open image file"),
		"./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

	if (fileName.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Failed to open picture");
		return;
	}

	ui.lineEdit->setText(fileName);

	// todo ���Ž���ͶӰ����
}
void Reconstruction::on_pushButton_9_clicked()
{
	// todo �������
}

void Reconstruction::on_pushButton_10_clicked()
{
	// todo ������Ƭ
}
#pragma endregion 

#pragma region ��ά�ؽ���ť
#pragma endregion 