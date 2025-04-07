# Program Manajemen Kota dan Penduduk (DLL & SLL)

Program ini dibuat untuk memenuhi tugas praktikum **Struktur Data dan Algoritma** dengan fokus pada penerapan **Doubly Linked List (DLL)** dan **Singly Linked List (SLL)** secara bersamaan dalam satu sistem terintegrasi.

---

Tujuan Program

Membuat sebuah program berbasis bahasa C yang dapat mengelola:

- Data **kota** yang disimpan dalam struktur **Doubly Linked List (DLL)** secara dinamis.
- Data **penduduk** pada masing-masing kota yang disimpan dalam **Singly Linked List (SLL)**.
- Setiap kota memiliki daftar penduduk sendiri yang bisa dimanipulasi secara independen.

---

Fitur Program (Menu)

Program menyediakan antarmuka berbasis teks (CLI) dengan menu interaktif berikut:

1. **Menambah Kota**
   - Menambahkan node baru ke DLL kota.
2. **Menghapus Kota**
   - Menghapus kota dari DLL sekaligus membebaskan semua penduduk (SLL) di kota tersebut.
3. **Menambah Penduduk ke Kota**
   - Menambahkan nama penduduk ke list penduduk (SLL) pada kota yang dipilih.
4. **Menghapus Penduduk dari Kota**
   - Menghapus penduduk berdasarkan nama dari kota tertentu.
5. **Menampilkan Semua Kota dan Penduduk**
   - Menampilkan daftar seluruh kota beserta penduduk masing-masing.
6. **Mencari Penduduk di Semua Kota**
   - Mencari nama penduduk (pencarian tidak sensitif terhadap huruf besar/kecil).
7. **Menampilkan Statistik**
   - Menampilkan:
     - Total jumlah kota
     - Total jumlah penduduk
     - Kota dengan jumlah penduduk terbanyak (kota terpadat)
8. **Keluar**
   - Mengakhiri program dan membebaskan semua memori.

---

Lesson Learned

Selama pengembangan program ini, saya mempelajari banyak hal penting dalam praktik langsung:

- **Implementasi Doubly Linked List (DLL)**:
  - Traversal dua arah dengan pointer `prev` dan `next`.
  - Operasi efisien untuk penambahan/penghapusan node dengan `head` dan `tail`.

- **Integrasi DLL + SLL**:
  - Setiap node kota (DLL) memiliki satu SLL untuk penduduk.
  - Penghapusan hierarkis tidak menyebabkan memory leak.

- **Manajemen Memori Dinamis**:
  - Pemanfaatan `malloc()` dan `free()` secara tepat.
  - Semua memori dibersihkan secara otomatis saat kota dihapus atau program selesai.

- **Pencarian Case-Insensitive**:
  - Menggunakan `strcasecmp()` membuat pencarian lebih user-friendly.

- **Modularitas dan Validasi**:
  - Pemisahan logika kota vs penduduk memudahkan pengembangan.
  - Validasi input mencegah kesalahan saat runtime.

---

Catatan Tambahan

- Semua data disimpan secara **dinamis** (tanpa batas jumlah kota atau penduduk, tergantung memori).
- Program ini berjalan melalui **menu CLI** dan belum mendukung penyimpanan ke file.
- Nama kota dan penduduk dianggap **unik dalam konteks masing-masing**, namun tidak dicek duplikasinya secara eksplisit.
- Proyek ini cocok sebagai dasar untuk pengembangan lebih lanjut seperti sistem administrasi wilayah, atau simulasi data hierarkis.

---

Referensi

- Project GitHub: [https://github.com/DevManu-de/doublist.git](https://github.com/DevManu-de/doublist.git)

---

