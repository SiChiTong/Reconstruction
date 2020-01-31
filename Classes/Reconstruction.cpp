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

#pragma region ����˵�
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
#pragma endregion 

#pragma region ����궨-��ť

// ���ͼ��
void Reconstruction::on_pushButton_5_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open multiple image file"),
		"./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));		// todo �ļ����ʹ�ȷ��

	if (fileName.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Failed to open picture");
		return;
	}

	// todo �洢�ļ����ļ�·��
}

// �������
void Reconstruction::on_pushButton_6_clicked()
{
	// todo ������㣬�洢��Ƭ��

	// �궨��־����ʾ������Ƭ���洢·��
	ui.textBrowser_7->append("");
}

// ����궨
void Reconstruction::on_pushButton_7_clicked()
{
	int size = ui.spinBox->value();
	int row = ui.spinBox_2->value();
	int col = ui.spinBox_3->value();
	// todo ����궨


	// �������������ʾ�궨���
	ui.textBrowser->append("");
	ui.textBrowser_2->append("");
	ui.textBrowser_3->append("");
	ui.textBrowser_4->append("");
	ui.textBrowser_5->append("");
	ui.textBrowser_6->append("");
}

// ������
void Reconstruction::on_pushButton_8_clicked()
{
	QFileDialog fileDialog;
	QString fileName = fileDialog.getSaveFileName(this, "Open File", "", "Text File(*.txt)");	// todo �����ļ�����
	if (fileName == "")
	{
		return;
	}
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))	// todo �����ļ�����
	{
		QMessageBox::warning(this, "error", "open file failure!");
		return;
	}
	else
	{
		// todo ������
	}
}
#pragma endregion 

#pragma region ͼ��ͶӰ-��ť

// ѡ���ļ�
void Reconstruction::on_pushButton_4_clicked()
{
	// ѡ��ͶӰͼ��
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open image file"),
		"./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));	

	if (fileName.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Failed to open file");
		return;
	}

	ui.lineEdit->setText(fileName);

	// todo ���Ž���ͶӰ����
}

// �������
void Reconstruction::on_pushButton_9_clicked()
{
	// todo �������

	// todo Ȼ�����һ������ ���㵽����Ƭ��Ȼ������������ť��ȷ�� ȡ��
}

// ������Ƭ
void Reconstruction::on_pushButton_10_clicked()
{
	// todo ������Ƭ
}
#pragma endregion 

#pragma region ��ά�ؽ�-��ť

// �쳣��ѡ��
void Reconstruction::on_pushButton_11_clicked()
{
	// todo �쳣��ѡ��
}

// �쳣���޳�
void Reconstruction::on_pushButton_12_clicked()
{
	// todo �쳣���޳�
}

// �������
void Reconstruction::on_pushButton_13_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open multiple image file"),
		"./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));		// todo �ļ����ʹ�ȷ��

	if (fileName.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Failed to open file");
		return;
	}

	// todo �洢�ļ����ļ�·��
}

// �������
void Reconstruction::on_pushButton_14_clicked()
{
	// todo �������
}

// �����ͼ
void Reconstruction::on_pushButton_15_clicked()
{
	// todo �����ͼ
}

// ��ɫѡȡ
void Reconstruction::on_pushButton_16_clicked()
{
	QColor color = QColorDialog::getColor(Qt::black);
	if (color.isValid()){
		// qDebug("x:%f, %f, %f",color.redF(), color.greenF(), color.blueF());
		// todo ��ɫѡȡ����ѡ����ɫcolor����������color���д���
	}
}
#pragma endregion
