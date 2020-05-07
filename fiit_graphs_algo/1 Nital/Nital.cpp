#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;


string output="";
map<char, string> graph;
map<char, int> used;
void dfs_rec(char start);
char bf;//Предыдущая вершина
vector <string> ways;
ifstream in("input.txt");
ofstream out("output.txt");

int main(){
  string line,str1,str2;
  int n,i,j;

  map<char, string> ::iterator it=graph.begin();//Создаём итератор для нашего графа
  map<char, int> ::iterator iter;


  if (in.is_open())
    {
        in>>n;
        // cout<<" n= "<<n<<"\n";
        getline(in,line);
        line="";
        // cout<<line<<"\n";
        getline(in,str1);
        //Обрабатываем случай когда слово всего одно
        if (n==0 || n==1 ){
          output=str1;
          out<<output;
          exit(0);
        }


        while (getline(in,str2)) {

          if (str1<=str2){//Если размер первой строки меньше либо равен второй
            for (i=0;i<str1.size();i++){//то идём по всем буквам строк, но не дальше конца первой строки
              if (graph.find(str1[i])==graph.end()){//Проверяем есть ли буквы первого слова в вершинах графа
                graph.insert(pair<char,string>(str1[i],""));//если нет то добавляем
              }
              if (str1[i]==str2[i]) continue;//Если буквы первого и второго слова равны- переходим к селедующей итерации
                else{//Если нет то
                  if (graph[str1[i]].find(str2[i])==string::npos){//Если связи в графе между буквами ещё нет
                    graph[str1[i]]=graph[str1[i]]+str2[i];//то создаём
                    line=line+str2[i];//Добавляем в список не истоков

                    break;//и переходим к следующей паре слов
                  }
                  else break;//Если уже есть связь, просто переходим к следующей паре слов

                }

            }

          }
          else{//Если размер первой строки больше чем второй
            for (i=0;i<str2.size();i++){//то идём по всем буквам строк, но не дальше конца второй строки
              if (graph.find(str1[i])==graph.end()){//Проверяем есть ли буквы первого слова в вершинах графа
                graph.insert(pair<char,string>(str1[i],""));//если нет то добавляем
              }
              if (str1[i]==str2[i]) continue;//Если буквы первого и второго слова равны(в этой позиции)- переходим к селедующей итерации
                else{//Если нет то
                  if (graph[str1[i]].find(str2[i])==string::npos){//Если связи в графе между буквами ещё нет
                    graph[str1[i]]=graph[str1[i]]+str2[i];//то создаём
                    line=line+str2[i];//Добавляем в список не истоков
                    break;//и переходим к следующей паре слов
                  }
                  else break;//Если уже есть связь, просто переходим к следующей паре слов

                }

            }
          }

          //Проверка букв оставшихся в слове, на вхождение в алфавит
          for (j=i;j<str1.size();j++){

            if (graph.find(str1[j])==graph.end()){//Проверяем есть ли буквы  последнего слова в вершинах графа
              graph.insert(pair<char,string>(str1[j],""));//если нет то добавляем
            }
          }
        str1=str2;//Делаем второе слово этой итерации, первым для следующей
      }
      //Проверка букв оставшихся в последнем слове, на вхождение в алфавит
      for (j=i;j<str1.size();j++){

        if (graph.find(str1[j])==graph.end()){//Проверяем есть ли буквы  последнего слова в вершинах графа
          graph.insert(pair<char,string>(str1[j],""));//если нет то добавляем
        }
      }

    // Выводим граф
     // it=graph.begin();
     // for (int i = 0; it != graph.end(); it++, i++) {  // выводим их
     //   cout << i << ") Key " << it->first << ", Value " << it->second << endl;
     //   }

    }


    //Формируем словарь просмотренности вершин
    it=graph.begin();
    while(it != graph.end()){
      used.insert(pair<char,int>(it->first,0));
      it++;
    }

    //DFS для всех истоков И не истоков для нахождения контуров
    it=graph.begin();
    while(it != graph.end()){
      if (line.find(it->first)==string::npos){
        //dfs для истоков
        dfs_rec(it->first);
        // cout<<"abc = "<<output<<"\n";
        ways.insert(ways.end(),output);
        // out<<output;
        output="";
        iter=used.begin();
        while(iter != used.end()){
          iter->second=0;
          iter++;
        }
        it++;
      }
      else {//для не истоков
        // printf("ne istok \n");
		    dfs_rec(it->first);
        // cout<<"abc = "<<output<<"\n";
        output="";
        iter=used.begin();
        while(iter != used.end()){
          iter->second=0;
          iter++;
        }
        it++;
      }
    }


    // printf("Size of ways =%d \n",ways.size());
    // for(i=0;i<ways.size();i++){
    //
    //   cout<<"Way "<<i<<"="<<ways[i]<<"\n";
    // }

    //Формируем строку алфавита из вектора путей
    //Если есть только один путь, значит все буквы содержаться в нём, и мы его и Выводим
    if (ways.size()==1){
      out<<ways[0];
      exit(0);
    }
    else{
      //Начнём использовать n для хранения индекса самого длинного пути
      n=0;
      str1=ways[0];
      for(i=1;i<ways.size();i++){//ищем самый длинный путь
        if (str1.size()<ways[i].size()){
          n=i;
          str1=ways[i];
        }
      }

      //Добавляем в вывод сначала самый длинный путь а потом все остальные буквы из остальных путей, если их уже нет в выводе.
      output=str1;
      str2="";
      for(i=0;i<ways.size();i++){//
        if (i!=n){//если это не самый длинный путь
          for(j=0;j<ways[i].size();j++){//то идём по всем буквам этого пути
            if (output.find(ways[i][j])==string::npos){//И если этой буквы нет в выводе
              str2= str2+ways[i][j];//Добавляем её
            }
            else{//прерываем цикл
              break;
            }
          }
          //Добавляем не пересекающийся путь в начало
          output=str2+output;
          str2="";
        }
      }
      // cout<<output<<"\n";
      out<<output;


    }





    in.close();
    out.close();

  return 0;
  }


void dfs_rec(char start){
  int i;

  switch (used[start]) {
    case 0:{
	  // cout<<"Hup! \n";
      used[start]=1;
      if (graph[start]!=""){//Если множество переходов не пустое
        for (i=0;i<graph[start].size();i++){//Для всех элементов множества
          if (used[graph[start][i]]==0){//Если

            dfs_rec(graph[start][i]);
          }
		  else if(used[graph[start][i]]==1){
			        // cout<<"Hop1! \n";
					output="-";
					out<<output;
					in.close();
					out.close();
					exit(0);

		  }
        }
        used[start]=2;
        output=start+output;
      }
      else{
        used[start]=2;
        output=start+output;
      }
      break;
    }
    case 1:{
      // cout<<"Hop2! \n";
      output="-";
	    out<<output;
	    in.close();
      out.close();
	    exit(0);
      break;
    }
    case 2:{
	  // cout<<"Hip! \n";
      break;
    }
  }
}
