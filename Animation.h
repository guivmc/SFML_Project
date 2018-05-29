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
	Animation();
	~Animation();
	Animation(sf::IntRect rects[], float secondsToElapse, int totalFrmaes);

	void updateLoopAnim();
	void updateLoopAnimReverse();
	void updateAnim();

	//Getters
	sf::IntRect &getCurrentFrame();

	//Setters
	void setRectsArr(sf::IntRect rects[]);
	void setSecondsToElapse(float secondsToElapse);
};


