#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>

const int MAX = 30;
using namespace std;

struct Canh {
	char to;
	int value;
};

struct Dinh {
	int n=0;
	char name;
	Canh canh[MAX];
};
 
struct DsKe {
	int n=0;
	Dinh dinh[MAX];
};


void nhapCanh(Canh& canh);
void xuatCanh(Canh canh);
void nhapDinh(Dinh& dinh);
void xuatDinh(Dinh dinh);
void nhapDsKe(DsKe& dsKe);
void xuatDsKe(DsKe dsKe);
void themCanh(Dinh& d, char to, int value);
void themDinh(DsKe& dsDinh, char name);

void dijkstra(DsKe graph, char src, char dest);