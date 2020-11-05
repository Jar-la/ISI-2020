/**
 * @file   main.cpp
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Sep 2012
 *
 * @brief  Declares an application, a main window and a 3D scene
 *
 *
 */
#include <QApplication>
#include "my_main_window.h"


#include "my_object3d.h"
#include "objects/cube.h"
#include "objects/pyramid.h"
#include "objects/cubeCorner.h"
#include "objects/disk.h"
#include "objects/diskHole.h"
#include "objects/cylindre.h"
#include "objects/cone.h"
#include "objects/sphere.h"
#include "objects/torus.h"
#include "objects/func_surface.h"
#include "objects/off_loader.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <tclap/CmdLine.h>

int main(int argc, char *argv[]){
  QApplication app(argc, argv);

  // Parse program arguments here
  // with the tclap library
  // http://tclap.sourceforge.net/manual.html
  bool offFileToLoad =false;
  string offFilePath;

  try{
      TCLAP::CmdLine cmd("Command description message",' ',"0.1");
      TCLAP::ValueArg<std::string> offFileArg("","off","off file to display",false,"","path to the OFF file");
      cmd.add(offFileArg);
      cmd.parse(argc, argv);
      offFilePath = offFileArg.getValue();
      if(offFilePath != ""){
          offFileToLoad = true;
      }
  } catch (TCLAP::ArgException &e)  // catch any exceptions
  { std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }


  // initialize my custom 3D scene
  float objectRadius = 1.;
  QPointer<MyScene> myScene = new MyScene(objectRadius);

  //add simple objects
  myScene->addObject(new Cube());
  myScene->addObject(new Pyramid());
  myScene->addObject(new CubeCorner());
  myScene->addObject(new Disk());       //nVertices defaults to 20
  myScene->addObject(new DiskHole());   //nVertices defaults to 20
  myScene->addObject(new Cylinder());   //nVertices defaults to 20 and nDivH defaults to 5
  myScene->addObject(new Cone());       //nVertices defaults to 20 and nDivH defaults to 5
  myScene->addObject(new Sphere());     //nVertices defaults to 20
  myScene->addObject(new Torus());      //nVertices defaults to 20, nRings defaults to 16 and ringRadius to 0.25

  // add surface functions
  myScene->addObject(new FuncSurface(50,50,-PI,PI,-PI,PI,func_expcos));
  myScene->addObject(new FuncSurface(50,50,-PI,PI,-PI,PI,func_expsin));
  myScene->addObject(new FuncSurface(50,50,-2*PI,2*PI,-2*PI,2*PI,func_sinXsinY));
  myScene->addObject(new FuncSurface(50,50,-2*PI,2*PI,-2*PI,2*PI,func_cosXcosY));

  // add user defined OFF files
  if (offFileToLoad){
      myScene->addObject(new OffLoader(offFilePath));
  }

  // initialize my custom main window
  QPointer<MyMainWindow> myMainWindow = new MyMainWindow(myScene);
  // display the window
  myMainWindow->show();
  // enter in the main loop
  return app.exec();
}

