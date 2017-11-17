#include <iostream>
#define a 10;
#define b 11;
#define c 12;
#define d 13;
#define e 14;
#define f 15;

using namespace std;

int Sbox[16][16][2];
int Rcon[4][10][2];
int matriz[4][4][2];
int matriz2[4][4][2];
int matriz3[4][4][2];
int matriz4[4][4][2];
int respuesta[4][16][2];

void generar_sbox(){
    Sbox[0][0][0] = 6;
    Sbox[0][0][1] = 3;
    Sbox[0][1][0] = 7;
    Sbox[0][1][1] = c;
    Sbox[0][2][0] = 7;
    Sbox[0][2][1] = 7;
    Sbox[0][3][0] = 7;
    Sbox[0][3][1] = b;
    Sbox[0][4][0] = f;
    Sbox[0][4][1] = 2;
    Sbox[0][5][0] = 6;
    Sbox[0][5][1] = b;
    Sbox[0][6][0] = 6;
    Sbox[0][6][1] = f;
    Sbox[0][7][0] = c;
    Sbox[0][7][1] = 5;
    Sbox[0][8][0] = 3;
    Sbox[0][8][1] = 0;
    Sbox[0][9][0] = 0;
    Sbox[0][9][1] = 1;
    Sbox[0][10][0] = 6;
    Sbox[0][10][1] = 7;
    Sbox[0][11][0] = 2;
    Sbox[0][11][1] = b;
    Sbox[0][12][0] = f;
    Sbox[0][12][1] = e;
    Sbox[0][13][0] = d;
    Sbox[0][13][1] = 7;
    Sbox[0][14][0] = a;
    Sbox[0][14][1] = b;
    Sbox[0][15][0] = 7;
    Sbox[0][15][1] = 6;

    Sbox[1][0][0] = c;
    Sbox[1][0][1] = a;
    Sbox[1][1][0] = 8;
    Sbox[1][1][1] = 2;
    Sbox[1][2][0] = c;
    Sbox[1][2][1] = 9;
    Sbox[1][3][0] = 7;
    Sbox[1][3][1] = d;
    Sbox[1][4][0] = f;
    Sbox[1][4][1] = a;
    Sbox[1][5][0] = 5;
    Sbox[1][5][1] = 9;
    Sbox[1][6][0] = 4;
    Sbox[1][6][1] = 7;
    Sbox[1][7][0] = f;
    Sbox[1][7][1] = 0;
    Sbox[1][8][0] = a;
    Sbox[1][8][1] = d;
    Sbox[1][9][0] = d;
    Sbox[1][9][1] = 4;
    Sbox[1][10][0] = a;
    Sbox[1][10][1] = 2;
    Sbox[1][11][0] = a;
    Sbox[1][11][1] = f;
    Sbox[1][12][0] = 9;
    Sbox[1][12][1] = c;
    Sbox[1][13][0] = a;
    Sbox[1][13][1] = 4;
    Sbox[1][14][0] = 7;
    Sbox[1][14][1] = 2;
    Sbox[1][15][0] = c;
    Sbox[1][15][1] = 0;

    Sbox[2][0][0] = b;
    Sbox[2][0][1] = 7;
    Sbox[2][1][0] = f;
    Sbox[2][1][1] = d;
    Sbox[2][2][0] = 9;
    Sbox[2][2][1] = 3;
    Sbox[2][3][0] = 2;
    Sbox[2][3][1] = 6;
    Sbox[2][4][0] = 3;
    Sbox[2][4][1] = 6;
    Sbox[2][5][0] = 3;
    Sbox[2][5][1] = f;
    Sbox[2][6][0] = f;
    Sbox[2][6][1] = 7;
    Sbox[2][7][0] = c;
    Sbox[2][7][1] = c;
    Sbox[2][8][0] = 3;
    Sbox[2][8][1] = 4;
    Sbox[2][9][0] = a;
    Sbox[2][9][1] = 5;
    Sbox[2][10][0] = e;
    Sbox[2][10][1] = 5;
    Sbox[2][11][0] = f;
    Sbox[2][11][1] = 1;
    Sbox[2][12][0] = 7;
    Sbox[2][12][1] = 1;
    Sbox[2][13][0] = d;
    Sbox[2][13][1] = 8;
    Sbox[2][14][0] = 3;
    Sbox[2][14][1] = 1;
    Sbox[2][15][0] = 1;
    Sbox[2][15][1] = 5;

    Sbox[3][0][0] = 0;
    Sbox[3][0][1] = 4;
    Sbox[3][1][0] = c;
    Sbox[3][1][1] = 7;
    Sbox[3][2][0] = 2;
    Sbox[3][2][1] = 3;
    Sbox[3][3][0] = c;
    Sbox[3][3][1] = 3;
    Sbox[3][4][0] = 1;
    Sbox[3][4][1] = 8;
    Sbox[3][5][0] = 9;
    Sbox[3][5][1] = 6;
    Sbox[3][6][0] = 0;
    Sbox[3][6][1] = 5;
    Sbox[3][7][0] = 9;
    Sbox[3][7][1] = a;
    Sbox[3][8][0] = 0;
    Sbox[3][8][1] = 7;
    Sbox[3][9][0] = 1;
    Sbox[3][9][1] = 2;
    Sbox[3][10][0] = 8;
    Sbox[3][10][1] = 0;
    Sbox[3][11][0] = e;
    Sbox[3][11][1] = 2;
    Sbox[3][12][0] = e;
    Sbox[3][12][1] = b;
    Sbox[3][13][0] = 2;
    Sbox[3][13][1] = 7;
    Sbox[3][14][0] = b;
    Sbox[3][14][1] = 2;
    Sbox[3][15][0] = 7;
    Sbox[3][15][1] = 5;

    Sbox[4][0][0] = 0;
    Sbox[4][0][1] = 9;
    Sbox[4][1][0] = 8;
    Sbox[4][1][1] = 3;
    Sbox[4][2][0] = 2;
    Sbox[4][2][1] = c;
    Sbox[4][3][0] = 1;
    Sbox[4][3][1] = a;
    Sbox[4][4][0] = 1;
    Sbox[4][4][1] = b;
    Sbox[4][5][0] = 6;
    Sbox[4][5][1] = e;
    Sbox[4][6][0] = 5;
    Sbox[4][6][1] = a;
    Sbox[4][7][0] = a;
    Sbox[4][7][1] = 0;
    Sbox[4][8][0] = 5;
    Sbox[4][8][1] = 2;
    Sbox[4][9][0] = 3;
    Sbox[4][9][1] = b;
    Sbox[4][10][0] = d;
    Sbox[4][10][1] = 6;
    Sbox[4][11][0] = d;
    Sbox[4][11][1] = 3;
    Sbox[4][12][0] = 2;
    Sbox[4][12][1] = 9;
    Sbox[4][13][0] = e;
    Sbox[4][13][1] = 3;
    Sbox[4][14][0] = 2;
    Sbox[4][14][1] = f;
    Sbox[4][15][0] = 8;
    Sbox[4][15][1] = 4;

    Sbox[5][0][0] = 5;
    Sbox[5][0][1] = 3;
    Sbox[5][1][0] = d;
    Sbox[5][1][1] = 1;
    Sbox[5][2][0] = 0;
    Sbox[5][2][1] = 0;
    Sbox[5][3][0] = e;
    Sbox[5][3][1] = d;
    Sbox[5][4][0] = 2;
    Sbox[5][4][1] = 0;
    Sbox[5][5][0] = f;
    Sbox[5][5][1] = c;
    Sbox[5][6][0] = b;
    Sbox[5][6][1] = 1;
    Sbox[5][7][0] = 5;
    Sbox[5][7][1] = b;
    Sbox[5][8][0] = 6;
    Sbox[5][8][1] = a;
    Sbox[5][9][0] = c;
    Sbox[5][9][1] = b;
    Sbox[5][10][0] = b;
    Sbox[5][10][1] = e;
    Sbox[5][11][0] = 3;
    Sbox[5][11][1] = 9;
    Sbox[5][12][0] = 4;
    Sbox[5][12][1] = a;
    Sbox[5][13][0] = 4;
    Sbox[5][13][1] = c;
    Sbox[5][14][0] = 5;
    Sbox[5][14][1] = 8;
    Sbox[5][15][0] = c;
    Sbox[5][15][1] = f;

    Sbox[6][0][0] = d;
    Sbox[6][0][1] = 0;
    Sbox[6][1][0] = e;
    Sbox[6][1][1] = f;
    Sbox[6][2][0] = a;
    Sbox[6][2][1] = a;
    Sbox[6][3][0] = f;
    Sbox[6][3][1] = b;
    Sbox[6][4][0] = 4;
    Sbox[6][4][1] = 3;
    Sbox[6][5][0] = 4;
    Sbox[6][5][1] = d;
    Sbox[6][6][0] = 3;
    Sbox[6][6][1] = 3;
    Sbox[6][7][0] = 8;
    Sbox[6][7][1] = 5;
    Sbox[6][8][0] = 4;
    Sbox[6][8][1] = 5;
    Sbox[6][9][0] = f;
    Sbox[6][9][1] = 9;
    Sbox[6][10][0] = 0;
    Sbox[6][10][1] = 2;
    Sbox[6][11][0] = 7;
    Sbox[6][11][1] = f;
    Sbox[6][12][0] = 5;
    Sbox[6][12][1] = 0;
    Sbox[6][13][0] = 3;
    Sbox[6][13][1] = c;
    Sbox[6][14][0] = 9;
    Sbox[6][14][1] = f;
    Sbox[6][15][0] = a;
    Sbox[6][15][1] = 8;

    Sbox[7][0][0] = 5;
    Sbox[7][0][1] = 1;
    Sbox[7][1][0] = a;
    Sbox[7][1][1] = 3;
    Sbox[7][2][0] = 4;
    Sbox[7][2][1] = 0;
    Sbox[7][3][0] = 8;
    Sbox[7][3][1] = f;
    Sbox[7][4][0] = 9;
    Sbox[7][4][1] = 2;
    Sbox[7][5][0] = 9;
    Sbox[7][5][1] = d;
    Sbox[7][6][0] = 3;
    Sbox[7][6][1] = 8;
    Sbox[7][7][0] = f;
    Sbox[7][7][1] = 5;
    Sbox[7][8][0] = b;
    Sbox[7][8][1] = c;
    Sbox[7][9][0] = b;
    Sbox[7][9][1] = 6;
    Sbox[7][10][0] = d;
    Sbox[7][10][1] = a;
    Sbox[7][11][0] = 2;
    Sbox[7][11][1] = 1;
    Sbox[7][12][0] = 1;
    Sbox[7][12][1] = 0;
    Sbox[7][13][0] = f;
    Sbox[7][13][1] = f;
    Sbox[7][14][0] = f;
    Sbox[7][14][1] = 3;
    Sbox[7][15][0] = d;
    Sbox[7][15][1] = 2;

    Sbox[8][0][0] = c;
    Sbox[8][0][1] = d;
    Sbox[8][1][0] = 0;
    Sbox[8][1][1] = c;
    Sbox[8][2][0] = 1;
    Sbox[8][2][1] = 3;
    Sbox[8][3][0] = e;
    Sbox[8][3][1] = c;
    Sbox[8][4][0] = 5;
    Sbox[8][4][1] = f;
    Sbox[8][5][0] = 9;
    Sbox[8][5][1] = 7;
    Sbox[8][6][0] = 4;
    Sbox[8][6][1] = 4;
    Sbox[8][7][0] = 1;
    Sbox[8][7][1] = 7;
    Sbox[8][8][0] = c;
    Sbox[8][8][1] = 4;
    Sbox[8][9][0] = a;
    Sbox[8][9][1] = 7;
    Sbox[8][10][0] = 7;
    Sbox[8][10][1] = e;
    Sbox[8][11][0] = 3;
    Sbox[8][11][1] = d;
    Sbox[8][12][0] = 6;
    Sbox[8][12][1] = 4;
    Sbox[8][13][0] = 5;
    Sbox[8][13][1] = d;
    Sbox[8][14][0] = 1;
    Sbox[8][14][1] = 9;
    Sbox[8][15][0] = 7;
    Sbox[8][15][1] = 3;

    Sbox[9][0][0] = 6;
    Sbox[9][0][1] = 0;
    Sbox[9][1][0] = 8;
    Sbox[9][1][1] = 1;
    Sbox[9][2][0] = 4;
    Sbox[9][2][1] = f;
    Sbox[9][3][0] = d;
    Sbox[9][3][1] = c;
    Sbox[9][4][0] = 2;
    Sbox[9][4][1] = 2;
    Sbox[9][5][0] = 2;
    Sbox[9][5][1] = a;
    Sbox[9][6][0] = 9;
    Sbox[9][6][1] = 0;
    Sbox[9][7][0] = 8;
    Sbox[9][7][1] = 8;
    Sbox[9][8][0] = 4;
    Sbox[9][8][1] = 6;
    Sbox[9][9][0] = e;
    Sbox[9][9][1] = e;
    Sbox[9][10][0] = b;
    Sbox[9][10][1] = 8;
    Sbox[9][11][0] = 1;
    Sbox[9][11][1] = 4;
    Sbox[9][12][0] = d;
    Sbox[9][12][1] = e;
    Sbox[9][13][0] = 5;
    Sbox[9][13][1] = e;
    Sbox[9][14][0] = 0;
    Sbox[9][14][1] = b;
    Sbox[9][15][0] = d;
    Sbox[9][15][1] = b;

    Sbox[10][0][0] = e;
    Sbox[10][0][1] = 0;
    Sbox[10][1][0] = 3;
    Sbox[10][1][1] = 2;
    Sbox[10][2][0] = 3;
    Sbox[10][2][1] = a;
    Sbox[10][3][0] = 0;
    Sbox[10][3][1] = a;
    Sbox[10][4][0] = 4;
    Sbox[10][4][1] = 9;
    Sbox[10][5][0] = 0;
    Sbox[10][5][1] = 6;
    Sbox[10][6][0] = 2;
    Sbox[10][6][1] = 4;
    Sbox[10][7][0] = 5;
    Sbox[10][7][1] = c;
    Sbox[10][8][0] = c;
    Sbox[10][8][1] = 2;
    Sbox[10][9][0] = d;
    Sbox[10][9][1] = 3;
    Sbox[10][10][0] = a;
    Sbox[10][10][1] = c;
    Sbox[10][11][0] = 6;
    Sbox[10][11][1] = 2;
    Sbox[10][12][0] = 9;
    Sbox[10][12][1] = 1;
    Sbox[10][13][0] = 9;
    Sbox[10][13][1] = 5;
    Sbox[10][14][0] = e;
    Sbox[10][14][1] = 4;
    Sbox[10][15][0] = 7;
    Sbox[10][15][1] = 9;

    Sbox[11][0][0] = e;
    Sbox[11][0][1] = 7;
    Sbox[11][1][0] = c;
    Sbox[11][1][1] = 8;
    Sbox[11][2][0] = 3;
    Sbox[11][2][1] = 7;
    Sbox[11][3][0] = 6;
    Sbox[11][3][1] = d;
    Sbox[11][4][0] = 8;
    Sbox[11][4][1] = d;
    Sbox[11][5][0] = d;
    Sbox[11][5][1] = 5;
    Sbox[11][6][0] = 4;
    Sbox[11][6][1] = e;
    Sbox[11][7][0] = a;
    Sbox[11][7][1] = 9;
    Sbox[11][8][0] = 6;
    Sbox[11][8][1] = c;
    Sbox[11][9][0] = 5;
    Sbox[11][9][1] = 6;
    Sbox[11][10][0] = f;
    Sbox[11][10][1] = 4;
    Sbox[11][11][0] = e;
    Sbox[11][11][1] = a;
    Sbox[11][12][0] = 6;
    Sbox[11][12][1] = 5;
    Sbox[11][13][0] = 7;
    Sbox[11][13][1] = a;
    Sbox[11][14][0] = a;
    Sbox[11][14][1] = e;
    Sbox[11][15][0] = 0;
    Sbox[11][15][1] = 8;

    Sbox[12][0][0] = b;
    Sbox[12][0][1] = a;
    Sbox[12][1][0] = 7;
    Sbox[12][1][1] = 8;
    Sbox[12][2][0] = 2;
    Sbox[12][2][1] = 5;
    Sbox[12][3][0] = 2;
    Sbox[12][3][1] = e;
    Sbox[12][4][0] = 1;
    Sbox[12][4][1] = c;
    Sbox[12][5][0] = a;
    Sbox[12][5][1] = 6;
    Sbox[12][6][0] = b;
    Sbox[12][6][1] = 4;
    Sbox[12][7][0] = c;
    Sbox[12][7][1] = 6;
    Sbox[12][8][0] = e;
    Sbox[12][8][1] = 8;
    Sbox[12][9][0] = d;
    Sbox[12][9][1] = d;
    Sbox[12][10][0] = 7;
    Sbox[12][10][1] = 4;
    Sbox[12][11][0] = 1;
    Sbox[12][11][1] = f;
    Sbox[12][12][0] = 4;
    Sbox[12][12][1] = b;
    Sbox[12][13][0] = b;
    Sbox[12][13][1] = d;
    Sbox[12][14][0] = 8;
    Sbox[12][14][1] = b;
    Sbox[12][15][0] = 8;
    Sbox[12][15][1] = a;

    Sbox[13][0][0] = 7;
    Sbox[13][0][1] = 0;
    Sbox[13][1][0] = 3;
    Sbox[13][1][1] = e;
    Sbox[13][2][0] = b;
    Sbox[13][2][1] = 5;
    Sbox[13][3][0] = 6;
    Sbox[13][3][1] = 6;
    Sbox[13][4][0] = 4;
    Sbox[13][4][1] = 8;
    Sbox[13][5][0] = 0;
    Sbox[13][5][1] = 3;
    Sbox[13][6][0] = f;
    Sbox[13][6][1] = 6;
    Sbox[13][7][0] = 0;
    Sbox[13][7][1] = e;
    Sbox[13][8][0] = 6;
    Sbox[13][8][1] = 1;
    Sbox[13][9][0] = 3;
    Sbox[13][9][1] = 5;
    Sbox[13][10][0] = 5;
    Sbox[13][10][1] = 7;
    Sbox[13][11][0] = b;
    Sbox[13][11][1] = 9;
    Sbox[13][12][0] = 8;
    Sbox[13][12][1] = 6;
    Sbox[13][13][0] = c;
    Sbox[13][13][1] = 1;
    Sbox[13][14][0] = 1;
    Sbox[13][14][1] = d;
    Sbox[13][15][0] = 9;
    Sbox[13][15][1] = e;

    Sbox[14][0][0] = e;
    Sbox[14][0][1] = 1;
    Sbox[14][1][0] = f;
    Sbox[14][1][1] = 8;
    Sbox[14][2][0] = 9;
    Sbox[14][2][1] = 8;
    Sbox[14][3][0] = 1;
    Sbox[14][3][1] = 1;
    Sbox[14][4][0] = 6;
    Sbox[14][4][1] = 9;
    Sbox[14][5][0] = d;
    Sbox[14][5][1] = 9;
    Sbox[14][6][0] = 8;
    Sbox[14][6][1] = e;
    Sbox[14][7][0] = 9;
    Sbox[14][7][1] = 4;
    Sbox[14][8][0] = 9;
    Sbox[14][8][1] = b;
    Sbox[14][9][0] = 1;
    Sbox[14][9][1] = e;
    Sbox[14][10][0] = 8;
    Sbox[14][10][1] = 7;
    Sbox[14][11][0] = e;
    Sbox[14][11][1] = 9;
    Sbox[14][12][0] = c;
    Sbox[14][12][1] = e;
    Sbox[14][13][0] = 5;
    Sbox[14][13][1] = 5;
    Sbox[14][14][0] = 2;
    Sbox[14][14][1] = 8;
    Sbox[14][15][0] = d;
    Sbox[14][15][1] = f;

    Sbox[15][0][0] = 8;
    Sbox[15][0][1] = c;
    Sbox[15][1][0] = a;
    Sbox[15][1][1] = 1;
    Sbox[15][2][0] = 8;
    Sbox[15][2][1] = 9;
    Sbox[15][3][0] = 0;
    Sbox[15][3][1] = d;
    Sbox[15][4][0] = b;
    Sbox[15][4][1] = f;
    Sbox[15][5][0] = e;
    Sbox[15][5][1] = 6;
    Sbox[15][6][0] = 4;
    Sbox[15][6][1] = 2;
    Sbox[15][7][0] = 6;
    Sbox[15][7][1] = 8;
    Sbox[15][8][0] = 4;
    Sbox[15][8][1] = 1;
    Sbox[15][9][0] = 9;
    Sbox[15][9][1] = 9;
    Sbox[15][10][0] = 2;
    Sbox[15][10][1] = d;
    Sbox[15][11][0] = 0;
    Sbox[15][11][1] = f;
    Sbox[15][12][0] = b;
    Sbox[15][12][1] = 0;
    Sbox[15][13][0] = 5;
    Sbox[15][13][1] = 4;
    Sbox[15][14][0] = b;
    Sbox[15][14][1] = b;
    Sbox[15][15][0] = 1;
    Sbox[15][15][1] = 6;
}

