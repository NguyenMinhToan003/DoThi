#include "thuvien.h";


void nhapCanh(Canh& canh) {
	cout << "\nNhap Canh ke : ";
	cin >> canh.to;
	cout << "\nNhap Trong so : ";
	cin >> canh.value;
}
void xuatCanh(Canh canh) {
	cout << " Ke voi canh " << canh.to << " co trong so :" << canh.value << endl;
}
void nhapDinh(Dinh& dinh) {
	cout << "\nNhap ten Dinh : ";
	cin >> dinh.name;
	cout << "\nNhap so luong canh : ";
	cin >> dinh.n;
	for (int i = 0; i < dinh.n; i++) {
		nhapCanh(dinh.canh[i]);
	}
}
void xuatDinh(Dinh dinh) {
	cout << "\nTen Dinh : " << dinh.name << endl;
	for (int i = 0; i < dinh.n; i++) {
		xuatCanh(dinh.canh[i]);
	}
}
void nhapDSDinh(DSDinh& dsDinh) {
	cout << "\nNhap so luong dinh : ";
	cin >> dsDinh.n;
	for (int i = 0; i < dsDinh.n; i++) {
		nhapDinh(dsDinh.dinh[i]);
	}
}
void xuatDSDinh(DSDinh dsDinh) {
	for (int i = 0; i < dsDinh.n; i++) {
		xuatDinh(dsDinh.dinh[i]);
	}
}