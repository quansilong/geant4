// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLImmediateWin32Viewer.hh,v 1.2.2.1 1999/12/07 20:53:15 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 
// Class G4OpenGLImmediateWin32Viewer : a class derived from
//   G4OpenGLWin32Viewer and G4OpenGLImmediateViewer.

#ifdef G4VIS_BUILD_OPENGLWIN32_DRIVER

#ifndef G4OpenGLIMMEDIATEWIN32VIEWER_HH
#define G4OpenGLIMMEDIATEWIN32VIEWER_HH

#include "G4VViewer.hh"
#include "G4OpenGLImmediateViewer.hh"
#include "G4OpenGLWin32Viewer.hh"

#include "globals.hh"
#include "g4rw/tvordvec.h"

class G4OpenGLImmediateSceneHandler;

class G4OpenGLImmediateWin32Viewer:
public G4OpenGLWin32Viewer, public G4OpenGLImmediateViewer{
  
public:
  G4OpenGLImmediateWin32Viewer (G4OpenGLImmediateSceneHandler& scene);
  void DrawView ();
};

#endif

#endif