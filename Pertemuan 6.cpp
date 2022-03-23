#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *head = NULL;

int size = 0;

bool running = true;

bool isEmptyLinkedList()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

int menuUtama()
{
    int pilihan;

    do
    {
        cout << "+============================================+" << endl;
        cout << "+======= 2B - Suci Wulandari -  ======+" << endl;
        cout << "+============= Menu Linked List =============+" << endl;
        cout << "+============================================+" << endl;
        cout << "1. Insert Awal" << endl;
        cout << "2. Insert Tengah" << endl;
        cout << "3. Insert Akhir" << endl;
        cout << "4. Delete Awal" << endl;
        cout << "5. Delete Tengah" << endl;
        cout << "6. Delete Akhir" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Quit" << endl;
        cout << "+============================================+" << endl;
        cout << "Masukan Pilihan [1-8]: ";
        cin >> pilihan;
        if (pilihan < 1 || pilihan > 8)
        {
            cout << "Masukan Pilihan 1 Sampai 8!" << endl;
        }
        cout << endl;
    } while (pilihan < 1 && pilihan > 8);

    return pilihan;
}

int insertValue()
{
    int value;
    cout << "Masukan Value : ";
    cin >> value;
    return value;
}

void exitProgram()
{
    cout << "Terimakasih Telah Mampir :)" << endl;
    running = false;
}

void insertAwal(int value)
{
    Node *firstNode = new Node;

    if (isEmptyLinkedList())
    {
        firstNode->value = value;
    }
    else
    {
        firstNode->value = value;
        firstNode->next = head;
    }
    head = firstNode;
    size++;
}

void insertTengah(int value)
{
    if (isEmptyLinkedList())
    {
        cout << "Linked List Masih Kosong!" << endl;
        cout << endl;
        return;
    }

    if (size < 2)
    {
        cout << "Size Masih Dibawah 2" << endl;
    }

    int tengah = ceil((double)size / 2);
    Node *prevTengah = NULL;

    for (int i = 0; i < tengah; i++)
    {
        if(prevTengah == NULL) {
            prevTengah = head;
        } else {
            prevTengah = prevTengah->next;
        }
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = prevTengah->next;

    prevTengah->next = newNode;
    size++;
}

void insertAkhir(int value)
{
    if (isEmptyLinkedList())
    {
        cout << "Linked List Masih Kosong!" << endl;
        cout << endl;
        return;
    }

    Node *nodeAkhir = head;

    for (int i = 0; i < size - 1; i++)
    {
        nodeAkhir = nodeAkhir->next;
    }

    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    nodeAkhir->next = newNode;
    size++;
}

void deleteAwal()
{
    if (isEmptyLinkedList())
    {
        cout << "Linked List Masih Kosong!" << endl;
        return;
    }
    head = head->next;
    size--;
}

void deleteTengah()
{
    if (isEmptyLinkedList())
    {
        cout << "Linked List Masih Kosong!" << endl;
        return;
    }

    if (size < 2)
    {
        cout << "Size Masih Dibawah 2" << endl;
    }

    int tengah = ceil((double)size / 2);

    Node *prevTengah = NULL;

    for (int i = 0; i < tengah; i++)
    {
        if(prevTengah == NULL) {
            prevTengah = head;
        } else {
            prevTengah = prevTengah->next;
        }
    }

    prevTengah->next = prevTengah->next->next;
    size--;
}

void deleteAkhir()
{
    if (isEmptyLinkedList())
    {
        cout << "Linked List Masih Kosong!" << endl;
        return;
    }

    Node *nodeAkhir = NULL;

    for (int i = 0; i < size - 1; i++)
    {
        if(nodeAkhir == NULL) {
            nodeAkhir = head;
        } else {
            nodeAkhir = nodeAkhir->next;
        }
    }

    nodeAkhir->next = NULL;
    size--;
}

void tampilkanData()
{
    Node *travel = head;
    string status = "";

    cout << "+============================================+" << endl;
    cout << "+================= List Data ================+" << endl;
    cout << "+============================================+" << endl;


    for (int i = 0; i < size; i++)
    {
        status = travel == head ? " <-- Head" : (travel->next == NULL ? " <-- Tail" : "");
        cout << i + 1 << ". " << travel->value << status << endl;
        travel = travel->next;
    }


    cout << "+============================================+" << endl;
    cout << endl;
}

void eksekusiFitur(int pilihan)
{
    int value;
    if (pilihan < 4)
    {
        value = insertValue();
    } 

    if(pilihan == 1) {
        insertAwal(value);
    } else if(pilihan == 2) {
        insertTengah(value);
    } else if (pilihan == 3){
        insertAkhir(value);
    } else if (pilihan == 4) {
        deleteAwal();
    } else if (pilihan == 5) {
        deleteTengah();
    } else if (pilihan == 6) {
        deleteAkhir();
    } else if (pilihan == 7) {
        tampilkanData();
    } else if (pilihan == 8) {
        exitProgram();
    }
}


int main()
{
    while (running)
    {
        eksekusiFitur(menuUtama());
    }
}
