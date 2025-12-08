#include <iostream>
#include "Thrift.h"

using namespace std;

void createRootL(adrLemari &root){ //membuat root lemari
    root = nullptr;
}

adrLemari createItemRoot(infotype x){
    adrLemari p = new lemari;
    p->data.nama = x.nama;
    p->data.kategori = x.kategori;
    p->data.jenis = x.jenis;
    p->data.id = x.id;
    p->data.harga = x.harga;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

adrLemari createItemP(infotype x){
    adrLemari p = new lemari;
    p->data.nama = x.nama;
    p->data.kategori = x.kategori;
    p->data.jenis = x.jenis;
    p->data.id = x.id;
    p->data.harga = x.harga;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}

void insertItemAtasan(adrLemari &root, adrLemari p){
    if (root == nullptr){
        root = p;
    } else if (p->data.id < root->data.id || p->data.id < 40){
        insertItemAtasan(root->left, p);
    } else if (p->data.id > root->data.id || p->data.id > 40 && p->data.id < 80){
        insertItemAtasan(root->right, p);
    }
}

void insertItemBawahan(adrLemari &root, adrLemari p){
    if (root == nullptr){
        root = p;
    } else if (p->data.id < root->data.id || p->data.id < 120 && p->data.id > 80){
        insertItemBawahan(root->left, p);
    } else if (p->data.id > root->data.id || p->data.id > 120 && p->data.id < 160){
        insertItemBawahan(root->right, p);
    }
}

void InsertRoot(adrLemari akar, adrLemari atasan, adrLemari bawahan) {
    akar->left = atasan;
    akar->right = bawahan;
}

void readPreOrderAtasan(adrLemari root){
    if (root != nullptr){
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
        readPreOrderAtasan(root->left);
        readPreOrderAtasan(root->right);
    }
}

void readInOrderAtasan(adrLemari root){
    if (root != nullptr){
        readInOrderAtasan(root->left);
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
        readInOrderAtasan(root->right);
    }
}
void readPostOrderBawahan(adrLemari root){
    if (root != nullptr){
        readPostOrderBawahan(root->left);
        readPostOrderBawahan(root->right);
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
    }
}

void readLevelOrderBawahan(adrLemari root, int level){
    if (level == 1) {
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
    }
    else if (level > 1) {
        readLevelOrderBawahan(root->left, level - 1);
        readLevelOrderBawahan(root->right, level - 1);
    }
}


int tinggiTree(adrLemari root) {
    if (root == nullptr){
        return 0;
    }
    return 1 + max(tinggiTree(root->left), tinggiTree(root->right));
}

void urutanLevel(adrLemari root) {
    int t = tinggiTree(root);
    for (int i = 1; i <= t; i++) {
        readLevelOrderBawahan(root, i);
    }
}

void menu(adrLemari root){
    int x, level;
    cout << "Pilih model display: " << endl;
    cout << "1. Display Atasan dengan Pre-Order \n";
    cout << "2. Display Atasan dengan In-Order \n";
    cout << "3. Display Bawahan dengan Post-Order \n";
    cout << "4. Display Bawahan dengan Level-Order \n";
    cin >> x;
    switch (x){
        case 1:
        cout << "Menampilan berdasarkan traversal Pre-Order untuk data Atasan: ";
        readPreOrderAtasan(root);
        case 2:
        cout << "\Menampilkan berdasarkan traversal In-Order untuk data Atasan: ";
        readInOrderAtasan(root);
        case 3:
        cout << "\nMenampilkan berdasarkan traversal Post-Order untuk data Bawahan: ";
        readPostOrderBawahan(root);
        case 4:
        cout << "\nMenampilkan berdasarkan traversal Level-Order untuk data Bawahan: ";
        level = tinggiTree(root);
        readLevelOrderBawahan(root, level);
    }
}


adrLemari searchItemP(adrLemari root, infotype x);
void updateItemP(adrLemari &root, adrLemari &p);
void deleteItemP(adrLemari &root, adrLemari &p);
