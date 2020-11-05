#include <iostream>
#include <fstream>
#include "objects/off_loader.h"

OffLoader::OffLoader(string offFilePath)
  : TriMesh()
{
  _name = "OffLoader";

   vector<Vertex> v;
   vector<Triangle> t;
   string line;

   bool ReadNbLine =false; // Have the line containing vertex_count face_count edge_count been read
   int vertex_count;
   int face_count;
   int edge_count;

   streampos prec;
   ifstream offFile(offFilePath);
   if (offFile.is_open())
   {
     while ( !offFile.eof() )
     {
         if (!ReadNbLine){ // si on n'as pas encore recupérer les nombres
             prec = offFile.tellg();
             getline(offFile,line);
               if ( !(line.compare(0,1,"#") ==0 || line.compare(0,1,"O") ==0 || line.compare("")==0 )){
                   offFile.seekg(prec);

                   offFile >> vertex_count >> face_count >>edge_count;

                   getline(offFile,line);
                   ReadNbLine =true;
               }


           }else if (vertex_count > (v.size()) ){ //si on n'as pas lu tout les sommets
               Vertex temp;
               float x,y,z;

               offFile >> x >> y>> z;

               temp.x=x;
               temp.y=y;
               temp.z=z;

               v.push_back(temp);
               getline(offFile,line);
         }else{

               int nbVertices;
               int nbTriangles;
               vector<int> ver;

               offFile >> nbVertices ;
               nbTriangles =nbVertices-2;

               for (int i = 0; i < nbVertices; ++i){
                   int a;

                   offFile >> a;
                   ver.push_back(a);
               }
               for(int i= 1; i <= nbTriangles; ++i){
                   if (ver[0] != ver[1]){
                       Triangle temp;
                       temp.push_back(ver[0]);
                       temp.push_back(ver[i]);
                       temp.push_back(ver[i+1]);

                       t.push_back(temp);
                   }

               }
               getline(offFile,line);
           }
       }
     offFile.close();
   }

   else cout << "Unable to open file";



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
  this->normalize();
}
