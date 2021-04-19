#pragma once

#include <vector>
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem
{
public:
	vector<Particle> particleSet;

	// newLocation zawiera wektor pozycji śmierci cząsteczek
	vector<ofVec3f> newLocations;

	// czy ten emiter stworzył już nowe emitery?
	bool canChild = true;

	// generation to aktualne pokolenie emiterów
	const int generation;

	ParticleSystem(const ofVec3f loc, int gen, ofVec3f color);
	~ParticleSystem() { ; }

	void addParticle();
	void setSpawnDelay(const float& delay);
	void resetTimer();

	// czy minął spawnDelay?
	bool canSpawn() const;

	// allDead() sprawdza, czy wszystkie wyemitowane cząsteczki nie żyją
	const bool allDead() const;

	// canCopy() sprawdza, czy można stworzyć kolejne pokolenie emiterów
	const bool canCopy() const;

	void update(const float& dt);
	void draw() const;

private:
	// martwe cząsteczki są usuwane z wektora particleSet, więc
	// zmienna countSpawned upewnia się, że utworzy się odpowiednia ilość cząsteczek
	int countSpawned = 0;

	// maxSpawn określa ile cząsteczek może wyemitować emiter
	const int maxSpawn = 10;

	// maxGen określa ile razy jedna rodzina emiterów stworzy kolejne emitery
	const int maxGen = 2;

	ofVec3f location;
	const ofVec3f childColor;

	// może określić po jakim czasie i z jakim interwałem
	// zacznie tworzyć cząsteczki
	float spawnDelay;

	// liczy ile czasu upłynęło od narodzin emitera
	float timer;
};

