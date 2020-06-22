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
int way_of_ray(vector<vector<int>> &wizards,vector<vector<int>> &graph, int vertex,int stream,bool &dulgur_range);

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
  bool dulgur_range;
  int score_of_strike=0,tmp=0;
  for(int i=1;i<n;++i)
  {
    if(graph[0][i]!=-1)
    {

      cout<<"\n";
      cout<<"I try to bring them light! \n";
      cout<<"Thru wizard["<<i<<"] with ray power = "<<graph[0][i]<<"\n";
      dulgur_range=false;
      tmp=way_of_ray(wizards,graph,i,graph[0][i],dulgur_range);
      if(dulgur_range)
      {
        score_of_strike+=tmp;
      }
      cout<<"Rayback is "<<score_of_strike<<"\n";
      cout<<"Ray to vertex["<<i<<"] has been complete \n";
      cout<<"\n";
    }
  }


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
    // cout<<"friends = "<<wizards[i][2]<<"\n";
    cout<<"dulgurboom = "<<wizards[i][3]<<"\n";
    cout<<"\n";
  }






  in.close();
  out.close();
}

int way_of_ray(vector<vector<int>> &wizards,vector<vector<int>> &graph, int vertex,int stream, bool &dulgur_range)
{
  cout<<"Check 1 hungry of wizard["<<vertex<<"]= "<<wizards[vertex][0]<<"\n";
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
    // cout<<"i "<<i<<"\n";
    if(wizards[vertex][3]==0)
    {
        // cout<<"It's a trap!\n \n";
        return 0;
    }
    if(graph[vertex][i]<0)
    {
      continue;
    }

    // cout<<"Check hungry of vertex["<<vertex<<"]= "<<wizards[vertex][0]<<"\n";
    // cout<<"wizards[vertex][3]="<<wizards[vertex][3]<<"\n";
    // cout<<"graph[vertex][i]= "<<graph[vertex][i]<<"\n";

    if(wizards[vertex][3]>graph[vertex][i])
    {
      wizards[vertex][3]=wizards[vertex][3]-graph[vertex][i];
      // cout<<"Save some power = "<<wizards[vertex][3]<<"\n";
      wizards[vertex][3]=wizards[vertex][3]+way_of_ray(wizards,graph,i,graph[vertex][i],dulgur_range);
    }
    else
    {
      // cout<<"Ray is empty!\n";
      // cout<<"vertex "<<vertex<<"\n";
      int tmp=wizards[vertex][3];
      wizards[vertex][3]=0;
      wizards[vertex][3]=wizards[vertex][3]+way_of_ray(wizards,graph,i,tmp,dulgur_range);
    }
    // way_of_ray(wizards,graph,i,wizards[vertex][3])
  }


  // cout<<"Wizard No "<<vertex<<"\n";
  // cout<<"hungry = "<<wizards[vertex][0]<<"\n";
  // cout<<"friends = "<<wizards[vertex][2]<<"\n";
  // cout<<"dulgurboom = "<<wizards[vertex][3]<<"\n";
  // cout<<"\n";
  // cout<<"dulgurfight="<<wizards[vertex][1]<<"\n";

  if( wizards[vertex][3]!=0)
  {

    int tmp=wizards[vertex][3];
    if (stream>= wizards[vertex][3])
    {
       wizards[vertex][3]=0;
       cout<<"Backray is "<<tmp<<" from "<<vertex<<"\n";
       return  tmp;
    }
    else
    {
       wizards[vertex][3]= wizards[vertex][3]-stream;
       return stream;
    }
  }
  else
  {
    // cout<<"No backstream from "<<vertex<<" \n \n";
    dulgur_range=true;
    return 0;
  }

    // return wizards[vertex][3];

}
