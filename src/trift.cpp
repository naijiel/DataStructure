#include <iostream>
#include "Thrift.h"

using namespace std;

void createTreeL(adrLemari &root){
    root = nullptr;
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

void insertItemP(adrLemari &root, adrLemari p){
    if (root == nullptr){
        root = p;
    } else if (p->data.id < root->data.id || p->data.id < 40){
        insertItemP(root->left, p);
    } else if (p->data.id > root->data.id || p->data.id > 120){
        insertItemP(root->right, p);
    }
}

void readPreOrder(adrLemari root){
    if (root != nullptr){
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
        readPreOrder(root->left);
        readPreOrder(root->right);
    }
}

void readInOrder(adrLemari root){
    if (root != nullptr){
        readInOrder(root->left);
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
        readInOrder(root->right);
    }
}
void readPostOrder(adrLemari root){
    if (root != nullptr){
        readPostOrder(root->left);
        readPostOrder(root->right);
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
    }
}

void readLevelOrder(adrLemari root, int level){
    if (level == 1) {
        cout << "\n--------------------------------------------" << endl;
        cout << root->data.id << endl;
        cout << root->data.nama << endl;
        cout << root->data.kategori << endl;
        cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
    }
    else if (level > 1) {
        readLevelOrder(root->left, level - 1);
        readLevelOrder(root->right, level - 1);
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
        readLevelOrder(root, i);
    }
}

adrLemari searchItemP(adrLemari root, infotype x);
void updateItemP(adrLemari &root, adrLemari &p);
void deleteItemP(adrLemari &root, adrLemari &p);
