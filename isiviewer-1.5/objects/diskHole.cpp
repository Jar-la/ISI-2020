#include "diskHole.h"

DiskHole::DiskHole()
  : TriMesh()
{
  _name = "DiskHole";

  // vertex
  vector<vector<GLfloat>> vCercleExt;
  vector<vector<GLfloat>> vCercleInt;

  vector<vector<GLint>> t;      // Triangles


  float rCInt = 0.5;            // Rayon du cercle interieur entre 0 et 1
  float nbDiv= 20;                 // Nunber of "slices"
  int inc = 360/nbDiv;          // Angle of each "slices"
  // vertex coordinates


  // Push the vertex of the "edge" of the circle
  for (int i=0; i< 360; i+= inc){
      vector<GLfloat> tempExt;
      vector<GLfloat> tempInt;

      tempExt.push_back(cos( i * PI/180));
      tempInt.push_back(rCInt * (cos( i * PI/180)));

      tempExt.push_back(sin( i * PI/180));
      tempInt.push_back(rCInt * (sin( i * PI/180)));

      tempExt.push_back(0);
      tempInt.push_back(0);

      vCercleExt.push_back(tempExt);
      vCercleInt.push_back(tempInt);
      //cout <<"[" << tempInt[0] << ","<< tempInt[1] << ","<< tempInt[2] << "]\n";
      //cout <<"[" << tempExt[0] << ","<< tempExt[1] << ","<< tempExt[2] << "]\n";

  }


  // triangles vertex indices
  for(int i = 0; i < vCercleExt.size(); ++i ) {
      vector<GLint> tempExt;

      int current = i ;
      int next = (i+1)%vCercleExt.size();

      tempExt.push_back(current);
      tempExt.push_back(current);
      tempExt.push_back(next);

      t.push_back(tempExt);

  }
  for(int i = 0; i < vCercleInt.size(); ++i ) {
      vector<GLint> tempInt;

      int current = i ;
      int next = (i+1)%vCercleExt.size();

      tempInt.push_back(current);
      tempInt.push_back(next);
      tempInt.push_back(next);

      t.push_back(tempInt);
  }


  //--- Fill vertices and triangles vectors

  // Fill vertices vector
  vector<GLfloat> buffer;
  vector<vector<GLfloat>>::iterator it;
  for(it = vCercleExt.begin(); it != vCercleExt.end(); ++it) {
      buffer = *it;
      this->addVertex(buffer[0],buffer[1],buffer[2]);

  }
  for(it = vCercleInt.begin(); it != vCercleInt.end(); ++it) {
      buffer = *it;
      this->addVertex(buffer[0],buffer[1],buffer[2]);

  }
  // Fill triangles vector
  for(int i = 0; i < nbDiv; i++) {

      this->addTriangle(t[i][0] + nbDiv, t[i][1], t[i][2]);
      this->addTriangle(t[i][0] + nbDiv, t[i][2], t[i][2] + nbDiv);

  }
  // Fill normals vectors
  computeNormalsT();
  computeNormalsV();



}
