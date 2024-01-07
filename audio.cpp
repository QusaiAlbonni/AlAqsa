#include "audio.h"
#include <random>
#include "Collision.h"

std::vector<std::shared_ptr<sf::Sound>> AudioManager::stepsSounds;
std::vector<std::shared_ptr<sf::Sound>> AudioManager::stepsConcreteSounds;
std::vector<sf::SoundBuffer> AudioManager::stepsBuffers;
std::vector<sf::SoundBuffer> AudioManager::stepsConcreteBuffers;
std::queue<std::shared_ptr<sf::Sound>> AudioManager::stepsQueue;

std::shared_ptr<sf::Music> AudioManager::nightAmbient = std::make_shared<sf::Music>();
std::shared_ptr<sf::Music> AudioManager::dayAmbient = std::make_shared<sf::Music>();

int AudioManager::stepind = 0;
double AudioManager::lastFootstep = 0;

bool AudioManager::inDome = false;


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



	if (!nightAmbient->openFromFile("res/audio/nightScape.wav")) {
		std::cout << "ERROR:: sfml audio couldnt be loaded " << "nightScape.wav";
	}
	else
	{
		nightAmbient->setLoop(1);
	}
	if (!dayAmbient->openFromFile("res/audio/dayScape.mp3")) {
		std::cout << "ERROR:: sfml audio couldnt be loaded " << "dayScape.mp3";
	}
	else
	{
		dayAmbient->setLoop(1);
	}

}

void AudioManager::playFootSteps()
{
		stepind++;
		lastFootstep = glfwGetTime();
		if (((camera.Position.z < 20 && camera.Position.z > -90) && (camera.Position.x < 25 && camera.Position.x > -85)
			)|| (camera.Position.x > -35.0f && camera.Position.x < -25.0f && camera.Position.z > 20.0f) || camera.Position.z > 55.0f) {
			int rand = getRandomIntBetween(0, 3);
			stepsConcreteSounds[rand]->setVolume(20.0f);
			stepsConcreteSounds[rand]->play();

		}
		else {
			int rand = getRandomIntBetween(0, 3);
			stepsSounds[rand]->play();

		}
}

void AudioManager::playBackGround()
{
	nightAmbient->setAttenuation(0.0);
	dayAmbient->setAttenuation(0.0);
	nightAmbient->setVolume(100.f);
	dayAmbient->setVolume(150.f);
	if (night)
	{
		dayAmbient->stop();
		if (nightAmbient->getStatus() == sf::Music::Stopped)
		{
			nightAmbient->play();
		}
		
	}
	else {
		nightAmbient->stop();
		if (dayAmbient->getStatus() == sf::Music::Stopped)
		{
			dayAmbient->play();
		}
	}
}


int AudioManager::getRandomIntBetween(int a, int b) {


	std::random_device rd;
	std::mt19937 gen(rd());

	// Define the range [a, b]
	std::uniform_int_distribution<int> distribution(a, b);

	// Generate a random integer
	int randomInt = distribution(gen);

	return randomInt;
}