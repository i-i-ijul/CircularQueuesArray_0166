/**
 * @mainpage Documentation Queue
 * 
 * @section introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular array
 * 
 * @section Operation
 * project ini memiliki beberapa operasi antara lain:
 * 1.insert
 * 2.delete
 * 3.display
 * 
 * @section cara penggunaan
 * berikut merupakan beberapa menu yang bisa digunakan:
 * 1.enqueue
 * 2.dequeue
 * 3.display
 * 4.exit
 * 
 * @author Ijul
 * @section profile
 * Nama : Izzul Haqqi
 * NIM : 20240140166
 * Kelas : D
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright ijul@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;
/**
 * @class queues
 * @brief class untuk mengoperasikan lengkap queues
 * 
 */
class Queues
{
private:
    static const int max = 5; ///< variable private max untuk menyimpan max size queue/data
    int front; ///< variable private front untuk mendandakan posisi depan antrian
    int rear; ///< variable private rear untuk menyimpan posisi akhir antrian
    int queue_array[5]; ///< variable private queue untuk menyimpan elemen antrian

public:
    /**
     * @brief 
     * set default queues NULL 
     * with front = -1 and rear = -1
     */
    Queues()
    {
        front = -1;///<menetapkan posisi awal front
        rear = -1;///<menetapkan posisi awal rear
    }

    /**
     * @brief method untuk menyimpan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */

    void insert()
    {
        int num;///< variable num untuk memasukkan data pada antrian
        cout << "enter a number: ";///< output untuk memberi keterangan
        cin >> num;///<input keyboard
        cout << endl;///<output untuk memisahkan line

        // 1. cek apakah ada antrian penuh
        if ((front == 0 && rear == max - 1) || (front == rear + 1))///<variable untuk mengecek posisi front pada == 0 dan rear pada max == -1
        {
            cout << "\nQueue overflow\n"; // 1.a
            return;                       // 1.b
        }

        // 2. cek apakah antrian kosong
        if (front == -1)
        {
            front = 0; // 2.a
            rear = 0;  // 2.b
        }
        else
        {
            // jika rear berada di posisi terakgir array, kembali ke awal array
            if (rear == max - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
        queue_array[rear] = num;
    }

    /**
     * @brief method untuk menghapus data pada antrian
     * data dihapus pada array
     */
    void remove()
    {
        // cek apakah antrian kosong
        if (front == -1) ///< mengecek posisi front == -1
        {
            cout << "queue underflow\n";///<output keterangan bahwa queue underflow
            return;
        }
        cout << "\nthe element deleted from the queue is: " << queue_array[front] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (front == rear) ///<mengecek apakah posisi front sama dengan rear
        {
            front = -1;///<menjadikan posisi front pada elemen terakhir
            rear = -1;///<menjadikan posisi rear pada elemen terakhir
        }
        else
        {
            // jika element yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }

    /**
     * @brief method untuk menampilkan semua data
     * data ditampilkan dalam program
     */
    void display()
    {
        int front_position = front;
        int rear_position = rear;

        // cek apakah antrian kosong
        if (front == -1) ///<mengecek posisi front
        {
            cout << "queue is empty\n"; ///<output keterangan bahwa queue kosong
            return;
        }

        cout << "\nelements in the queue are...\n";///<memberi tahu elements pada indeks ke berapa

        // jika front position <= rear_position, iterasi dari front hingga rear
        if (front_position <= rear_position)
        {
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << " ";
                front_position++;///<memindahkan front ke depan hingga berputar ke belakang rear
            }
            cout << endl;
        }
        else
        {
            // jika front_position > rear_position, iterasi dari front hingga akhir array
            while (front_position <= max - 1)
            {
                cout << queue_array[front_position] << " ";
                front_position++;///<memindahkan front hingga ke posisi akhir array
            }

            front_position = 0;

            // iterasi dari awal array hingga rear
            while (front_position <= rear_position) ///<eksekusi array dari awal sampe akhir
            {
                cout << queue_array[front_position] << " ";
                front_position++;///<memindahkan posisi front ke depan
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. implement delete operation" << endl;
            cout << "3. display values" << endl;
            cout << "4. exit" << endl;
            cout << "enter ur choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "invalid option!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
    return 0;
}