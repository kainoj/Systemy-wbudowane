#include <stdio.h>
#include <string.h>
#include <time.h>
/*
Napisz funkcję, która w zadanym jako parametr napisie (tablicy typu char,  jej rozmiar jest drugim parametrem) przesunie wszystkie spacje na początek zachowując względny porządek pozostałych znaków, np. “Ala ma kota” => “  Alamakota”. [30]

*/

// W najgorszym przypadku (same spacje) funkcja ta dziala O(n^2)
char *spaces(char *txt, int len) {
	//printf("input: %s#\n", txt ); 	
	int counter=0;
	for(int i=0; i<len; i++) {
		if( txt[i] == ' ' ) {
			for(int j=i; j>counter; j--)
				txt[j] = txt[j-1];				
			txt[counter++]=' ';
		}
	}
	return txt;
}


char *spaces2(char *txt, int len) {

	//printf("input: %s#\n", txt );
	int counter =0;
	for(int i=len-1; i>=0; i--) {
		if( txt[i] == ' ')
			counter++;
		else 
			txt[i+counter] = txt[i];
	}
	for(int i=0; i<counter; i++)
		txt[i]= ' ';
	return txt;
}


int main() {
	char text[] = "                                                                                                                                            wqe qwe qwe qwe qwe ef dv sddv dfvb       a  sd  d f a s d f g h h h h h h h h ss we we 2   5 4 3             ala ma kota                                  ";
	size_t len = strlen(text);

	
	//printf("f1:\n%s#\n", spaces(text, len));
	//printf("f2:\n%s#\n", spaces2(text, len));

	char t1[len+1];
	char t2[len+1];

	strcpy(t1, text);
	strcpy(t2, text);

	clock_t t = clock();
	spaces(t1, len);
	t = clock()-t;
	printf("f1 took: %ld clocks\n", t);

	t=clock();
	spaces2(t2, len);
	t = clock()-t;
	printf("f2 took: %ld clocks\n", t);

	return 0;
}



























/*	printf("time: %.25f\n",  (double)(1.0*t/CLOCKS_PER_SEC) );
	printf("time: %ld\n", t);
	*/