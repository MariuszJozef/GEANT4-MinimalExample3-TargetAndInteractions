#ifndef HDR_MYDETECTORCONSTRUCTION_HH_
#define HDR_MYDETECTORCONSTRUCTION_HH_

#include "G4VUserDetectorConstruction.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;

#include "G4Box.hh"
#include "G4Trd.hh"
#include "G4Sphere.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "globals.hh"

#include "G4ThreeVector.hh"

class MyDetectorConstruction: public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	virtual ~MyDetectorConstruction();
	virtual G4VPhysicalVolume* Construct();
	G4ThreeVector GetHalfLabSize() const { return halfLabSize; }

private:
	G4ThreeVector halfLabSize;
	G4Box *solidLab = 0;
	G4Trd *solidTrapezoid = 0;
	G4Sphere *solidSphere = 0;

	G4LogicalVolume *logicalLab = NULL;
	G4LogicalVolume *logicalTrapezoid = 0;
	G4LogicalVolume *logicalSphere = 0;

	G4VPhysicalVolume *physicalLab = 0;
	G4VPhysicalVolume *physicalTrapezoid = 0;
	G4VPhysicalVolume *physicalSphere = 0;

	G4Material *labMaterial = 0;
	G4Material *trapezoidMaterial = NULL;
	G4Material *sphereMaterial = 0;

	void DefineMaterials();
	G4VPhysicalVolume* ConstructDetector();
};

#endif /* HDR_MYDETECTORCONSTRUCTION_HH_ */
