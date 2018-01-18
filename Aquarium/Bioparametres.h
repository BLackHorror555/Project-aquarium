#pragma once


struct Bioparametres
{
	//время жизни
	int planktonLifetime;
	int fishLifetime;
	int sharkLifetime;
	//период размножения
	int planktonReproductionPeriod;
	int fishReproductionPeriod;
	int sharkReproductionPeriod;
	//скорость передвижения
	float planktonSpeed;
	float fishSpeed;
	float sharkSpeed;
	//сколько может прожить без еды
	int fishHungerLifetime;
	int sharkHungerLifetime;
	//дистанция обзора
	int planktonViewDistance;
	int fishViewDistance;
	int sharkViewDistance;
	//расстояние, с которого хищник может броситься на жертву
	int fishEatingDistance;
	int sharkEatingDistance;
	//угол, на который может измениться направление движения за один тик при свободним движении 
	int planktonMoveRange;
	int fishMoveRange;
	int sharkMoveRange;
};

