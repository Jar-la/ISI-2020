#include "cylindre.h"

Cylinder::Cylinder(int nVertices, int nDivH)
  : TriMesh()
{
  _name = "Cylinder";

  // vertex
  vector<Circle> vDisksEdge;
  Vertex vCenterTop(0.0, 1.0, 0.0);
  Vertex vCenterBot(0.0, -1.0, 0.0);

  vector<Triangle> t;      // Triangles

  int nbDivC= nVertices;         // Nunber of "slices"
  float inc = 360.0/nbDivC;          // Angle of each "slices"
  float nbDivH =(float)nDivH;
  float res = 2.0/nbDivH;



  // Push the vertex of the edge of a cylinder
  for ( int i=0; i<= nbDivH; ++i){   // for each heights
      Circle circle;
      for (float j=0; j< nbDivC; ++j){   // for each points around the circle
          Vertex temp;
          temp.x = (cos( j*inc * PI/180));
          temp.y = ((res * i) - 1);
          temp.z = (sin( j*inc * PI/180));

          circle.push_back(temp);
      }
      vDisksEdge.push_back(circle);
  }


  // Push the triangles of the edge of a cylinder
  for (int i=0; i < nbDivH; ++i){
      for(int j = 0; j < nbDivC; ++j ) {
          Triangle temp1, temp2;
          // nbDivC * i => Dans le cercle au actuel
          // nbDivC * (i+1) => Dans le cercle au dessus

          temp1.push_back( j + (nbDivC * i) );
          temp1.push_back( j + (nbDivC * (i+1)) );
          temp1.push_back( ((j+1) % nbDivC) + (nbDivC * i) );

          t.push_back(temp1);

          temp2.push_back( j + (nbDivC * (i+1)) );
          temp2.push_back( ((j+1) % nbDivC) + (nbDivC * (i+1)) );
          temp2.push_back( ((j+1) % nbDivC) + (nbDivC * i) );

          t.push_back(temp2);
      }
  }

  for(int i=0; i < nbDivC; ++i){

      Triangle temp1, temp2;

      temp1.push_back(i);
      temp1.push_back( (i+1)% nbDivC );
      temp1.push_back(vDisksEdge.size() * nbDivC);

      t.push_back(temp1);

      temp2.push_back( (vDisksEdge.size() * nbDivC) + 1);
      temp2.push_back( ((vDisksEdge.size() * nbDivC) - nbDivC) + (i + 1) % nbDivC );
      temp2.push_back( ((vDisksEdge.size() * nbDivC) - nbDivC) +i);

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
