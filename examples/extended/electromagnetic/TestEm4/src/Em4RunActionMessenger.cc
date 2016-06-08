// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em4RunActionMessenger.cc,v 1.1.4.1 1999/12/07 20:47:07 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "Em4RunActionMessenger.hh"
#include "Em4RunAction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

Em4RunActionMessenger::Em4RunActionMessenger(Em4RunAction* run)
:Em4Run(run)
{ 
  SaveCmd = new G4UIcmdWithAString("/run/save",this);
  SaveCmd->SetGuidance("Save run statistic");
  SaveCmd->SetGuidance("  Choice : on(default),off");
  SaveCmd->SetParameterName("choice",true);
  SaveCmd->SetDefaultValue("on");
  SaveCmd->SetCandidates("on off");
  SaveCmd->AvailableForStates(Idle);
  
  RndmDir = new G4UIdirectory("/rndm/");
  RndmDir->SetGuidance("Rndm status control.");
  
  RndmSaveCmd = new G4UIcmdWithAnInteger("/rndm/save",this);
  RndmSaveCmd->SetGuidance("set frequency to save rndm status on external files.");
  RndmSaveCmd->SetGuidance("freq = 0 not saved");
  RndmSaveCmd->SetGuidance("freq > 0 saved on: beginOfRun.rndm");
  RndmSaveCmd->SetGuidance("freq = 1 saved on:   endOfRun.rndm");
  RndmSaveCmd->SetGuidance("freq = 2 saved on: endOfEvent.rndm");    
  RndmSaveCmd->SetParameterName("frequency",false);
  RndmSaveCmd->SetRange("frequency>=0 && frequency<=2");
  RndmSaveCmd->AvailableForStates(PreInit,Idle); 
         
  RndmReadCmd = new G4UIcmdWithAString("/rndm/read",this);
  RndmReadCmd->SetGuidance("get rndm status from an external file.");
  RndmReadCmd->SetParameterName("fileName",true);
  RndmReadCmd->SetDefaultValue ("beginOfRun.rndm");
  RndmReadCmd->AvailableForStates(PreInit,Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

Em4RunActionMessenger::~Em4RunActionMessenger()
{  
  delete SaveCmd;
  delete RndmSaveCmd; delete RndmReadCmd; delete RndmDir;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void Em4RunActionMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
  if (command == SaveCmd) Em4Run->SetSaveFlag(newValue);
  
  if (command == RndmSaveCmd)
      Em4Run->SetRndmFreq(RndmSaveCmd->GetNewIntValue(newValue));
		 
  if (command == RndmReadCmd)
    { G4cout << "\n---> rndm status restored from file: " << newValue << endl;
      HepRandom::restoreEngineStatus(newValue);
      HepRandom::showEngineStatus();
    }   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....