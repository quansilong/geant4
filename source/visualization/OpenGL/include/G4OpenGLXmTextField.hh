// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmTextField.hh,v 1.2.8.1 1999/12/07 20:53:21 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 
//Text field class. Inherits from G4OpenGLXmVWidgetComponent

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#ifndef G4OPENGLXMTEXTFIELD_HH
#define G4OPENGLXMTEXTFIELD_HH

#include "G4OpenGLXmVWidgetComponent.hh"
//#include "G4OpenGLXmConvenienceRoutines.hh"

class G4OpenGLXmTextField : public G4OpenGLXmVWidgetComponent
{

public:
  G4OpenGLXmTextField (char*,G4double*); //constructor
  G4OpenGLXmTextField (char*,char*);     //constructor
  ~G4OpenGLXmTextField ();               //destructor

  void SetName (char*);
  char* GetName ();

  void SetValue (G4double);
  void SetValue (char*);
  char* GetValue ();

  void AddYourselfTo (G4OpenGLXmVWidgetContainer*);

  Widget* GetPointerToParent ();
  Widget* GetPointerToWidget ();

private:
  char* name;
  void* value;
  G4bool text;
  char* initial;
  Widget text_label;
  Widget text_field;
  Widget* parent;
};

#endif

#endif