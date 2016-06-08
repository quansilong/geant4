// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4AntiNeutrinoE.cc,v 1.1.10.1 1999/12/07 20:49:47 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 
// ----------------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      4th April 1996, G.Cosmo        by H.Kurashige,7  July 1996
// **********************************************************************

#include <fstream.h>
#include <iomanip.h>

#include "G4AntiNeutrinoE.hh"

// ######################################################################
// ###                   ANTI NEUTRINO                                ###
// ######################################################################

G4AntiNeutrinoE::G4AntiNeutrinoE(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VLepton( aName,mass,width,charge,iSpin,iParity,
              iConjugation,iIsospin,iIsospin3,gParity,pType,
              lepton,baryon,encoding,stable,lifetime,decaytable )
{
}
// ......................................................................
// ...                 static member definitions                      ...
// ......................................................................
//     
//    Arguments for constructor are as follows
//               name             mass          width         charge
//             2*spin           parity  C-conjugation
//          2*Isospin       2*Isospin3       G-parity
//               type    lepton number  baryon number   PDG encoding
//             stable         lifetime    decay table 
//
G4AntiNeutrinoE G4AntiNeutrinoE::theAntiNeutrinoE(
	  "anti_nu_e",          0.0*MeV,       0.0*MeV,         0.0, 
		    1,               0,             0,          
		    0,               0,             0,             
	     "lepton",              -1,             0,          -12,
		 true,             0.0,          NULL
);

G4AntiNeutrinoE* G4AntiNeutrinoE::AntiNeutrinoEDefinition()
{
  return &theAntiNeutrinoE;
}
// initialization for static cut values
G4double   G4AntiNeutrinoE::theAntiNeutrinoELengthCut = -1.0;
G4double*  G4AntiNeutrinoE::theAntiNeutrinoEKineticEnergyCuts = NULL;
// **********************************************************************
// **************************** SetCuts *********************************
// **********************************************************************

void G4AntiNeutrinoE::SetCuts(G4double aCut)
{
  theCutInMaxInteractionLength = aCut;

  const G4MaterialTable* materialTable = G4Material::GetMaterialTable();
  // Create the vector of cuts in energy
  // corresponding to the stopping range cut
  if(theKineticEnergyCuts) delete [] theKineticEnergyCuts;
  theKineticEnergyCuts = new G4double [materialTable->length()];

  // Build range vector for every material, convert cut into energy-cut,
  // fill theKineticEnergyCuts and delete the range vector
  for (G4int J=0; J<materialTable->length(); J++)
  {
    G4Material* aMaterial = (*materialTable)[J];
    theKineticEnergyCuts[J] = 0.0*keV;
  }
  theAntiNeutrinoELengthCut = theCutInMaxInteractionLength;  
  theAntiNeutrinoEKineticEnergyCuts = theKineticEnergyCuts;
  // Rebuild the physics tables for every process for this particle type
  
}