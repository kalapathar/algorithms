#include <iostream>
using namespace std;
#include "elapsed_time.h"
#include <cmath>

void recursion(int n)

{
  double x = 2 * 3;
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < i; ++j ) {
      x = 32*sin(.32);
    }
  }
 
  if (n > 0)
    recursion(n/2);
}

int main(){

start_timer();
recursion(100);
//32*sin(.32);
double clock=elapsed_time();
cout<<"Total cycles: "<<clock<<endl;

}



