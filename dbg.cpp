#include <pthread.h>
#include <string>
#include <iostream>

using namespace std;

string cmd;

struct {
  bool paused;
  unsigned int line;
} dbg;

#define DBG dbg.line = __LINE__; while(dbg.paused){}

void *f(void *arg){
  while(getline(cin, cmd)){
    if(cmd == "pause"){
      dbg.paused = !dbg.paused;
      cout << "execution paused at line " << dbg.line << endl;
    } else {
      cout << "unknown dbg cmd: " << cmd << endl;
    }
  }
  return NULL;
}

int dbg_start(){
  pthread_t t;
  pthread_create(&t, NULL, f, NULL);
  return 0;
}
