#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur untuk menyimpan data pelanggan
struct Pelanggan {
    string nama;
    string alamat;
    string tanggalAcara;
};

// Struktur untuk menyimpan data transaksi
struct Transaksi {
    string tanggalTransaksi;
    string pendapatan;
};

// Deklarasi fungsi pencarian biner
int pencarianBinerDescending(const vector<Pelanggan>& data, const string& kunci);

// Fungsi untuk login
bool masuk() {
    string nama;
    string nim;
    int cobaMasuk = 0;

    while (cobaMasuk < 3) {
        cout << "Silakan masukkan nama Anda: ";
        cin >> nama;
        cout << "Silakan masukkan NIM Anda: ";
        cin >> nim;

        if (nama == "Azmy" && nim == "2309106118") {
            cout << "Anda berhasil masuk" << endl;
            cout << "Selamat datang, " << nama << "!" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            cobaMasuk++;
        }
    }

    cout << "Anda telah mencoba masuk 3 kali. Program diakhiri." << endl;
    return false;
}

// Fungsi untuk menampilkan semua data pelanggan dan transaksi
void tampilkanData(const vector<Pelanggan>& daftarPelanggan, const vector<Transaksi>& daftarTransaksi) {
    cout << "Data Pelanggan:" << endl;
    for (int i = 0; i < daftarPelanggan.size(); ++i) {
        cout << "Nama: " << daftarPelanggan[i].nama
             << ", Alamat: " << daftarPelanggan[i].alamat
             << ", Tanggal Acara: " << daftarPelanggan[i].tanggalAcara
             << endl;
    }

    cout << "\nData Transaksi:" << endl;
    for (int i = 0; i < daftarTransaksi.size(); ++i) {
        cout << "Tanggal Transaksi: " << daftarTransaksi[i].tanggalTransaksi
             << ", Pendapatan: " << daftarTransaksi[i].pendapatan
             << endl;
    }
}

// Fungsi untuk menambahkan data pelanggan baru
void tambahPelanggan(vector<Pelanggan>& daftarPelanggan) {
    Pelanggan pelanggan;
    cout << "Masukkan Nama Pelanggan: ";
    cin >> pelanggan.nama;
    cout << "Masukkan Alamat Pelanggan: ";
    cin >> pelanggan.alamat;
    cout << "Masukkan Tanggal Acara: ";
    cin >> pelanggan.tanggalAcara;
    daftarPelanggan.push_back(pelanggan);
    cout << "Data Pelanggan berhasil ditambahkan." << endl;
}

// Fungsi untuk menambahkan data transaksi baru
void tambahTransaksi(vector<Transaksi>& daftarTransaksi) {
    Transaksi transaksi;
    cout << "Masukkan Tanggal Transaksi: ";
    cin >> transaksi.tanggalTransaksi;
    cout << "Masukkan Pendapatan: ";
    cin >> transaksi.pendapatan;
    daftarTransaksi.push_back(transaksi);
    cout << "Data Transaksi berhasil ditambahkan." << endl;
}

