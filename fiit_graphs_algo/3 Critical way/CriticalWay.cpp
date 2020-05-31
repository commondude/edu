#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");



void dfs (int start,vector<vector<int>> &g,vector<int> &ans,vector<bool> &used) {
	used[start] = true;
	for (size_t i=0; i<g[start].size(); ++i) {
		if (!used[i]&&g[start][i]!=-2147483647){
			dfs (i,g,ans,used);
		}
	}
	ans.push_back (start);
}

void topological_sort(vector<vector<int>> &g,vector<int> &ans,vector<bool> &used) {
	int n=g.size();
	for (size_t i=0; i<n; ++i){
		used[i] = false;
	}
	ans.clear();

	for (int i=0; i<n; ++i){
		if (!used[i]){
			dfs (i,g,ans,used);
		}
	}

	reverse (ans.begin(), ans.end());
}



int main(){
  if (in.is_open())
    {
      int n,i,j,z,min_int=-2147483647;
      in>>n;
      vector<int> w;//Вектор весов
      vector<vector<int>> v(n,vector<int>()),b(n,vector<int>());//Граф



      for(i=0;i<n;i++){//Считываем строку весов
        in>>j;
        w.push_back(j);
      }

      for(i=0;i<n;i++){//Считываем дуги
        for(j=0;j<n;j++){
          in>>z;
          if(z==1){
            v[i].push_back(w[i]);
          }else{
            v[i].push_back(0);
          }
        }
      }

			// cout<<"Input done!\n";
      // Вывод
      // for(i=0;i<n;i++){
      //   for(j=0;j<n;j++){
      //     cout<<v[i][j]<<" ";
      //   }
      //   cout<<"\n";
      // }
			// cout<<"\n";

      //Topologic sort
			vector<bool> used(n);
			vector<int> ans(n);


      topological_sort(v,ans,used);
			// cout<<"Ans size "<<ans.size()<<"\n";
			// cout<<"Ans= ";
			// for (i=0;i<ans.size();i++){
			// 	cout<<ans[i];
			// }
			//
			// cout<<"\n";


			//Меняем нули на min_int
			for(i=0;i<v.size();i++)
				for(j=0;j<v.size();j++)
					if (v[i][j]==0)
						v[i][j]=min_int;


			//Производим поиск критических путей
			for(i=0;i<b.size();i++){
				for(j=0;j<b.size();j++){
					b[i].push_back(0);
				}
			}

			for(i=0;i<n;++i){
				for(j=i+1;j<n;++j){
					for(z=j+1;z<n;++z)
						if(v[ans[i]][ans[z]]<(v[ans[i]][ans[j]]+v[ans[j]][ans[z]])&&(v[ans[i]][ans[j]]>0)&&(v[ans[j]][ans[z]]>0)){
							v[ans[i]][ans[z]]=v[ans[i]][ans[j]]+v[ans[j]][ans[z]];
							b[ans[i]][ans[z]]=ans[j];
						}
					}
			}

			//Меняем  min_int  на нули
			for(i=0;i<v.size();i++)
				for(j=0;j<v.size();j++)
					if (v[i][j]<0)
						v[i][j]=0;

			//Прибавляем вес конечных вершин
			for(i=0;i<v.size();i++)
				for(j=0;j<v.size();j++)
					if (v[i][j]>0)
						v[i][j]+=w[j];

			// Вывод
      // for(i=0;i<n;i++){
      //   for(j=0;j<n;j++){
      //     cout<<b[i][j]<<" ";
      //   }
      //   cout<<"\n";
      // }
			// cout<<"\n";
			//Вывод в файл
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					out<<v[i][j]<<" ";
				}
				out<<"\n";
			}


    }


  in.close();
  out.close();
}
