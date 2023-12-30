#include "audio.h"
#include <random>

std::vector<std::shared_ptr<sf::Sound>> AudioManager::stepsSounds;
std::vector<std::shared_ptr<sf::Sound>> AudioManager::stepsConcreteSounds;
std::vector<sf::SoundBuffer> AudioManager::stepsBuffers;
std::vector<sf::SoundBuffer> AudioManager::stepsConcreteBuffers;
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
	//

	stepsConcreteBuffers.push_back(sf::SoundBuffer{});
	stepsConcreteBuffers[0].loadFromFile("./res/audio/pl_step1.wav");
	stepsConcreteBuffers.push_back(sf::SoundBuffer{});
	stepsConcreteBuffers[1].loadFromFile("./res/audio/pl_step2.wav");
	stepsConcreteBuffers.push_back(sf::SoundBuffer{});
	stepsConcreteBuffers[2].loadFromFile("./res/audio/pl_step3.wav");
	stepsConcreteBuffers.push_back(sf::SoundBuffer{});
	stepsConcreteBuffers[3].loadFromFile("./res/audio/pl_step4.wav");

	//







	//
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


	stepsConcreteSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsConcreteSounds[0]->setBuffer(stepsConcreteBuffers[0]);
	//
	stepsConcreteSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsConcreteSounds[1]->setBuffer(stepsConcreteBuffers[1]);
	//
	stepsConcreteSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsConcreteSounds[2]->setBuffer(stepsConcreteBuffers[2]);
	//
	stepsConcreteSounds.push_back(std::make_shared<sf::Sound>(sf::Sound{}));
	stepsConcreteSounds[3]->setBuffer(stepsConcreteBuffers[3]);



	for (size_t i = 0; i < 4; i++)
	{
		stepsQueue.push(stepsSounds[i]);
	}
}

void AudioManager::playFootSteps()
{
		stepind++;
		lastFootstep = glfwGetTime();
		if ((camera.Position.z < 20 && camera.Position.z > -90) && (camera.Position.x < 20 && camera.Position.x > -90))
			stepsConcreteSounds[getRandomIntBetween(0, 3)]->play();
		else
			stepsSounds[getRandomIntBetween(0, 3)]->play();
}


int AudioManager::getRandomIntBetween(int a, int b) {
	// Seed the random number generator (use a different seed for each run)
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::random_device rd;
	std::mt19937 gen(seed);

	// Define the range [a, b]
	std::uniform_int_distribution<int> distribution(a, b);

	// Generate a random integer
	int randomInt = distribution(gen);

	return randomInt;
}