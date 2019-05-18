#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    PlaySound("sweep.wav", NULL, SND_FILENAME);
    return 0;
}
