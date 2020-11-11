/**
 * @author Alexandre LAFON & Aurelien LLORCA
 * @date   Oct 2020
 *
 *  Defines a 3D  Sphere
 */
#ifndef  _SPHERE_H_
#define  _SPHERE_H_

#include "triMesh.h"

/**
 *  Sphere Object
 *
 */
class  Sphere : public TriMesh {
public:
  Sphere(int nVertices = 20);
  virtual ~ Sphere(){};

};

#endif
