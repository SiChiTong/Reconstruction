#include <QtWidgets/QApplication>
#include "Loading.h"
#include "Reconstruction.h"
#include <windows.h>

int main(int argc, char *argv[])
{
	AllocConsole();//�������̨
	freopen("CONOUT$", "w+t", stdout);//�����̨���
	QApplication a(argc, argv);
	Loading l;
	l.show();
	return a.exec();
}
