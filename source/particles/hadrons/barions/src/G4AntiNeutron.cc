// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4AntiNeutron.cc,v 1.2.6.1 1999/12/07 20:49:28 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 
// ----------------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      4th April 1996, G.Cosmo
//                          H.Kurashige 7 July 1996
// **********************************************************************
#include <fstream.h>
#include <iomanip.h>

#include "G4AntiNeutron.hh"

// ######################################################################
// ###                          ANTI NEUTRON                          ###
// ######################################################################

G4AntiNeutron::G4AntiNeutron(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VBaryon( aName,mass,width,charge,iSpin,iParity,
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
G4AntiNeutron G4AntiNeutron::theAntiNeutron(
       "anti_neutron",  0.93956563*GeV,       0.0*MeV,         0.0, 
		    1,              +1,             0,          
		    1,              +1,             0,             
	     "baryon",               0,            -1,       -2112,
		 true,            -1.0,          NULL
);
G4AntiNeutron* G4AntiNeutron::AntiNeutronDefinition(){return &theAntiNeutron;}
// initialization for static cut values
G4double   G4AntiNeutron::theAntiNeutronLengthCut = -1.0;
G4double*  G4AntiNeutron::theAntiNeutronKineticEnergyCuts = NULL;

// **********************************************************************
// **************************** SetCuts *********************************
// **********************************************************************
//  In this version Input Cut Value is meaning less
//  theKineticEnergyCuts for all materials are set to LowestEnergy
void G4AntiNeutron::SetCuts(G4double aCut)
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
    theKineticEnergyCuts[J] = LowestEnergy;
  }
  theAntiNeutronLengthCut = theCutInMaxInteractionLength;  
  theAntiNeutronKineticEnergyCuts = theKineticEnergyCuts;
  // Rebuild the physics tables for every process for this particle type
  
}









