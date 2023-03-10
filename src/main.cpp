// Nama : Ferindya Aulia Berlianty
// NIM : 13521161
// Kelas : K 01
// Deskripsi : Tugas Kecil 1 Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

// Definisi fungsi dan prosedur yang digunakan
bool valid(float b, float c, float d, float e);
// Mengecek apakah input b, c, d, e merupakan bilangan positif
void swap(int x, float *b, float *c, float *d, float *e, float r, float s, float t, float u);
// Mengubah urutan posisi
void hitung1(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung b ... c ... d ... e
void hitung2(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung (b ... c) ... d ... e
void hitung3(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung b ... (c ... d) ... e
void hitung4(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung b ... c ... (d ... e)
void hitung5(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung (b ... (c ... d)) ... e
void hitung6(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung ((b ... c) ... d) ... e
void hitung7(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban);
// menghitung (b ... c) ... (d ... e)
void convert(string input, float *value);
// mengubah masukan string (kartu) menjadi integer

int main() {
	srand(time(0));
    bool check;
    int i, x, y;
    int count;
    string a, j, q, k;
    float b, c, d, e;
    float r, s, t, u;
	float time;
    
	vector<string> jawaban;
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
            b = (rand()%13)+1;
            c = (rand()%13)+1;
            d = (rand()%13)+1;
            e = (rand()%13)+1;
			check = valid(b, c, d, e);
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
                hitung1(x, y, b, c, d, e, &count, jawaban);
                hitung2(x, y, b, c, d, e, &count, jawaban);
                hitung3(x, y, b, c, d, e, &count, jawaban);
                hitung4(x, y, b, c, d, e, &count, jawaban);
                hitung5(x, y, b, c, d, e, &count, jawaban);
				hitung6(x, y, b, c, d, e, &count, jawaban);
				hitung7(x, y, b, c, d, e, &count, jawaban);
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
	// tulis ke layar
	for (int i = 0; i < jawaban.size(); i++){
		cout << jawaban[i] << endl;
	}
	// tulis ke file
	string ans, namaFile;
    printf("Apakah ingin menyimpan solusi ? (y/n)\n");
	cin >> ans;
	if (ans == "y") {
		printf("Masukkan nama file (dengan format.txt): \n");
		cin >> namaFile;
		printf("Hasil berhasil disimpan dalam file.\n");
		ofstream file;
		file.open("../test/" + namaFile);
		for (int i = 0 ;i < jawaban.size(); i++){
		file << jawaban[i] << endl;
	}
	file.close();
	}
	else if (ans == "n") {
		printf("Hasil tidak disimpan dalam file.\n");
	}
	
    printf("Waktu Eksekusi Program  = %.5f detik\n", time);
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

void hitung1(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) { 
    float hasil1, hasil2, hasil3, hasil4;
	char tmp[20]; 
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
                        sprintf(tmp,"%7d. %.0f + %.0f + %0.f + %.0f\n", (*f), b, c, d, e); 
						jawaban.push_back(string(tmp)); 
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f + %0.f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f + %0.f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f + %0.f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
                        sprintf(tmp,"%7d. %.0f + %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
                        (*f)++;
                        sprintf(tmp,"%7d. %.0f + %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
                    }
                    if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
				}
			}
			break;
		}
    }
}

void hitung2(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
    float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
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
						sprintf(tmp,"%7d. (%.0f + %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / %.0f) + %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) + %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) + %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) + %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / %.0f) - %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) - %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) - %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) - %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / %.0f) * %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) * %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) * %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) * %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / %.0f) / %.0f + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) / %.0f - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) / %.0f * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / %.0f) / %.0f / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                 }
            }
            break;
        }
    }
}

void hitung3(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
    float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
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
						sprintf(tmp,"%7d. %.0f + (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / (%.0f + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / (%.0f - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / (%.0f * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / (%.0f / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / (%.0f / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung4(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
    float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
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
						sprintf(tmp,"%7d. %.0f + %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f + %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f + %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f - %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f - %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f * %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f * %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f + (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f - (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. %.0f / %.0f / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. %.0f / %.0f / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung5(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
    float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
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
						sprintf(tmp,"%7d. (%.0f + (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                }
                case 2: {
                    hasil1 = (b - (c - d)) + e;
                    hasil2 = (b - (c - d)) - e;
                    hasil4 = (b - (c - d)) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f * (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f * (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / (%.0f + %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f + %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f + %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f + %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / (%.0f - %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f - %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f - %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f - %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / (%.0f * %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f * %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f * %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f * %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f / (%.0f / %.0f)) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f / %.0f)) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f / %.0f)) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f / (%.0f / %.0f)) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung6(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
    float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
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
						sprintf(tmp,"%7d. ((%.0f + %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f + %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					
                }
                case 3: {
                    hasil1 = ((b + c) * d) + e;
                    hasil2 = ((b + c) * d) - e;
                    hasil3 = ((b + c) * d) * e;
                    hasil4 = ((b + c) * d) / e;
                    if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f + %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f + %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f - %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					
                }
                case 2: {
                    hasil3 = ((b - c) - d) * e;
                    hasil4 = ((b - c) - d) / e;
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
						break;
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f - %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f - %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f - %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f * %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f * %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f * %.0f) / %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) / %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) / %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f * %.0f) / %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f / %.0f) + %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) + %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) + %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) + %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f / %.0f) - %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) - %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) - %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) - %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. ((%.0f / %.0f) * %.0f) + %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) * %.0f) - %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) * %.0f) * %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. ((%.0f / %.0f) * %.0f) / %.0f\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
                }
            }
            break;
        }
    }
}

void hitung7(int x, int y, float b, float c, float d, float e, int *f, vector<string> &jawaban) {
	float hasil1, hasil2, hasil3, hasil4;
    char tmp[20];
	switch (x) {
		case 1: {
			switch (y) {
				case 1: {
					hasil1 = (b + c) + (d * e);
					hasil2 = (b + c) + (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
				}
				case 2: {
					hasil1 = (b + c) - (d * e);
					hasil2 = (b + c) - (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + %.0f) * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f + %.0f) / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f + %.0f) / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) + (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) + (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
				}
				case 2: {
					hasil1 = (b - c) - (d * e);
					hasil2 = (b - c) - (d / e);
					if (((hasil1 - 24) >= -0.00001) && ((hasil1 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) - (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) - (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) * (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) * (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
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
						sprintf(tmp,"%7d. (%.0f - %.0f) / (%.0f + %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil2 - 24) >= -0.00001) && ((hasil2 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / (%.0f - %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil3 - 24) >= -0.00001) && ((hasil3 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / (%.0f * %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					if (((hasil4 - 24) >= -0.00001) && ((hasil4 - 24) <= 0.00001)) {
						(*f)++;
						sprintf(tmp,"%7d. (%.0f - %.0f) / (%.0f / %.0f)\n", (*f), b, c, d, e);
                        jawaban.push_back(string(tmp));
					}
					break;
				}
			}
			break;
		}
	}
}