
#include "sphere.h"

 Sphere:: Sphere(int nVertices) //default  20
  : TriMesh()
{
  _name = "Sphere";

  // vertex
  vector<Vertex> v;
  Vertex vCenterTop(0.0, 1.0, 0.0);
  Vertex vCenterBot(0.0, -1.0, 0.0);
  vector<Triangle> t;      // Triangles

  float latInc = 360.0/nVertices;         // Angle of each "slices"
  float lonInc = 180.0/nVertices;
  float r = 1.0;

  // Vertex
  for(float la = 0.0; la < 360.0; la += latInc){
        for(float lo = 0.0; lo < 180.0; lo += lonInc){
          Vertex temp;

          temp.x = (float) (r * sin(lo * PI/180) * cos(la * PI/180));
          temp.y = (float) (r * cos(lo * PI/180) );
          temp.z = (float) (r * sin(lo * PI/180) * sin(la * PI/180));

          v.push_back(temp);
      }
  }
  v.push_back(vCenterTop);
  v.push_back(vCenterBot);

  // Triangles
  for(int tr=0; tr<nVertices;++tr ){
      for (int i =0; i<nVertices-1; ++i){
          Triangle temp,temp2;
          if (v[i].x != v[i+nVertices].x){

          temp.push_back((i + (tr * nVertices)) % (v.size()-2 ));
          temp.push_back((i+nVertices + (tr * nVertices)) % (v.size()-2) );
          temp.push_back((i+nVertices +1 + (tr * nVertices)) % (v.size()-2) );

          temp2.push_back((i+ (tr * nVertices)) % (v.size()-2) );
          temp2.push_back((i+nVertices+1+ (tr * nVertices)) % (v.size()-2) );
          temp2.push_back((i+1+ (tr * nVertices)) % (v.size()-2) );

          t.push_back(temp);
          t.push_back(temp2);
          }
      }
  }


  for (int i = 0; i<nVertices;i++){
      Triangle temp,temp2;

      temp.push_back(i*nVertices +1);
      temp.push_back(v.size()-2);
      temp.push_back(((i+1) % nVertices)*nVertices +1);

      t.push_back(temp);

      temp2.push_back(v.size()-1);
      temp2.push_back(i*nVertices +nVertices-1);
      temp2.push_back(((i+1) % nVertices)*nVertices +nVertices-1);

      t.push_back(temp2);

  }

  //--- Fill vertices and triangles vectors

  // Fill vertices vector

  for ( int i = 0 ; i!= v.size(); ++i){   // for each heights
      this->addVertex(v[i].x, v[i].y, v[i].z);
  }

  // Fill triangles vector
  for(int i = 0; i < t.size(); i++) {
      this->addTriangle(t[i][0] , t[i][1], t[i][2]);
  }

  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();

}

