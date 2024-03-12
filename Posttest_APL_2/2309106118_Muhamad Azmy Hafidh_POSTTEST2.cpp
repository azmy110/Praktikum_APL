#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data konsumen
struct Konsumen {
    string nama;
    string alamat;
    string tanggalAcara;
};

// Struktur untuk menyimpan data transaksi
struct Transaksi {
    string tanggalTransaksi;
    string omset;
};

// Fungsi login
bool login() {
    string NAMA;
    string NIM;
    int trylogin = 0;

    while (trylogin < 3) {
        cout << "Silahkan masukkan nama anda : ";
        cin >> NAMA;
        cout << "Silakan masukkan nim anda : ";
        cin >> NIM;

        if (NAMA == "Azmy" && NIM == "2309106118") {
            cout << "Anda berhasil login" << endl;
            cout << "Selamat Datang, " << NAMA << "!" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            trylogin++;
        }
    }

    cout << "Anda sudah mencoba login sebanyak 3 kali. Program Berhenti." << endl;
    return false;
}

// Fungsi untuk menampilkan semua data konsumen dan transaksi
void tampilkanData(const vector<Konsumen>& daftarKonsumen, const vector<Transaksi>& daftarTransaksi) {
    cout << "Data Konsumen:" << endl;
    for (int i = 0; i < daftarKonsumen.size(); ++i) {
        cout << "Nama: " << daftarKonsumen[i].nama << ", Alamat: " << daftarKonsumen[i].alamat << ", Tanggal Acara: " << daftarKonsumen[i].tanggalAcara << endl;
    }
    
    cout << "\nData Transaksi:" << endl;
    for (int i = 0; i < daftarTransaksi.size(); ++i) {
        cout << "Tanggal Transaksi: " << daftarTransaksi[i].tanggalTransaksi << ", Omset: " << daftarTransaksi[i].omset << endl;
    }
}

// Fungsi untuk menambahkan data konsumen baru
void tambahkanKonsumen(vector<Konsumen>& daftarKonsumen) {
    Konsumen konsumen;
    cout << "Masukkan Nama Konsumen: ";
    cin >> konsumen.nama;
    cout << "Masukkan Alamat Konsumen: ";
    cin >> konsumen.alamat;
    cout << "Masukkan Tanggal Acara: ";
    cin >> konsumen.tanggalAcara;
    daftarKonsumen.push_back(konsumen);
    cout << "Data Konsumen berhasil ditambahkan." << endl;
}

// Fungsi untuk menambahkan data transaksi baru
void tambahkanTransaksi(vector<Transaksi>& daftarTransaksi) {
    Transaksi transaksi;
    cout << "Masukkan Tanggal Transaksi: ";
    cin >> transaksi.tanggalTransaksi;
    cout << "Masukkan Omset: ";
    cin >> transaksi.omset;
    daftarTransaksi.push_back(transaksi);
    cout << "Data Transaksi berhasil ditambahkan." << endl;
}

// Fungsi untuk mengubah data konsumen atau transaksi
void ubahData(vector<Konsumen>& daftarKonsumen, vector<Transaksi>& daftarTransaksi) {
    int choice;
    cout << "Pilih data yang ingin diubah:" << endl;
    cout << "1. Data Konsumen" << endl;
    cout << "2. Data Transaksi" << endl;
    cout << "Pilihan: ";
    cin >> choice;

    if (choice == 1) {
        int index;
        cout << "Masukkan indeks data konsumen yang ingin diubah: ";
        cin >> index;
        if (index >= 0 && index < daftarKonsumen.size()) {
            cout << "Masukkan Nama Konsumen: ";
            cin >> daftarKonsumen[index].nama;
            cout << "Masukkan Alamat Konsumen: ";
            cin >> daftarKonsumen[index].alamat;
            cout << "Masukkan Tanggal Acara: ";
            cin >> daftarKonsumen[index].tanggalAcara;
            cout << "Data Konsumen berhasil diubah." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else if (choice == 2) {
        int index;
        cout << "Masukkan indeks data transaksi yang ingin diubah: ";
        cin >> index;
        if (index >= 0 && index < daftarTransaksi.size()) {
            cout << "Masukkan Tanggal Transaksi: ";
            cin >> daftarTransaksi[index].tanggalTransaksi;
            cout << "Masukkan Omset: ";
            cin >> daftarTransaksi[index].omset;
            cout << "Data Transaksi berhasil diubah." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Fungsi untuk menghapus data konsumen atau transaksi
void hapusData(vector<Konsumen>& daftarKonsumen, vector<Transaksi>& daftarTransaksi) {
    int choice;
    cout << "Pilih data yang ingin dihapus:" << endl;
    cout << "1. Data Konsumen" << endl;
    cout << "2. Data Transaksi" << endl;
    cout << "Pilihan: ";
    cin >> choice;

    if (choice == 1) {
        int index;
        cout << "Masukkan indeks data konsumen yang ingin dihapus: ";
        cin >> index;
        if (index >= 0 && index < daftarKonsumen.size()) {
            daftarKonsumen.erase(daftarKonsumen.begin() + index);
            cout << "Data Konsumen berhasil dihapus." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else if (choice == 2) {
        int index;
        cout << "Masukkan indeks data transaksi yang ingin dihapus: ";
        cin >> index;
        if (index >= 0 && index < daftarTransaksi.size()) {
            daftarTransaksi.erase(daftarTransaksi.begin() + index);
            cout << "Data Transaksi berhasil dihapus." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

int main() {
    if (!login()) {
        return 0; // Keluar dari program jika login gagal
    }

    // Contoh data konsumen dan transaksi
    vector<Konsumen> daftarKonsumen;

    Konsumen konsumen1;
    konsumen1.nama = "Opick";
    konsumen1.alamat = "Suwandi";
    konsumen1.tanggalAcara = "2024-03-12";
    daftarKonsumen.push_back(konsumen1);

    Konsumen konsumen2;
    konsumen2.nama = "Azmy";
    konsumen2.alamat = "Bengkuring";
    konsumen2.tanggalAcara = "2024-02-19";
    daftarKonsumen.push_back(konsumen2);

    vector<Transaksi> daftarTransaksi;
    Transaksi transaksi1;
    transaksi1.tanggalTransaksi = "2024-03-12";
    transaksi1.omset = "Rp5.000.000";
    daftarTransaksi.push_back(transaksi1);

    Transaksi transaksi2;
    transaksi2.tanggalTransaksi = "2024-03-15";
    transaksi2.omset = "Rp3.500.000";
    daftarTransaksi.push_back(transaksi2);

    int choice;
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tampilkan Data Konsumen dan Transaksi" << endl;
        cout << "2. Tambah Data Konsumen dan Transaksi" << endl;
        cout << "3. Ubah Data Konsumen dan Transaksi" << endl;
        cout << "4. Hapus Data Konsumen dan Transaksi" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tampilkanData(daftarKonsumen, daftarTransaksi);
                break;
            case 2:
                tambahkanKonsumen(daftarKonsumen);
                tambahkanTransaksi(daftarTransaksi);
                break;
            case 3:
                ubahData(daftarKonsumen, daftarTransaksi);
                break;
            case 4:
                hapusData(daftarKonsumen, daftarTransaksi);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 5);

    return 0;
}
