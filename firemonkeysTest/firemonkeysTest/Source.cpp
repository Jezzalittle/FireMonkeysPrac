#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "RemoveExpiredTimersTest.h"
#include <time.h>       
#include "StreamTest.h"


//struct Float3
//{
//	float x, y, z;
//};
//
//float Distance(const Float3& lhs, const Float3& rhs)
//{
//	return sqrtf(powf(rhs.x - lhs.x, 2) + powf(rhs.y - lhs.y, 2) + powf(rhs.z - lhs.z, 2));
//}
//
//float Magnitude(const Float3& lhs)
//{
//	return sqrtf(powf(lhs.x, 2) + powf(lhs.y, 2) + powf(lhs.z, 2));
//}
//
//
//class World;
//
//class Entity
//{
//public:
//	World & GetWorld();
//
//	// Returns the current 3D position (in meters) of the entity within the world
//	Float3 GetPosition();
//
//	// Returns the current velocity of the character (in meters per second)
//	Float3 GetVelocity();
//
//	// Start playing an animation.  Animations stop playing (freezing on their
//	// final frame) when complete.
//	void StartAnimation(std::string const& anim);
//	bool IsAnimationComplete();
//
//	// Get the duration of an animation, in seconds
//	float GetAnimationDuration(std::string const& anim);
//
//	// Called every frame with the time elapsed since previous frame, in seconds
//	virtual void Update(float timestep) = 0;
//};
//
//class World
//{
//public:
//	// Get a list of all the characters in the world.
//	std::vector<Entity*> const& GetCharacters();
//
//	// Get a list of all the doors in the world.
//	std::vector<Entity*> const& GetDoors();
//};
//
//// Represents an automatic door which should open for characters as they approach.  
//// The following animations are available:
////
////   IDLE_CLOSED, IDLE_OPEN, OPENING, CLOSING
////
//class Door : public Entity
//{
//public:
//	// Candidate to implement.  Must try to ensure door is open whenever a 
//	// character approaches within 1 meter, and is closed otherwise, without 
//	// snapping animations.
//	virtual void Update(float timestep) override
//	{
//
//		//Basic state machine
//
//
//		//if the door is closed
//		if (m_currentAnimation == IDLE_CLOSED)
//		{
//			//foreach character in the world
//			for (auto& character : GetWorld().GetCharacters())
//			{
//				//if the distastance of this character is less then 1 * the speed the character is running
//				if (Distance(character->GetPosition(), GetPosition()) < 1 * Magnitude(GetVelocity()))
//				{
//					//switch states to OPENING
//					m_currentAnimation = OPENING;
//					//start OPENING animation
//					StartAnimation("OPENING");
//				}
//			}
//		}
//
//		//if the door is opening
//		if (m_currentAnimation == OPENING)
//		{
//			//if the opening animation is complete
//			if (IsAnimationComplete())
//			{
//				//switch states to IDLE_OPEN
//				m_currentAnimation = IDLE_OPEN;
//				//Play Idle Animation if there is one??????
//				StartAnimation("IDLE_OPEN");
//			}
//		}
//		//if the door is open
//		if (m_currentAnimation == IDLE_OPEN)
//		{
//			//foreach character in the world
//			for (auto& character : GetWorld().GetCharacters())
//			{
//				//if the distastance of this character is greater than 1 from the door
//				if (Distance(character->GetPosition, GetPosition()) > 1)
//				{
//					//switch States to closing 
//					m_currentAnimation = CLOSING;
//					//start CLOSING Animation
//					StartAnimation("CLOSING");
//				}
//			}
//		}
//
//		//if the door is closing
//		if (m_currentAnimation == CLOSING)
//		{
//			//if the animation is done
//			if (IsAnimationComplete())
//			{
//				//swich state to IDLE_CLOSED
//				m_currentAnimation == IDLE_CLOSED;
//				//play idle animation if there is one 
//				StartAnimation("IDLE_CLOSED");
//			}
//		}
//	}
//
//private:
//
//	enum DOOR_ANIM { IDLE_CLOSED, OPENING, IDLE_OPEN, CLOSING };
//
//	DOOR_ANIM m_currentAnimation = IDLE_CLOSED;
//
//
//};
//
//size_t Read(char* buf, size_t bytes);
//
//std::vector<char> ReadAll()
//{
//	char buf[1024];
//	//should be larger for fast results 
//	int currentMaxIndex = 1;
//	std::vector<char> returnArr;
//
//	//while current max index is less then the current index
//	while (currentMaxIndex < Read(buf, currentMaxIndex))
//	{
//		//incress current max index
//		currentMaxIndex * 2;
//	}
//
//	//set current max index to the highest index once we have found it
//	currentMaxIndex = Read(buf, currentMaxIndex);
//
//	//start a loop from 0 to current max index
//	for (size_t i = 0; i < currentMaxIndex; i++)
//	{
//		//add that value to the return array
//		returnArr.push_back(buf[i]);
//	}
//
//	//return the returnArr
//	return returnArr;
//
//}


int main()
{
	srand(time(NULL));
	std::vector<Timer*>* timerTest;
	timerTest = new std::vector<Timer*>();

	std::cout << "####### Remove Expired Timers Test #######" << std::endl << std::endl;

	for (size_t i = 0; i < 5; i++)
	{
		timerTest->push_back(new Timer());
	}

	RemoveExpiredTimersTest* expiredTimersTest = new RemoveExpiredTimersTest();

	std::cout << std::endl << std::endl;

	expiredTimersTest->beginTest(*timerTest);

	std::cout << "####### Stream Test #######" << std::endl << std::endl;

	size_t randomNumberSize = rand() % 100 + 10;
	char* randomCharValue = new char[randomNumberSize];

	std::cout << "Input Length: " << randomNumberSize << std::endl;

	std::cout << "Input" << std::endl;

	for (size_t i = 0; i < randomNumberSize; i++)
	{
		randomCharValue[i] = 'a' + rand() % 26;
		std::cout << randomCharValue[i]; 
	}
	randomCharValue[randomNumberSize] = '\0';

	std::cout << std::endl << std::endl;

	StreamTest* streamTest = new StreamTest();
	std::vector<char> bufValues = streamTest->ReadAll(randomCharValue);

	std::cout << "Output as vector" << std::endl;

	for (size_t i = 0; i < bufValues.size(); i++)
	{
		std::cout << bufValues[i];
	}
	std::cout << std::endl;
	
	std::cout << "Output Length: " << bufValues.size() << std::endl;

	std::cout << std::endl << std::endl;

	system("pause");

}

