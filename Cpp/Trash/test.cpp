#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <chrono>
#include <ctime>
#include <fstream>
// #include <strsafe.h>
using namespace std;

#define BUFFERSIZE (3 * 2000)

int main() {

    // Open serial port
    HANDLE serialHandle;

    serialHandle = CreateFile("\\\\.\\COM9", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    // Do some basic settings
    DCB serialParams = { 0 };
    serialParams.DCBlength = sizeof(serialParams);

    GetCommState(serialHandle, &serialParams);
    serialParams.BaudRate = 115200;
    serialParams.ByteSize = 8;
    serialParams.StopBits = TWOSTOPBITS;
    serialParams.Parity = NOPARITY;
    SetCommState(serialHandle, &serialParams);

    // Set timeouts
    COMMTIMEOUTS timeout = { 0 };
    timeout.ReadIntervalTimeout = 50;
    timeout.ReadTotalTimeoutConstant = 50;
    timeout.ReadTotalTimeoutMultiplier = 50;
    timeout.WriteTotalTimeoutConstant = 50;
    timeout.WriteTotalTimeoutMultiplier = 10;

    SetCommTimeouts(serialHandle, &timeout);

    DWORD ol = {0};
    byte ReadBuffer[BUFFERSIZE] = {0};
    char ProcBuffer[BUFFERSIZE] = {0};

    auto start = clock();
    ReadFile(serialHandle, ReadBuffer, BUFFERSIZE, &ol, 0);
    auto end = clock();

    // for (int i = 0; i < BUFFERSIZE; i++) {
    //     printf("%d\n", ReadBuffer[i]);
    //     // cout << ReadBuffer[i] << endl;
    // }
    

    int head = -1;
    while (ReadBuffer[++head] != 0) {}

    int N = (BUFFERSIZE - head) / 3;
    int *arr = (int*) malloc(sizeof(int) * N);

    // char num_s[5] = {0};
    for (int i = 0; i < N; i ++) {
        // printf("%d, %d\n", ReadBuffer[head + i * 3 + 1], ReadBuffer[head + i * 3 + 2]);
        arr[i] = (ReadBuffer[head + i * 3 + 1] << 8) + ReadBuffer[head + i * 3 + 2];
        printf("%d\n", arr[i]);
    }
    
    printf("%f\n", float(end - start) / CLOCKS_PER_SEC);

    fstream f;
    f.open("raw.txt", ios::out);
    for (int i = 0; i < N; i ++)
        f << arr[i] - 1900 << '\n';
    f.close();

    CloseHandle(serialHandle);

    return 0;
}
