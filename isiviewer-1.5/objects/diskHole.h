/**
 * @author Alexandre LAFON
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
  DiskHole();
  virtual ~DiskHole(){};

};

#endif
