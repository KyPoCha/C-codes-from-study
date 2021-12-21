#ifndef __PROGTEST__
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#endif /* __PROGTEST__ */

long long max( long long a, long long b, long long c)
{
  if (a >= b && a >= c){
        return a;
  }
  if (b >= a && b >= c){
        return b;
  }
  if (c >= a && c >= b){
        return c;
  }
  return 1;
}


long long min( long long a, long long b, long long c)
{
  if (a <= b && a <= c){
	return a;
  }
  if (b <= a && b <= c){
	return b;
  }
  if (c <= a && c <=b){
	return c;
  }
  return 1;
}


long long avg3 ( long long a, long long b, long long c )
{
  if(a != LLONG_MAX || b != LLONG_MAX || c!= LLONG_MAX){
    long long prumer = (a+b+c) / 3;
    if(a==b && b==c && a==c){
	long long prumer = a;
	return prumer;
	}
    if( min(a,b,c) != max(a,b,c) && ((long long)((min(a,b,c) + max(a,b,c))) > LLONG_MAX)){
	return (long long)(max(a,b,c) - min(a,b,c) / 3);
        }
    if(min(a,b,c) == max(a,b,c)){
        return (long long) (max(a,b,c));
	}
    return prumer;
  }
  else{
  return LLONG_MAX;
  }
}

#ifndef __PROGTEST__
int main (int argc, char * argv [])
{
  assert ( avg3 ( 9223372036854775800, 9223372036854775800, 9223372036854775800 ) == 9223372036854775800);
  assert( avg3 ( 9223372036854775800, 4611686018427387897, 3 ) == 4611686018427387900);

  assert ( avg3 ( 1, 2, 3 ) == 2 );
  assert ( avg3 ( -100, 100, 30 ) == 10 );
  assert ( avg3 ( 1, 2, 2 ) == 1 );
  assert ( avg3 ( -1, -2, -2 ) == -1 );
  assert ( avg3 ( LLONG_MAX, LLONG_MAX, LLONG_MAX ) == LLONG_MAX );
  return 0;
}
#endif /* __PROGTEST__ */
