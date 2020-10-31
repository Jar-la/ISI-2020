#include "torus.h"

 Torus:: Torus(int nVertices, int nRings, float ringRadius) //default  20, 16, 0.25
  : TriMesh()
{
  _name = " Torus";

  // vertex
  vector<Vertex> ver;      // Vertices
  vector<Triangle> t;      // Triangles

  float radius = 1- ringRadius;

  int numVerticesPerRow = nVertices ;
  int numVerticesPerColumn = nRings ;

  float theta = 0.0f;
  float phi = 0.0f;
  float verticalAngularStride = (float)(PI * 2.0f) / (float)nRings;
  float horizontalAngularStride = ((float)PI * 2.0f) / (float)nVertices;

  // Vertex
  for (int verticalIt = 0; verticalIt < numVerticesPerColumn; verticalIt++)
  {
    theta = verticalAngularStride * verticalIt;

    for (int horizontalIt = 0; horizontalIt < numVerticesPerRow; horizontalIt++)
    {
      phi = horizontalAngularStride * horizontalIt;

      Vertex temp;
      temp.x = (float)cos(theta) * (radius + ringRadius * (float)cos(phi));
      temp.y = (float)sin(theta) * (radius + ringRadius * (float)cos(phi));
      temp.z = ringRadius * (float)sin(phi);

      ver.push_back(temp);

    }
  }


  // Triangles
  for(int j = 0 ; j < nRings; ++j){
        for(int i = 0; i < nVertices ; ++i){

          Triangle temp,temp2;
          short lt = (short)((i + j * (numVerticesPerRow)) % ver.size());
          short rt = (short)(((i + 1) + j * (numVerticesPerRow)) % ver.size());

          short lb = (short)((i + (j + 1) * (numVerticesPerRow)) % ver.size());
          short rb = (short)(((i + 1) + (j + 1) * (numVerticesPerRow)) % ver.size());

          temp.push_back(lt);
          temp.push_back(lb);
          temp.push_back(rt);
          t.push_back(temp);

          temp2.push_back(rt);
          temp2.push_back(lb);
          temp2.push_back(rb);
          t.push_back(temp2);

      }
  }


  //--- Fill vertices and triangles vectors

  // Fill vertices vector

  for ( int i = 0 ; i!= ver.size(); ++i){   // for each heights
      this->addVertex(ver[i].x, ver[i].y, ver[i].z);
  }

  // Fill triangles vector
  for(int i = 0; i < t.size(); i++) {
      this->addTriangle(t[i][0] , t[i][1], t[i][2]);
  }

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();





}

