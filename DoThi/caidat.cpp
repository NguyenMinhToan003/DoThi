#include "thuvien.h"


void nhapCanh(Canh& canh) {
	cout << "\nNhap Dinh ke : ";
	cin >> canh.to;
	cout << "\nNhap Trong so : ";
	cin >> canh.value;
}
void xuatCanh(Canh canh) {
	cout << "(" << canh.to << ", " << canh.value << ") ";
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
	cout << "Dinh " << dinh.name << ": ";
	for (int j = 0; j < dinh.n; ++j) {
		xuatCanh(dinh.canh[j]);
	}
	cout << endl;
}
void nhapDsKe(DsKe& dsKe) {
	cout << "\nNhap so luong dinh : ";
	cin >> dsKe.n;
	for (int i = 0; i < dsKe.n; i++) {
		nhapDinh(dsKe.dinh[i]);
	}
}
void xuatDsKe(DsKe dsKe) {
	for (int i = 0; i < dsKe.n; i++) {
		xuatDinh(dsKe.dinh[i]);
	}
}

void themCanh(Dinh& d, char to, int value) {
	if (d.n < MAX) {
		d.canh[d.n].to = to;
		d.canh[d.n].value = value;
		d.n++;
	}
	else {
		cout << "Vuot qua so luong canh toi da!" << endl;
	}
}

void themDinh(DsKe& DsKe, char name) {
	if (DsKe.n < MAX) {
		DsKe.dinh[DsKe.n].name = name; 
		DsKe.n++;
	}
	else {
		cout << "Vuot qua so luong dinh toi da!" << endl;
	}
}

char layDinhUuTien(const DsKe& DsKe, const bool processed[], const int distance[]) {
	int minDistance = 9999;
	char u = ' ';

	for (int i = 0; i < DsKe.n; ++i) {
		if (!processed[DsKe.dinh[i].name - 'A'] && distance[DsKe.dinh[i].name - 'A'] < minDistance) {
			minDistance = distance[DsKe.dinh[i].name - 'A'];
			u = DsKe.dinh[i].name;
		}
	}

	return u;
}


void dijkstra(const DsKe& DsKe, char source, int distance[]) {
	bool processed[MAX] = { false };

	distance[source - 'A'] = 0;

	for (int count = 0; count < DsKe.n - 1; ++count) {
		char u = layDinhUuTien(DsKe, processed, distance);
		processed[u - 'A'] = true;

		for (int i = 0; i < DsKe.n; ++i) {
			if (DsKe.dinh[i].name == u) {
				for (int j = 0; j < DsKe.dinh[i].n; ++j) {
					char v = DsKe.dinh[i].canh[j].to;
					int weight = DsKe.dinh[i].canh[j].value;
					if (!processed[v - 'A'] && distance[u - 'A'] + weight < distance[v - 'A']) {
						distance[v - 'A'] = distance[u - 'A'] + weight;
					}
				}
				break;
			}
		}
	}
}
