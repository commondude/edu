#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("test7.txt");
ofstream out("output.txt");

void max_flow();
void basenet();
void way_of_ray(vector<vector<int>> &wizards,vector<vector<int>> &graph, int vertex,int stream);

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
      cout<<"Vertex["<<i<<"] has edges :\n";
      for(int j=0;j<n;++j)
      {
        if(graph[i][j]!=-1)
        {
            cout<<"To vertex["<<j<<"] which weight is "<<graph[i][j]<<"\n";
        }

      }
    }

  }

  for(int i=1;i<n;++i)
  {
    if(graph[0][i]!=-1)
    {
      // cout<<"I try to bring them light! \n";
      // cout<<"Thru wizard["<<i<<"] with ray power = "<<graph[0][i]<<"\n";
      way_of_ray(wizards,graph,i,graph[0][i]);
      // cout<<"Ray to vertex["<<i<<"] has been complete \n";
      // cout<<"\n";
    }
  }

  int score_of_strike=0;
  for(int i=1;i<n;++i)
  {
    if(wizards[i][0]==0)
    {
      if(wizards[i][1]==1)
      {
        score_of_strike+=wizards[i][3];
      }

    }
    else
    {
      score_of_strike=-1;
      break;
    }
  }

  out<<score_of_strike;

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

void way_of_ray(vector<vector<int>> &wizards,vector<vector<int>> &graph, int vertex,int stream)
{
  cout<<"Check 1 hungry of vertex["<<vertex<<"]= "<<wizards[vertex][0]<<"\n";
  cout<<"wizards[vertex][3]= "<<wizards[vertex][3]<<"\n";
  cout<<"stream "<<stream<<"\n";
  if(stream>wizards[vertex][0])
  {
    wizards[vertex][3]=wizards[vertex][3]+stream-wizards[vertex][0];
    wizards[vertex][0]=0;
  }
  else
  {
    wizards[vertex][0]=wizards[vertex][0]-stream;
  }
  cout<<"Check 2 hungry of vertex["<<vertex<<"]= "<<wizards[vertex][0]<<"\n";
  cout<<"Ray power steel = "<<wizards[vertex][3]<<"\n";

  for(int i=1;i<wizards.size();++i)
  {
    cout<<"i "<<i<<"\n";
    if(wizards[vertex][3]==0)
    {
        return;
    }
    if(graph[vertex][i]<0)
    {
      continue;
    }

    cout<<"Check hungry of vertex["<<vertex<<"]= "<<wizards[vertex][0]<<"\n";
    cout<<"wizards[vertex][3]="<<wizards[vertex][3]<<"\n";
    cout<<"graph[vertex][i]= "<<graph[vertex][i]<<"\n";
    if(wizards[vertex][3]>graph[vertex][i])
    {
      wizards[vertex][3]=wizards[vertex][3]-graph[vertex][i];
      cout<<"Save some power = "<<wizards[vertex][3]<<"\n";
      way_of_ray(wizards,graph,i,graph[vertex][i]);
    }
    else
    {
      cout<<"Ray is empty!\n";
      cout<<"vertex "<<vertex<<"\n";
      int tmp=wizards[vertex][3];
      wizards[vertex][3]=0;
      way_of_ray(wizards,graph,i,tmp);
    }
    // way_of_ray(wizards,graph,i,wizards[vertex][3])
  }

  cout<<"Wizard №"<<vertex<<"\n";
  cout<<"hungry = "<<wizards[vertex][0]<<"\n";
  cout<<"friends = "<<wizards[vertex][2]<<"\n";
  cout<<"dulgurboom = "<<wizards[vertex][3]<<"\n";
  cout<<"\n";

}
