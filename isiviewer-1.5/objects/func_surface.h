/**
 * @author Alexandre Lafon
 * @date   Oct 2020
 *
 * Defines a surface that displays a function
 */
#ifndef  _FUNC_SURFACE_H_
#define  _FUNC_SURFACE_H_

#include "triMesh.h"

/**
 * Surface Object
 *
 */
class FuncSurface : public TriMesh {
public:
  FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float(&func)(float, float));
  virtual ~FuncSurface(){};

};
float func_expcos(float x, float y);
float func_expsin(float x, float y);
float func_sinXsinY(float x, float y);
float func_cosXcosY(float x, float y);


#endif
