# GEANT4-MinimalExample3-TargetAndInteractions
N.B.
[Cpp17GEANT4-Example3](https://github.com/MariuszJozef/Cpp17GEANT4-Example3) is an updated version of this same example as here that has beed refactored into modern C++11/14/17 with unique pointers etc.

Here is a trapezoidal target with a spherical body within inself which can serve either as a cavity or as a denser obstruction (with higher atomic number) to radiation by changing the material types of either body. The material types are hard-coded here for simplicity but this will be remedied in MinimalExample4. The main electromagnetic interactions are enabled in the PhysicsList class. The incident particle type and its energy can be chaged at runtime at the Qt prompt by issuing the command:

/gun/particle particleName
  
/gun/energy energy unit
  
And you can query the current values of these quantities thus:

?/gun/particle

?gun/energy

![Radiation interacts with the target](GEANT4-MinimalWorkingExample3-run1.gif)

![Radiation interacts with the target](GEANT4-MinimalWorkingExample3-run3.gif)

## N.B.
In GEANT4 not every instance of a class with "new" needs to be explicitly deleted by the user, this is handled by the GEANT4 kernel. (Refer online to "Geant4 User's Guide for Application Developers".)
