#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n,k,i,j,roads,start_building,finish_building;



int main(){

  if (in.is_open())
    {
      in>>n;
      in>>k;
      cout<<n<<"\n";
      cout<<k<<"\n";
      vector<vector<string>> v(k+1,vector<string>(n,""));
      cout<<"Vector size "<<v.size()<<"\n";

      for(i=0;i<k;i++){
        in>>roads;
        cout << "Number of roads " <<roads<< '\n';

        for(j=0;j<roads;j++){
          in>>start_building;
          in>>finish_building;
          cout << "Road from " <<start_building<<" to "<<finish_building<< '\n';
          start_building-=1;
          finish_building-=1;
          //Добавляем дуги между вершинами в текущей карте
          if(v[i][start_building].find((char)finish_building)==string::npos){
            v[i][start_building]+=to_string(finish_building);
            // std::cout << "sdf " << to_string(finish_building)<<'\n';
          }


          if(v[i][finish_building].find((char)start_building)==string::npos){
            v[i][finish_building]+=to_string(start_building);
          }


          




        }
      }
      cout << "Input done!" << '\n';


      // Вывод графа
      for (i=0;i<k;i++){
        cout << "Map №" <<i<< '\n';
        for(j=0;j<n;j++){
          cout << "Vertex №" <<j<<" has roads to "<<v[i][j]<< '\n';
        }
      }
    }
    else{
      std::cout << "File not found!" << '\n';
    }






   in.close();
   out.close();
}
