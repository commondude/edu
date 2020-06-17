#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int kraskal();

int main(){
  if (in.is_open())
    {
      //Input size N(cities) and M(roads)
      int n,m,
          v1,v2,w;
      in>>n;
      cout<<"n= "<<n<<"\n";
      in>>m;
      cout<<"m= "<<m<<"\n";

      vector<vector<int>> v(n,vector<int>(2));
      map<int,vector<int>> graph;

      for(int i=0;i<m;++i){
        in>>v1;
        in>>v2;
        in>>w;
        //graph.insert(w,[v1,v2]);

        cout<<"v1= "<<v1<<"\n";
        cout<<"v2= "<<v2<<"\n";
        cout<<"w= "<<w<<"\n";
      }



    }


  in.close();
  out.close();
}
