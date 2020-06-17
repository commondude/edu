#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int kraskal_sum(int n, map<int,vector<int>> &graph );

int main(){
  if (in.is_open())
    {
      //Input size N(cities) and M(roads)
      int n,m,
          v1,v2,w;
      in>>n;
      // cout<<"n= "<<n<<"\n";
      in>>m;
      // cout<<"m= "<<m<<"\n";

      map<int,vector<int>> graph;
      vector<int> t(2);
      for(int i=0;i<m;++i){
        in>>v1;
        in>>v2;
        in>>w;
        t[0]=v1-1;
        t[1]=v2-1;
        graph[w]=t;
        // cout<<"v1= "<<graph[w][0]<<"\n";
        // cout<<"v2= "<<graph[w][1]<<"\n";
        // cout<<"w= "<<w<<"\n";
      }

      // int i=0;
      // for(auto it=graph.begin();it!=graph.end();it++)
      // {
      //     cout<<"Weight of "<<i<<" edge = "<<it->first<<"\n";
      //     cout<<"It goes from "<<it->second[0]<<" to "<<it->second[1]<<"\n";
      //     i++;
      // }

      cout<<kraskal_sum(n,graph) <<"\n";



    }


  in.close();
  out.close();
}


int kraskal_sum(int n, map<int,vector<int>> &graph )
{
  int i;
  int sum=0;

  //Создаём 2 вектора компонентов связности
  vector<int> comp(n);
  vector<vector<int>> wlist(n);
  // cout<<"Enter Kraskal\n";
  for(i=0;i<n;++i)
  {
    comp[i]=i;
    // cout<<"Op\n";
    wlist[i].push_back(i);
    // cout<<"Chop\n";
  }
  // cout<<"Comp create\n";
  //Создаём вектор весов оставного дерева
  std::vector<int> weight;

  for(auto it=graph.begin();it!=graph.end();it++)
  {
    cout<<"it->second[0] = "<<it->second[0]<<" it->second[1] = "<<it->second[1]<<"\n";
    if(comp[it->second[0]]!=comp[it->second[1]])
    {
      cout<<"second[0]= "<<wlist[it->second[0]].size()<< "second[1] = "<<wlist[it->second[1]].size()<<"\n";
      if(wlist[it->second[0]].size()>=wlist[it->second[1]].size())
      {
        cout<<"Zero bigger\n";
        comp[it->second[1]]=it->second[0];

        for(i=0;i<wlist[it->second[1]].size();i++)
        {
          wlist[it->second[0]].push_back(wlist[it->second[1]][i]);
        }
        wlist[it->second[1]].clear();

      }
      else
      {
        cout<<"One bigger\n";
        comp[it->second[0]]=it->second[1];

        for(i=0;i<wlist[it->second[0]].size();i++)
        {
          wlist[it->second[1]].push_back(wlist[it->second[0]][i]);
        }
        wlist[it->second[0]].clear();
      }


      weight.push_back(it->first);
      cout<<"Add some weight = "<<it->first<<"\n";


    }
    // cout<<"And sum is...\n";

    for(i=0;i<weight.size();++i)
    {
      sum+=weight[i];
    }

  }


  return sum;
}
