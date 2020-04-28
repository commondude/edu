#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

string dfs(string str) {
  str[0]='k';
  return str;
}

int main(){
  string str="sosiska";

  str[0]='p';
  str=dfs(str);
  cout<<str;
  return 0;
}
