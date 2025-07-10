#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX = 100;
struct Mahasiswa{
	string nim;
	string nama;
	float uts;
	float uas;
	float nilaiAkhir;
	string status;
};

int bacaData (Mahasiswa mhs[]){
//	format penulisan data yaitu (nim nama uts uas)
//	nama hanya bisa satu kata, apabila ingin lebih, gunakan "_" atau "-" karena saya tidak gunakan getline(kurang bisa) hehe
	ifstream file("data.txt");
	int i = 0;
	while(file >> mhs[i].nim >> mhs[i].nama >> mhs[i].uts >> mhs[i].uas){
		mhs[i].nilaiAkhir = (mhs[i].uts + mhs[i].uas) / 2.0;
     if(mhs[i].nilaiAkhir >= 75){
     	mhs[i].status = "Lulus";
	 } else {
	 	mhs[i].status = "Tidak Lulus";
	 }
        i++;
    }
    file.close();
    return i; 
}

void tampilkanData(Mahasiswa mhs[], int n) {
    cout << "Data Mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nim << "\t" << mhs[i].nama << "\t" << mhs[i].uts << "\t" << mhs[i].uas << "\t" << mhs[i].nilaiAkhir << "\t" << mhs[i].status << endl;
    }
    cout << endl;
}

void simpanKeFile(Mahasiswa mhs[], int n){
	ofstream file1("nilai akhir.txt");
	ofstream file2("status lulus.txt");
	    for (int i = 0; i < n; i++) {
        file1 << mhs[i].nim << " " << mhs[i].nama << " " << mhs[i].nilaiAkhir << endl;
        file2 << mhs[i].nim << " " << mhs[i].nama << " " << mhs[i].status << endl;
    }
    file1.close();
    file2.close();
    cout << "Data berhasil disimpan ke file .txt" << endl;
    cout << endl;
}
void cariNama(Mahasiswa mhs[], int n, string kunci) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nama == kunci) {
            cout << "Ditemukan: " << mhs[i].nama << " | Nilai Akhir: " << mhs[i].nilaiAkhir << " | Status: " << mhs[i].status << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) 
	cout << "Nama tidak ditemukan." << endl;
    cout << endl;
}
void cariNilai(Mahasiswa mhs[], int n, float nilai) {
	bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nilaiAkhir == nilai) {
            cout <<"Mahasiswa dengan nilai " << nilai << ": " << mhs[i].nama << " (" << mhs[i].nim << ")\n";
        	ditemukan = true;
		}
    }
    if(!ditemukan)
    cout << "Nilai tidak ditemukan." << endl;
    cout << endl;
}
void urutkanAscending(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mhs[i].nilaiAkhir > mhs[j].nilaiAkhir) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
    cout << endl;
}

void urutkanDescending(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mhs[i].nilaiAkhir < mhs[j].nilaiAkhir) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
    cout << endl;
}

int main(){
	Mahasiswa mhs[MAX];
    int jumlah = bacaData(mhs);
    int pilih;
    string cari;
    float nilai;
	
	do{
		cout << "=== SISTEM PENILAIAN MAHASISWA ===" << endl;
		cout << "1. Tampilkan Data Mahasiswa" << endl;
		cout << "2. Cari Nilai berdasarkan Nama" << endl;
		cout << "3. Cari Nilai" << endl;
		cout << "4. Urutkan Nilai secara Ascending (besar - kecil)" << endl;
		cout << "5. Urutkan Nilai secara Descending (kecil - besar)" << endl;
		cout << "6. Simpan data ke file .txt" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilihan Anda: ";
		cin >> pilih;

        switch (pilih) {
            case 1: 
				tampilkanData(mhs, jumlah); 
				break;
            case 2: 
				cout << "Masukkan nama: "; 
				cin >> cari;
				cariNama(mhs, jumlah, cari); 
				break;
            case 3: 
				cout << "Masukkan nilai yang ingin dicari (nilai akhir): "; 
				cin >> nilai; 
				cariNilai(mhs, jumlah, nilai); 
				break;
            case 4: 
				urutkanAscending(mhs, jumlah); 
				tampilkanData(mhs, jumlah); 
				cout << "Data berhasil diurutkan dari besar - kecil." << endl;
				break;
            case 5: 
				urutkanDescending(mhs, jumlah); 
				tampilkanData(mhs, jumlah); 
				cout << "Data berhasil diurutkan dari kecil - besar." << endl;
				break;
            case 6: 
				simpanKeFile(mhs, jumlah);  
				break;
            case 0: 
				cout << "Terimakasih!." << endl; 
				break;
            default: 
				cout << "Pilihan anda tidak valid.\n";
        }
	}while(pilih != 0);
	
	return 0;
}


