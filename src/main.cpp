#include <iostream>
#include "Thrift.h"

using namespace std;

int main()
{
    adrLemari root, p, akar, atasan, bawahan, hasil, hasilDel;
    infotype x;
    int y, i, n, level, a;
    int Count = 0;

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

    createRootL(atasan);
    x.nama = "Atasan";
    x.id = 40;
    x.kategori = "-";
    x.jenis = "root";
    x.harga = 0;
    atasan = createItemRoot(x);
    //insertItemP(root, p);

    createRootL(bawahan);
    x.nama = "Bawahan";
    x.id = 120;
    x.kategori = "-";
    x.jenis = "root";
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
            insertItemAtasan(atasan, p);
        } else if (x.kategori == "Bawahan") {
            p = createItemP(x);
            insertItemBawahan(bawahan, p);
        };
    };
    cout << endl;
    menu();
    cout << endl;
    InsertRoot(akar, atasan, bawahan);

    cin >> a;
    switch (a){
        case 1:
            cout << "Menampilkan berdasarkan traversal Pre-Order untuk data Atasan: ";
            readPreOrderAtasan(atasan);
        break;
        case 2:
            cout << "\Menampilkan berdasarkan traversal In-Order untuk data Atasan: ";
            readInOrderAtasan(atasan);
        break;
        case 3:
            cout << "\nMenampilkan berdasarkan traversal Post-Order untuk data Bawahan: ";
            readPostOrderBawahan(bawahan);
        break;
        case 4:
            cout << "\nMenampilkan berdasarkan traversal Level-Order untuk data Bawahan:\n";
            level = tinggiTree(bawahan);
            for (int i = 1; i <= level; i++) {
                cout << "=== LEVEL " << i << " ===\n";
                readLevelOrderBawahan(bawahan, i);
            }
        break;
        case 5:
            cout << "\nMasukkan id yang ingin anda cari[except 40, 80, 120]: ";
            cin >> y;
            hasil = searchItemPByid(akar, y);
            if (hasil == nullptr){
                cout << "Data dengan id " << y << " tidak ditemukan!\n";
            } else {
                cout << "id data: " << hasil->data.id << endl;
                cout << "nama data: " << hasil->data.nama << endl;
                cout << "kategori data: " << hasil->data.kategori << endl;
                cout << "jenis data: " << hasil->data.jenis << endl;
                cout << "harga data: " << hasil->data.harga << endl;
            }
        break;
        case 6:
            cout << "\nMelakukan update pada sebuah data y: ";
            cout << "\nMasukkan id yang ingin anda update[except 40, 80, 120]: ";
            cin >> y;
            updateItemP(akar, atasan, bawahan, y);
        break;
        case 7:
            cout << "\nMelakukan delete pada sebuah data y: ";
            cout << "\nMasukkan id yang ingin anda delete[except 40, 80, 120]: ";
            cin >> y;
            hasilDel = deleteNode(akar, y);
        break;
        case 8:
            cout << "Menampilkan harga maksimal untuk data Atasan: ";
            cout << MaxByHargaAtasan(atasan)->data.harga;
        break;
        case 9:
            cout << "Menampilkan harga maksimal untuk data Bawahan: ";
            cout << MaxByHargaBawahan(bawahan)->data.harga;
        break;
        case 10:
            cout << "Menampilkan total harga data Atasan: ";
            countAtasanWithPreOrder(atasan, Count);
            cout << Count << endl;
        break;
        case 11:
            cout << "Menampilkan total harga data Bawahan: ";
            countAtasanWithPreOrder(bawahan, Count);
            cout << Count << endl;
        break;
        case 12:
            cout << "Menampilkan total harga item: " << countAll(atasan, bawahan);
        break;
    default:
        cout << "Pilihan tidak valid \n";
    }
    readPreOrderAtasan(hasilDel);

    return 0;
}
