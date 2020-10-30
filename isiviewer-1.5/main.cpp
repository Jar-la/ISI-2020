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


/**
* Program usage
* Should be handled with the tclap library
*/
void usage(char* name){
  cout<< "usage: " << name << " [options]" <<endl;
  cout<< "options:" <<endl;
  cout<< "  -h, --help                 shows this message" <<endl;
  cout<< "  --off file                 loads OFF file" <<endl;
}

int main(int argc, char *argv[]){
  QApplication app(argc, argv);

  // Parse program arguments here
  // with the tclap library
  // http://tclap.sourceforge.net/manual.html
  //

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
  myScene->addObject(new Cone(20,10));       //nVertices defaults to 20 and nDivH defaults to 5
  myScene->addObject(new Sphere(50));

  // add surface functions
  // ...

  // add user defined OFF files
  // ...

  // initialize my custom main window
  QPointer<MyMainWindow> myMainWindow = new MyMainWindow(myScene);
  // display the window
  myMainWindow->show();
  // enter in the main loop
  return app.exec();
}

