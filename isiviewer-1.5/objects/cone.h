/**
 * @author Alexandre LAFON
 * @date   Oct 2020
 *
 *  Defines a 3D Cone
 */
#ifndef  _CONE_H_
#define  _CONE_H_

#include "triMesh.h"

typedef std::vector<Vertex> Circle;

/**
 * Cone Object
 *
 */
class Cone : public TriMesh {
public:
  Cone(int nVertices = 20, int nDivH =5);
  virtual ~Cone(){};

};

#endif
