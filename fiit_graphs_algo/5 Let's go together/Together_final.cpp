#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <list>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int max_int = 2147483647;

void dejkstra(vector<vector<int>> &graph,vector<int> &distance,vector<vector<int>>  &parents, int &n);

void bfs(int &k,int &n,vector<vector<int>>  &parents,vector<int> &count_pass,vector<int> &k_ways);


int main(){
  if (in.is_open()!=true)
    {
      return 1;
    }

  int n,m,k;
  in>>n>>m>>k;

  vector<int> k_ways(k);
  for(int j=0;j<k;++j)
  {
    in>>k_ways[j];
  }

 vector<vector<int>> graph(n,vector<int>(n));
 int from,to,dist;
 for(int i=0;i<m;++i)
 {
   in>>from>>to>>dist;
   graph[from][to]=dist;
   graph[to][from]=dist;
 }

 vector<int> distance(n,max_int);
 vector<vector<int>> parents(n);

 dejkstra(graph,distance,parents,n);


 vector<int> count_pass(n,0);

 bfs(k,n,parents,count_pass,k_ways);

 int max_vertex,max_dist=0;
 for (int i=0;i<n;++i)
 {

   if(count_pass[i]==k && distance[i]>max_dist)
   {
      max_vertex=i;
      max_dist=distance[i];
   }
 }

 out<<max_dist;

 in.close();
 out.close();
}

void dejkstra(vector<vector<int>> &graph,vector<int> &distance,vector<vector<int>>  &parents,int &n)
{
  vector<bool> black(n,false);
  list<int> ordung;
  distance[0]=0;
  ordung.push_back(0);


  while (!ordung.empty())
  {

    int min_dist = max_int,min=0;


    for (list<int>::iterator it = ordung.begin(); it != ordung.end(); ++it)
    {
        if (!black[*it] && distance[*it] < min_dist) {
            min= *it;

            min_dist = distance[*it];

        }
    }


    ordung.remove(min);
    black[min]=true;


    for (int i = 0; i< n; i++)
    {

      if(!black[i] && graph[min][i]!=0 && distance[i] >= distance[min] + graph[min][i] )
      {

        ordung.push_back(i);


        if(distance[i] == distance[min] + graph[min][i])
        {
          parents[i].push_back(min);
        }
        else
        {
          parents[i].clear();
          parents[i].push_back(min);
          distance[i]=distance[min]+graph[min][i];
        }
      }
    }


  }

}

void bfs(int &k,int &n,vector<vector<int>>  &parents,vector<int> &count_pass, vector<int> &k_ways)
{
  list<int> ordung;
    for (int j = 0; j < k; ++j) {//Для каждой отдельной группы сотрудников
        vector<int> color(n, 0);                  //0 - белый, 1 - серый, 2 - чёрный
        count_pass[k_ways[j]] += 1;
        ordung.push_back(k_ways[j]);
        while (!ordung.empty())
        {
            int current_vertex = ordung.front();
            ordung.pop_front();
            for (auto i : parents[current_vertex]) {  //Для каждого родителя текущей вершины
                if (color[i] == 0) {
                    count_pass[i] += 1;
                    ordung.push_back(i);
                    color[i] = 1;}
            }
            color[current_vertex] = 2;
        }
    }
}
