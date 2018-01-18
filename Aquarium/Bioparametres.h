#pragma once


struct Bioparametres
{
	//����� �����
	int planktonLifetime;
	int fishLifetime;
	int sharkLifetime;
	//������ �����������
	int planktonReproductionPeriod;
	int fishReproductionPeriod;
	int sharkReproductionPeriod;
	//�������� ������������
	float planktonSpeed;
	float fishSpeed;
	float sharkSpeed;
	//������� ����� ������� ��� ���
	int fishHungerLifetime;
	int sharkHungerLifetime;
	//��������� ������
	int planktonViewDistance;
	int fishViewDistance;
	int sharkViewDistance;
	//����������, � �������� ������ ����� ��������� �� ������
	int fishEatingDistance;
	int sharkEatingDistance;
	//����, �� ������� ����� ���������� ����������� �������� �� ���� ��� ��� ��������� �������� 
	int planktonMoveRange;
	int fishMoveRange;
	int sharkMoveRange;
};

