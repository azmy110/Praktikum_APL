#include <iostream>
#include <string>
#include <vector>
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

// Fungsi untuk menghapus data pelanggan atau transaksi
void hapusData(vector<Pelanggan>& daftarPelanggan, vector<Transaksi>& daftarTransaksi) {
    int pilihan;
    cout << "Pilih data yang ingin Anda hapus:" << endl;
    cout << "1. Data Pelanggan" << endl;
    cout << "2. Data Transaksi" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        int indeks;
        cout << "Masukkan indeks data pelanggan yang ingin Anda hapus: ";
        cin >> indeks;

        if (indeks >= 0 && indeks < daftarPelanggan.size()) {
            daftarPelanggan.erase(daftarPelanggan.begin() + indeks);
            cout << "Data Pelanggan berhasil dihapus." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else if (pilihan == 2) {
        int indeks;
        cout << "Masukkan indeks data transaksi yang ingin Anda hapus: ";
        cin >> indeks;

        if (indeks >= 0 && indeks < daftarTransaksi.size()) {
            daftarTransaksi.erase(daftarTransaksi.begin() + indeks);
            cout << "Data Transaksi berhasil dihapus." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}

// Fungsi rekursif untuk menambahkan data pelanggan dan transaksi
void tambahDataSecaraRekursif(vector<Pelanggan>& daftarPelanggan, vector<Transaksi>& daftarTransaksi) {
    // Tambahkan data pelanggan
    tambahPelanggan(daftarPelanggan);
    
    // Tambahkan data transaksi
    tambahTransaksi(daftarTransaksi);

    // Tanyakan apakah ingin menambahkan data lagi
    char lagi;
    bool inputValid = false; // Untuk menyimpan status kevalidan input
    do {
        cout << "Apakah Anda ingin menambahkan data lagi? (y/n): ";
        cin >> lagi;

        // Validasi input
        if (lagi == 'y' || lagi == 'Y') {
            // Jika ya, panggil fungsi rekursif lagi
            tambahDataSecaraRekursif(daftarPelanggan, daftarTransaksi);
            inputValid = true; // Set status kevalidan input menjadi true
        } else if (lagi == 'n' || lagi == 'N') {
            inputValid = true; // Set status kevalidan input menjadi true
        } else {
            cout << "Pilihan tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
            // Bersihkan buffer input untuk menghindari loop tak terbatas jika input tidak valid
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!inputValid); // Ulangi hingga input valid
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
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarPelanggan, daftarTransaksi);
                break;
            case 2:
                tambahDataSecaraRekursif(daftarPelanggan, daftarTransaksi);
                break;
            case 3:
                modifikasiData(daftarPelanggan, daftarTransaksi);
                break;
            case 4:
                hapusData(daftarPelanggan, daftarTransaksi);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
