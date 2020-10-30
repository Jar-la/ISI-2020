/**
 * @author Alexandre LAFON
 * @date   Oct 2020
 *
 *  Defines a 3D  Sphere
 */
#ifndef  _SPHERE_H_
#define  _SPHERE_H_

#include "triMesh.h"

typedef std::vector<Vertex> Circle;

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
