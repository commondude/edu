#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("test2.txt");
ofstream out("output.txt");

int kraskal_sum(int n, map<int,vector<int>> &graph,vector<int> &weight );

int main(){
  if (in.is_open())
    {
      //Input size N(cities) and M(roads)
      int n,m,min,second_min=0,
          v1,v2,w;
      //Создаём вектор весов оставного дерева
      std::vector<int> weight,memory_weight;

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
      min=kraskal_sum(n,graph,weight);
      cout<< "min = "<<min<<"\n";
      memory_weight.swap(weight);
      // cout<<"memory size "<<memory_weight.size()<<"\n";
      // for(int i=memory_weight.size()-1;i>=0;--i)
      // {
      //
      //   weight.clear();
      //   w=memory_weight[i];
      //
      //   t[0]=graph[w][0];
      //   t[1]=graph[w][1];
      //
      //   graph.erase(w);
      //   second_min=kraskal_sum(n,graph,weight);
      //   cout<<"second_min ="<<second_min<<"\n";
      //   cout<<"\n";
      //   graph[w]=t;
      //   if(second_min>min)
      //   {
      //     break;
      //   }
      //
      //
      //
      // }

      out<<second_min;

    }


  in.close();
  out.close();
}


int kraskal_sum(int n, map<int,vector<int>> &graph,vector<int> &weight )
{
  int i,border;
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





  for(auto it=graph.begin();it!=graph.end();it++)//Проходим все дуги сортированные по весу от мин к макс
  {
    // cout<<"from = "<<it->second[0]<<" to = "<<it->second[1]<<"\n";

    if(comp[it->second[0]]!=comp[it->second[1]])//Если вершины в разных компонентах связности
    {
      if(wlist[comp[it->second[0]]].size()>=wlist[comp[it->second[1]]].size())//Если размер КС исх вершины больше либо равен размеру КС вх вершины
      //То
      {
        cout<<"Zero bigger "<<wlist[comp[it->second[0]]].size()<<" then "<<wlist[comp[it->second[1]]].size()<<"\n";


        border=wlist[comp[it->second[1]]].size();//Количество вершин КС вх вершины
        for(int i=0;i<border;++i)//по количеству вершин КС
        {

          // cout<<"Test i= "<<i<<"\n";
          cout<<"Test1 size= "<<border<<"\n";
          wlist[comp[it->second[0]]].push_back(wlist[comp[it->second[1]]][i]);//добавляем вершину из КСвх в КСисх
          comp[wlist[it->second[1]][i]]=comp[it->second[0]];//переприсваиваем  значение КС добавленной вершине
        }

        wlist[comp[it->second[1]]].clear();//Очищаем КС вх вершины
        comp[it->second[1]]=comp[it->second[0]];

      }
      //Иначе
      else
      {
        cout<<"One bigger "<<wlist[comp[it->second[1]]].size()<<" then "<<wlist[comp[it->second[0]]].size()<<"\n";
        // comp[it->second[0]]=comp[it->second[1]];
        border=wlist[comp[it->second[0]]].size();
        for(i=0;i<border;i++)
        {
          cout<<"Test1 size= "<<border<<"\n";
          wlist[comp[it->second[1]]].push_back(wlist[comp[it->second[0]]][i]);
          comp[wlist[it->second[0]][i]]=comp[it->second[1]];
        }
        wlist[comp[it->second[0]]].clear();
        comp[it->second[0]]=comp[it->second[1]];
      }


      weight.push_back(it->first);
      // cout<<"Add some weight = "<<it->first<<"\n";

      for (i=0;i<n;++i)
      {
        cout<<"Weight list of "<<i<<" segment"<<"\n";
        for(int j=0;j<wlist[i].size();++j)
        {
            cout<<wlist[i][j]<<" ";
        }
        cout<<"\n";
      }

      for(i=0;i<n;++i)
      {
        cout<<"Comp "<<i<<" elem = "<<comp[i]<<"\n";
      }
      cout<<"\n";
    }

  }



  // for(i=0;i<n;++i)
  // {
  //   cout<<"Comp "<<i<<" elem = "<<comp[i]<<"\n";
  // }
  // cout<<"\n";

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
  if(weight.size()<n-1){
    sum=0;
  }
  return sum;
}
