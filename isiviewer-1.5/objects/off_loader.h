/**
 * @author Alexandre Lafon & Aurelien LLORCA
 * @date   Oct 2020
 *
 * Parses a OFF File
 */
#ifndef  _OFF_LOADER_H_
#define  _OFF_LOADER_H_

#include "triMesh.h"

/**
 * Object described by the off File
 *
 */
class OffLoader : public TriMesh {
public:
  OffLoader(string offFilePath);
  virtual ~OffLoader(){};

};


#endif
