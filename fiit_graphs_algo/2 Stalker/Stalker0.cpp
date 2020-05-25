#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n,k,i,j,z,roads,start_building,finish_building;



int main(){

  if (in.is_open())
    {
      in>>n;
      in>>k;
      cout<<n<<"\n";
      cout<<k<<"\n";
      vector<vector<int>> v(n*(k+1),vector<int>());
      cout<<"Vector size "<<v.size()<<"\n";
      vector<int> d(n*k,-1);

      for(i=1;i<k+1;i++){
        in>>roads;
        cout << "Number of roads " <<roads<< '\n';

        for(j=0;j<roads;j++){
          in>>start_building;
          in>>finish_building;
          cout << "Road from " <<start_building<<" to "<<finish_building<< '\n';
          start_building-=1;
          finish_building-=1;
          cout<<start_building<<" "<<finish_building<<"\n";
          //Добавляем дуги между вершинами в текущей карте
          cout<<(n*i)+start_building<<"\n";
          v[((n*i)+start_building)].push_back(finish_building);
          cout<<(n*i)+finish_building<<"\n";
          v[((n*i)+finish_building)].push_back(start_building);



          }







        }

      cout << "Input done!" << '\n';


      // Вывод графа
      // for (i=0;i<k+1;i++){
      //   cout << "Map №" <<i<< '\n';
      //   for (j=0;j<n;j++){
      //     for(z=0;z<v[i*k+j].size();z++){
      //       cout << "Vertex №" <<j+1<<" has roads to "<<v[i*k+j][z]<< '\n';
      //     }
      //   }
      // }

      for(i=0;i<(n*(k+1));i++){
        cout<<v[i].size()<<"\n";
        for(j=0;j<v[i].size();j++){
          cout << v[i][j];
        }

      }

    }
    else{
      std::cout << "File not found!" << '\n';
    }





   cout<<"\n";
   in.close();
   out.close();
}
