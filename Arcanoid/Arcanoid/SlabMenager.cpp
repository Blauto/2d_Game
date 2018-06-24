#include "SlabMenager.h"
#include "stdafx.h"

SlabMenager::SlabMenager(Game * ga)
{
	game = ga;
	generateNewLvl();
}

void SlabMenager::generateNewLvl()
{
	float center = game->windowMode.width / 2;
	float toCenterDistance = 0;
	float fromTopDistance = topDistance;
	Slab exampleSlab(0, 0, 1);
	float pointDistanceHorizontal = slabSpace + exampleSlab.getWidth();
	float pointDistanceVertical = slabSpace + exampleSlab.getHeight();
	Slab* newSlab = nullptr;

	rowCount = (std::rand() % 6) + 2;

	for (int i = 0; i < rowCount; i++) {

		while (true) {

			if (center + toCenterDistance + exampleSlab.getWidth() > game->windowMode.width)
				break;
			int slabType = (std::rand() % 4);
			toCenterDistance += pointDistanceHorizontal;
			
			if (slabType != 0) {

				addSlab(center + toCenterDistance, fromTopDistance, slabType);

				addSlab(center - toCenterDistance, fromTopDistance, slabType);
			}
		}

		toCenterDistance = 0;
		fromTopDistance += exampleSlab.getHeight() + slabSpace;
	}
}

void SlabMenager::update(float DeltaTime)
{

	if (slabList.empty()) {

		if (deltaTimer > respawnDelay) {
			deltaTimer = 0;
			game->ballList.clear();
			game->respawnBall();
			generateNewLvl();
	
			game->refreshTextCounter();
		}
		else {
			deltaTimer += DeltaTime;
			game->window.draw(game->lvlText);
		}
	}


	for (it = slabList.begin(); it != slabList.end(); it++) {

		it->Draw(game->window);
	}
}

void SlabMenager::addSlab(float argX, float argY, int live)
{
	Slab *newSlab = new Slab(argX, argY, live);

	slabList.push_back(*newSlab);
}

sf::Vector2f SlabMenager::checkColision(sf::CircleShape & ball)
{
	for (it = slabList.begin(); it != slabList.end(); it++) {

		if (ball.getGlobalBounds().intersects(it->slab.getGlobalBounds())) {

			sf::Vector2f slabPosPom = it->slab.getPosition();

			it->removeLive();
			if (it->live < 1) {
				slabList.erase(it++);
				game->playerPoints += 50;
			}


			return slabPosPom;
		}
	}
	return sf::Vector2f(0.0f, 0.0f);
}