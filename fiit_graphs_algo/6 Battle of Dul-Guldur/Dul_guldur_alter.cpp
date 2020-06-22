#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("test5.txt");
ofstream out("output.txt");

void max_flow();
void basenet();

int main(){
  if (!in.is_open())
    {
      return 1;
    }

  int n;
  in>>n;

  vector<vector<int>> wizards(n,vector<int>(4));
  for(int i=0;i<n;++i)
  {
    in>>wizards[i][0];
    in>>wizards[i][1];
    in>>wizards[i][2];
    wizards[i][3]=0;
  }

  vector<vector<int>> graph(n,vector<int>(n,-1));
  int to,weight;
  for(int i=0;i<n;++i)
  {
      if(wizards[i][2]!=0)
      {
        for(int j=0;j<wizards[i][2];++j)
        {
          in>>to>>weight;
          graph[i][to]=weight;
        }
      }
  }

  // //Вывод графа
  for(int i=0;i<n;++i)
  {
    if(wizards[i][2]!=0)
    {
      // cout<<"Vertex["<<i<<"] has edges :\n";
      for(int j=0;j<n;++j)
      {
        if(graph[i][j]!=-1)
        {
            // cout<<"To vertex["<<j<<"] which weight is "<<graph[i][j]<<"\n";
        }

      }
    }

  }


  cout<<"\n";
  for(int i=0;i<n;++i)
  {
    cout<<"Wizard №"<<i<<"\n";
    cout<<"hungry = "<<wizards[i][0]<<"\n";
    cout<<"dulgurfight="<<wizards[i][1]<<"\n";
    cout<<"friends = "<<wizards[i][2]<<"\n";
    cout<<"dulgurboom = "<<wizards[i][3]<<"\n";
    cout<<"\n";
  }








  in.close();
  out.close();
}
