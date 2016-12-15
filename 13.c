#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

void printIntInBin(int n) {
	int i=31;
	while(i>=0) printf("%d%s",  (n>>i--)&1, !(i%4) ? ".": "");
	printf("\n");
}

int getIthBit(int n, int i) {
	return (n>>i)&1;
}

int setIthBit(int n, int i, int v) {
	return n ^= (-v ^ n) & (1 << i);
}

int dumbSwap(int n) {
	int b;
	for(int i=0; i<16; i++) {
		b = getIthBit(n, i);
		n = setIthBit(n, i, getIthBit(n,31-i));
		n = setIthBit(n, 31-i, b);
	}
	return n;
}

int swap2(int v) {
	unsigned int r = v; 				// r will be reversed bits of v; first get LSB of v
	int s = sizeof(v) * CHAR_BIT - 1; 	// CHAR_BIT - liczba bitow  w char

	for (v >>= 1; v; v >>= 1) {   
		//printIntInBin(r);
		r <<= 1;
		r |= v & 1;
		s--;
	}
	return r <<= s;
}

int smartSwap(int n) {
	n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
	n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
	n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
	n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
	return ((n >> 16)& 0x0000ffff) | ((n << 16)& 0xffff0000);
}



const unsigned int n = 400000000 ;
unsigned int *tab;


int main() {
	srand(time(NULL));
	printf("start\n\n");
	tab = malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++)
		tab[i] = rand();
	printf("start2\n\n");
	int x=0;
	clock_t t;

	int s=0;
	t = clock();
	for(x=0; x<n; x++);
		s+=dumbSwap(tab[x]);
	t = clock()-t;
	printf("dumbSwap took: %ld clocks\n", t);
	printf("%d\n", s);

	s=0;
	t = clock();
	for(x=0; x<n; x++);
		s+=swap2(tab[x]);
	t = clock()-t;
	printf("swap2 took: %ld clocks\n", t);
	printf("%d\n", s);

	s=0;
	t = clock();
	for(x=0; x<n; x++);
		s+=smartSwap(tab[x]);
	t = clock()-t;
	printf("smartSwap took: %ld clocks\n", t);
	
	printf("%d\n", s);

	free(tab);
	return 0;
}