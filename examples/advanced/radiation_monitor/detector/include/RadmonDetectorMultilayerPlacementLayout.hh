//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// File name:     RadmonDetectorMultilayerPlacementLayout.hh
// Creation date: Sep 2005
// Main author:   Riccardo Capra <capra@ge.infn.it>
//
// Id:            $Id: RadmonDetectorMultilayerPlacementLayout.hh,v 1.4 2006/06/29 16:10:45 gunter Exp $
// Tag:           $Name: geant4-08-02 $
//
// Description:   Internal class to manage placed multilayer
//

#ifndef   RADMONDETECTORMULTILAYERPLACEMENTLAYOUT_HH
 #define  RADMONDETECTORMULTILAYERPLACEMENTLAYOUT_HH
 
 // Include files
 #include "G4RotationMatrix.hh"
 #include "G4ThreeVector.hh"
 #include "G4String.hh"
 
 class RadmonDetectorMultilayerPlacementLayout
 {
  public:
   inline                                       RadmonDetectorMultilayerPlacementLayout();
   inline                                       RadmonDetectorMultilayerPlacementLayout(const RadmonDetectorMultilayerPlacementLayout & copy);
   inline                                      ~RadmonDetectorMultilayerPlacementLayout();

   inline RadmonDetectorMultilayerPlacementLayout & operator=(const RadmonDetectorMultilayerPlacementLayout & copy);

   inline const G4String &                      GetLabel(void) const;
   inline const G4String &                      GetMultilayerLabel(void) const;

   inline void                                  SetLabel(const G4String & label);
   inline void                                  SetMultilayerLabel(const G4String & label);

   inline const G4ThreeVector &                 GetAbsolutePosition(void) const;
   inline const G4RotationMatrix &              GetAbsoluteRotation(void) const;
   G4ThreeVector                                GetRelativePosition(const RadmonDetectorMultilayerPlacementLayout & reference) const;
   G4RotationMatrix                             GetRelativeRotation(const RadmonDetectorMultilayerPlacementLayout & reference) const;

   inline void                                  SetAbsolutePosition(const G4ThreeVector & position);
   inline void                                  SetAbsoluteRotation(const G4RotationMatrix & rotation);
   void                                         SetRelativePosition(const RadmonDetectorMultilayerPlacementLayout & reference, const G4ThreeVector & position);
   void                                         SetRelativeRotation(const RadmonDetectorMultilayerPlacementLayout & reference, const G4RotationMatrix & rotation);

   void                                         DumpLayout(std::ostream & out, const G4String & indent=G4String()) const;

  private:
  // Private attributes
   G4String                                     placementLabel;
   G4String                                     multilayerLabel;
   G4RotationMatrix                             multilayerRotation;
   G4ThreeVector                                multilayerPosition;
 };

 // Inline implementations
 #include "RadmonDetectorMultilayerPlacementLayout.icc"
#endif /* RADMONDETECTORMULTILAYERPLACEMENTLAYOUT_HH */