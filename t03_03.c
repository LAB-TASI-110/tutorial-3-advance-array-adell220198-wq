#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Untuk fungsi alokasi memori dinamis seperti malloc dan free
#include <string.h> // Disertakan sesuai permintaan, meskipun tidak digunakan secara langsung

int main() {
    int n; // Variabel untuk menyimpan jumlah nilai yang akan dimasukkan
    
    // Langkah 2: Input n
    // Membaca bilangan bulat positif pertama yang merepresentasikan jumlah nilai (n)
    scanf("%d", &n); 

    // Validasi sederhana untuk n positif, meskipun prompt tidak meminta eksplisit,
    // ini adalah praktik yang baik untuk menghindari alokasi memori yang tidak valid.
    if (n <= 0) {
        printf("Jumlah nilai (n) harus bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Menggunakan alokasi memori dinamis untuk menyimpan n nilai.
    // Ini penting karena ukuran array tidak diketahui saat kompilasi.
    int *scores = (int *)malloc(n * sizeof(int));
    // Periksa apakah alokasi memori berhasil
    if (scores == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; // Keluar dengan kode error
    }

    long long sum = 0; // Menggunakan long long untuk sum agar dapat menampung jumlah nilai yang besar
    double average = 0.0; // Menggunakan double untuk rata-rata agar presisi terjaga
    int min_val = 101;   // Inisialisasi dengan nilai di luar rentang (0-100) yang mungkin
    int max_val = -1;    // Inisialisasi dengan nilai di luar rentang (0-100) yang mungkin

    // Langkah 3: Input n Nilai dan Perhitungan Awal (sum, min_val, max_val)
    for (int i = 0; i < n; i++) {
        // Membaca setiap nilai tugas mahasiswa
        scanf("%d", &scores[i]);

        // Validasi nilai berada dalam rentang 0-100, praktik yang baik.
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Nilai tugas harus antara 0 dan 100.\n");
            free(scores); // Bebaskan memori sebelum keluar
            return 1; // Keluar dengan kode error
        }

        sum += scores[i]; // Menambahkan nilai ke total sum

        // Mengupdate nilai minimum dan maksimum
        if (scores[i] < min_val) {
            min_val = scores[i];
        }
        if (scores[i] > max_val) {
            max_val = scores[i];
        }
    }

    // Langkah 4: Hitung Rata-rata
    // Melakukan casting 'n' ke double agar hasil pembagian float
    average = (double)sum / n; 

    int countAboveAverage = 0; // Variabel untuk menghitung nilai di atas atau sama dengan rata-rata

    // Langkah 5: Hitung Jumlah Nilai di Atas Rata-rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            countAboveAverage++; // Menambah hitungan jika nilai >= rata-rata
        }
    }

    // Langkah 6: Hitung Rentang Nilai
    int range = max_val - min_val;

    // Langkah 7: Tampilkan Keluaran
    printf("%lld\n", sum);             // Output jumlah seluruh nilai
    printf("%.2f\n", average);         // Output nilai rata-rata dengan 2 digit presisi
    printf("%d\n", countAboveAverage); // Output banyaknya nilai >= rata-rata
    printf("%d\n", range);             // Output rentang nilai (maksimum - minimum)

    // Penting: Bebaskan memori yang dialokasikan secara dinamis setelah selesai digunakan
    free(scores); 
    scores = NULL; // Hindari dangling pointer

    return 0; // Program berakhir dengan sukses
}
