#include "Reconstruction.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>

Reconstruction::Reconstruction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	/* �����on_XXX_clicked()����ۣ�Qt��Ԫ����QMetaObject���Զ���Ѱ����ص��źŲ����ӣ���������connect()�����ˣ�����ͻ��������Ρ�
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
	 connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(on_pushButton_11_clicked()));
	 connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushButton_12_clicked()));
	 connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(on_pushButton_13_clicked()));
	 connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(on_pushButton_14_clicked()));
	 connect(ui.pushButton_15, SIGNAL(clicked()), this, SLOT(on_pushButton_15_clicked()));
	 connect(ui.pushButton_16, SIGNAL(clicked()), this, SLOT(on_pushButton_16_clicked()));
	*/
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
	// ���ͼ��
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open multiple image file"),
		"./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));		// todo �ļ����ʹ�ȷ��

	if (fileName.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Failed to open picture");
		return;
	}

	// todo ���ļ��洢��ĳ������
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
	// ѡ��ͶӰͼ��
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
void Reconstruction::on_pushButton_11_clicked()
{
	// todo �쳣��ѡ��
}

void Reconstruction::on_pushButton_12_clicked()
{
	// todo �쳣���޳�
}

void Reconstruction::on_pushButton_13_clicked()
{
	// todo �������
}

void Reconstruction::on_pushButton_14_clicked()
{
	// todo �������
}

void Reconstruction::on_pushButton_15_clicked()
{
	// todo �����ͼ
}

void Reconstruction::on_pushButton_16_clicked()
{
	// ��ɫѡȡ
	QColor color = QColorDialog::getColor(Qt::black);
	if (color.isValid()){
		// qDebug("x:%f, %f, %f",color.redF(), color.greenF(), color.blueF());
		// todo ��ɫѡȡ����ѡ����ɫcolor����������color���д���
	}
}
#pragma endregion 