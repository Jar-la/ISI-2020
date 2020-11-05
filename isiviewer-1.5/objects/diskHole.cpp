#include "diskHole.h"

DiskHole::DiskHole(int nVertices)
  : TriMesh()
{
  _name = "DiskHole";

  // Vertex
  vector<Vertex> vCercleExt;
  vector<Vertex> vCercleInt;

  // Triangles
  vector<Triangle> t;


  float rCInt = 0.5;                // Rayon du cercle interieur entre 0 et 1
  float inc = 360.0/nVertices;      // Angle of each "slices"
  float incRad = inc * PI / 180;    // Angle in radians

  // vertex coordinates --------------------------------------

  // Push the vertex of the circles perimeters
  for (int i=0; i< nVertices; ++i){
      Vertex tempExt;
      Vertex tempInt;

      tempExt.x = cos(i* incRad);
      tempInt.x = rCInt * cos( i * incRad);

      tempExt.y = sin(i * incRad);
      tempInt.y = rCInt * sin( i * incRad);

      tempExt.z = 0;
      tempInt.z = 0;

      vCercleExt.push_back(tempExt);
      vCercleInt.push_back(tempInt);

  }

  // Triangles vertex indices ------------------------------------

  // Push the exterior circle
  for(int i = 0; i < vCercleExt.size(); ++i ) {
      Triangle tempExt;

      int current = i ;
      int current2 = (i + 1) % vCercleExt.size();
      int next = i + vCercleExt.size();

      tempExt.push_back(current);
      tempExt.push_back(current2);
      tempExt.push_back(next);

      t.push_back(tempExt);
  }

  // Push the interior circle
  for(int i = 0; i < vCercleInt.size(); ++i ) {
      vector<GLint> tempInt;

      int current = (i + 1) % vCercleExt.size();
      int next    =  i                           + vCercleExt.size();
      int next2   =((i + 1) % vCercleExt.size()) + vCercleExt.size();

      tempInt.push_back(current);
      tempInt.push_back(next2);
      tempInt.push_back(next);

      t.push_back(tempInt);
  }


  //--- Fill vertices and triangles vectors---------------

  // Fill vertices vector
  for(int i = 0; i != vCercleExt.size(); ++i) {
      this->addVertex(vCercleExt[i][0], vCercleExt[i][1], vCercleExt[i][2]);
  }
  for(int i = 0; i != vCercleInt.size(); ++i) {
      this->addVertex(vCercleInt[i][0], vCercleInt[i][1], vCercleInt[i][2]);
  }

  // Fill triangles vector
  for(int i = 0; i != t.size(); ++i) {
      this->addTriangle(t[i][0], t[i][1], t[i][2]);
  }

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();
}
