#ifndef MYPRIMARYGENERATORACTION_HH_
#define MYPRIMARYGENERATORACTION_HH_

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"

class G4ParticleGun;
class G4ParticleDefinition;
class G4Event;

class MyPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{
public:
	MyPrimaryGeneratorAction(G4ThreeVector halfLabSize);
	~MyPrimaryGeneratorAction();

public:
	void GeneratePrimaries(G4Event* anEvent);

private:
	G4ParticleGun *particleGun;
	G4ParticleDefinition *electron;
	G4ParticleDefinition *positron;
	G4ParticleDefinition *opticalphoton;
	G4ParticleDefinition *gamma;
	G4ParticleDefinition *proton;
	G4ParticleDefinition *antiproton;

	G4double gunEnergy;
	G4ThreeVector gunPosition, halfLabSize;
};

#endif /* MYPRIMARYGENERATORACTION_HH_ */
