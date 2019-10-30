#pragma once
#include <vector>
#include <math.h>

class World;

struct Float3
{
public:
	float x, y, z;
	Float3() { x = 0; y = 0; z = 0; }
	Float3(float a_x, float a_y, float a_z) { x = a_x; y = a_y; z = a_z; }
	~Float3();

	static float SqrMagnitude(const Float3& a_float3) { return a_float3.x * a_float3.x + a_float3.y * a_float3.y + a_float3.z * a_float3.z; };
	static float Magnitude(const Float3& a_float3) { return sqrt(SqrMagnitude(a_float3)); };
	static Float3& Normalise(const Float3& a_float3) { float dist = Float3::Magnitude(a_float3); return *(new Float3(a_float3.x / dist, a_float3.y / dist, a_float3.z / dist)); };

	friend Float3& operator + (const Float3& lhs, const Float3& rhs) 
	{
		return new Float3(rhs.x + lhs.x, rhs.y * lhs.y, rhs.z * lhs.z);
	}

	friend Float3& operator * (const float lhs, const Float3& rhs)
	{
		return new Float3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
	}
	
	friend Float3& operator - (const Float3& lhs, const Float3& rhs)
	{
		return new Float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
	}

	friend bool operator == (const Float3& lhs, const Float3& rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
	}

};

class Entity
{
private:
	
	Float3* velocity;
	int animationTimer;
	std::string* lastAnim;
	World& world;
	Float3* position;
	void WrongInputMsg();

protected:



public:

	Entity() = delete;
	Entity(World& a_world, Float3* a_position);
	Entity(World& a_world, Float3* a_position, float a_speed);
	~Entity();

	World& GetWorld();

	// Returns the current 3D position (in meters) of the entity within the world
	Float3& GetPosition() { return (*position); };
	void SetPosition(Float3& a_float3) { *position = a_float3; };

	// Returns the current velocity of the character (in meters per second)
	Float3& GetVelocity();

	// Start playing an animation.  Animations stop playing (freezing on their
// final frame) when complete.
	void StartAnimation(std::string const& anim);
	bool IsAnimationComplete();



	// Called every frame with the time elapsed since previous frame, in seconds
	virtual void Update(float timestep) = 0;
};

class Character : public Entity
{
public:

	//Character() = delete;
	Character(World& a_world, Float3* a_position, Float3* a_velocity) : Entity(a_world, a_position, a_velocity) { a_world.AddCharacter(this); };
	~Character();

	Float3& GetFuturePos();

	virtual void Update(float a_timestemp) override;


};

// Represents an automatic door which should open for characters as they approach.  
// The following animations are available:
//
//   IDLE_CLOSED, IDLE_OPEN, OPENING, CLOSING
//
class Door : public Entity
{
public:
	// Candidate to implement.  Must try to ensure door is open whenever a 
	// character approaches within 1 meter, and is closed otherwise, without 
	// snapping animations.
	Door(World& a_world, Float3* a_position, Float3* a_velocity) : Entity(a_world, a_position, a_velocity) { a_world.AddDoor(this); };


	virtual void Update(float timestep) override;
};



class World
{
private:

	std::vector<Character*> characters;
	std::vector<Door*> doors;



public:

	World();
	~World();

	Character& GetClosestCharacter(Float3& a_float3);
	Door& GetClosestDoor(Float3& a_float3);
	void AddCharacter(Character* a_character);
	void AddDoor(Door* a_door);

	// Get a list of all the characters in the world.
	std::vector<Character*> const& GetCharacters() { return characters; };

	// Get a list of all the doors in the world.
	std::vector<Door*> const& GetDoors() { return doors; };
};



class DoorAnimationTest
{
public:

	DoorAnimationTest();
	~DoorAnimationTest();
};

