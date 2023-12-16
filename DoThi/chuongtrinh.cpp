#include "thuvien.h"



int main() {
    DsKe graph;


    themDinh(graph, 'A');
    themDinh(graph, 'B');
    themDinh(graph, 'C');
    themCanh(graph.dinh[0], 'B', 1);
    themCanh(graph.dinh[1], 'C', 2);
    themCanh(graph.dinh[0], 'C', 2);
    char source, destination;
    cout << "Nhap dinh bat dau (A, B, C, ...): ";
    cin >> source;
    cout << "Nhap dinh ket thuc (A, B, C, ...): ";
    cin >> destination;
    int distance[MAX];
    dijkstra(graph, source,destination);

    return 0;
}

