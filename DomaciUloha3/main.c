#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#include <math.h>
#endif /* __PROGTEST__ */

double twoWayDistance ( int fuelTotal, int maxLoad )
{
	fuelTotal = (double)fuelTotal;
	maxLoad = (double)maxLoad;
	double cesta = 0.0;

	if(fuelTotal <= maxLoad){
		return fuelTotal / 2.0;
	}
	if(maxLoad == 0){
		return 0;
	}
	double odp = fuelTotal/maxLoad;
	for(int i = 1; i <= odp; i++){
		cesta += maxLoad / (double)(i);
	}
	double odp2 = fuelTotal / maxLoad - odp - 1;
        cesta += (fuelTotal - maxLoad * odp)/(fuelTotal/maxLoad - odp2);

	return cesta / 2.0;

}

#ifndef __PROGTEST__
int smallDiff ( double a, double b )
{
  return fabs ( a - b ) < 1e-6 * fabs ( b );
}
int main ( int argc, char * argv [] )
{

  assert ( smallDiff ( twoWayDistance ( 800, 1000 ), 400.000000 ) );
  assert ( smallDiff ( twoWayDistance ( 2000, 1000 ), 750.000000 ) );
  assert ( smallDiff ( twoWayDistance ( 20000, 1000 ), 1798.869829 ) );
  assert ( smallDiff ( twoWayDistance ( 200000, 1000 ), 2939.015474 ) );
  assert ( smallDiff ( twoWayDistance ( 2000000, 1000 ), 4089.184052 ) );
  assert ( smallDiff ( twoWayDistance ( 20000, 100 ), 293.901547 ) );
  assert ( smallDiff ( twoWayDistance ( 20000, 10000 ), 7500.000000 ) );
  assert ( smallDiff ( twoWayDistance ( 4365, 1000 ), 1078.166667 ) );
  return 0;
}
#endif /* __PROGTEST__ */
