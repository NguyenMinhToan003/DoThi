#include "thuvien.h"



int main() {
    DsKe dsk;
    int option=0;
    themDinh(dsk, 'A');
    themDinh(dsk, 'B');
    themDinh(dsk, 'D');
    themDinh(dsk, 'C');
    themCanh(dsk.dinh[0], 'B', 1);
    themCanh(dsk.dinh[1], 'C', 2);
    themCanh(dsk.dinh[0], 'C',4);
    themCanh(dsk.dinh[2], 'C', 3);
    themCanh(dsk.dinh[2], 'A', 3);
    do {
        dongGachNgang();
        cout << "\n1.Nhap Danh Sach Ke.";
        cout << "\n2.Xuat Danh Sach Ke.";
        cout << "\n3.Them Dinh.";
        cout << "\n4.Them Canh.";
        cout << "\n5.Tim Duong Di Ngan Nhat Giua Hai Dinh.";
        cout << "\n0.Dung.";
        cout << "\nNhap Lua Chon: ";
        cin >> option;
        
        system("cls");
        if (option == 1) {
            nhapDsKe(dsk);
        }
        else if (option == 2) {
            xuatDsKe(dsk);
        }
        else if (option == 3) {
            cout << "\nNhap Ten Dinh: ";
            char dinh;
            cin >> dinh;
            themDinh(dsk, dinh);
            int op = 0;
            do {
                cout << "\nThem Canh Khong (0: khong, 1: co): ";
                cin >> op;
                if (op) {
                    cout << "\nNhap Ten Dinh Ke : ";
                    char dKe;
                    int trgSo;
                    cin >> dKe;
                    cout << "\nNhap Trong So : ";
                    cin >> trgSo;
                    int chso = timDinh_chiSo(dsk, dinh);
                    themCanh(dsk.dinh[chso], dKe, trgSo);
                }
            } while (op != 0);
        }
        else if (option == 4) {
            char dinh;
            int canh;
            cout << "\nNhap Dinh Can Them Canh : ";
            cin >> dinh;
            int chso = timDinh_chiSo(dsk, dinh);
            if (chso != -1) {
                cout << "\nNhap So Luong Canh Can Them Vao Dinh : ";
                cin >> canh;
                for (int i = 0; i < canh; i++) {
                    char  dinhKe;
                    int trgSo;
                    cout << "\nNhap Dinh Ke : ";
                    cin >> dinhKe;
                    cout << "\nNhap Trong So : ";
                    cin >> trgSo;
                    themCanh(dsk.dinh[chso], dinhKe, trgSo);
                }
            }
            else
            {
                cout << "\nDinh Khong Ton Tai !";
            }
        }
        else if (option == 5) {
            char source, destination;
            cout << "Nhap dinh bat dau (A, B, C, ...): ";
            cin >> source;
            cout << "Nhap dinh ket thuc (A, B, C, ...): ";
            cin >> destination;
            int distance[MAX];
            dijkstra(dsk, source, destination);
        }
        
    } while (option!=0);
   /* themDinh(dsk, 'A');
    themDinh(dsk, 'B');
    themDinh(dsk, 'C');
    themCanh(dsk.dinh[0], 'B', 1);
    themCanh(dsk.dinh[1], 'C', 2);
    themCanh(dsk.dinh[0], 'C', 2);
    char source, destination;
    cout << "Nhap dinh bat dau (A, B, C, ...): ";
    cin >> source;
    cout << "Nhap dinh ket thuc (A, B, C, ...): ";
    cin >> destination;
    int distance[MAX];
    dijkstra(dsk, source,destination);*/

    return 0;
}

