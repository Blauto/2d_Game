#pragma once
#include "stdafx.h"

class Game;
class Slab;

class SlabMenager
{
public:
	SlabMenager(Game * ga);
	~SlabMenager() = default;
	void generateNewLvl();
	void update(float DeltaTime);
	void addSlab(float argX, float argY, int live);
	int rowCount;
	float topDistance{ 150.0f };
	float slabSpace{ 5.0f };
	sf::Vector2f checkColision(sf::CircleShape &ball);
	mutable std::list<Slab>::iterator it;
private:
	std::list<Slab> slabList;
	Game * game;
	float respawnDelay{ 3.0f }; //inSec
	float deltaTimer{ 0.0f };
};

