#include "cubeCorner.h"

CubeCorner::CubeCorner()
  : TriMesh()
{
  _name = "CubeCorner";

  // vertex coordinates
  static const GLfloat v[11][3] = {
      {-1,-1,-1},{1,-1,-1},{1,-1,1},{-1,-1,1}, // bottom
      {-1,1,-1},{1,1,-1},{1,1,1},{-1,1,1}, // top
      {0,1,1},{1,1,0},{1,0,1}
  };

  // triangles vertex indices
  static const GLint t[16][3] = {
      {3,1,2},{3,0,1},          // Bottom triangles
      {4,0,3},{4,3,7},          // West triangles
      {5,0,4},{5,1,0},          // back triangles
      {4,9,5},{4,8,9},{4,7,8},  // top triangles
      {1,5,9},{1,9,10},{1,10,2},// East triangles
      {3,8,7},{3,10,8},{3,2,10},// Front triangles
      {8,10,9}
  };

  // triangle vertex normals
  static const GLint nt[16][3] = {
      {0,-1,0},{0,-1,0},
      {-1,0,0},{-1,0,0},
      {0,0,-1},{0,0,-1},
      {0,1,0},{0,1,0},{0,1,0},
      {1,0,0},{1,0,0},{1,0,0},
      {0,0,1},{0,0,1},{0,0,1},
      {1,1,1}
  };

  // triangle vertex normals
  static const GLint nv[48][3] = {
      {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
      {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},
      {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},
      {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},
      {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
      {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},
      {1,1,1},{1,1,1},{1,1,1}
  };


  //--- Fill vertices and triangles vectors

  // Fill vertices vector
  for (int i=0; i<11 ; ++i)
      this->addVertex(v[i][0], v[i][1], v[i][2]);

  // Fill triangles vector
  for (int i=0; i<16; ++i)
      this->addTriangle(t[i][0], t[i][1], t[i][2]);


   // Fill normals vectors
  bool use_computed_normals = true;
  if (use_computed_normals) {
      computeNormalsT();
      computeNormalsV();

  } else { // use manually defined normals
      // set triangle normals
      for (int i=0; i<16; ++i) {
          Normal nT(nt[i][0], nt[i][1], nt[i][2]);
          this->addNormalT(nT);
      }
      // set triangle vertex normals
      for (int i=0; i<48; ++i) {
          Normal nV(nv[i][0], nv[i][1], nv[i][2]);
          this->addNormalV(nV);
      }
  }

}
