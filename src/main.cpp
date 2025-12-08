#include <iostream>
#include "Thrift.h"

using namespace std;

int main()
{
    adrLemari root, p, akar, atasan, bawahan;
    infotype x;
    int i, n, level;

    cout << "Masukkan input size: ";
    cin >> n;
    createRootL(root);
    x.nama = "Lemari";
    x.id = 80;
    x.kategori = "ruang";
    x.jenis = "wadah";
    x.harga = 500000;
    akar = createItemRoot(x);
    //insertItemP(root, p);

    createRootL(root);
    x.nama = "Atasan";
    x.id = 80;
    x.kategori = "-";
    x.jenis = "wadah";
    x.harga = 0;
    atasan = createItemRoot(x);
    //insertItemP(root, p);

    createRootL(root);
    x.nama = "Bawahan";
    x.id = 80;
    x.kategori = "-";
    x.jenis = "wadah";
    x.harga = 0;
    bawahan = createItemRoot(x);
    //insertItemP(root, p);

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
        if (x.kategori == "Atasan") {
            p = createItemP(x);
            insertItemAtasan(root, p);
        } else if (x.kategori == "Bawahan") {
            p = createItemP(x);
            insertItemBawahan(root, p);
        };
    };
    InsertRoot(akar, atasan, bawahan);
    cout << endl;
    menu(root);
    cout << endl;
    return 0;
}
