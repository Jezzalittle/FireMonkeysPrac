#include "DoorAnimationTest.h"
#include <iostream>
#include <limits>


DoorAnimationTest::DoorAnimationTest()
{
}


DoorAnimationTest::~DoorAnimationTest()
{
}





Entity::Entity(World& a_world, Float3* a_position) : world(a_world)
{
	position = a_position;
	velocity = new Float3();
	animationTimer = 0;
	lastAnim = new std::string("IDLE_CLOSED");
}

Entity::Entity(World& a_world, Float3* a_position, float a_speed) : world(a_world)
{
	position = a_position;
	*velocity = (*position) - world.GetClosestDoor(*position).GetPosition();
	animationTimer = 0;
	lastAnim = new std::string("IDLE_CLOSED");
}

Entity::~Entity()
{
	delete position;
	delete velocity;
	delete lastAnim;

}

World& Entity::GetWorld()
{
	return world;
}

Float3& Entity::GetVelocity()
{
	return *velocity;
}

void Entity::StartAnimation(std::string const & anim)
{
	if (*lastAnim == "IDLE_CLOSED")
	{
		if (anim == "OPENING")
			animationTimer = 3;
		else
			WrongInputMsg();
	}
	else if (*lastAnim == "IDLE_OPEN")
	{
		if (anim == "CLOSING")
			animationTimer = 3;
		else
			WrongInputMsg();
	}
	else
		WrongInputMsg();

}

void Entity::WrongInputMsg()
{
	std::cout << "Wrong input door animation is: " << lastAnim << std::endl;
}

bool Entity::IsAnimationComplete()
{
	return (animationTimer > 0);
}


Float3 & Character::GetFuturePos()
{
	return GetPosition() + GetVelocity();

}

void Character::Update(float a_timestemp)
{
	SetPosition(GetFuturePos());
}

Character & World::GetClosestCharacter(Float3 & a_float3)
{
	Character* closestCharacter = nullptr;
	float currentClosest = std::numeric_limits<float>::max();
	float current = 0.0f;
	for (Character* character : characters)
	{
		current = Float3::SqrMagnitude(character->GetPosition() - a_float3);
		if (current < currentClosest)
		{
			currentClosest = current;
			closestCharacter = closestCharacter;
		}
	}

	return *closestCharacter;
}

Door & World::GetClosestDoor(Float3& a_position)
{
	Door* closestDoor = nullptr;
	float currentClosest = std::numeric_limits<float>::max();
	float current = 0.0f;
	for (auto& door : doors)
	{
		current = Float3::SqrMagnitude(door->GetPosition() - a_position);
		if (current < currentClosest)
		{
			currentClosest = current;
			closestDoor = door;
		}
	}

	return *closestDoor;

}

void Door::Update(float timestep)
{
	Character closestCharacter = GetWorld().GetClosestCharacter(GetPosition());

	if (Float3::Normalise(closestCharacter.GetVelocity) == Float3::Normalise(GetPosition() - closestCharacter.GetPosition()))
	{
		for (auto& character : GetWorld().GetCharacters())
		{
			if(Float3::Magnitude(character->GetPosition() - GetPosition()) < )
		}
	}

}
