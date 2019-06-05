# GEANT4-MinimalWorkingExample3-TargetAndInteractions
Here is a trapezoidal target with a spherical body within inself which can serve either as a cavity or as a denser obstruction to radiation by changing the material types of either body (hard-coded here for simplicity). The main electromagnetic interactions are enabled in the PhysicsList class.

![Radiation interacts with the target](GEANT4-MinimalWorkingExample3-run1.gif)

![Radiation interacts with the target](GEANT4-MinimalWorkingExample3-run3.gif)

##N.B.
In GEANT4 not every instance of a class with "new" needs to be explicitly deleted by the user, this is handled by the GEANT4 kernel.
