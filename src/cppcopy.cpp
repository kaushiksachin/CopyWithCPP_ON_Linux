/*
 * Date: 2019-07-01
 * Author: Sachin Kaushik (kaushiksachin11@gmail.com)
*/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
    clock_t start, end;
    start = clock();

    ifstream source(argv[1], ios::binary);
    ofstream dest(argv[2], ios::binary);

    // file size
    source.seekg(0, ios::end);
    ifstream::pos_type size = source.tellg();
    source.seekg(0);
    // allocate memory for buffer
    char* buffer = new char[size];

    // copy file    
    source.read(buffer, size);
    dest.write(buffer, size);

    // clean up
    delete[] buffer;
    source.close();
    dest.close();

    end = clock();

    cout << "==========STATSTICS==========" << "\n";
    cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << "\n";
    cout << "CPU-TIME START " << start << "\n";
    cout << "CPU-TIME END " << end << "\n";
    cout << "CPU-TIME END - START " <<  end - start << "\n";
    cout << "TIME(SEC) " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}
