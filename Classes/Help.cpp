#include "Help.h"

Help::Help(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	// QTextCodec *codec = QTextCodec::codecForName("utf-8");	//��������
	// QTextCodec::setCodecForLocale(codec);
	ui.textBrowser->setText(QString::fromUtf8("help"));	// ��ʱ����д��ʾ����
}

Help::~Help()
{
}
