/**
 * @author Alexandre LAFON
 * @date   Oct 2020
 *
 *  Defines a 3D Cylinder
 */
#ifndef  _CYLINDER_H_
#define  _CYLINDER_H_

#include "triMesh.h"

typedef std::vector<Vertex> Circle;

/**
 * Cylinder Object
 *
 */
class Cylinder : public TriMesh {
public:
  Cylinder();
  virtual ~Cylinder(){};

};

#endif
