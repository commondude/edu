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
      in>>m;
      map<int,vector<int>> graph;
      vector<int> t(2);
      for(int i=0;i<m;++i){
        in>>v1;
        in>>v2;
        in>>w;
        t[0]=v1-1;
        t[1]=v2-1;
        graph[w]=t;
      }

      // int i=0;
      // for(auto it=graph.begin();it!=graph.end();it++)
      // {
      //     cout<<"Weight of "<<i<<" edge = "<<it->first<<"\n";
      //     cout<<"It goes from "<<it->second[0]<<" to "<<it->second[1]<<"\n";
      //     i++;
      // }

      out<<kraskal_sum(n,graph) <<"\n";
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

  for(i=0;i<n;++i)
  {
    comp[i]=i;
    wlist[i].push_back(i);

  }

  // cout<<"Wlist\n";
  //
  // for(i=0;i<n;++i)
  // {
  //
  //   cout<<wlist[i][0];
  //
  // }
  // cout<<"\n";



  //Создаём вектор весов оставного дерева
  std::vector<int> weight;

  for(auto it=graph.begin();it!=graph.end();it++)
  {
    // cout<<"from = "<<it->second[0]<<" to = "<<it->second[1]<<"\n";

    if(comp[it->second[0]]!=comp[it->second[1]])
    {
      // cout<<"size of segment From= "<<wlist[comp[it->second[0]]].size()<< "\n  size of segment To = "<<wlist[comp[it->second[1]]].size()<<"\n";

      if(wlist[comp[it->second[0]]].size()>=wlist[comp[it->second[1]]].size())
      {
        // cout<<"Zero bigger\n";
        comp[it->second[1]]=comp[it->second[0]];

        for(i=0;i<wlist[it->second[1]].size();i++)
        {
          wlist[comp[it->second[0]]].push_back(wlist[it->second[1]][i]);
        }
        wlist[it->second[1]].clear();

      }
      else
      {
        // cout<<"One bigger\n";
        comp[it->second[0]]=comp[it->second[1]];

        for(i=0;i<wlist[it->second[0]].size();i++)
        {
          wlist[comp[it->second[1]]].push_back(wlist[it->second[0]][i]);
        }
        wlist[it->second[0]].clear();
      }


      weight.push_back(it->first);
      // cout<<"Add some weight = "<<it->first<<"\n";


    }
    // for (i=0;i<n;++i)
    // {
    //   cout<<"Weight list of "<<i<<" segment"<<"\n";
    //   for(int j=0;j<wlist[i].size();++j)
    //   {
    //       cout<<wlist[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
  }

  // cout<<"And sum is...\n";
  // cout<<"sum= "<<sum<<"\n";
  for(i=0;i<weight.size();++i)
  {
    // cout<<"Weight["<<i<<"]= "<<weight[i]<<"\n";
    sum+=weight[i];
    // cout<<"sum= "<<sum<<"\n";
  }

  // for (i=0;i<n;++i)
  // {
  //   cout<<"Weight list of "<<i<<" segment"<<"\n";
  //   for(int j=0;j<wlist[i].size();++j)
  //   {
  //       cout<<wlist[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }

  return sum;
}
