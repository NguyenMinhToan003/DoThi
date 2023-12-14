#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const int MAX = 30;
using namespace std;

struct Canh {
	char to;
	int value;
};


struct Dinh {
	int n;
	char name;
	Canh canh[MAX];
};
 
struct DSDinh {
	int n;
	Dinh dinh[MAX];
};


void nhapCanh(Canh& canh);
void xuatCanh(Canh canh);
void nhapDinh(Dinh& dinh);
void xuatDinh(Dinh dinh);
void nhapDSDinh(DSDinh& dsDinh);
void xuatDSDinh(DSDinh dsDinh);