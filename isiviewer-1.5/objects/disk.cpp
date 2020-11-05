#include "disk.h"

Disk::Disk(int nVertices)
  : TriMesh()
{
  _name = "Disk";

  vector<Vertex> v;            // Vertices
  Vertex center(0.0,0.0,0.0);
  vector<Triangle> t;          // Triangles

  float inc = 360.0/nVertices; // Angle of each "slices"

  // Vertex coordinates-----------------------------------

  // Push the vertex of the "edge" of the circle
  for (int i=0; i< nVertices; ++i){
      Vertex temp;

      temp.x = cos( i*inc * PI/180);
      temp.y = sin( i*inc * PI/180);
      temp.z = 0;

      v.push_back(temp);
  }

  // Push the center
  v.push_back(center);

  // Triangles -------------------------------------------
  for(int i = 0; i < v.size(); i++) {
      Triangle temp;

      int current = i ;
      int next = (i+1)% (v.size() -1);
      int center = v.size()-1;

      temp.push_back(center);
      temp.push_back(current);
      temp.push_back(next);

      t.push_back(temp);
  }


  //--- Fill vertices and triangles vectors---------------

  // Fill vertices vector
  for(int i = 0; i != v.size(); ++i) {
      this->addVertex(v[i][0], v[i][1], v[i][2]);

  }

  // Fill triangles vector
  for(int i = 0; i != t.size(); ++i) {
      this->addTriangle(t[i][0], t[i][1], t[i][2]);
  }

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();
}