void generar_rcon(){
    Rcon[0][0][0]=0;
	Rcon[0][0][1]=1;
	Rcon[0][1][0]=0;
	Rcon[0][1][1]=2;
	Rcon[0][2][0]=0;
	Rcon[0][2][1]=4;
	Rcon[0][3][0]=0;
	Rcon[0][3][1]=8;
	Rcon[0][4][0]=1;
	Rcon[0][4][1]=0;
	Rcon[0][5][0]=2;
	Rcon[0][5][1]=0;
	Rcon[0][6][0]=4;
	Rcon[0][6][1]=0;
	Rcon[0][7][0]=8;
	Rcon[0][7][1]=0;
	Rcon[0][8][0]=1;
	Rcon[0][8][1]=b;
	Rcon[0][9][1]=3;
	Rcon[0][9][1]=6;
}

void generar_clave(){
    matriz[0][0][0] = 2;
    matriz[0][0][1] = b;
    matriz[0][1][0] = 2;
    matriz[0][1][1] = 8;
    matriz[0][2][0] = a;
    matriz[0][2][1] = b;
    matriz[0][3][0] = 0;
    matriz[0][3][1] = 9;

    matriz[1][0][0] = 7;
    matriz[1][0][1] = e;
    matriz[1][1][0] = a;
    matriz[1][1][1] = e;
    matriz[1][2][0] = f;
    matriz[1][2][1] = 7;
    matriz[1][3][0] = c;
    matriz[1][3][1] = f;

    matriz[2][0][0] = 1;
    matriz[2][0][1] = 5;
    matriz[2][1][0] = d;
    matriz[2][1][1] = 2;
    matriz[2][2][0] = 1;
    matriz[2][2][1] = 5;
    matriz[2][3][0] = 4;
    matriz[2][3][1] = f;

    matriz[3][0][0] = 1;
    matriz[3][0][1] = 6;
    matriz[3][1][0] = a;
    matriz[3][1][1] = 6;
    matriz[3][2][0] = 8;
    matriz[3][2][1] = 8;
    matriz[3][3][0] = 3;
    matriz[3][3][1] = c;
}

