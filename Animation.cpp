#include "stdafx.h"
#include "Animation.h"
#include <iostream>

Animation::Animation(sf::IntRect rects[], float secondsToElapse, int totalFrames)
{
	this->secondsToElapse = secondsToElapse;
	frameIndex = 0;					//size of rects in the system / size of one IntRect in system
	this->totalFrames = totalFrames; //sizeof(*rects) / sizeof(sf::IntRect *) + 1;
	this->rects = rects;
	//starts clock
	clock.restart();
}

//Methods
void Animation::soloAnim()
{
	if (frameIndex > totalFrames) return;
	float elapsed = clock.getElapsedTime().asSeconds();
	if (elapsed >= secondsToElapse)
	{
		clock.restart();
		frameIndex++;
	}
}

void Animation::loopDirectAnim()
{
	float elapsed = clock.getElapsedTime().asSeconds();
	if (elapsed >= secondsToElapse)
	{
		clock.restart();
		frameIndex++;
		//reset frame
		if (frameIndex >= totalFrames)
		{
			frameIndex = 0;
		}
	}	
}

void Animation::loopReverseAnim()
{
	bool reverse = false;
	float elapsed = clock.getElapsedTime().asSeconds();
	if (elapsed >= secondsToElapse)
	{
		clock.restart();
		//reset frame
		if (frameIndex <= totalFrames && !reverse)
		{
			frameIndex++;
			if (frameIndex >= totalFrames)
			{
				frameIndex = totalFrames;
				reverse = true;
			}
		}
		else if (frameIndex <= totalFrames && reverse)
		{
			frameIndex--;
			if (frameIndex <= 0)
			{			
				frameIndex = 0;
				reverse = false;
			}
		}
	}
}

//Getters
sf::IntRect &Animation::getCurrentFrame()
{
	//To avoid possible erro with updateAnim()
	//if (frameIndex > totalFrames) return rectsArr.at(totalFrames - 1);
	return *(rects + frameIndex);
}

//Setters
void Animation::setRectsArr(sf::IntRect rects[])
{
	this->rects = rects;
}

void Animation::setSecondsToElapse(float secondsToElapse)
{
	this->secondsToElapse = secondsToElapse;
}