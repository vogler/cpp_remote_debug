#include <pthread.h>
#include <string>
#include <iostream>

using namespace std;

string cmd;

struct {
  bool paused;
  unsigned int line;
  unsigned int breakpoint;
} dbg;

#define C_(A,B) A##B
#define C(A,B) C_(A,B)
#define DBG C(L,__LINE__): dbg.line = __LINE__; dbg.paused |= dbg.line == dbg.breakpoint; if(dbg.paused) cout << "execution paused at line " << dbg.line << endl; while(dbg.paused) sleep(1);

void *f(void *arg){
  while(getline(cin, cmd)){ // read until endl
    if(cmd == "pause"){
      dbg.paused = true;
    } else if(cmd == "resume"){
      dbg.paused = false;
    } else if(cmd == "break"){ // e.g. break 42
      cout << "on which line?" << endl;
      cin >> ws >> dbg.breakpoint;
      cin.ignore();
      cout << "breakpoint set at line " << dbg.breakpoint << endl;
    } else if(cmd == "exit"){
      exit(0);
    } else {
      cout << "unknown dbg cmd: " << cmd << endl;
    }
  }
  return nullptr;
}

int dbg_start(){
  pthread_t t;
  pthread_create(&t, nullptr, f, nullptr);
  return 0;
}
