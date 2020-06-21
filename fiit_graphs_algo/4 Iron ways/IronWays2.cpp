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
  if (in.is_open()) {
    return 0;
  }

  int n,m,min,second_min=0,
      v1,v2,w;
  std::vector<int> weights, weights2;

  in>>n;
  in>>m;
  map<int,vector<int>> graph;
  for(int i=0;i<m;++i) {
    in >> v1 >> v2 >>w;
    graph[w]={v1,v2};
  }

  min=kraskal_sum(n,graph,weights);

  weights2.

  for (int i = 0; i < weights.size(); ++i) {
    int temp = graph[i][1];
    graph[i][1] = graph[i][0];

    min2 = kraskal_sum(n,graph,weights);

    graph[i][1] = temp;
  }

  out<<second_min;

  in.close();
  out.close();
}


int kraskal_sum(int n, map<int,vector<int>> &graph,vector<int> &weight ) {
  int i,border;
  int sum=0;
  vector<int> comp(n);
  vector<vector<int>> wlist(n);

  for(i=0;i<n;++i) {
    comp[i]=i;
    wlist[i].push_back(i);
  }

  for(auto it=graph.begin();it!=graph.end();it++) {
    if(comp[it->second[0]]!=comp[it->second[1]]) {
      if(wlist[comp[it->second[0]]].size() >= wlist[comp[it->second[1]]].size()) {




        border=wlist[comp[it->second[1]]].size();//Количество вершин КС вх вершины

        for(int i=0;i<border;++i) {
          wlist[comp[it->second[0]]].push_back(wlist[comp[it->second[1]]][i]);//добавляем вершину из КСвх в КСисх
          comp[wlist[it->second[1]][i]]=comp[it->second[0]];//переприсваиваем  значение КС добавленной вершине
        }

        wlist[comp[it->second[1]]].clear();//Очищаем КС вх вершины
        comp[it->second[1]]=comp[it->second[0]];




      } else {
        border=wlist[comp[it->second[0]]].size();
        for(i=0;i<border;i++) {
          wlist[comp[it->second[1]]].push_back(wlist[comp[it->second[0]]][i]);
          comp[wlist[it->second[0]][i]]=comp[it->second[1]];
        }
        wlist[comp[it->second[0]]].clear();
        comp[it->second[0]]=comp[it->second[1]];
      }

      weight.push_back(it->first);
    }
  }





  for(i=0;i<weight.size();++i)
    sum+=weight[i];

  if(weight.size()<n-1)
    sum=0;

  return sum;
}
