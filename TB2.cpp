#include <iostream>
#include <conio.h>
using namespace std;

// prepare struct
struct antrian
{
    // data
    string nama;
    int nik;
    string jenis_vaksin;
    int vaksin_ke;

    // pointer next
    antrian *next;
};

int maxQueue = 2;
antrian *head, *tail, *current, *del, *newNode;

// count Linked List
int count()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int banyak = 0;
        current = head;
        while (current != NULL)
        {
            current = current->next;
            banyak++;
        }
        return banyak;
    }
}

// isFull Linked List
bool isFull()
{
    if (count() == maxQueue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isEmpty Linked List
bool isEmpty()
{
    if (count() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// enqueue / penambahan
void enqueue(string nama, int nik, string jenis_vaksin, int vaksin_ke)
{

    if (isFull())
    {
        cout << "Antrian Penuh !!" << endl;
    }
    else
    {

        if (isEmpty())
        {
            head = new antrian();
            head->nama = nama;
            head->nik = nik;
            head->jenis_vaksin = jenis_vaksin;
            head->vaksin_ke = vaksin_ke;
            head->next = NULL;
            tail = head;
        }
        else
        {
            newNode = new antrian();
            newNode->nama = nama;
            newNode->nik = nik;
            newNode->jenis_vaksin = jenis_vaksin;
            newNode->vaksin_ke = vaksin_ke;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// dequeue Linked List
void dequeue()
{
    if (isEmpty())
    {
        cout << "Data Antrian Kosong!!" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

// destroy / clear
void clear()
{
    if (isEmpty())
    {
        cout << "Data Antrian Kosong!!" << endl;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            del = current;
            current = current->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
}

// display Linked List
void display()
{
    if (isEmpty())
    {
        cout << "Data Antrian Kosong!!" << endl;
    }
    else
    {
        if (isFull())
        {
            cout << "Data Penuh!!\n";
        }
        cout << "Banyak data antrian : " << count() << endl;
        cout << "Data Antrian : " << endl;
        cout << endl;
        current = head;
        int nomor = 1;
        while (nomor <= maxQueue)
        {

            if (current != NULL)
            {
                cout << "Antrian " << nomor
                     << "\nNama          : " << current->nama 
                     << "\nNIK           : " << current->nik 
                     << "\nJenis vaksin  : " << current->jenis_vaksin 
                     << "\nVaksin ke     : "<< current->vaksin_ke << endl
                     << endl;
                current = current->next;
            }
            else
            {
                cout << "Antrian " << nomor << "\n(kosong)" << endl;
            }

            nomor++;
        }
    }
    cout << "\n"
         << endl;
}

void display2()
{
    display();
    cout << "\n(Tekan ENTER untuk melanjutkan)";
    getch();
}

int main()
{

    int input = 1;

    while (input != 0)
    {
        count();
        cout << "PROGRAM VAKSINASI COVID-19\n" << endl;
        cout << "1. Masukkan data" << endl;
        cout << "2. Hapus pasien paling depan" << endl;
        cout << "3. Tampilkan data" << endl;
        cout << "4. Hapus seluruh data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> input;

        switch (input)
        {
        case 1:
        {
            string nama;
            string jenis_vaksin;
            int nik;
            int vaksin_ke;

            if (isFull())
            {
                system("cls");
                cout << "Data Sudah Penuh TIDAK DAPAT ditambah\n";
                display();
                break;
            } else
            {
            system("cls");
            cout << "Masukkan Data Antrian\n";
            cout << "Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "NIK : ";
            cin >> nik;
            cout << "Jenis vaksin : ";
            cin.ignore();
            getline(cin, jenis_vaksin);
            cout << "Vaksin ke : ";
            cin >> vaksin_ke;
            enqueue(nama, nik, jenis_vaksin, vaksin_ke);
            cout << "\n\n";
            system("cls");
            display();
            break;
            }
        }
        case 2:
            system("cls");
            dequeue();
            display();
            break;
        case 3:
            system("cls");
            display2();
            cout << "\n\n";
            system("cls");
            break;
        case 4:
            system("cls");
            clear();
            display();
            break;
        case 0:
            cout << "Terima kasih telah menggunakan program ini" << endl;
            break;
        default:
            system("cls");
			cout << "Pilihan tidak tersedia\n " << endl;
            break;
        }
    }
}