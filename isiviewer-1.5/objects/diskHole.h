/**
 * @author Alexandre LAFON & Aurelien LLORCA
 * @date   Oct 2020
 *
 *  Defines a 2D disk with a hole
 */
#ifndef  _DISKHOLE_H_
#define  _DISKHOLE_H_

#include "triMesh.h"

/**
 * DiskHole Object
 *
 */
class DiskHole : public TriMesh {
public:
  DiskHole(int nVertices = 20);
  virtual ~DiskHole(){};

};

#endif
