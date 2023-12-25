#pragma once
#ifndef AUDIO_H
#define AUDIO_H
#include <unordered_map>
#include "common.h"
#include <vector>
#include <queue>
#include <filesystem>

class AudioManager
{
public:
	static int stepind;
	static double lastFootstep;
	static std::vector<std::shared_ptr<sf::Sound>> stepsSounds;
	static std::queue<std::shared_ptr<sf::Sound>> stepsQueue;
	static std::vector<sf::SoundBuffer> stepsBuffers;
	static void init();
	static void playFootSteps();

private:
	static int getRandomIntBetween(int a, int b);
};

#endif

