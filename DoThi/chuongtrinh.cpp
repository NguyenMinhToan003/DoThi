#include "thuvien.h"



int main() {
    DsKe graph;
    nhapDsKe(graph); // Input the graph
    
    char source;
    cout << "Nhap dinh bat dau (A, B, C, ...): ";
    cin >> source;

    int distance[MAX];
    dijkstra(graph, source, distance);

    // Output the shortest distances
    for (int i = 0; i < graph.n; ++i) {
        cout << "Shortest distance from " << source << " to " << graph.dinh[i].name << ": " << distance[i] << endl;
    }

    return 0;
}
