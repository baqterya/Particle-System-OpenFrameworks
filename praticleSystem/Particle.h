#include <iostream>
#include "ofMain.h"

class Particle {

public:
	Particle();
	Particle(const ofVec3f& pos, const ofVec3f& col, const float& life);
	
	//konstruktor kopiujący
	Particle(const Particle& p);
	Particle& operator= (const Particle&) = default;

	// konstruktor przenoszący
	Particle(Particle&& p) noexcept;
	Particle& operator= (Particle&&) = default;

	~Particle() { ; }

	// settery
	void setPosition(const ofVec3f& pos);
	void setVelocity(const ofVec3f& vel);
	void setAcceleration(const ofVec3f& acc);
	void setColor(const ofVec3f& col);

	// gettery
	const ofVec3f getPosition() const;
	const ofVec3f getVelocity() const;
	const ofVec3f getAcceleration() const;
	const ofVec3f getColor() const;

	// czy lifespan cząsteczki minął?
	const bool isDead() const;

	void applyForce(const ofVec3f& force);

	void update(const float& dt);
	void draw() const;

private:
	ofVec3f position;
	ofVec3f velocity;
	ofVec3f acceleration;
	ofVec3f color;

	float lifespan;
};