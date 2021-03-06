#include <stdio.h>
#include <stdlib.h>

#define NMAX  100000

int v[NMAX];

/*cea mai mare pozitie pe care se afla un element cu valoarea x sau -1 daca aceasta valoare nu se gaseste in sir */
int bsearch0(int v[], int x, int st, int dr) {
	
	int mid = (st + dr) / 2;
	if(st == dr) {
		int ok = 0;
		while(x == v[st]) ++st, ok = 1;
		if(ok) return st - 1; else return -1;	
	}
	if(v[mid] < x) return bsearch0(v, x, mid + 1, dr);
	else  return bsearch0(v, x, st, mid);
}
/*cea mai mare pozitie pe care se afla un element cu valoarea mai mica sau egala cu x in sir.*/
int bsearch1(int v[], int x, int st, int dr) {
	
	int mid = (st + dr) / 2;
	
	if(st == dr) {
		if(v[st] > x) --st;
		return st;	
	}
	
	if(v[mid] <= x)		return bsearch1(v, x, mid + 1, dr);
	return bsearch1(v, x, st, mid);
}

/*cea mai mica pozitie pe care se afla un element cu valoarea mai mare sau egala cu x in sir*/

int bsearch2(int x, int st, int dr) {
	int mid = (st + dr) / 2;

	if(st == dr) {
		if(v[st] <  x) ++st;		
		return st;
	}

	if(v[mid] < x) return bsearch2(x, mid + 1, dr);
	return bsearch2(x, st, mid);
}

int main() {
	
	FILE *in = fopen("cautbin.in","r");
	FILE *out = fopen("cautbin.out", "w");

	int N; int T; int type; int x;

	fscanf(in,"%d",&N);

	for(int i = 1; i <= N; ++i)
		fscanf(in, "%d", &v[i]);
	fscanf(in, "%d", &T);
	
	while(T--) {
		fscanf(in,"%d%d", &type, &x);
		switch(type) {		
			case 0: fprintf(out,"%d\n", bsearch0(v, x, 1, N)) ;break;	
			case 1: fprintf(out,"%d\n", bsearch1(v, x, 1, N)) ; break;
			case 2: fprintf(out,"%d\n", bsearch2(v, x, 1, N)); break;		
		}	
		
	}
	
	fclose(in); fclose(out);
	return 0;
}
