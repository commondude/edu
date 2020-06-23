#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;



ofstream out("output.txt");

int make_graph(string filename, vector<vector<int>> &wizards, vector<vector<pair<int,int>>> &graph);
void print_graph(vector<vector<int>> &wizards, vector<vector<pair<int,int>>> &graph);
void max_flow();
void basenet();

int main(){

  vector<vector<int>> wizards;
  vector<vector<pair<int,int>>> graph;

  make_graph("test5.txt",wizards,graph);
  print_graph(wizards,graph);














  out.close();
}


int make_graph(string filename, vector<vector<int>> &wizards, vector<vector<pair<int,int>>> &graph)
{
    ifstream in(filename);
    if (!in.is_open())
      {
        return 1;
      }

      int n;
      in>>n;

      vector<int> tmp_wizard(4,0);
      for(int i=0;i<n;++i)
      {
        wizards.push_back(tmp_wizard);
        in>>wizards[i][0];
        in>>wizards[i][1];
        in>>wizards[i][2];
        wizards[i][3]=0;
      }

      vector<pair<int,int>> tmp_graph(n,{0,0});

      int to,weight;
      for(int i=0;i<n;++i)
      {
          if(wizards[i][2]!=0)
          {
            for(int j=0;j<wizards[i][2];++j)
            {
              in>>to>>weight;
              tmp_graph[to]={weight,0};

            }
            graph.push_back(tmp_graph);
            for(int j=0;j<n;++j)
            {
              tmp_graph[j]={0,0};
            }
          }
          else
          {
            graph.push_back(tmp_graph);
          }
      }

      in.close();
      return 0;
}


void print_graph(vector<vector<int>> &wizards, vector<vector<pair<int,int>>> &graph)
{
  // //Вывод графа
  int n=wizards.size();
  for(int i=0;i<n;++i)
  {
    if(wizards[i][2]!=0)
    {
      cout<<"Vertex["<<i<<"] has edges :\n";
      for(int j=0;j<n;++j)
      {

        if(graph[i][j].first!=0)
        {
            cout<<"To vertex["<<j<<"] which weight is "<<graph[i][j].first<<"\n";
        }

      }
      cout<< '\n';
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
}

// void max_flow(vector<vector<int>> &wizards, vector<vector<pair<int,int>>> &graph)
// {
//   int n=wizards.size();
//   vector<bool> black(n,false);
//   list<int> ordung;
//   distance[0]=0;
//   ordung.push_back(0);
//
//
//   while (!ordung.empty())
//   {
//
//     int min_dist = max_int,min=0;
//
//
//     for (list<int>::iterator it = ordung.begin(); it != ordung.end(); ++it)
//     {
//         if (!black[*it] && distance[*it] < min_dist) {
//             min= *it;
//
//             min_dist = distance[*it];
//
//         }
//     }
//
//
//     ordung.remove(min);
//     black[min]=true;
//
//
//     for (int i = 0; i< n; i++)
//     {
//
//       if(!black[i] && graph[min][i]!=0 && distance[i] >= distance[min] + graph[min][i] )
//       {
//
//         ordung.push_back(i);
//
//
//         if(distance[i] == distance[min] + graph[min][i])
//         {
//           parents[i].push_back(min);
//         }
//         else
//         {
//           parents[i].clear();
//           parents[i].push_back(min);
//           distance[i]=distance[min]+graph[min][i];
//         }
//       }
//     }
//
//
//   }
//
// }
