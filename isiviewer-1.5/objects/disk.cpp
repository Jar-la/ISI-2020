#include "disk.h"

Disk::Disk(int nVertices)
  : TriMesh()
{
  _name = "Disk";

  vector<vector<GLfloat>> v;    // vertex
  vector<vector<GLint>> t;      // Triangles

  int nbDiv= nVertices;         // Nunber of "slices"
  int inc = 360/nbDiv;          // Angle of each "slices"

  // vertex coordinates

  // Push the center
  vector<GLfloat>center;
  center.push_back( 0.0 );
  center.push_back( 0.0 );
  center.push_back( 0.0 );
  v.push_back(center);

  // Push the vertex of the "edge" of the circle
  for (int i=0; i< nbDiv; ++i){
      vector<GLfloat> temp;
      temp.push_back(cos( i*inc * PI/180));
      temp.push_back(sin( i*inc * PI/180));
      temp.push_back(0);
      v.push_back(temp);
  }


  // triangles vertex indices
  for(int i = 1; i <= v.size(); i++) {
      vector<GLint> temp;
      int current = i ;
      int next = (i+1)%v.size();
      if (next == 0 ) next =1;
      temp.push_back(0);
      temp.push_back(current);
      temp.push_back(next);
      t.push_back(temp);
  }


  //--- Fill vertices and triangles vectors

  // Fill vertices vector
  //cout << "v.size() = " << v.size() << endl;
  for(int i = 0; i != v.size(); ++i) {

      //cout << i << ": [" << v[i][0] << ","<< v[i][1] << ","<< v[i][2] << "]\n";
      this->addVertex(v[i][0], v[i][1], v[i][2]);

  }
  // Fill triangles vector
  for(int i = 0; i != t.size(); ++i) {

      //cout << i << ": [" << t[i][0] << ","<< t[i][1] << ","<< t[i][2] << "]\n";
      this->addTriangle(t[i][0], t[i][1], t[i][2]);

  }
  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();




}
