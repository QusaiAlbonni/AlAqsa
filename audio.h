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
	static double lastDomeDoorCollide;
	static bool inDome;
	static std::vector<std::shared_ptr<sf::Sound>> stepsSounds;
	static std::vector<std::shared_ptr<sf::Sound>> stepsConcreteSounds;
	static std::queue<std::shared_ptr<sf::Sound>> stepsQueue;
	static std::vector<sf::SoundBuffer> stepsBuffers;
	static std::vector<sf::SoundBuffer> stepsConcreteBuffers;
	static std::shared_ptr<sf::Music> nightAmbient;
	static std::shared_ptr<sf::Music> dayAmbient;
	static void init();
	static void playFootSteps();
	static void playBackGround();
private:
	static int getRandomIntBetween(int a, int b);
};

#endif

