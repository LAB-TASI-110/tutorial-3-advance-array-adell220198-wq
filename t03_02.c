#include <stdio.h> // Untuk input/output seperti printf dan scanf
#include <stdlib.h> // Untuk fungsi utilitas umum (tidak esensial untuk kasus ini tapi sesuai permintaan)
#include <string.h> // Untuk manipulasi string (tidak esensial untuk kasus ini tapi sesuai permintaan)

int main() {
    // Langkah 3: Pembacaan Jumlah Mahasiswa (n)
    int n;
    scanf("%d", &n); // Membaca jumlah nilai (n) dari input

    // Langkah 4: Deklarasi Array untuk Nilai Mahasiswa
    // Menggunakan Variable Length Array (VLA) yang ukurannya ditentukan saat runtime
    int scores[n]; 
    
    // Inisialisasi variabel untuk perhitungan
    double total_sum = 0.0; // Menggunakan double untuk akurasi rata-rata
    int count_above_average = 0;

    // Langkah 5: Pembacaan Nilai-Nilai Tugas dan Perhitungan Jumlah
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score); // Membaca setiap nilai tugas
        scores[i] = score;   // Menyimpan nilai ke dalam array
        total_sum += score;  // Menambahkan nilai ke total_sum
    }

    // Langkah 6: Perhitungan Rata-Rata
    double average = 0.0;
    if (n > 0) { // Pastikan n bukan nol untuk menghindari pembagian dengan nol
        average = total_sum / n; 
    }

    // Langkah 7: Perhitungan Jumlah Mahasiswa di Atas atau Sama dengan Rata-Rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++;
        }
    }

    // Langkah 8: Menampilkan Hasil
    printf("%.0f\n", total_sum); // Menampilkan jumlah seluruh nilai (tanpa desimal)
    printf("%.2f\n", average);   // Menampilkan rata-rata dengan 2 digit presisi
    printf("%d\n", count_above_average); // Menampilkan jumlah mahasiswa di atas rata-rata

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}
