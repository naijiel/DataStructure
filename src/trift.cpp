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

void insertItemAtasan(adrLemari &atasan, adrLemari p){
    if (atasan == nullptr){
        atasan = p;
    } else if (p->data.id < atasan->data.id){
        insertItemAtasan(atasan->left, p);
    } else if (p->data.id > atasan->data.id && p->data.id < 80){
        insertItemAtasan(atasan->right, p);
    }
}

void insertItemBawahan(adrLemari &bawahan, adrLemari p){
    if (bawahan == nullptr){
        bawahan = p;
    } else if (p->data.id < bawahan->data.id && p->data.id > 80){
        insertItemBawahan(bawahan->left, p);
    } else if (p->data.id > bawahan->data.id && p->data.id < 160){
        insertItemBawahan(bawahan->right, p);
    }
}



void InsertRoot(adrLemari &akar, adrLemari atasan, adrLemari bawahan) {
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
    if (root == nullptr){
        return;
    }
    if (level == 1) {
        cout << "--------------------------------------------" << endl;
        cout << root->data.id << endl; cout << root->data.nama << endl;
        cout << root->data.kategori << endl; cout << root->data.jenis << endl;
        cout << root->data.harga << endl;
        cout << endl;
    } else if (level > 1) {
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
    cout << "TINGGI TREE = " << t << endl;   // <--- cek tinggi

    for (int i = 1; i <= t; i++) {
        cout << "\n=== LEVEL " << i << " ===";
        readLevelOrderBawahan(root, i);
    }
}

void menu(){
    cout << "Pilih model display: " << endl;
    cout << "1. Display Atasan dengan Pre-Order \n";
    cout << "2. Display Atasan dengan In-Order \n";
    cout << "3. Display Bawahan dengan Post-Order \n";
    cout << "4. Display Bawahan dengan Level-Order \n";
    cout << "5. Mencari data pakaian menggunakan id \n";
    cout << "6. Update \n";
    cout << "7. Delete \n";
    cout << "8. Display max harga Atasan \n";
    cout << "9. Display max harga Bawahan \n";
    cout << "10. Total harga item Atasan \n";
    cout << "11. Total harga item Bawahan \n";
    cout << "12. Total harga semua item \n";
}


adrLemari searchItemPByid(adrLemari root, int x){
    if (root == nullptr){
        return nullptr;
    }

    if (root->data.id == x){
        return root;
    } else if (root->data.id < x){
        return searchItemPByid(root->right, x);
    } else if (root->data.id > x){
        return searchItemPByid(root->left, x);
    }
}

void updateItemP(adrLemari &root, adrLemari &atasan, adrLemari &bawahan, int p){
    adrLemari x;
    x = searchItemPByid(root, p);
    if (x == nullptr){
        if (p < 80){
            insertItemAtasan(atasan, x);
        } else if (p > 80 && p < 160) {
            insertItemBawahan(bawahan, x);
        }
    } else {
        cout << "Data sebelum diupdate: " << endl;
        cout << "id data: " << x->data.id << endl;
        cout << "nama data: " << x->data.nama << endl;
        cout << "kategori data: " << x->data.kategori << endl;
        cout << "jenis data: " << x->data.jenis << endl;
        cout << "harga data: " << x->data.harga << endl;
        cout << "\nAkan diupdate: " << endl;

        cout << "Id data yang akan diupdate: " << x->data.id << endl;
        cout << "Nama data yang akan diupdate: " << x->data.nama << endl;
        cout << "Kategori data yang akan diupdate: " << x->data.kategori << endl;
        cout << "Update jenis: ";
        cin >> x->data.jenis;
        cout << "Update harga: ";
        cin >> x->data.harga;
    }
}

adrLemari deleteNode(adrLemari root, int key) {
    if (root == nullptr) return nullptr;

    // ====== CARI KEY DI SUBTREE =======
    if (key < root->data.id) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data.id) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // ======= NODE DITEMUKAN =======

        // CASE 1: Tanpa child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // CASE 2: Satu child kanan
        if (root->left == nullptr) {
            adrLemari temp = root->right;
            delete root;
            return temp;
        }

        // CASE 3: Satu child kiri
        if (root->right == nullptr) {
            adrLemari temp = root->left;
            delete root;
            return temp;
        }

        // CASE 4: Dua child (mirip gaya kamu — sederhana)
        adrLemari temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;

        // Copy data successor
        root->data = temp->data;
        root->data.id = temp->data.id;

        // Hapus successor
        root->right = deleteNode(root->right, temp->data.id);
    }

    return root;
}

adrLemari MaxByHargaAtasan(adrLemari root) {
    adrLemari maxNode = nullptr;
    adrLemari kiri, kanan;

    if (root == nullptr){
        return nullptr;
    }
    // cek root (skip root dummy yang tidak punya harga)
    if (root->data.jenis != "root") {
        maxNode = root;
    }
    // cek kiri
    kiri = MaxByHargaAtasan(root->left);
    if (kiri != nullptr && (maxNode == nullptr || kiri->data.harga > maxNode->data.harga)) {
        maxNode = kiri;
    }
    // cek kanan
    kanan = MaxByHargaAtasan(root->right);
    if (kanan != nullptr && (maxNode == nullptr || kanan->data.harga > maxNode->data.harga)) {
        maxNode = kanan;
    }

    return maxNode;
}


adrLemari MaxByHargaBawahan(adrLemari root){
    adrLemari maxNode = nullptr;
    adrLemari kiri, kanan;

    if (root == nullptr){
        return nullptr;
    }
    // cek root (skip root dummy yang tidak punya harga)
    if (root->data.jenis != "root") {
        maxNode = root;
    }
    // cek kiri
    kiri = MaxByHargaBawahan(root->left);
    if (kiri != nullptr && (maxNode == nullptr || kiri->data.harga > maxNode->data.harga)) {
        maxNode = kiri;
    }
    // cek kanan
    kanan = MaxByHargaBawahan(root->right);
    if (kanan != nullptr && (maxNode == nullptr || kanan->data.harga > maxNode->data.harga)) {
        maxNode = kanan;
    }

    return maxNode;
}

void countAtasanWithPreOrder(adrLemari root, int &Count){
    if (root != nullptr){
        Count = Count + root->data.harga;
        countAtasanWithPreOrder(root->left, Count);
        countAtasanWithPreOrder(root->right, Count);
    }
}

void countBawahanWithPreOrder(adrLemari root, int &Count){
    if (root != nullptr){
        Count = Count + root->data.harga;
        countBawahanWithPreOrder(root->left, Count);
        countBawahanWithPreOrder(root->right, Count);
    }
}

int countAll(adrLemari atas, adrLemari bawah){
    int total1;
    int total2;
    countAtasanWithPreOrder(atas, total1);
    countBawahanWithPreOrder(bawah, total2);

    return total1 + total2;
}
