#include "audio.h"
#include <random>

std::vector<std::shared_ptr<sf::Sound>> AudioManager::stepsSounds;
std::vector<sf::SoundBuffer> AudioManager::stepsBuffers;
std::queue<std::shared_ptr<sf::Sound>> AudioManager::stepsQueue;
int AudioManager::stepind = 0;
double AudioManager::lastFootstep = 0;


void AudioManager::init(){
	stepsBuffers.push_back(sf::SoundBuffer{});
	stepsBuffers[0].loadFromFile("./res/audio/gr_step1.wav");
	stepsBuffers.push_back(sf::SoundBuffer{});
	stepsBuffers[1].loadFromFile("./res/audio/gr_step2.wav");
	stepsBuffers.push_back(sf::SoundBuffer{});
	stepsBuffers[2].loadFromFile("./res/audio/gr_step3.wav");
	stepsBuffers.push_back(sf::SoundBuffer{});
	stepsBuffers[3].loadFromFile("./res/audio/gr_step4.wav");




	stepsSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsSounds[0]->setBuffer(stepsBuffers[0]);
	//
	stepsSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsSounds[1]->setBuffer(stepsBuffers[1]);
	//
	stepsSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsSounds[2]->setBuffer(stepsBuffers[2]);
	//
	stepsSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsSounds[3]->setBuffer(stepsBuffers[3]);




	for (size_t i = 0; i < 4; i++)
	{
		stepsQueue.push(stepsSounds[i]);
	}
}

void AudioManager::playFootSteps()
{
		stepind++;
		lastFootstep = glfwGetTime();
		stepsSounds[getRandomIntBetween(0, 3)]->play();
}


int AudioManager::getRandomIntBetween(int a, int b) {
	// Seed the random number generator (use a different seed for each run)
	std::random_device rd;
	std::mt19937 gen(rd());

	// Define the range [a, b]
	std::uniform_int_distribution<int> distribution(a, b);

	// Generate a random integer
	int randomInt = distribution(gen);

	return randomInt;
}