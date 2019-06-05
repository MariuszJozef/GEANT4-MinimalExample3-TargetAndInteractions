#include "MyPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction(G4ThreeVector halfLabSize)
: halfLabSize(halfLabSize)
{
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName;

	electron = particleTable->FindParticle(particleName="e-");
	positron = particleTable->FindParticle(particleName="e+");
	opticalphoton = particleTable->FindParticle(particleName="opticalphoton");
	gamma = particleTable->FindParticle(particleName="gamma");
	proton = particleTable->FindParticle(particleName="proton");
	antiproton = particleTable->FindParticle(particleName="anti_proton");

	G4ParticleDefinition *particle = electron;

	gunEnergy = 25*MeV;
	gunPosition = G4ThreeVector(0, 0, -halfLabSize.z());

	particleGun = new G4ParticleGun(1);
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleEnergy(gunEnergy);
	particleGun->SetParticlePosition(gunPosition);
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction()
{
	delete particleGun;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	// If SetParticleMomentumDirection is placed in constructor,
	// the directions will not be randomised.
	particleGun->SetParticleMomentumDirection(
						G4ThreeVector( 0.25 * (G4UniformRand() - 0.5),
									   0.25 * (G4UniformRand() - 0.5),
									   1) );
	particleGun->GeneratePrimaryVertex(anEvent);
}






