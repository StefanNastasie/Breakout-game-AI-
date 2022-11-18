/*
 * Game.cpp
 */

#include "Game.h"


//Private functions
void Game::initVariables()
{
	this -> window = nullptr;
}

void Game::initGridMatrix()
{
	for(int i = 0; i < 8; i++)
	{
		int c = 20;

		for(int j = 0; j < 12; j++)
		{
			brickGridx[i][j] = c;
			c += 50;
		}
	}

	int c = 20;

	for(int i = 0; i < 8; i++)
		{

			for(int j = 0; j < 12; j++)
			{
				brickGridy[i][j] = c;

			}
			c += 15;
		}
}

void Game::initWindow()
{
	this -> videoMode.height = 480;
	this -> videoMode.width = 640;
	this -> window = new sf::RenderWindow(this -> videoMode, "BipBop", sf::Style::Titlebar | sf::Style::Close);
	this -> window -> setFramerateLimit(60);
}

void Game::initBrick(int x_pos, int y_pos)
{
		this -> brick.setPosition(x_pos, y_pos);
		this -> brick.setSize(sf::Vector2f(40.f, 10.f));
		this -> brick.setFillColor(sf::Color::Green);
		this -> brick.setOutlineColor(sf::Color::White);
		this -> brick.setOutlineThickness(1.f);



}

void Game::renderBricks()
{
	for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 12; j++)
			{
				initBrick(brickGridx[i][j], brickGridy[i][j]);
				this -> window -> draw(brick);
			}
		}
}

void Game::initPaddle()
{
	this -> paddle.setPosition(260.f, 440.f);
	this -> paddle.setSize(sf::Vector2f(120.f, 20.f));
	this -> paddle.setFillColor(sf::Color::White);
	this -> paddle.setOutlineColor(sf::Color::Red);
	this -> paddle.setOutlineThickness(1.f);
	this -> paddlePosition.x = 260;
	this -> paddlePosition.y = 440;

}

void Game::movePaddleleft()
{
	//this -> paddlePosition.y = 440;
	this -> paddlePosition.x -= this -> paddleXVelocity;
	//this -> paddlePosition.x *= this -> dt;
	//this -> paddlePosition.x *= this -> multiplier;


	if(this -> paddlePosition.x > 0){
		this -> paddle.setPosition(this -> paddlePosition);
	}
	else{
		this -> paddlePosition.x = 0;
		this -> paddle.setPosition(this -> paddlePosition);
	}
}

void Game::movePaddleright()
{
	//this -> paddlePosition.y = 440;
	this -> paddlePosition.x += this -> paddleXVelocity;
	//this -> paddlePosition.x *= this -> dt;
	//this -> paddlePosition.x *= this -> multiplier;


	if( this -> paddlePosition.x < 520){
		this -> paddle.setPosition(this -> paddlePosition);
	}
	else{
			this -> paddlePosition.x = 520;
			this -> paddle.setPosition(this -> paddlePosition);
	}
}

void Game::initBall()
{
		this -> ball.setPosition(310.f, 415.f);
		this -> ball.setRadius(10);
		this -> ball.setFillColor(sf::Color::Cyan);
		this -> ball.setOutlineColor(sf::Color::White);
		this -> ball.setOutlineThickness(1.f);
		this -> ballPosition.x = 310;
		this -> ballPosition.y = 415;

}

void Game::moveBall()
{
	if(start)
	{



		if(this -> ballPosition.x < 0 || ballPosition.x > 620){

			this -> ballXVelocity *= -1;
		}

		if(this -> ballPosition.y < 0 || ballPosition.y > 470){

					this -> ballYVelocity *= -1;
		}

		if((this -> ballPosition.y == this -> paddlePosition.y - 20) &&
		   (this -> ballPosition.x >= this -> paddlePosition.x && ballPosition.x < this -> paddlePosition.x + 120)){

					this -> ballYVelocity *= -1;
		}







		this -> ballPosition.x += this -> ballXVelocity;
		this -> ballPosition.y += this -> ballYVelocity;
		this -> ball.setPosition(this -> ballPosition);

		}

		//this -> ballPosition.x *= this -> dt;
		//this -> ballPosition.x *= this -> multiplier;



		//this -> ballPosition.y *= this -> dt;
		//this -> ballPosition.y *= this -> multiplier;





					//this -> ballPosition.y = 1;

			}






//Constructors / Destructors
Game::Game() {

	this -> initVariables();
	this -> initWindow();
	this -> initPaddle();
	this -> initBall();
	this -> initGridMatrix();

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			this -> initBrick(brickGridx[i][j], brickGridy[i][j]);
		}
	}


}

Game::~Game() {

	delete this -> window;
}

//Accessors

const bool Game::running() const
{
	return this -> window -> isOpen();
}



//Functions

void Game::pollEvents()
{
	//Event polling
		while (this -> window -> pollEvent(this -> ev))
			{
				if(ev.type == sf::Event::Closed){
					this -> window -> close();
					break;
				}

				if(ev.type == sf::Event::KeyReleased){

					if(ev.key.code == sf::Keyboard::Space){
						 start = true;
					}
				}


				if(ev.type == sf::Event::KeyPressed){

					if(ev.key.code == sf::Keyboard::A){
						//std::cout << "left" << std::endl;
						movePaddleleft();
					}

					if(ev.key.code == sf::Keyboard::D){
						//std::cout << "right" << std::endl;
						movePaddleright();
					}

				}
		    	dt = clock.restart().asSeconds();


			}
}

void Game::update()
{
	this -> pollEvents();
	if(start){
		moveBall();
	}
}

void Game::render()
{
	/*
	 * @return void
	 * - clear old frame
	 * - render objects
	 * - diplay frame in window
	 *
	 */

	this -> window -> clear(sf::Color::Black);

	// Draw game objects

	this -> window -> draw(this -> paddle);
	this -> window -> draw(this -> ball);
	this -> renderBricks();


	this -> window -> display();

}


