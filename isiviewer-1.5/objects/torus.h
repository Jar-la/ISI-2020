/**
 * @author Alexandre LAFON
 * @date   Oct 2020
 *
 *  Defines a 3D Torus
 */
#ifndef  _TORUS_H_
#define  _TORUS_H_

#include "triMesh.h"



/**
 *  Torus Object
 *
 */
class  Torus : public TriMesh {
public:
  Torus(int nVertices = 20, int nRings= 16, float ringRadius = 0.25 );
  virtual ~ Torus(){};

};

#endif
