﻿#include "thuvien.h"


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

int findMinDistance(int dist[], bool visited[], int n) {
    int minDist = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(DsKe graph, char src, char dest) {
    int n = graph.n;
    int dist[MAX];
    bool visited[MAX];
    int prev[MAX];


    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        prev[i] = -1;
    }

    // Find the index of the source node
    int srcIndex = -1;
    for (int i = 0; i < n; i++) {
        if (graph.dinh[i].name == src) {
            srcIndex = i;
            break;
        }
    }

    // If source node is not found, return
    if (srcIndex == -1) {
        cout << "Diem dau khong tim thay !" << endl;
        return;
    }

    // Set distance of source node to 0
    dist[srcIndex] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < graph.dinh[u].n; v++) {
            char to = graph.dinh[u].canh[v].to;
            int value = graph.dinh[u].canh[v].value;

            int toIndex = -1;
            for (int i = 0; i < n; i++) {
                if (graph.dinh[i].name == to) {
                    toIndex = i;
                    break;
                }
            }

            if (toIndex != -1 && !visited[toIndex] && dist[u] != INT_MAX &&
                dist[u] + value < dist[toIndex]) {
                dist[toIndex] = dist[u] + value;
                prev[toIndex] = u;
            }
        }
    }

    // If destination node is not reachable, return
    int destIndex = -1;
    for (int i = 0; i < n; i++) {
        if (graph.dinh[i].name == dest) {
            destIndex = i;
            break;
        }
    }

    if (dist[destIndex] == INT_MAX) {
        cout << "Khong tim thay duong di!" << endl;
        return;
    }

    // Print the shortest path
    cout << "Duong di ngan nhat tu  " << src << " toi dinh " << dest << ":" << endl;
    cout << "Path: ";
    int current = destIndex;
    while (current != srcIndex) {
        cout << graph.dinh[current].name << " <- ";
        current = prev[current];
    }
    cout << graph.dinh[srcIndex].name << endl;
    cout << "Trong so : " << dist[destIndex] << endl;
}
int timDinh_chiSo(DsKe dsk, char name) {
    int chso = -1;
    for (int i = 0; i < dsk.n; i++) {
        if (name == dsk.dinh[i].name)
        {
            chso = i; break;
        }
    }
    return chso;
}
void dongGachNgang() {
    for (int i = 0; i < 133; i++) {
        cout << "-";
    }
    cout << endl;
}