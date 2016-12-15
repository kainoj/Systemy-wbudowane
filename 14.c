#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Napisz program, który z tablicy liczb typu int bez znaku (wczytaj z pliku lub wylosuj przynajmniej 300MB tablice) policzy wszystkie te, których negacja bitowa ma co najmniej dwa bity ustawione na jedynkę.  [30]
*/
/*
	10100100
	01011011
	
*/

unsigned int cntBits(unsigned int m) {
	m = (m & 0x55555555) + ((m & 0xaaaaaaaa) >> 1);
	m = (m & 0x33333333) + ((m & 0xcccccccc) >> 2);
	m = (m & 0x0f0f0f0f) + ((m & 0xf0f0f0f0) >> 4);
	m = (m & 0x00ff00ff) + ((m & 0xff00ff00) >> 8);
	return (m & 0x0000ffff) + ((m & 0xffff0000) >> 16);
}


unsigned int f2(unsigned int m) {
	return  !( (m & (m-1)) ==0);
}
                  
const int tsize = 75000000;
unsigned int    t[75000000]; 

int main() {
	srand(time(NULL));

	for(int i=0;i<75000000; i++)
		t[i] = rand();

	//    00000001000
	//	  00000000111

	int c = 0;
	int m;
	int i = tsize;

	clock_t tm = clock();
	
	for(int i=0;i<tsize;i++)  {
		if(cntBits(~t[i])>=2) {
			c++;
		}
	}
//////////////////////////////////////
//////////////////////////////////////

	tm = clock() - 	tm;
	printf("it took: %ld clocks\n", tm);
	printf("\nc= %d\n", c);
	c=0;

	tm = clock();
	for(int i=0;i<tsize;i++) {
		if(f2(~t[i])) {
			c++;
		}
	}

	tm = clock() - 	tm;
	printf("f2 took: %ld clocks\n", tm);
	printf("\nc= %d\n", c);

	return 0;
}






















/*
to zajmuje srednio 650k cykli (z domyślną optymalizacją)

for(int i=0;i<tsize;i++) 
		if(cntBits(t[i])>=2)
			c++;
*/

/*
620k cykli

while(--i) {
		if(cntBits(t[i])>=2)
			c++;
	}
*/


/*


while(--i) {
		m = ~t[i];
		m = (m & 0x55555555) + ((m & 0xaaaaaaaa) >> 1);
		m = (m & 0x33333333) + ((m & 0xcccccccc) >> 2);
		m = (m & 0x0f0f0f0f) + ((m & 0xf0f0f0f0) >> 4);
		m = (m & 0x00ff00ff) + ((m & 0xff00ff00) >> 8);
		m = (m & 0x0000ffff) + ((m & 0xffff0000) >> 16);
		c = m>=2 ? c+1: c;
	}


*/