#include "cone.h"

Cone::Cone(int nVertices, int nDivH) //default  20
  : TriMesh()
{
  _name = "Cone";

  // vertex
  vector<Circle> vDisksEdge;
  Vertex vTop(0.0, 1.0, 0.0);
  Vertex vCenterBot(0.0, -1.0, 0.0);

  vector<Triangle> t;      // Triangles

  float incC = 360/nVertices ;         // Angle of each "slices"
  double incH = 2.0/nDivH;
  double decR= 1.0/nDivH;


  // Vertex de l'empilement de disques
  float r=1.0;
  for (double h = -1.0; h < 1; h+=incH ){
      Circle circle;
      for (int j=0; j< nVertices; ++j){   // for each points around the circle


          Vertex temp;
          temp.x = ((cos( j*incC * PI/180))*r);
          temp.y = (h);
          temp.z = ((sin( j*incC * PI/180))*r);

          circle.push_back(temp);
      }
      vDisksEdge.push_back(circle);
      r-=decR;
  }

  // Push the triangle of the edge of the cone
  for (int i=0; i < nDivH-1; ++i){
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
  this->addVertex(vTop.x, vTop.y, vTop.z );

  // Fill triangles vector
  for(int i = 0; i < t.size(); i++) {
      this->addTriangle(t[i][0] , t[i][1], t[i][2]);
  }

/*
  for (int i= 0; i< _vertices.size(); i++){
      cout << "v" << i << "=["<< _vertices[i].x << "," << _vertices[i].y << "," << _vertices[i].z << "]" << endl;
  }

  cout << "Triangle \n";
  for (int i= 0; i< _triangles.size() ; i++){
      cout << "t" << i << "=["<< _triangles[i][0] << "," << _triangles[i][1] << "," << _triangles[i][2] << "]" << endl;
  }
*/

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();





}
