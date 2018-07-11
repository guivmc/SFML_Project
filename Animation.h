#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class Animation
{
protected:
	//Timing
	sf::Clock clock;
	float totalTime, secondsToElapse;
	int animSheetHeight, currentFrameWidth, totalFrames, frameCount = 0;
	sf::Vector2i spriteSize;

public:
	Animation(sf::Vector2i spriteSize, int animSheetHeight, float secondsToElapse, int totalFrmaes);
   ~Animation(){}

	//Anims. with the sequence 1-2-3
    sf::IntRect &soloAnim(float dt);
	//Anims. with the sequence 1-2-3-1-2-3
	//void directAnim(float dt);
	//Anims. with the sequence 1-2-3-2-1
	//void reverseAnim(float dt);

	//Getters
	sf::IntRect &getCurrentFrame();
	//Setters
	void setSecondsToElapse(float secondsToElapse);
};


