#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


string output="";
map<char, string> graph;
map<char, int> used;
void dfs_rec(char start);

int main(){
  string line,str1,str2;
  int n,i,j;

  map<char, string> ::iterator it=graph.begin();//Создаём итератор для нашего графа
  map<char, int> ::iterator iter;
  ifstream in("input.txt");
  ofstream out("output.txt");

  if (in.is_open())
    {
        in>>n;
        // cout<<" n= "<<n<<"\n";
        getline(in,line);
        line="";
        // cout<<line<<"\n";
        getline(in,str1);

        while (getline(in,str2)) {
          //printf("Str1= %s ,Str2 =%s",str1,str2);
          // cout<<"str1= "<<str1<<" str2= "<<str2<<"\n";

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

              // printf(" str1[%d]= %c \n",i,str1[i]);
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

    // Выводим граф
    // it=graph.begin();
    // for (int i = 0; it != graph.end(); it++, i++) {  // выводим их
    //   cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
    //   }

    }

    it=graph.begin();
    while(it != graph.end()){
      used.insert(pair<char,int>(it->first,0));
      it++;
    }
    //DFS для всех истоков
    it=graph.begin();
    while(it != graph.end()){
      if (line.find(it->first)==string::npos){
        //dfs


        dfs_rec(it->first);
        // cout<<"abc = "<<output<<"\n";
        out<<output;
        output="";
        iter=used.begin();
        while(iter != used.end()){
          iter->second=0;
          iter++;
        }
        it++;
      }
      else {
        // printf("ne istok \n");
        it++;
      }
    }

    //Тест



    in.close();
    out.close();

  return 0;
  }


void dfs_rec(char start){
  int i;

  switch (used[start]) {
    case 0:{
      used[start]=1;
      if (graph[start]!=""){
        for (i=0;i<graph[start].size();i++){
          if (used[graph[start][i]]==0){
            dfs_rec(graph[start][i]);
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
      output="-";
      exit(0);
      break;
    }
    case 2:{

      break;
    }
  }
  // used[start]=1;
  // output=output+start;
  // if (graph[start]!=""){
  //   for (i=0;i<graph[start].size();i++){
  //     if (used[graph[start][i]]==0){
  //       dfs_rec(graph[start][i]);
  //     }
  //   }
  // }
}
