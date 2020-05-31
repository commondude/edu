#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void dfs (int start,vector<vector<int>> &g,vector<int> &ans,vector<bool> &used, int &index) {
	used[start] = true;
	for (size_t i=0; i<g[start].size(); ++i)
		if (!used[i]&&g[start][i]!=-2147483647)
			dfs (i,g,ans,used,index);
	ans[index] = start;
}

void topological_sort(vector<vector<int>> &g,vector<int> &ans) {
	int n=g.size(), index = n-1;
	vector<bool> used(n);
	for (size_t i=0; i<n; ++i)
		used[i] = false;
	ans.clear();

	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i,g,ans,used,index);
}

int main(){
  if (in.is_open())
    {
      int n,i,j,z,min_int=-2147483647;
      in>>n;
      vector<int> w;//Вектор весов
      vector<vector<int>> v(n,vector<int>());//Граф

      for(i=0;i<n;i++){//Считываем строку весов
        in>>j;
        w.push_back(j);
      }

      for(i=0;i<n;i++)
        for(j=0;j<n;j++){
          in>>z;
          if(z==1)
            v[i].push_back(w[i]);
          else
            v[i].push_back(min_int);
        }

	  vector<int> ans(n);
      topological_sort(v,ans);

	  for(i=0;i<n;++i)
		for(j=i+1;j<n;++j)
		  if(v[ans[i]][ans[j]]!=min_int)
		    for(z=j+1;z<n;++z)
			  if((v[ans[j]][ans[z]]!=min_int)&&(v[ans[i]][ans[z]]<v[ans[i]][ans[j]]+v[ans[j]][ans[z]]))
				v[ans[i]][ans[z]]=v[ans[i]][ans[j]]+v[ans[j]][ans[z]];

	  for(i=0;i<v.size();i++) {
		 for(j=0;j<v.size();j++)
		  if (v[i][j]==min_int)
			 out<< "0"<<" ";
		  else
		    out<<v[i][j]+w[j]<<" ";
		out<<"\n";
	  }
    }

  in.close();
  out.close();
}
