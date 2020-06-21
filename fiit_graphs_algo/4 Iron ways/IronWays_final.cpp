#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int kraskal_sum(int n, map<int,vector<int>> &graph,vector<int> &weight );

int main(){
  if (in.is_open()!=true)
    {
      return 1;

    }

    int n,m,min,second_min=0,
        v1,v2,w;
    //Создаём вектор весов оставного дерева
    std::vector<int> weight,memory_weight;

    in>>n;
    in>>m;
    map<int,vector<int>> graph;
    map<int,int> summap;
    map<int,int> :: iterator sm;
    vector<int> t(2);

    for(int i=0;i<m;++i){
      in>>v1>>v2>>w;
      t[0]=v1-1;
      t[1]=v2-1;
      graph[w]=t;
    }

    min=kraskal_sum(n,graph,weight);
    memory_weight.swap(weight);

    for(int i=memory_weight.size()-1;i>=0;--i)
    {
      weight.clear();
      w=memory_weight[i];
      t[0]=graph[w][0];
      t[1]=graph[w][1];
      graph.erase(w);

      second_min=kraskal_sum(n,graph,weight);

      graph[w]=t;

      if(second_min!=0)
      {

        summap[second_min]=second_min;
      }
    }

    sm=summap.begin();
    second_min=sm->second;
    out<<second_min;

    in.close();
    out.close();
}


int kraskal_sum(int n, map<int,vector<int>> &graph,vector<int> &weight )
{
  int i,border,v,iz,toclear;
  int sum=0;

  //Создаём 2 вектора компонентов связности
  vector<int> comp(n);
  vector<vector<int>> wlist(n);

  for(i=0;i<n;++i)
  {
    comp[i]=i;
    wlist[i].push_back(i);

  }


  for(auto it=graph.begin();it!=graph.end();it++)//Проходим все дуги сортированные по весу от мин к макс
  {

    iz=it->second[0];//Сахар для исходящей вершины
    v=it->second[1];//Сахар для вершины в которую идёт дуга

    if(comp[iz]!=comp[v])//Если вершины в разных компонентах связности
    {
      if(wlist[comp[iz]].size()>=wlist[comp[v]].size())//Если размер КС исх вершины больше либо равен размеру КС вх вершины

      {

        toclear=comp[v];//Запоминаем поглащаемую КС
        border=wlist[toclear].size();//Количество вершин КС вх вершины

        for(i=0;i<border;++i)//по количеству вершин КС
        {
          wlist[comp[iz]].push_back(wlist[toclear][i]);//добавляем вершину из КСвх в КСисх
          comp[wlist[toclear][i]]=comp[iz];//переприсваиваем  значение КС добавленной вершине
        }
        wlist[toclear].clear();//Очищаем КС вх вершины
      }
      else
      {
        toclear=comp[iz];
        border=wlist[toclear].size();

        for(i=0;i<border;i++)
        {
          wlist[comp[v]].push_back(wlist[toclear][i]);
          comp[wlist[toclear][i]]=comp[v];
        }
        wlist[toclear].clear();
      }

      weight.push_back(it->first);
    }
  }

  if(weight.size()<n-1){
    sum=0;
  }
  else
  {
    for(i=0;i<weight.size();++i)
    {
      sum+=weight[i];
    }
  }

  return sum;
}
