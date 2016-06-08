// This code implementation is the intellectual property of
// neutron_hp -- header file
// J.P. Wellisch, Nov-1996
// A prototype of the low energy neutron transport model.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NeutronHPTCFissionFS.hh,v 1.3 1999/07/02 09:59:59 johna Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
#ifndef G4NeutronHPTCFissionFS_h
#define G4NeutronHPTCFissionFS_h 1

#include "globals.hh"
#include "G4Track.hh"
#include "G4DynamicParticleVector.hh"
#include "G4NeutronHPFissionBaseFS.hh"

class G4NeutronHPTCFissionFS : public G4NeutronHPFissionBaseFS
{
  public:
  
  G4NeutronHPTCFissionFS(){ hasXsec = false; }
  ~G4NeutronHPTCFissionFS(){}
  void Init (G4double A, G4double Z, G4String & dirName, G4String & aFSType);
  G4DynamicParticleVector * ApplyYourself(G4int NNeutrons);
  G4NeutronHPFinalState * New() 
  {
   G4NeutronHPTCFissionFS * theNew = new G4NeutronHPTCFissionFS;
   return theNew;
  }
  
  private:
  G4ParticleChange * ApplyYourself(const G4Track & theTrack) { return NULL; }
    
};
#endif