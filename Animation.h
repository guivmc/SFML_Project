#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>


class Animation
{
private:
	//Timing
	sf::Clock clock;
	float secondsToElapse;
	//Rects
	sf::IntRect *rects;
	int frameIndex, totalFrames;

public:
	Animation(){}
   ~Animation(){}
	Animation(sf::IntRect rects[], float secondsToElapse, int totalFrmaes);

	void playAnim();

	//Anims. with the sequence 1-2-3-1-2-3
	void loopDirectAnim();
	//Anims. with the sequence 1-2-3-2-1-2-3
	void loopReverseAnim();
	//Anims. with the sequence 1-2-3
	void soloAnim();

	//Getters
	sf::IntRect &getCurrentFrame();

	//Setters
	void setRectsArr(sf::IntRect rects[]);
	void setSecondsToElapse(float secondsToElapse);
};


