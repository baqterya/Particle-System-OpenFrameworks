#include "Particle.h"

Particle::Particle() 
	: lifespan(5)
{
}

Particle::Particle(const ofVec3f& pos, const ofVec3f& col, const float& life)
	: position(pos), lifespan(life), 
	velocity(ofRandom(-200, 200), ofRandom(-200, 200), ofRandom(-50, 50)),
	acceleration(0, 100, 0), color(col)
{
}

Particle::Particle(const Particle& p)
	: position(p.position), velocity(p.velocity), acceleration(p.acceleration),
	lifespan(p.lifespan), color(p.color)
{
	;
}

Particle::Particle(Particle&& p) noexcept
	: position(p.position), velocity(p.velocity), acceleration(p.acceleration),
	lifespan(p.lifespan), color(p.color)
{
	;
}

void Particle::setPosition(const ofVec3f& pos) {
	position = pos;
}
void Particle::setVelocity(const ofVec3f& vel) {
	velocity = vel;
}
void Particle::setAcceleration(const ofVec3f& acc) {
	acceleration = acc;
}
void Particle::setColor(const ofVec3f& col) {
	color = col;
}

const ofVec3f Particle::getPosition() const {
	return position;
}
const ofVec3f Particle::getVelocity() const {
	return velocity;
}
const ofVec3f Particle::getAcceleration() const {
	return acceleration;
}

const ofVec3f Particle::getColor() const {
	return color;
}

const bool Particle::isDead() const {
	return lifespan < 0.0;
}

void Particle::applyForce(const ofVec3f& force) {
	acceleration += force;
}

void Particle::update(const float& dt) {
	position += velocity * dt;
	velocity += acceleration * dt;
	lifespan -= 0.02;
}
void Particle::draw() const {
	ofSetColor(color.x, color.y, color.z, lifespan * 50);
	ofNoFill();
	ofDrawSphere(position, 5);
}