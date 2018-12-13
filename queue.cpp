#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

typedef struct data{
	string nama;
	string posisi;
	int noPemain;
}dData;

class simpul
{
	public :
		dData pemain;
		simpul* pBerikutnya;


		simpul(string nP,string pP, int np)
		{
			pemain.nama = nP;
			pemain.posisi = pP;
			pemain.noPemain = np;
			pBerikutnya = NULL;
		}

		void tampilSimpul()
		{
			cout << pemain.noPemain << "--->" << pemain.nama << "--->" << pemain.posisi<<endl;
		}
};

class linkedlist
{
	private :
		simpul* pPertama;
		simpul* pAkhir;

	public :
		linkedlist() : pPertama(NULL)
		{}

		~linkedlist()
		{
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}

		bool apaKosong()
		{
			return (pPertama==NULL);
		}

		void sisipAkhir(string nP, string pP, int np)
		{
			simpul* pSimpulBaru = new simpul(nP,pP,np);
			if(apaKosong())
			{
				pPertama = pSimpulBaru;
			}
			else
			{
				pAkhir->pBerikutnya=pSimpulBaru;
			}
			pAkhir=pSimpulBaru;
		}

		void hapusPertama()
		{
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}

		void tampilSenarai()
		{
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "DATA KOSONG";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};

class queuelist
{
	private :
		linkedlist* pSenarai;

	public :
		queuelist()
		{
			pSenarai = new linkedlist;
		}

		~queuelist()
		{
			delete pSenarai;
		}

		void push(string nP, string pP, int np)
		{
			pSenarai->sisipAkhir(nP,pP,np);
		}

		void pop()
		{
			pSenarai->hapusPertama();
		}

		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}

		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};

int main()
{
	queuelist queue;
	int pilih, no;
	string nama, posisi;
	do
	{
        cout << "\n------------------------------------------------------\n" ;
		cout << "             QUEUE MENGGUNAKAN LINKED LIST           \n\n" ;
		cout << "1:ENQUEUE \n" ;
		cout << "2:DEQUEUE \n" ;
		cout << "3:TAMPIL \n" ;
		cout << "4:EXIT \n" ;
		cout << "Data Pemain Bola \n" ;
		cout << "PILIH (1-4):";
		cin >> pilih;
		cout << "\n----------------------\n" ;

		switch(pilih)
		{
			case 1 :
				cout << "\nNo Punggung: "; cin >> no;
				cin.ignore(256,'\n');
				cout << "Nama         : "; getline(cin,nama);
				cout << "Posisi       : "; getline(cin,posisi);
				queue.push(nama,posisi,no);
				break;

			case 2 :
				queue.pop();
				break;

			case 3 :
				queue.tampilTumpukan();
				break;

			case 4 :
                exit(0);
				break;

			default :
				cout << "pilihan yang anda masukkan salah"<<endl;
		}
	} while (true);
	getch();
	return 0;
}
