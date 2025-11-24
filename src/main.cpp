#include <iostream>
#include "Thrift.h"

using namespace std;

int main()
{
    adrLemari root, p;
    infotype x;
    int i, n, level;

    cout << "Masukkan input size: ";
    cin >> n;
    createTreeL(root);
    x.nama = "lemari";
    x.id = 80;
    x.kategori = "ruang";
    x.jenis = "wadah";
    x.harga = 500000;
    p = createItemP(x);
    insertItemP(root, p);
    for (i = 1; i <= n; i++) {
        cout << "Masukkan id pakaian: ";
        cin >> x.id;
        cout << "Masukkan nama pakaian: ";
        cin >> x.nama;
        cout << "Masukkan kategori pakaian: ";
        cin >> x.kategori;
        cout << "Masukkan jenis pakaian: ";
        cin >> x.jenis;
        cout << "Masukkan harga pakaian: ";
        cin >> x.harga;
        p = createItemP(x);
        insertItemP(root, p);
        cout << endl;
    }
    cout << "Tampilkan berdasarkan traversal Pre-Order: ";
    readPreOrder(root);
    cout << endl;
    cout << "\nTampilkan berdasarkan traversal In-Order: ";
    readInOrder(root);
    cout << endl;
    cout << "\nTampilkan berdasarkan traversal Post-Order: ";
    readPostOrder(root);
    cout << endl;
    cout << "\nTampilkan berdasarkan traversal Level-Order: ";
    readLevelOrder(root, level);
    cout << endl;
    return 0;
}
