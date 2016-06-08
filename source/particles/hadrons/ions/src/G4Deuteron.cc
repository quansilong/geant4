// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4Deuteron.cc,v 1.2.8.1 1999/12/07 20:49:36 gunter Exp $
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
// **********************************************************************
//  Added by J.L.Chuma, TRIUMF, 27 June 1996
//  Added G4Deuteron::DeuteronDefinition() by H.Kurashige, 27 June 1996
//  Fixed parameters H. Kurashige, 25 Apr 1998
// ----------------------------------------------------------------------

#include <fstream.h>
#include <iomanip.h>

#include "G4Deuteron.hh"

// ######################################################################
// ###                           DEUTERON                             ###
// ######################################################################

G4Deuteron::G4Deuteron(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VIon( aName,mass,width,charge,iSpin,iParity,
           iConjugation,iIsospin,iIsospin3,gParity,pType,
           lepton,baryon,encoding,stable,lifetime,decaytable )
{
}

G4Deuteron::~G4Deuteron()
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

G4Deuteron G4Deuteron::theDeuteron(
           "deuteron",    1.875613*GeV,       0.0*MeV,  +1.0*eplus, 
		    2,              +1,             0,          
		    0,               0,             0,             
	    "nucleus",               0,            +2,           0,
		 true,            -1.0,          NULL
);

G4Deuteron* G4Deuteron::DeuteronDefinition(){return &theDeuteron;}
// initialization for static cut values
G4double   G4Deuteron::theDeuteronLengthCut;
G4double*  G4Deuteron::theDeuteronKineticEnergyCuts;