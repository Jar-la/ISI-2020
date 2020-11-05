#include "cylindre.h"

Cylinder::Cylinder(int nVertices, int nDivH)
  : TriMesh()
{
  _name = "Cylinder";

  // Vertex
  vector<Circle> vDisksEdge;
  Vertex vCenterTop(0.0, 1.0, 0.0);
  Vertex vCenterBot(0.0, -1.0, 0.0);

  vector<Triangle> t;               // Triangles

  float inc = 360.0/nVertices;      // Angle of each "slices"
  float incRad = inc * PI/180;      // Angle in radian
  float incH = 2.0/nDivH;           // difference in height

  // Push the vertex of the edge of a cylinder
  for ( int i=0; i<= nDivH; ++i){           // for each heights
      Circle circle;
      for (float j=0; j< nVertices; ++j){   // for each points around the circle
          Vertex temp;
          temp.x = cos(j * incRad);
          temp.y = (incH * i) - 1;
          temp.z = sin(j * incRad);

          circle.push_back(temp);
      }
      vDisksEdge.push_back(circle);
  }

  // Push the triangles of the sides of a cylinder
  for (int i=0; i < nDivH; ++i){
      for(int j = 0; j < nVertices; ++j ) {
          Triangle temp1, temp2;
          // nVertices * i => Dans le cercle au actuel
          // nVertices * (i+1) => Dans le cercle au dessus

          temp1.push_back( j + (nVertices * i) );
          temp1.push_back( j + (nVertices * (i+1)) );
          temp1.push_back( ((j+1) % nVertices) + (nVertices * i) );

          t.push_back(temp1);

          temp2.push_back( j + (nVertices * (i+1)) );
          temp2.push_back( ((j+1) % nVertices) + (nVertices * (i+1)) );
          temp2.push_back( ((j+1) % nVertices) + (nVertices * i) );

          t.push_back(temp2);
      }
  }

  // Push the triangles of the top and bottom of a cylinder
  for(int i=0; i < nVertices; ++i){

      Triangle temp1, temp2;

      temp1.push_back(i);
      temp1.push_back( (i+1)% nVertices );
      temp1.push_back(vDisksEdge.size() * nVertices);

      t.push_back(temp1);

      temp2.push_back( (vDisksEdge.size() * nVertices) + 1);
      temp2.push_back( ((vDisksEdge.size() * nVertices) - nVertices) + (i + 1) % nVertices );
      temp2.push_back( ((vDisksEdge.size() * nVertices) - nVertices) +i);

      t.push_back(temp2);
  }

  //--- Fill vertices and triangles vectors

  // Fill vertices vector

  for ( int i = 0 ; i!= vDisksEdge.size(); ++i){   // for each heights
      Circle circle = vDisksEdge[i];
      for (int j=0; j!= circle.size(); ++j){   // for each points aroound the circle
          this->addVertex(circle[j].x, circle[j].y, circle[j].z ); //add it to the vertex list
      }
  }
  this->addVertex(vCenterBot.x, vCenterBot.y, vCenterBot.z );
  this->addVertex(vCenterTop.x, vCenterTop.y, vCenterTop.z );

  // Fill triangles vector
  for(int i = 0; i < t.size(); i++) {
      this->addTriangle(t[i][0] , t[i][1], t[i][2]);
  }

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();
}
