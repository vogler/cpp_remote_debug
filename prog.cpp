#include "dbg.cpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
  dbg_start();
  DBG for(int i = 0; i < 999; i++){
  DBG   cout << "iter " << i << endl;
  DBG   sleep(2);
  DBG }
  DBG return 0;
}
