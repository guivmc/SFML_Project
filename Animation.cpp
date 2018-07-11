#include "stdafx.h"
#include "Animation.h"

Animation::Animation(sf::Vector2i spriteSize, int animSheetHeight, float secondsToElapse, int totalFrmaes)
{
	this->secondsToElapse = secondsToElapse;
	this->animSheetHeight = animSheetHeight;
	this->totalFrames = totalFrames;
	this->spriteSize  = spriteSize;
	currentFrameWidth = 0;
}
//Methods
sf::IntRect &Animation::soloAnim(float dt)
{
	totalTime += dt;

	if (totalTime >= secondsToElapse)
	{
		totalTime -= secondsToElapse;
		currentFrameWidth += spriteSize.x;
		if (spriteSize.x * (totalFrames - 1) == currentFrameWidth)
		{
			currentFrameWidth = 0;
		}
	}

	return sf::IntRect(currentFrameWidth, animSheetHeight, spriteSize.x, spriteSize.y);
}

//void Animation::directAnim(float dt)
//{
//	float elapsed = clock.getElapsedTime().asSeconds();
//	if (elapsed >= secondsToElapse)
//	{
//		clock.restart();
//		//currentFrame.x += spriteSize.x;
//		//reset frame
//		/*if (frameIndex >= totalFrames)
//		{
//			frameIndex = 0;
//		}*/
//	}
//}
//
//void Animation::reverseAnim(float dt)
//{
//	bool reverse = false;
//	float elapsed = clock.getElapsedTime().asSeconds();
//	if (elapsed >= secondsToElapse)
//	{
//		clock.restart();
//		//reset frame
//		/*if (frameIndex <= totalFrames && !reverse)
//		{
//			currentFrame.x += spriteSize.x;
//			if (frameIndex >= totalFrames)
//			{
//				frameIndex = totalFrames;
//				reverse = true;
//			}
//		}
//		else if (frameIndex <= totalFrames && reverse)
//		{
//			currentFrame.x -= spriteSize.x;
//			if (frameIndex <= 0)
//			{
//				frameIndex = 0;
//				reverse = false;
//			}
//		}*/
//	}
//}



//Getters
sf::IntRect &Animation::getCurrentFrame()
{
	return sf::IntRect(currentFrameWidth, animSheetHeight, spriteSize.x, spriteSize.y);
}

//Setters
void Animation::setSecondsToElapse(float secondsToElapse)
{
	this->secondsToElapse = secondsToElapse;
}