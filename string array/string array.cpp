#include <iostream>
#include <string>

using namespace std;

int main() {
    // Meminta pengguna memasukkan jumlah mahasiswa
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;

    // Deklarasi array mahasiswa dan array absensi
    string* mahasiswa = new string[jumlahMahasiswa];
    bool* hadir = new bool[jumlahMahasiswa]; // Array bool untuk menandai kehadiran

    // Input nama mahasiswa
    cout << "\nMasukkan nama mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << ": ";
        cin.ignore();
        getline(cin, mahasiswa[i]);
        hadir[i] = false; // Inisialisasi sebagai tidak hadir
    }

    // Menampilkan daftar mahasiswa
    cout << "\nDaftar Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << i + 1 << ". " << mahasiswa[i] << endl;
    }

    // Input absensi
    cout << "\nMasukkan nomor mahasiswa yang hadir (masukkan 0 untuk berhenti):" << endl;
    int nomor;
    while (true) {
        cout << "Nomor mahasiswa: ";
        cin >> nomor;

        if (nomor == 0) {
            break; // Keluar dari loop jika pengguna memasukkan 0
        }

        if (nomor > 0 && nomor <= jumlahMahasiswa) {
            hadir[nomor - 1] = true; // Tandai mahasiswa sebagai hadir
        }
        else {
            cout << "Nomor mahasiswa tidak valid!" << endl;
        }
    }

    // Menampilkan hasil absensi
    cout << "\nDaftar Kehadiran Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << mahasiswa[i] << " - " << (hadir[i] ? "Hadir" : "Tidak Hadir") << endl;
    }

    // Membersihkan memori
    delete[] mahasiswa;
    delete[] hadir;

    return 0;
}
