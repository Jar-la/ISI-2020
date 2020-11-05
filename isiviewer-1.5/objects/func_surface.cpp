#include "func_surface.h"

float func_expcos(float x, float y) {
 return exp(-(x*x/2+y*y/2))*cos(2*x*x+2*y*y);
}
float func_expsin(float x, float y) {
 return exp(-(x*x/2+y*y/2))*sin(2*x*x+2*y*y);
}
float func_sinXsinY(float x, float y) {
 return sin(x) * sin(y);
}
float func_cosXcosY(float x, float y) {
 return cos(x) * cos(y);
}

//nbx et nby sont le nombre de points d'échantillonage dans les directions x et y
//les min* et max* sont les bornes min et max dans les deux directions.
FuncSurface::FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float (&func)(float, float))
  : TriMesh()
{
  _name = "FuncSurface";

   vector<Vertex> v;
   vector<Triangle> t;

   double x;
   double y;
   double incX = 2.0/nbx;
   double incY = 2.0/nby;

   double valX;
   double valY;
   double valZ =0;
   double incValX = (maxx - minx) / nbx;
   double incValY = (maxy - miny) / nby;

   valX = minx;
   for( x = -1.0; x < 1.0 + incX; x += incX){
       valY = miny;
       for(y = -1.0; y< 1.0 + incX; y += incY){
           Vertex temp;
           valZ=0;
           valZ = func(valX,valY);

           temp.x = x;
           temp.y = valZ;
           temp.z = y;

           v.push_back(temp);
           valY+= incValY;
       }
       valX += incValX;
   }

   for(int j = 0; j < nbx; ++j){
       for(int i = 0; i < nby; ++i){

           Triangle temp1, temp2;

           int a = (i) + (j * nby + 1 * j);
           int b = (i + 1) + (j * nby + 1 * j);
           int c = (i + nby + 1 ) + (j * nby + 1 * j);
           int d = (i + 1 + nby + 1 ) + (j * nby + 1 * j);

           temp1.push_back(a);
           temp1.push_back(b);
           temp1.push_back(c);

           temp2.push_back(c);
           temp2.push_back(b);
           temp2.push_back(d);

           t.push_back(temp1);
           t.push_back(temp2);

       }
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
