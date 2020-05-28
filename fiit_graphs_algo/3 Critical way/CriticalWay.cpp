#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("test4.txt");
ofstream out("output.txt");



void dfs (int start,vector<vector<int>> &g,vector<int> &ans,vector<bool> &used) {
	used[start] = true;
	cout<<"start= "<<start<<"\n";
	for (size_t i=0; i<g[start].size(); ++i) {
		//int to = g[start][i];
		if (!used[i]&&g[start][i]>0){

			dfs (i,g,ans,used);
		}
	}
	 cout<<"push start "<<start<<"\n";
	ans.push_back (start);
}

void topological_sort(vector<vector<int>> &g,vector<int> &ans,vector<bool> &used) {
	int n=g.size();
	// cout<<"n= "<<n<<"\n";
	for (size_t i=0; i<n; ++i){
		used[i] = false;
		 // cout<<"used["<<i<<"]= "<<used[i]<<"\n";
	}
	ans.clear();

	for (int i=0; i<n; ++i){
		// cout<<used[i];
		// cout<<"test2\n";
		if (!used[i]){
			// cout<<"test3\n";
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
      // cout<<"n= "<<n<<"\n";
      vector<int> w;//Вектор весов
      vector<vector<int>> v(n,vector<int>()),b(n,vector<int>());//Граф
			// vector<vector<int>> ;



      for(i=0;i<n;i++){//Считываем строку весов
        in>>j;
        w.push_back(j);
        // cout<<"Weight of "<<i<<" vertex is "<<j<<"\n";
      }

      for(i=0;i<n;i++){//Считываем дуги
        for(j=0;j<n;j++){
          in>>z;
          //cout<<"z "<<z<<"\n";
          if(z==1){
            v[i].push_back(w[i]);
            //cout<<"Exist from "<<i<<" to "<<j<<" weight "<<w[i]<<"\n";
            // cout<<w[i]<<" ";
          }else{
            v[i].push_back(0);
            //cout<<"Doesn't Exist from "<<i<<" to "<<j<<" weight "<<0  <<"\n";
            // cout<<0<<" ";
          }
        }
        // cout<<"\n";
      }

			cout<<"Input done!\n";
      // Вывод
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          cout<<v[i][j]<<" ";
        }
        cout<<"\n";
      }
			cout<<"\n";

      //Topologic sort
			vector<bool> used(n);
			vector<int> ans={0,9,1,3,5,2,6,4,7,8};



      // topological_sort(v,ans,used);
			// cout<<"Ans size "<<ans.size()<<"\n";
			// cout<<"Ans= ";
			// for (i=0;i<ans.size();i++){
			// 	cout<<ans[i];
			// }

			cout<<"\n";

			//Меняем строки в матрице в соответствии
			//с проведённой топологической сортировкой
			// for(i=0;i<v.size();i++)
			// 	if (ans[i]!=i){
			// 		for(j=0;j<v.size();j++){
			// 			z=v[i][j];
			// 			v[i][j]=v[ans[i]][j];
			// 			v[ans[i]][j]=z;
			// 			//И в векторе весов
			// 			z=w[i];
			// 			w[i]=w[ans[i]];
			// 			w[ans[i]]=z;
			//
			//
			// 		}
			//
			// 	}




			//Вывод
			// for(i=0;i<n;i++){
			// 	for(j=0;j<n;j++){
			// 		cout<<v[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }
			// cout<<"\n";


			//Меняем нули на min_int
			for(i=0;i<v.size();i++)
				for(j=0;j<v.size();j++)
					if (v[i][j]==0)
						v[i][j]=min_int;


			//Производим поиск критических путей

			// for(i=0;i<b.size();i++){
			// 	for(j=0;j<b.size();j++){
			// 		b[i].push_back(0);
			// 		cout<<b[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }

			cout<<"\n";
			for(i=0;i<n;++i){
				for(j=i+1;j<n;++j){
					for(z=j+1;z<n;++z)
						if(v[ans[i]][ans[z]]<(v[ans[i]][ans[j]]+v[ans[j]][ans[z]])){
							v[ans[i]][ans[z]]=v[ans[i]][ans[j]]+v[ans[j]][ans[z]];
							//b[i][z]=j;
						}
					}
			}

			for(i=0;i<n;++i){
				cout<<" ans[i]= "<<ans[i]<<"\n";

			}


			//Прибавляем вес конечных вершин в b
			// cout<<b.size()<<"\n";
			// for(i=0;i<b.size();i++)
			// 	for(j=0;j<b.size();j++)
			// 			b[i][j]+=w[j];
			// 			// if (b[i][j]>0)
			// 		// {
			// 		// 	cout<<"bob\n";
			// 		// 	b[i][j]+=w[j];
			// 		// }

			// Вывод b
			// cout<<"Output b\n";
			// for(i=0;i<n;i++){
			// 	for(j=0;j<n;j++){
			// 		cout<<b[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }

			//Вывод
			// for(i=0;i<n;i++){
			// 	for(j=0;j<n;j++){
			// 		cout<<v[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }



			// Вывод
			// for(i=0;i<n;i++){
			// 	for(j=0;j<n;j++){
			// 		cout<<v[i][j]<<" ";
			// 	}
			// 	cout<<"\n";
			// }


			//Меняем  min_int  на нули
			for(i=0;i<v.size();i++)
				for(j=0;j<v.size();j++)
					if (v[i][j]<0)
						v[i][j]=0;

			//Прибавляем вес конечных вершин
			// for(i=0;i<v.size();i++)
			// 	for(j=0;j<v.size();j++)
			// 		if (v[i][j]>0)
			// 			v[i][j]+=w[j];


			//Вывод
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					cout<<v[i][j]<<" ";
				}
				cout<<"\n";
			}

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
