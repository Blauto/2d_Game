#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game;

class Ball
{
public:
	friend class PaddleStick;
	friend class BallManager;
	Ball(Game * ga, float argX, float argY);
	Ball(Game * ga, float argX, float argY, sf::Vector2f dir);
	~Ball() = default;

	sf::Color color{ 255, 255, 255 };
	sf::CircleShape ball;
	void update(const float &DeltaTime);
	void Draw(sf::RenderWindow & window);
	float velocity{ 365 };
	float velocityBonus{ 0 };
	sf::Vector2f direction{ 1.0f, -1.0f};
	void speedAccelerate(float bonusVelocity); // o ile procent przy�pieszy� pi�k
private:
	bool stick{ false }; //czy kulka si� przyklei�a
	bool sticky{ false }; // czy mo�e si� przylei� 
	float stickDiference{ 0.0f };
	float stickBallPositionY{ 0 };
	void checkColisionWitchSlab();
	float radius{ 7 };
	Game * game;
};

