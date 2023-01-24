#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// Definisi fungsi dan prosedur yang digunakan
bool valid(float b, float c, float d, float e);
// Mengecek apakah input b, c, d, e merupakan bilangan positif
void swap(int x, float *b, float *c, float *d, float *e, float r, float s, float t, float u);
// Mengubah urutan posisi
void hitung1(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung2(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung3(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung4(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung5(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung6(int x, int y, float b, float c, float d, float e, int *f);
//
void hitung7(int x, int y, float b, float c, float d, float e, int *f);
//
void convert(string input, float *value);
//

int main() {
    bool check;
    int i, x, y;
    int count;
    string a, j, q, k;
    float b, c, d, e;
    float r, s, t, u;
	float time;

    check = false;
    count = 0;

    while (!check) {
		printf("Pilih masukan: \n");
		printf("Ketik 1 untuk Input Manual\n");
		printf("Ketik 2 untuk Random\n");
        int input;
        cin >> input;
        if(input == 1)
        {
            printf("\n Masukkan 4 angka/huruf : ");
            cin >> a >> j >> q >> k;
            convert(a,&b);
            convert(j,&c);
            convert(q,&d);
            convert(k,&e);
            check = valid(b, c, d, e);
        }
        else if(input == 2)
        {
            b = (rand()%12)+1;
            c = (rand()%12)+1;
            d = (rand()%12)+1;
            e = (rand()%12)+1;
        }

        if (!check) {
            printf("\n Masukan tidak sesuai ");
			printf("\n press enter to continue\n ");
			cin.get();
			cin.get();
			system("cls");
        }
    }
   
    r = b;
    s = c;
    t = d;
    u = e;
	time = clock();

    for (i = 0; i <= 24; i++) {
        for (x = 1; x <= 4; x++) {
            for (y = 1; y <= 4; y++) {
                hitung1(x, y, b, c, d, e, &count);
                hitung2(x, y, b, c, d, e, &count);
                hitung3(x, y, b, c, d, e, &count);
                hitung4(x, y, b, c, d, e, &count);
                hitung5(x, y, b, c, d, e, &count);
				hitung6(x, y, b, c, d, e, &count);
				hitung7(x, y, b, c, d, e, &count);
            }
        }
        swap(i, &b, &c, &d, &e, r, s, t, u);
    }

	time = (clock() - time) / CLOCKS_PER_SEC;

    if (count == 0) {
        printf("\n  Tidak ada solusi\n");
    } else {
        printf("\n  %d solutions found\n", count);
    }

    printf("\n Waktu Eksekusi  = %.3f detik\n", time);
	return 0;
}


void convert(string input, float *value)
{
    if(input == "A") {
       *value = 1;
    }
    else if (input == "J") {
       *value = 11;
    }
    else if (input == "Q") {
       *value = 12;
    }
    else if (input == "K") {
       *value = 13;
    }
	 else if (input == "1") {
       *value = 1;
    }
    else if (input == "2") {
       *value = 2;
    }
    else if (input == "3") {
       *value = 3;
    }
    else if (input == "4") {
       *value = 4;
    }
    else if (input == "5") {
       *value = 5;
    }
    else if (input == "6") {
       *value = 6;
    }
    else if (input == "7") {
       *value = 7;
    }
    else if (input == "8") {
       *value = 8;
    }
    else if (input == "9") {
       *value = 9;
    }
    else if (input == "10") {
       *value = 10;
    } else {
		*value = -1;
	}
}


bool valid(float b, float c, float d, float e) {
    bool cek;
    cek = true;
    if ((b < 0) || (c < 0) || (d < 0) || (e < 0)) {
        cek = false; 
    }
    return cek;
}

void swap(int x, float *b, float *c, float *d, float *e, float r, float s, float t, float u) {
    switch (x) {
        case 1:
        {
            *b = r; *c = s; *d = t; *e = u;
            break;
        }
        case 2:
        {
            *b = r; *c = s; *d = u; *e = t;
            break;
        }
        case 3:
        {
            *b = s; *c = r; *d = t; *e = u;
            break;
        }
        case 4:
        {
            *b = s; *c = r; *d = u; *e = t;
            break;
        }
        case 5:
        {
            *b = u; *c = t; *d = s; *e = r;
            break;
        }
        case 6:
        {
            *b = t; *c = u; *d = s; *e = r;
            break;
        }
        case 7:
        {
            *b = u; *c = t; *d = r; *e = s;
            break;
        }
        case 8:
        {
            *b = t; *c = u; *d = r; *e = s;
            break;
        }
        case 9:
        {
            *b = r; *c = u; *d = s; *e = t;
            break;
        }
        case 10:
        {
            *b = r; *c = u; *d = t; *e = s;
            break;
        }
        case 11:
        {
            *b = t; *c = r; *d = u; *e = s;
            break;
        }
        case 12:
        {
            *b = t; *c = r; *d = s; *e = u;
            break;
        }
        case 13:
        {
            *b = s; *c = u; *d = t; *e = r;
            break;
        }
        case 14:
        {
            *b = s; *c = u; *d = r; *e = t;
            break;
        }
        case 15:
        {
            *b = u; *c = s; *d = r; *e = t;
            break;
        }
        case 16:
        {
            *b = u; *c = s; *d = t; *e = r;
            break;
        }
        case 17:
        {
            *b = r; *c = t; *d = u; *e = s;
            break;
        }
        case 18:
        {
            *b = r; *c = t;*d = s; *e = u;
            break;
        }
        case 19:
        {
            *b = t; *c = s; *d = r; *e = u; 
            break;
        }
        case 20:
        {
            *b = t; *c = s; *d = u; *e = r;
            break;
        }
        case 21:
        {
            *b = s; *c = t; *d = r; *e = u;
            break;
        }
        case 22:
        {
            *b = s; *c = t; *d = u; *e = r;
			break;
        }
		case 23: 
		{
			*b = u; *c = r; *d = t; *e = s;
			break;
		}
		case 24: 
		{
			*b = u; *c = r; *d = s; *e = t;
			break;
		}
    }
}

void hitung1(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
                case 1:{
                    hasil1 = b + c + d + e;
                    hasil2 = b + c + d - e;
                    hasil3 = b + c + d * e;
                    hasil4 = b + c + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f + %0.f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f + %0.f - %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f + %0.f * %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f + %0.f / %.0f\n", (*f), b, c, d, e);
                    }
                    break;
                }
                case 2: {
                    hasil1 = b + c - d + e;
                    hasil2 = b + c - d - e;
                    hasil3 = b + c - d * e;
                    hasil4 = b + c - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
                        (*f)++;
                        printf("%7d. %.0f + %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
                    }
                    break;
                }
                case 3: {
                    hasil1 = b + c * d + e;
                    hasil2 = b + c * d - e;
                    hasil3 = b + c * d * e;
                    hasil4 = b + c * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b + c / d + e;
                    hasil2 = b + c / d - e;
                    hasil3 = b + c / d * e;
                    hasil4 = b + c / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;    
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = b - c + d + e;
                    hasil2 = b - c + d - e;
                    hasil3 = b - c + d * e;
                    hasil4 = b - c + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f - %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b - c - d + e;
                    hasil2 = b - c - d - e;
                    hasil3 = b - c - d * e;
                    hasil4 = b - c - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b - c * d + e;
                    hasil2 = b - c * d - e;
                    hasil3 = b - c * d * e;
                    hasil4 = b - c * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b - c / d + e;
                    hasil2 = b - c / d - e;
                    hasil3 = b - c / d * e;
                    hasil4 = b - c / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
		case 3: {
			switch (y) {
				case 1: {
					hasil1 = b * c + d + e;
                    hasil2 = b * c + d - e;
                    hasil3 = b * c + d * e;
                    hasil4 = b * c + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f * %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 2: {
					hasil1 = b * c - d + e;
                    hasil2 = b * c - d - e;
                    hasil3 = b * c - d * e;
                    hasil4 = b * c - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f * %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 3: {
					hasil1 = b * c * d + e;
                    hasil2 = b * c * d - e;
                    hasil3 = b * c * d * e;
                    hasil4 = b * c * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f * %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 4: {
					hasil1 = b * c / d + e;
                    hasil2 = b * c / d - e;
                    hasil3 = b * c / d * e;
                    hasil4 = b * c / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f * %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
			}
			break;
		}
		case 4: {
			switch (y) {
				case 1: {
					hasil1 = b / c + d + e;
                    hasil2 = b / c + d - e;
                    hasil3 = b / c + d * e;
                    hasil4 = b / c + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f / %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 2: {
					hasil1 = b / c - d + e;
                    hasil2 = b / c - d - e;
                    hasil3 = b / c - d * e;
                    hasil4 = b / c - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f / %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 3: {
					hasil1 = b / c * d + e;
                    hasil2 = b / c * d - e;
                    hasil3 = b / c * d * e;
                    hasil4 = b / c * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f / %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 4: {
					hasil1 = b / c / d + e;
                    hasil2 = b / c / d - e;
                    hasil3 = b / c / d * e;
                    hasil4 = b / c / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
                        (*f)++;
						printf("%7d. %.0f / %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
			}
			break;
		}
    }
}

void hitung2(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
                case 1: {
                    hasil1 = (b + c) + d + e;
                    hasil2 = (b + c) + d - e;
                    hasil3 = (b + c) + d * e;
                    hasil4 = (b + c) + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b + c) - d + e;
                    hasil2 = (b + c) - d - e;
                    hasil3 = (b + c) - d * e;
                    hasil4 = (b + c) - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b + c) * d + e;
                    hasil2 = (b + c) * d - e;
                    hasil3 = (b + c) * d * e;
                    hasil4 = (b + c) * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b + c) / d + e;
                    hasil2 = (b + c) / d - e;
                    hasil3 = (b + c) / d * e;
                    hasil4 = (b + c) / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = (b - c) + d + e;
                    hasil2 = (b - c) + d - e;
                    hasil3 = (b - c) + d * e;
                    hasil4 = (b - c) + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b - c) - d + e;
                    hasil2 = (b - c) - d - e;
                    hasil3 = (b - c) - d * e;
                    hasil4 = (b - c) - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {   
                    hasil1 = (b - c) * d + e;
                    hasil2 = (b - c) * d - e;
                    hasil3 = (b - c) * d * e;
                    hasil4 = (b - c) * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b - c) / d + e;
                    hasil2 = (b - c) / d - e;
                    hasil3 = (b - c) / d * e;
                    hasil4 = (b - c) / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 3: {
            switch (y) {
                case 1: {
                    hasil1 = (b * c) + d + e;
                    hasil2 = (b * c) + d - e;
                    hasil3 = (b * c) + d * e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b * c) - d + e;
                    hasil2 = (b * c) - d - e;
                    hasil3 = (b * c) - d * e;
                    hasil4 = (b * c) - c / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b * c) * d + e;
                    hasil2 = (b * c) * d - e;
                    hasil3 = (b * c) * d * e;
                    hasil4 = (b * c) * c / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b * c) / d + e;
                    hasil2 = (b * c) / d - e;
                    hasil3 = (b * c) / d * e;
                    hasil4 = (b * c) / c / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 4: {
            switch (y) {
                case 1: {
                    hasil1 = (b / c) + d + e;
                    hasil2 = (b / c) + d - e;
                    hasil3 = (b / c) + d * e;
                    hasil4 = (b / c) + d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b / c) - d + e;
                    hasil2 = (b / c) - d - e;
                    hasil3 = (b / c) - d * e;
                    hasil4 = (b / c) - d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b / c) * d + e;
                    hasil2 = (b / c) * d - e;
                    hasil3 = (b / c) * d * e;
                    hasil4 = (b / c) * d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b / c) / d + e;
                    hasil2 = (b / c) / d - e;
                    hasil3 = (b / c) / d * e;
                    hasil4 = (b / c) / d / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
					}
					break;
                 }
            }
            break;
        }
    }
}

void hitung3(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
                case 1: {
                    hasil1 = b + (c + d) + e;
                    hasil2 = b + (c + d) - e;
                    hasil3 = b + (c + d) * e;
                    hasil4 = b + (c + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b + (c - d) + e;
                    hasil2 = b + (c - d) - e;
                    hasil3 = b + (c - d) * e;
                    hasil4 = b + (c - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b + (c * d) + e;
                    hasil2 = b + (c * d) - e;
                    hasil3 = b + (c * d) * e;
                    hasil4 = b + (c * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b + (c / d) + e;
                    hasil2 = b + (c / d) - e;
                    hasil3 = b + (c / d) * e;
                    hasil4 = b + (c / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = b - (c + d) + e;
                    hasil2 = b - (c + d) - e;
                    hasil3 = b - (c + d) * e;
                    hasil4 = b - (c + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b - (c - d) + e;
                    hasil2 = b - (c - d) - e;
                    hasil3 = b - (c - d) * e;
                    hasil4 = b - (c - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b - (c * d) + e;
                    hasil2 = b - (c * d) - e;
                    hasil3 = b - (c * d) * e;
                    hasil4 = b - (c * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b - (c / d) + e;
                    hasil2 = b - (c / d) - e;
                    hasil3 = b - (c / d) * e;
                    hasil4 = b - (c / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 3: {
            switch (y) {
                case 1: {
                    hasil1 = b * (c + d) + e;
                    hasil2 = b * (c + d) - e;
                    hasil3 = b * (c + d) * e;
                    hasil4 = b * (c + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b * (c - d) + e;
                    hasil2 = b * (c - d) - e;
                    hasil3 = b * (c - d) * e;
                    hasil4 = b * (c - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b * (c * d) + e;
                    hasil2 = b * (c * d) - e;
                    hasil3 = b * (c * d) * e;
                    hasil4 = b * (c * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b * (c / d) + e;
                    hasil2 = b * (c / d) - e;
                    hasil3 = b * (c / d) * e;
                    hasil4 = b * (c / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 4: {
            switch (y) {
                case 1: {
                    hasil1 = b / (c + d) + e;
                    hasil2 = b / (c + d) - e;
                    hasil3 = b / (c + d) * e;
                    hasil4 = b / (c + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b / (c - d) + e;
                    hasil2 = b / (c - d) - e;
                    hasil3 = b / (c - d) * e;
                    hasil4 = b / (c - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b / (c * d) + e;
                    hasil2 = b / (c * d) - e;
                    hasil3 = b / (c * d) * e;
                    hasil4 = b / (c * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b / (c / d) + e;
                    hasil2 = b / (c / d) - e;
                    hasil3 = b / (c / d) * e;
                    hasil4 = b / (c / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung4(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
                case 1: {
                    hasil1 = b + c + (d + e);
                    hasil2 = b + c + (d - e);
                    hasil3 = b + c + (d * e);
                    hasil4 = b + c + (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b + c - (d + e);
                    hasil2 = b + c - (d - e);
                    hasil3 = b + c - (d * e);
                    hasil4 = b + c - (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b + c * (d + e);
                    hasil2 = b + c * (d - e);
                    hasil3 = b + c * (d * e);
                    hasil4 = b + c * (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b + c / (d + e);
                    hasil2 = b + c / (d - e);
                    hasil3 = b + c / (d * e);
                    hasil4 = b + c / (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f + %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = b - c + (d + e);
                    hasil2 = b - c + (d - e);
                    hasil3 = b - c + (d * e);
                    hasil4 = b - c + (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b - c - (d + e);
                    hasil2 = b - c - (d - e);
                    hasil3 = b - c - (d * e);
                    hasil4 = b - c - (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b - c * (d + e);
                    hasil2 = b - c * (d - e);
                    hasil3 = b - c * (d * e);
                    hasil4 = b - c * (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b - c / (d + e);
                    hasil2 = b - c / (d - e);
                    hasil3 = b - c / (d * e);
                    hasil4 = b - c / (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f - %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 3: {
            switch (y) {
                case 1: {
                    hasil1 = b * c + (d + e);
                    hasil2 = b * c + (d - e);
                    hasil3 = b * c + (d * e);
                    hasil4 = b * c + (d / e);
                     if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b * c - (d + e);
                    hasil2 = b * c - (d - e);
                    hasil3 = b * c - (d * e);
                    hasil4 = b * c - (d / e);
                     if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b * c * (d + e);
                    hasil2 = b * c * (d - e);
                    hasil3 = b * c * (d * e);
                    hasil4 = b * c * (d / e);
                     if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b * c / (d + e);
                    hasil2 = b * c / (d - e);
                    hasil3 = b * c / (d * e);
                    hasil4 = b * c / (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f * %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 4: {
            switch (y) {
                case 1: {
                    hasil1 = b / c + (d + e);
                    hasil2 = b / c + (d - e);
                    hasil3 = b / c + (d * e);
                    hasil4 = b / c + (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = b / c - (d + e);
                    hasil2 = b / c - (d - e);
                    hasil3 = b / c - (d * e);
                    hasil4 = b / c - (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = b / c * (d + e);
                    hasil2 = b / c * (d - e);
                    hasil3 = b / c * (d * e);
                    hasil4 = b / c * (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = b / c / (d + e);
                    hasil2 = b / c / (d - e);
                    hasil3 = b / c / (d * e);
                    hasil4 = b / c / (d / e);
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. %.0f / %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung5(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
                case 1: {
                    hasil1 = (b + (c + d)) + e;
                    hasil2 = (b + (c + d)) - e;
                    hasil3 = (b + (c + d)) * e;
                    hasil4 = (b + (c + d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b + (c - d)) + e;
                    hasil2 = (b + (c - d)) - e;
                    hasil3 = (b + (c - d)) * e;
                    hasil4 = (b + (c - d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b + (c * d)) + e;
                    hasil2 = (b + (c * d)) - e;
                    hasil3 = (b + (c * d)) * e;
                    hasil4 = (b + (c * d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b + (c / d)) + e;
                    hasil2 = (b + (c / d)) - e;
                    hasil3 = (b + (c / d)) * e;
                    hasil4 = (b + (c / d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = (b - (c + d)) + e;
                    hasil2 = (b - (c + d)) - e;
                    hasil3 = (b - (c + d)) * e;
                    hasil4 = (b - (c + d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b - (c - d)) + e;
                    hasil2 = (b - (c - d)) - e;
                    
                    hasil4 = (b - (c - d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b - (c * d)) + e;
                    hasil2 = (b - (c * d)) - e;
                    hasil3 = (b - (c * d)) * e;
                    hasil4 = (b - (c * d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b - (c / d)) + e;
                    hasil2 = (b - (c / d)) - e;
                    hasil3 = (b - (c / d)) * e;
                    hasil4 = (b - (c / d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 3: {
            switch (y) {
                case 1: {
                    hasil1 = (b * (c + d)) + e;
                    hasil2 = (b * (c + d)) - e;
                    hasil3 = (b * (c + d)) * e;
                    hasil4 = (b * (c + d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b * (c - d)) + e;
                    hasil2 = (b * (c - d)) - e;
                    hasil3 = (b * (c - d)) * e;
                    hasil4 = (b * (c - d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b * (c * d)) + e;
                    hasil2 = (b * (c * d)) - e;
                    hasil3 = (b * (c * d)) * e;
                    hasil4 = (b * (c * d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b * (c / d)) + e;
                    hasil2 = (b * (c / d)) - e;
                    hasil3 = (b * (c / d)) * e;
                    hasil4 = (b * (c / d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 4: {
            switch (y) {
                case 1: {
                    hasil1 = (b / (c + d)) + e;
                    hasil2 = (b / (c + d)) - e;
                    hasil3 = (b / (c + d)) * e;
                    hasil4 = (b / (c + d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = (b / (c - d)) + e;
                    hasil2 = (b / (c - d)) - e;
                    hasil3 = (b / (c - d)) * e;
                    hasil4 = (b / (c - d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = (b / (c * d)) + e;
                    hasil2 = (b / (c * d)) - e;
                    hasil3 = (b / (c * d)) * e;
                    hasil4 = (b / (c * d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = (b / (c / d)) + e;
                    hasil2 = (b / (c / d)) - e;
                    hasil3 = (b / (c / d)) * e;
                    hasil4 = (b / (c / d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung6(int x, int y, float b, float c, float d, float e, int *f) {
    float hasil1, hasil2, hasil3, hasil4;

    switch (x) {
        case 1: {
            switch (y) {
				case 1: {
					hasil1 = ((b + c) + d) + e;
                    hasil2 = ((b + c) + d) - e;
                    hasil3 = ((b + c) + d) * e;
                    hasil4 = ((b + c) + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
				}
				case 2: {
					hasil1 = ((b + c) - d) + e;
                    hasil2 = ((b + c) - d) - e;
                    hasil3 = ((b + c) - d) * e;
                    hasil4 = ((b + c) - d) / e;
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					
                }
                case 3: {
                    hasil1 = ((b + c) * d) + e;
                    hasil2 = ((b + c) * d) - e;
                    hasil3 = ((b + c) * d) * e;
                    hasil4 = ((b + c) * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = ((b + c) / d) + e;
                    hasil2 = ((b + c) / d) - e;
                    hasil3 = ((b + c) / d) * e;
                    hasil4 = ((b + c) / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 2: {
            switch (y) {
                case 1: {
                    hasil1 = ((b - c) + d) + e;
					hasil2 = ((b - c) + d) - e;
					hasil3 = ((b - c) + d) * e;
                    hasil4 = ((b - c) + d) / e;
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					
                }
                case 2: {
                    hasil3 = ((b - c) - d) * e;
                    hasil4 = ((b - c) - d) / e;
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
						break;
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = ((b - c) * d) + e;
                    hasil2 = ((b - c) * d) - e;
                    hasil3 = ((b - c) * d) * e;
                    hasil4 = ((b - c) * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 4: {
                    hasil1 = ((b - c) / d) + e;
                    hasil2 = ((b - c) / d) - e;
                    hasil3 = ((b - c) / d) * e;
                    hasil4 = ((b - c) / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 3: {
            switch (y) {
                case 1: {
                    hasil1 = ((b * c) + d) + e;
                    hasil2 = ((b * c) + d) - e;
                    hasil3 = ((b * c) + d) * e;
                    hasil4 = ((b * c) + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = ((b * c) - d) + e;
                    hasil2 = ((b * c) - d) - e;
                    hasil3 = ((b * c) - d) * e;
                    hasil4 = ((b * c) - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                
                case 3: {
                    hasil1 = ((b * c) / d) + e;
                    hasil2 = ((b * c) / d) - e;
                    hasil3 = ((b * c) / d) * e;
                    hasil4 = ((b * c) / d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
        case 4: {
            switch (y) {
                case 1: {
                    hasil1 = ((b / c) + d) + e;
                    hasil2 = ((b / c) + d) - e;
                    hasil3 = ((b / c) + d) * e;
                    hasil4 = ((b / c) + d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 2: {
                    hasil1 = ((b / c) - d) + e;
                    hasil2 = ((b / c) - d) - e;
                    hasil3 = ((b / c) - d) * e;
                    hasil4 = ((b / c) - d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
                case 3: {
                    hasil1 = ((b / c) * d) + e;
                    hasil2 = ((b / c) * d) - e;
                    hasil3 = ((b / c) * d) * e;
                    hasil4 = ((b / c) * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung7(int x, int y, float b, float c, float d, float e, int *f) {
	float hasil1, hasil2, hasil3, hasil4;

	switch (x) {
		case 1: {
			switch (y) {
				case 1: {
					hasil1 = (b + c) + (d * e);
					hasil2 = (b + c) + (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 2: {
					hasil1 = (b + c) - (d * e);
					hasil2 = (b + c) - (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 3: {
					hasil1 = (b + c) * (d + e);
					hasil2 = (b + c) * (d - e);
					hasil3 = (b + c) * (d * e);
					hasil4 = (b + c) * (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 4: {
					hasil1 = (b + c) / (d + e);
					hasil2 = (b + c) / (d - e);
					hasil3 = (b + c) / (d * e);
					hasil4 = (b + c) / (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f + %.0f) / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
			}
			break;
		}
		case 2: {
			switch (y) {
				case 1: {
					hasil1 = (b - c) + (d * e);
					hasil2 = (b - c) + (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) + (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 2: {
					hasil1 = (b - c) - (d * e);
					hasil2 = (b - c) - (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) - (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 3: {
					hasil1 = (b - c) * (d + e);
					hasil2 = (b - c) * (d - e);
					hasil3 = (b - c) * (d * e);
					hasil4 = (b - c) * (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) * (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
				case 4: {
					hasil1 = (b - c) / (d + e);
					hasil2 = (b - c) / (d - e);
					hasil3 = (b - c) / (d * e);
					hasil4 = (b - c) / (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / (%.0f + %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / (%.0f - %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / (%.0f * %.0f)\n", (*f), b, c, d, e);
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						printf("%7d. (%.0f - %.0f) / (%.0f / %.0f)\n", (*f), b, c, d, e);
					}
					break;
				}
			}
			break;
		}
	}
}