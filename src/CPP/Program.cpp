#include <bits/stdc++.h>
#include "includes/structs.hpp"

using std::cin;
using std::cout;
using std::endl;

// Program for demo all data structure i have learned
class Program {
public:
    void demoLinkedList() {
        char choice = 'n';
        int n, x;
        LinkedList* ll = new LinkedList();
        do {
            printf("---------------------------------\n");
            printf("DEMO LINKED LIST\n");
            printf("---------------------------------\n");
            printf("1. Tambah data\n");
            printf("2. Hapus data\n");
            printf("3. Tambah data pada index i\n");
            printf("4. Reverse\n");
            printf("---------------------------------\n");
            scanf("%c", &choice);
            printf("Masukkan pilihan : ");
            scanf("%c", &choice);
            switch(choice) {
                case '1' : 
                    printf("Masukkan angka : ");
                    scanf("%d", &x);
                    ll->add(x);
                    break;
                case '2' : 
                    printf("Masukkan index : ");
                    scanf("%d", &x);
                    ll->remove(x);
                    break;
                case '3' :
                    printf("Masukkan index : ");
                    scanf("%d", &x);
                    printf("Masukkan data  : ");
                    scanf("%d", &n);
                    ll->insert(x, n);
                    break;
                case '4' :
                    ll->reverse();
                    break;
            }
            printf("Ukuran Linked List : %d\n", ll->size());
            printf("Hasil : \n");
            ll->print();
            scanf("%c", &choice);
            printf("Sudah selesai ? (y/n) : ");
            scanf("%c", &choice);
        } while (choice != 'y');

        delete ll;
    }

    void demoPrefixTree() {
        char choice = 'n';
        int n, x; string s; bool flag;
        Trie* trie = new Trie();
        do {
            printf("---------------------------------\n");
            printf("DEMO PREFIX TREE\n");
            printf("---------------------------------\n");
            printf("1. Tambah string\n");
            printf("2. Cari prefix string\n");
            printf("3. Cari string\n");
            printf("4. Print sorted string\n");
            printf("Note: string yang diterima hanyalah lowercase tanpa spasi a-z\n");
            printf("---------------------------------\n");
            scanf("%c", &choice);
            printf("Masukkan pilihan : ");
            scanf("%c", &choice);
            switch(choice) {
                case '1' : 
                    printf("Masukkan string : ");
                    cin >> s;
                    trie->insert(s);
                    printf("Hasil : \n");
                    trie->printTrie(trie->root);
                    break;
                case '2' : 
                    printf("Masukkan prefix : ");
                    cin >> s;
                    flag = trie->startsWith(s);
                    cout << (flag ? "Hasil : ADA\n" : "Hasil : TIDAK ADA\n");
                    break;
                case '3' :
                    printf("Masukkan string yang ingin dicari : ");
                    cin >> s;
                    flag = trie->search(s);
                    cout << (flag ? "Hasil : ADA\n" : "Hasil : TIDAK ADA\n");
                    break;
                case '4' :
                    printf("-------------------------------------\n");
                    trie->printSort(trie->root);
                    printf("-------------------------------------\n");
                    break;
            }
            
            scanf("%c", &choice);
            printf("Sudah selesai ? (y/n) : ");
            scanf("%c", &choice);
        } while (choice != 'y');

        delete trie;
    }
};

int main() {
    Program* program = new Program();
    char choice;
    do {
        printf("--------------------------\n");
        printf("1. Demo Linked List\n");
        printf("2. Demo Prefix Tree\n");
        printf("--------------------------\n");
        printf("Masukkan pilihan : ");
        choice = getchar();
        switch(choice) {
            case '1':
                program->demoLinkedList();
                scanf("%c", &choice);
                break;
            case '2':
                program->demoPrefixTree();
                scanf("%c", &choice);
                break;
        }
        printf("Apakah ingin menggunakan program lagi ? (y/n) ");
        scanf("%c", &choice);

        printf("\n");
    } while(choice != 'n');

    delete program;
    
    return 0;
}