//C 
#include <stdio.h> 

int main() 
{ 
  long long a,b,c;
  scanf ("%ld %ld %ld",&a,&b,&c);
  long long s = c*(c-1)/2;
  s *= b;
  s += a * c;
  printf ("%ld",s);
  return 0;
}