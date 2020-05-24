#include "HisThread.h"

HisThread::HisThread(PointCloud<PointXYZRGB>* cloudArg, PolygonMesh* meshArg)
{
	mesh = meshArg;
	cloud = cloudArg;
}

void HisThread::run()
{
	PointCloud<PointXYZRGB>::Ptr finalCloud = cloud->makeShared();
	NormalEstimation<PointXYZRGB, Normal> n;//���߹��ƶ���
	PointCloud<Normal>::Ptr normals(new PointCloud<Normal>);//�洢���Ƶķ��ߵ�ָ��
	search::KdTree<PointXYZRGB>::Ptr tree(new search::KdTree<PointXYZRGB>);
	tree->setInputCloud(finalCloud);
	n.setInputCloud(finalCloud);
	n.setSearchMethod(tree);
	n.setKSearch(20);
	n.compute(*normals); //���㷨�ߣ�����洢��normals��

	//�����ƺͷ��߷ŵ�һ��
	PointCloud<PointXYZRGBNormal>::Ptr cloud_with_normals(new PointCloud<PointXYZRGBNormal>);
	concatenateFields(*finalCloud, *normals, *cloud_with_normals);

	//����������
	search::KdTree<PointXYZRGBNormal>::Ptr tree2(new search::KdTree<PointXYZRGBNormal>);
	tree2->setInputCloud(cloud_with_normals);
	//����Poisson���󣬲����ò���
	Poisson<PointXYZRGBNormal> pn;
	pn.setConfidence(true); //�Ƿ�ʹ�÷������Ĵ�С��Ϊ������Ϣ�����false�����з���������һ����
	pn.setDegree(2); //���ò���degree[1,5],ֵԽ��Խ��ϸ����ʱԽ�á�
	pn.setDepth(8); //���������ȣ����2^d x 2^d x 2^d������Ԫ�����ڰ˲�������Ӧ�����ܶȣ�ָ��ֵ��Ϊ�����ȡ�
	pn.setIsoDivide(8); //������ȡISO��ֵ����㷨�����
	pn.setManifold(true); //�Ƿ���Ӷ���ε����ģ�����������ǻ�ʱ�� �������б�־���������Ϊtrue����Զ���ν���ϸ�����ǻ�ʱ������ģ�����false�����
	pn.setManifold(false);
	pn.setOutputPolygons(false); //�Ƿ������������񣨶��������ǻ��ƶ�������Ľ����
	//pn.setSamplesPerNode(3.0); //��������һ���˲�������е����������С��������������[1.0-5.0],������[15.-20.]ƽ��
	pn.setSamplesPerNode(18); //��������һ���˲�������е����������С��������������[1.0-5.0],������[15.-20.]ƽ��
	pn.setScale(1.25); //���������ع���������ֱ���������߽�������ֱ���ı��ʡ�
	pn.setSolverDivide(8); //����������Է������Gauss-Seidel�������������
	//pn.setIndices();

	//���������������������
	pn.setSearchMethod(tree2);
	pn.setInputCloud(cloud_with_normals);
	
	//ִ���ع�
	pn.performReconstruction(*mesh);
	// auto pclData = PointCloudData::getInstance(cloud);
	// pclData->getViewer()->removeAllPointClouds();
	// pclData->getViewer()->addPolygonMesh(mesh, "my");

}
