/*
 * Game engine class
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



class Game
{
private:

	//Variables
	float paddleXVelocity = 10;
	float paddleYVelocity = 10;

	float ballXVelocity = 5;
	float ballYVelocity = 5;

	int brickGridx[8][12];
	int brickGridy[8][12];

	float dt;
	float multiplier = 200.f;


	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock clock;



	//Game objects
	sf::RectangleShape paddle;
	sf::Vector2f paddlePosition;

	sf::CircleShape ball;
	sf::Vector2f ballPosition;

	sf::RectangleShape brick;


	//Private function
	void initVariables();
	void initGridMatrix();
	void initWindow();
	void initPaddle();
	void movePaddleleft();
	void movePaddleright();
	void initBall();
	void moveBall();
	void initBrick(int x_pos, int y_pos);
	void renderBricks();


public:

	//Variables
	bool start = false;
	bool ballStart = true;


	//Contructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};

#endif /* GAME_H_ */
