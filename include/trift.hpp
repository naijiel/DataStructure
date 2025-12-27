#ifndef THRIFT_H_INCLUDED
#define THRIFT_H_INCLUDED
#include <iostream>

using namespace std;

struct infotype {
    string nama;
    string kategori;
    string jenis;
    int id;
    int harga;
};

typedef struct lemari *adrLemari;

struct lemari {
    infotype data;
    adrLemari left;
    adrLemari right;
};

adrLemari createItemRoot(infotype x);
adrLemari createItemP(infotype x);
void insertItemAtasan(adrLemari &atasan, adrLemari p);
void insertItemBawahan(adrLemari &bawahan, adrLemari p);
void InsertRoot(adrLemari &akar, adrLemari atasan, adrLemari bawahan);

void readPreOrderAtasan(adrLemari root);
void readInOrderAtasan(adrLemari root);
void readPostOrderBawahan(adrLemari root);
void readLevelOrderBawahan(adrLemari root, int level);
void urutanLevel(adrLemari root);
int tinggiTree(adrLemari root);

int menu();
adrLemari searchItemPByid(adrLemari root, int x);
void updateItemP(adrLemari &root, adrLemari &atasan, adrLemari &bawahan, int p);
adrLemari deleteNode(adrLemari root, int key);
adrLemari MaxByHargaAtasan(adrLemari root);
adrLemari MaxByHargaBawahan(adrLemari root);
void countAtasanWithPreOrder(adrLemari root, int &Count);
void countBawahanWithPreOrder(adrLemari root, int &Count);
int countAll(adrLemari atas, adrLemari bawah);
#endif // THRIFT_H_INCLUDED