void mod_mat(int ma_1[4][4][2], int ma_2[4][4][2], int rcon){
    /*ma_2[0][0][0] = ma_1[1][3][0];
    ma_2[0][0][1] = ma_1[1][3][1];
    ma_2[1][0][0] = ma_1[2][3][0];
    ma_2[1][0][1] = ma_1[2][3][1];
    ma_2[2][0][0] = ma_1[3][3][0];
    ma_2[2][0][1] = ma_1[3][3][1];
    ma_2[3][0][0] = ma_1[0][3][0];
    ma_2[3][0][1] = ma_1[0][3][1];*/

    ma_2[0][0][0] = Sbox[ma_1[1][3][0]][ma_1[1][3][1]][0];
    ma_2[0][0][1] = Sbox[ma_1[1][3][0]][ma_1[1][3][1]][1];
    ma_2[1][0][0] = Sbox[ma_1[2][3][0]][ma_1[2][3][1]][0];
    ma_2[1][0][1] = Sbox[ma_1[2][3][0]][ma_1[2][3][1]][1];
    ma_2[2][0][0] = Sbox[ma_1[3][3][0]][ma_1[3][3][1]][0];
    ma_2[2][0][1] = Sbox[ma_1[3][3][0]][ma_1[3][3][1]][1];
    ma_2[3][0][0] = Sbox[ma_1[0][3][0]][ma_1[0][3][1]][0];
    ma_2[3][0][1] = Sbox[ma_1[0][3][0]][ma_1[0][3][1]][1];

    for(int i = 0; i < 4; i++){
        ma_2[i][0][0] = ma_1[i][0][0] ^ ma_2[i][0][0] ^ Rcon[i][rcon][0];
        ma_2[i][0][1] = ma_1[i][0][1] ^ ma_2[i][0][1] ^ Rcon[i][rcon][1];
    }
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ma_2[j][i][0] = ma_1[j][i][0] ^ ma_2[j][i-1][0];
            ma_2[j][i][1] = ma_1[j][i][1] ^ ma_2[j][i-1][1];
        }
    }
}

