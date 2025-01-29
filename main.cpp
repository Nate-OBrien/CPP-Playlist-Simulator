#include <windows.h>
#include <iostream>
#include <MMsystem.h>
#pragma comment(lib, "winmm.lib" )

int main() {
    if (PlaySound(TEXT("FEIN.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
        std::cout << "Sound is playing!" << std::endl;
    } else {
        std::cout << "Failed to play sound." << std::endl;
    }
    
    // Add a pause to keep the program running while sound plays
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();
    return 0;
}