// Fungsi untuk memodifikasi data pelanggan atau transaksi
void modifikasiData(vector<Pelanggan>& daftarPelanggan, vector<Transaksi>& daftarTransaksi) {
    int pilihan;
    cout << "Pilih data yang ingin Anda modifikasi:" << endl;
    cout << "1. Data Pelanggan" << endl;
    cout << "2. Data Transaksi" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        int indeks;
        cout << "Masukkan indeks data pelanggan yang ingin Anda modifikasi: ";
        cin >> indeks;

        if (indeks >= 0 && indeks < daftarPelanggan.size()) {
            cout << "Masukkan Nama Pelanggan: ";
            cin >> daftarPelanggan[indeks].nama;
            cout << "Masukkan Alamat Pelanggan: ";
            cin >> daftarPelanggan[indeks].alamat;
            cout << "Masukkan Tanggal Acara: ";
            cin >> daftarPelanggan[indeks].tanggalAcara;
            cout << "Data Pelanggan berhasil dimodifikasi." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else if (pilihan == 2) {
        int indeks;
        cout << "Masukkan indeks data transaksi yang ingin Anda modifikasi: ";
        cin >> indeks;

        if (indeks >= 0 && indeks < daftarTransaksi.size()) {
            cout << "Masukkan Tanggal Transaksi: ";
            cin >> daftarTransaksi[indeks].tanggalTransaksi;
            cout << "Masukkan Pendapatan: ";
            cin >> daftarTransaksi[indeks].pendapatan;
            cout << "Data Transaksi berhasil dimodifikasi." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Fungsi untuk menghapus data pelanggan
void hapusPelanggan(vector<Pelanggan>& daftarPelanggan) {
    int indeks;
    cout << "Masukkan indeks data pelanggan yang ingin Anda hapus: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < daftarPelanggan.size()) {
        daftarPelanggan.erase(daftarPelanggan.begin() + indeks);
        cout << "Data pelanggan berhasil dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

// Fungsi untuk menghapus data transaksi
void hapusTransaksi(vector<Transaksi>& daftarTransaksi) {
    int indeks;
    cout << "Masukkan indeks data transaksi yang ingin Anda hapus: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < daftarTransaksi.size()) {
        daftarTransaksi.erase(daftarTransaksi.begin() + indeks);
        cout << "Data transaksi berhasil dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

// Fungsi untuk sorting huruf secara descending
void sortHurufDescending(vector<Pelanggan>& data) {
    sort(data.begin(), data.end(), [](const Pelanggan& a, const Pelanggan& b) {
        return a.nama > b.nama;
    });
}

// Fungsi untuk sorting angka secara ascending
void sortAngkaAscending(vector<Transaksi>& data) {
    sort(data.begin(), data.end(), [](const Transaksi& a, const Transaksi& b) {
        return stoi(a.pendapatan) < stoi(b.pendapatan);
    });
}

// Fungsi untuk sorting huruf secara ascending
void sortHurufAscending(vector<Pelanggan>& data) {
    sort(data.begin(), data.end(), [](const Pelanggan& a, const Pelanggan& b) {
        return a.nama < b.nama;
    });
}

// Fungsi untuk pencarian linear pada data terurut secara ascending
int pencarianLinearAscending(const vector<Pelanggan>& data, const string& kunci) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].nama == kunci) {
            return i;
        }
    }
    return -1; // Data tidak ditemukan
}

// Fungsi untuk pencarian biner pada data terurut secara descending
int pencarianBinerDescending(const vector<Pelanggan>& data, const string& kunci) {
    int kiri = 0;
    int kanan = data.size() - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (data[tengah].nama == kunci) {
            return tengah;
        } else if (data[tengah].nama > kunci) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1; // Data tidak ditemukan
}

// Fungsi utama
int main() {
    // Lakukan proses login
    if (!masuk()) {
        return 0; // Keluar dari program jika login gagal
    }

    // Inisialisasi vektor untuk menyimpan data pelanggan dan transaksi
    vector<Pelanggan> daftarPelanggan;
    vector<Transaksi> daftarTransaksi;

    // Menu utama
    int pilihan;
    do {
        // Tampilkan menu
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tampilkan Data Pelanggan dan Transaksi" << endl;
        cout << "2. Tambah Data Pelanggan dan Transaksi" << endl;
        cout << "3. Modifikasi Data Pelanggan dan Transaksi" << endl;
        cout << "4. Hapus Data Pelanggan dan Transaksi" << endl;
        cout << "5. Sort Data" << endl;
        cout << "6. Pencarian Data" << endl;
        cout << "7. Logout" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarPelanggan, daftarTransaksi);
                break;
            case 2:
                tambahPelanggan(daftarPelanggan);
                tambahTransaksi(daftarTransaksi);
                break;
            case 3:
                modifikasiData(daftarPelanggan, daftarTransaksi);
                break;
            case 4:
                cout << "Pilih data yang ingin Anda hapus:" << endl;
                cout << "1. Data Pelanggan" << endl;
                cout << "2. Data Transaksi" << endl;
                cout << "Pilihan: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    hapusPelanggan(daftarPelanggan);
                } else if (pilihan == 2) {
                    hapusTransaksi(daftarTransaksi);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 5:
                cout << "Pilih kategori sorting:" << endl;
                cout << "1. Data Pelanggan (Huruf Descending)" << endl;
                cout << "2. Data Transaksi (Angka Ascending)" << endl;
                cout << "3. Data Pelanggan (Huruf Ascending)" << endl; // Tambah pilihan baru
                cout << "Pilihan: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    sortHurufDescending(daftarPelanggan);
                } else if (pilihan == 2) {
                    sortAngkaAscending(daftarTransaksi);
                } else if (pilihan == 3) {
                    sortHurufAscending(daftarPelanggan); // Panggil fungsi sorting huruf ascending
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 6:
                cout << "Pilih metode pencarian:" << endl;
                cout << "1. Pencarian Linear (Data Terurut Ascending)" << endl;
                cout << "2. Pencarian Biner (Data Terurut Descending)" << endl;
                cout << "Pilihan: ";
                cin >> pilihan;
                if (pilihan == 1) {
                    string kunci;
                    cout << "Masukkan nama pelanggan yang ingin dicari: ";
                    cin >> kunci;
                    int hasil = pencarianLinearAscending(daftarPelanggan, kunci);
                    if (hasil != -1) {
                        cout << "Data ditemukan pada indeks: " << hasil << endl;
                    } else {
                        cout << "Data tidak ditemukan." << endl;
                    }
                } else if (pilihan == 2) {
                    string kunci;
                    cout << "Masukkan nama pelanggan yang ingin dicari: ";
                    cin >> kunci;
                    int hasil = pencarianBinerDescending(daftarPelanggan, kunci);
                    if (hasil != -1) {
                        cout << "Data ditemukan pada indeks: " << hasil << endl;
                    } else {
                        cout << "Data tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;

            case 7:
                cout << "Anda telah logout." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
