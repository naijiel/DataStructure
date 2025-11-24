#ifndef THRIFT_H_INCLUDED
#define THRIFT_H_INCLUDED
#include <iostream>

using namespace std;

struct infotype {
    string nama;
    string kategori;
    string jenis;
    int id;
    float harga;
};

typedef struct lemari *adrLemari;

struct lemari {
    infotype data;
    adrLemari left;
    adrLemari right;
};

void createTreeL(adrLemari &root);
adrLemari createItemP(infotype x);
void insertItemP(adrLemari &root, adrLemari p);

void readPreOrder(adrLemari root);
void readInOrder(adrLemari root);
void readPostOrder(adrLemari root);
void readLevelOrder(adrLemari root, int level);
int tinggiTree(adrLemari root);
void urutanLevel(adrLemari root);

adrLemari searchItemP(adrLemari root, infotype x);
void updateItemP(adrLemari &root, adrLemari &p);
void deleteItemP(adrLemari &root, adrLemari &p);

#endif // THRIFT_H_INCLUDED


// procedure create tree lemari
// function create node item pakaian
// procedure insert item berdasarkan kode unik (< 40 atasan; > 40 bawahan)
// procedure insert data pakaian (kategori: kaos/kemeja/rok/celana; harga: mahal(x > 50.000)/murah( x <= 50.000); model: bermotif/polos/bergaris
// function menghitung banyak pakaian yang yang memiliki harga mahal untuk kategori tertentu
// function menampilkan data pakaian yang termahal dari setiap kategori
// procedure display data tree
// 

