#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(const ofVec3f loc, int gen, ofVec3f color)
	: location(loc), spawnDelay(0), timer(0), generation(gen),
	childColor(color)
{
	;
}

void ParticleSystem::addParticle(){
	if (countSpawned < maxSpawn) {
		particleSet.push_back(Particle(location, childColor, 2));
		countSpawned++;
	}
}

void ParticleSystem::setSpawnDelay(const float& delay){
	spawnDelay = delay;
}
void ParticleSystem::resetTimer(){
	this->timer = 0.0;
}

bool ParticleSystem::canSpawn() const{
	return timer >= spawnDelay;
}

void ParticleSystem::update(const float& dt){
	auto i = std::begin(particleSet);

	while (i != std::end(particleSet)) {
		if (i->isDead()) {
			newLocations.push_back(i->getPosition());
			i = particleSet.erase(i);
		}
		else
			++i;
	}

	for (auto& p : particleSet) {
		p.update(dt);
	}

	this->timer += dt;
}

void ParticleSystem::draw() const{
	for (auto& p : particleSet) {
		p.draw();
	}
}

const bool ParticleSystem::allDead() const {
	return newLocations.size() == maxSpawn;
}

const bool ParticleSystem::canCopy() const{
	return generation < maxGen;
}