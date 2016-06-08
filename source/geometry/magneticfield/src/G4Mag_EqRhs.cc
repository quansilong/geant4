// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4Mag_EqRhs.cc,v 1.1.10.1 1999/12/07 20:48:06 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
//  This is the standard right-hand side for equation of motion  
//    in a pure Magnetic Field .
//
//   Other that might be required are:
//     i) is when using a moving reference frame ... or
//    ii) extending for other forces, eg an electric field
//
//            J. Apostolakis, January 13th, 1997
//
#include "G4MagneticField.hh"
#include "G4Mag_EqRhs.hh"
#include "G4EquationOfMotion.hh"

const G4double G4Mag_EqRhs::fUnitConstant = 0.299792458 * (GeV/(tesla*m)); 

// Constructor Implementation
//
G4Mag_EqRhs::G4Mag_EqRhs( G4MagneticField *magField ) 
   : G4EquationOfMotion(magField)
{ 
}

void  
G4Mag_EqRhs::SetChargeMomentumMass( const G4double particleCharge, // e+ units
			            const G4double MomentumXc,
                                    const G4double particleMass)
{
   fCof_val = fUnitConstant*particleCharge/MomentumXc; //  B must be in Tesla
   // fMass = particleMass;
}

G4Mag_EqRhs::~G4Mag_EqRhs() { }