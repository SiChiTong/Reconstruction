#include "Reconstruction.h"

Reconstruction::Reconstruction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	this->setContentsMargins(0, 0, 0, 0);
	this->setFixedSize(1110, 580);
	ui.centralWidget->setGeometry(0, 40, 1110, 400);
	ui.centralWidget->show();

	/* �����on_XXX_clicked()����ۣ�Qt��Ԫ����QMetaObject���Զ���Ѱ����ص��źŲ����ӣ���������connect()�����ˣ�����ͻ��������Ρ�
	 connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	*/
	// qss
	QFile file("Resources/qss/lightindigo.qss");
	file.open(QFile::ReadOnly);
	QTextStream filetext(&file);
	QString stylesheet = filetext.readAll();
	this->setStyleSheet(stylesheet);
	this->setStyle(QStyleFactory::create("Fusion"));
	file.close();
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
	}else
	{
		calPath = fileName;
	}
}

// �������
void Reconstruction::on_pushButton_6_clicked()
{
	if(calPath.isEmpty())
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Haven't uploaded calibration pictures!");
	}else
	{
		// todo ������㣬�洢��Ƭ��
	}
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
	if (fileName.isEmpty())
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
	picPath = "Resources/image/test.png";		// ���н�������ʹ��	
	DisplayPic *picDlg = new DisplayPic();
	picDlg->setPicPath(picPath);
	connect(picDlg, SIGNAL(getPicAction(QString)), this, SLOT(setPicAction(QString)));
	picDlg->show();
}

void Reconstruction::setPicAction(QString action)
{
	if(action=="confirmed")
	{
		qDebug("confirmed");
		confirmPic = true;
	}else if(action=="canceled")
	{
		qDebug("canceled");
		confirmPic = false;
	}
}

// ������Ƭ
void Reconstruction::on_pushButton_10_clicked()
{
	// todo ������Ƭ
	if(confirmPic)
	{
		QString fileName = QFileDialog::getSaveFileName(this,
		tr("save image"),
		"",
		tr("*.png;; *.jpg;; *.bmp;; All files(*.*)"));

		if (!fileName.isNull())
		{
			QImage iim(picPath);//����һ��ͼƬ����,�洢ԴͼƬ
			QPainter painter(&iim);//���û滭�豸
			QFile file(fileName);//����һ���ļ����󣬴洢�û�ѡ����ļ�
			if (!file.open(QIODevice::ReadWrite)) {
					return;
			}
			QByteArray ba;
			QBuffer buffer(&ba);
			buffer.open(QIODevice::WriteOnly);
			iim.save(&buffer, "JPG");//��ͼƬ������ʽд���ļ���������
			file.write(ba);//�����е�ͼƬд���ļ�������
		}
	}else
	{
		QMessageBox mesg;
		mesg.warning(this, "WARNING", "Haven't taken picture!");
	}
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
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("save screen shot"),
		"",
		tr("*.png;; *.jpg;; *.bmp;; All files(*.*)"));

	if (!fileName.isNull())
	{
		// ��ͼ��ѡ�Ŀؼ���ʱ�� label_17 ���
		QPixmap pix = QPixmap::grabWidget(ui.label_17);
		pix.save(fileName);
	}
}

// ��ɫѡȡ
void Reconstruction::on_pushButton_16_clicked()
{
	color = QColorDialog::getColor(Qt::black);
	if (color.isValid()){
		// qDebug("x:%f, %f, %f",color.redF(), color.greenF(), color.blueF());
		// todo ��ɫѡȡ����ѡ����ɫcolor����������color���д���
	}
}
#pragma endregion
