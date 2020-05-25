#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");



void dfs (int v,vector<vector<int>> &g,vector<int> &ans,bool *used) {
	*used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!*used[to])
			dfs (to);
	}
	ans.push_back (v);
}

void topological_sort(vector<vector<int>> &g,vector<int> &ans,bool *used) {
	for (int i=0; i<n; ++i)
		*used[i] = false;
	ans.clear();
	for (int i=0; i<n; ++i)
		if (!*used[i])
			dfs (i,g,ans,*used);
	reverse (ans.begin(), ans.end());
}



int main(){
  if (in.is_open())
    {
      int n,i,j,z,min_int=-2147483647;
      in>>n;
      cout<<"n= "<<n<<"\n";
      vector<int> w;//Вектор весов
      vector<vector<int>> v(n,vector<int>());//Граф
      vector<int> ans;
      bool used[n];

      for(i=0;i<n;i++){//Считываем строку весов
        in>>j;
        w.push_back(j);
        cout<<"Weight of "<<i<<" vertex is "<<j<<"\n";
      }

      for(i=0;i<n;i++){//Считываем дуги
        for(j=0;j<n;j++){
          in>>z;
          //cout<<"z "<<z<<"\n";
          if(z==1){
            v[i].push_back(w[i]);
            //cout<<"Exist from "<<i<<" to "<<j<<" weight "<<w[i]<<"\n";
            cout<<w[i]<<" ";
          }else{
            v[i].push_back(min_int);
            //cout<<"Doesn't Exist from "<<i<<" to "<<j<<" weight "<<0  <<"\n";
            cout<<0<<" ";
          }
        }
        cout<<"\n";
      }

      //Вывод
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<v[i][j]<<" ";
        }
        cout<<"\n";
      }

      //Topologic sort
      topological_sort(v,ans,used);





    }


  in.close();
  out.close();
}
