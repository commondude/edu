#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

// void dfs_rec(){
//
// }




int main(){
  if (in.is_open())
    {
      int n,i,j,z,min_int=-2147483647;
      in>>n;
      cout<<"n= "<<n<<"\n";
      vector<int> w;//Вектор весов
      vector<vector<int>> v(n,vector<int>());//Граф

      for(i=0;i<n;i++){
        in>>j;
        w.push_back(j);
        cout<<"Weight of "<<i<<" vertex is "<<j<<"\n";
      }

      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          in>>z;
          cout<<"z "<<z<<"\n";
          if(z==1){
            v[i].push_back(w[i]);
            cout<<"Exist from "<<i<<" to "<<j<<" weight "<<w[i]<<"\n";
          }else{
            v[i].push_back(min_int);
            cout<<"Doesn't Exist from "<<i<<" to "<<j<<" weight "<<0  <<"\n";
          }
        }
      }

      //Вывод
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<v[i][j]<<" ";
        }
        cout<<"\n";
      }




    }


  in.close();
  out.close();
}