void permutar(){
    generar_clave();
    mod_mat(matriz,matriz2,0);
    mod_mat(matriz2,matriz3,1);
    mod_mat(matriz3,matriz4,2);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            respuesta[i][j][0] = matriz[i][j][0];
            respuesta[i][j][1] = matriz[i][j][1];

            respuesta[i][j+4][0] = matriz2[i][j][0];
            respuesta[i][j+4][1] = matriz2[i][j][1];

            respuesta[i][j+8][0] = matriz3[i][j][0];
            respuesta[i][j+8][1] = matriz3[i][j][1];

            respuesta[i][j+12][0] = matriz4[i][j][0];
            respuesta[i][j+12][1] = matriz4[i][j][1];
        }
    }
}

void imprimir(int matriz[4][4][2]){
    int valores[] = {10,11,12,13,14,15};
    char letras[] = {'a','b','c','d','e','f'};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j][0] > 9){
                cout << letras[matriz[i][j][0] - 10];
            }
            else{
                cout << matriz[i][j][0];
            }
            if(matriz[i][j][1] > 9){
                cout << letras[matriz[i][j][1] - 10];
            }
            else{
                cout << matriz[i][j][1];
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void imprimir_rpta(){
    int valores[] = {10,11,12,13,14,15};
    char letras[] = {'a','b','c','d','e','f'};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 16; j++){
            if(respuesta[i][j][0] > 9){
                cout << letras[respuesta[i][j][0] - 10];
            }
            else{
                cout << respuesta[i][j][0];
            }
            if(respuesta[i][j][1] > 9){
                cout << letras[respuesta[i][j][1] - 10];
            }
            else{
                cout << respuesta[i][j][1];
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    generar_sbox();
    generar_rcon();
    permutar();
    imprimir_rpta();
    return 0;
}
