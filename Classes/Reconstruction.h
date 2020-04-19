#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QBuffer>
#include <QTextStream>
#include <QStyleFactory>
#include "DisplayPic.h"
#include "ui_Reconstruction.h"
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/vtk_lib_io.h>
#include <vtkRenderWindow.h>
#include <QProgressDialog>
#include "MyThread.h"
using namespace pcl;
using namespace std;

class Reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);

private:
	Ui::ReconstructionClass ui;
	QString calPath;	// 系统标定：标定图像的存储路径
	QString picPath = "Result/result.png";	// 三维重建：拍摄照片的存储路径
	PointCloud<PointXYZRGB> cloud;
	bool confirmPic = false;	// 三维重建：确定是否用所拍照片进行重建
	QColor color = Qt::black;	// 点云渲染：颜色

	// 多线程
	MyThread* t;
	bool loadingStatus = false;		// 点云渲染
	void setStyle();
	void setPicStyle();
	void setButtonStyle();
	void updateQVTK(PointCloud<PointXYZRGB> cloud);

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();
	void on_pushButton_10_clicked();
	void on_pushButton_11_clicked();
	void on_pushButton_12_clicked();
	void on_pushButton_13_clicked();
	void on_pushButton_14_clicked();
	void on_pushButton_15_clicked();
	void on_pushButton_16_clicked();
	void on_pushButton_17_clicked();
	void setPicAction(QString action);
	void setCloud();
};
