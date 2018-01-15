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
	int planktonSpeed;
	int fishSpeed;
	int sharkSpeed;
	//������� ����� ������� ��� ���
	int fishHungerLifetime;
	int sharkHungerLifetime;
	//��������� ������
	int planktonViewDistance;
	int fishViewDistance;
	int sharkViewDistance;
	//����������, � �������� ������ ����� ��������� �� ������
	int fishEatingDistance;
	int sharkEatingDistanse;
	//����, �� ������� ����� ���������� ����������� �������� �� ���� ��� ��� ��������� �������� 
	int planktonMoveRange;
	int fishMoveRange;
	int sharkMoveRange;
};

