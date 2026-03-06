#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Diperlukan untuk fungsi-fungsi umum (tidak mutlak untuk kasus ini, tapi disertakan sesuai permintaan)
#include <string.h> // Diperlukan untuk manipulasi string (tidak mutlak untuk kasus ini, tapi disertakan sesuai permintaan)

// Fungsi utama program
int main() {
    int n;          // Variabel untuk menyimpan jumlah nilai yang akan dimasukkan
    int nilai;      // Variabel sementara untuk menyimpan setiap nilai tugas
    long long sum = 0; // Variabel untuk menyimpan total jumlah nilai, menggunakan long long untuk keamanan
    double average; // Variabel untuk menyimpan nilai rata-rata

    // Membaca input pertama: jumlah nilai (n)
    scanf("%d", &n);

    // Membaca n buah nilai tugas dan menjumlahkannya
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai); // Membaca setiap nilai tugas
        sum += nilai;        // Menambahkan nilai ke total sum
    }

    // Menghitung nilai rata-rata
    // Pastikan sum di-cast ke double agar hasil pembagian berupa floating-point
    average = (double)sum / n;

    // Menampilkan jumlah seluruh nilai
    printf("%lld\n", sum);

    // Menampilkan nilai rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2f\n", average);

    return 0; // Mengindikasikan program berakhir dengan sukses
}