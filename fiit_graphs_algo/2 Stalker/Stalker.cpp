#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
//#include <queue>
// #include <map>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n,k,i,j,z,roads,start_building,finish_building,point;



int main(){

  if (in.is_open())
    {
      in>>n;
      in>>k;
      //cout<<n<<"\n";
      //cout<<k<<"\n";
      vector<vector<int>> v(n*(k+1),vector<int>());//Граф
      //cout<<"Vector size "<<v.size()<<"\n";
      vector<int> d(n*(k+1),-1);//Вектор посещённости и источника посещения
      list<int> q;//Очередь для BFS

      for(i=1;i<k+1;i++){
        in>>roads;
        //cout << "Number of roads " <<roads<< '\n';

        for(j=0;j<roads;j++){
          in>>start_building;
          in>>finish_building;
          //cout << "Road from " <<start_building<<" to "<<finish_building<< '\n';
          start_building-=1;
          finish_building-=1;

          //Добавляем дуги между вершинами в текущей карте
          //cout<<(n*i)+start_building<<"\n";
          v[((n*i)+start_building)].push_back((n*i)+finish_building);
          //cout<<v[((n*i)+start_building)].back()<<"\n";
          //cout<<(n*i)+finish_building<<"\n";
          v[((n*i)+finish_building)].push_back((n*i)+start_building);

          //Для стартовой и доп карты
          v[start_building].push_back((n*i)+start_building);
          v[((n*i)+start_building)].push_back(start_building);

          //Для финишной и доп карты
          v[finish_building].push_back((n*i)+finish_building);
          v[((n*i)+finish_building)].push_back(finish_building);


          }
        }

      //cout << "Input done!" << '\n';


      // Вывод графа

      // for(i=0;i<(n*(k+1));i++){
      //   if(i%n==0){
      //     //cout<<"Map No "<<i/n<<"\n";
      //   }
      //   //cout<<"Size of vector No "<<i<<"= "<<v[i].size()<<"\n";
      //   for(j=0;j<v[i].size();j++){
      //     //cout << v[i][j]<<" ";
      //   }
      //   //cout<<"\n";
      //
      // }

      //BFS
      q.push_front(0);
      d[0]=0;

      while (q.empty()==false){
        point=q.front();
        q.pop_front();
        //cout<<"Pop "<<point<<" Size "<<v[point].size()<<"\n";
        for(i=0;i<v[point].size();i++){// Идём по всем дугам вершины point
          ////cout<<"(d[v[point][i]= "<<d[v[point][i]]<<"\n";
          if(d[v[point][i]]==-1){// Если целевая вершина ещё не посещена
            if(point/n==v[point][i]/n){
              q.push_front(v[point][i]);//Добавляем её в начало очереди
            }else{
              q.push_back(v[point][i]);//Добавляем её в конец очереди
            }

            //cout<<v[point][i]<<" ";
            d[v[point][i]]=point;//Помечаем целевую вершину как посещённую из point

          }

        }

      }

      z=0;
      //cout<<"Revers Path is ";
      point=n-1;// Начинаем с конца пути
      if(d[point]!=-1){//Если он был достигнут
        while(point!=0){//Пока не придём обратно в начальную вершину
          //cout<<point<<" ";
          if(point<n){//Если индекс вершины в пределах адресов доп карты, платим.
            z++;
          }
          point=d[point];//Смотрим
        }

        out<<z;
      }
      else{
        out<<-1;
      }





    }
    else{
      cout << "File not found!" << '\n';
    }





   //cout<<"\n";
   in.close();
   out.close();
}
