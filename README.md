# KIJ Enkripsi

## Play Fair Cipher
Program ini merupakan program yang digunakan untuk mengenkripsi ataupun mendekripsikan sebuah file menggunakan metode Play Fair cipher
Program ini menggunakan key "QUATERVOIS"
Untuk proses pembuatannya kami menggunakan IDE Visual Studio Code

Untuk melakukan build (sudah kami build) bisa menggunakan syntax:

  **g++ -o playFair fair.cpp**

Fungsinya adalah untuk membuat playFair.exe yang nantinya akan dirun untuk menjalankan program

Kemudian untuk melakukan running program bisa menggunakan:

  **./playFair -mode path**

Path adalah path dari file yang ingin di enkripsi / dekripsi
Mode yang bisa dipilih adalah:

  **--h atau -help**               
    Mode ini digunakan untuk melihat manual penggunaan program ini
  
  **--e atau -enkripsi**            
    Mode untuk mengenkripsikan sebuah teks sesuai dengan path file yang telah ditentukan
  
  **--d atau -dekripsi**           
    Mode untuk mendekripsikan sebuah teks sesuai dengan path file yang telah ditentukan
