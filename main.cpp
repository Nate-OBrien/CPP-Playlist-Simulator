#include <windows.h>
#include <iostream>
#include <MMsystem.h>
#include <vector>
#include <string>
#pragma comment(lib, "winmm.lib" )

using namespace std;

void play();

int main() {
    vector<string> playlist {"Fein", "Carnival", "ETA", "Thick Of It"};
    int choice;
    string song;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a song\n";
        cout << "2. Delete a song\n";
        cout << "3. Open playlist\n";
        cout << "4. How Many Songs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a song to add: ";
                cin.ignore(); 
                getline(cin, song); 
                playlist.push_back(song);
                cout << song << " has been added" << endl;
                break;

            case 2:
                if (playlist.empty()) {
                    cout << "Playlist is empty" << endl;
                } else {
                    cout << "Your playlist contains the following songs:\n";
                    for (size_t i = 0; i < playlist.size(); i++) {
                        cout << i + 1 << ". " << playlist[i] << endl;
                    }

                    cout << "Enter the number of the song to delete: ";
                    int index;
                    cin >> index;

                    if (index > 0 && index <= playlist.size()) {
                        cout << playlist[index - 1] << " has been deleted" << endl;
                        playlist.erase(playlist.begin() + index - 1); 
                    } else {
                        cout << "Invalid song number" << endl;
                    }
                }
                break;

            case 3:
                cout << "Your playlist contains the following songs:\n";
                for (const auto s : playlist) {
                    cout << s << endl;
                }
                break;

            case 4:
                cout << "There are " << playlist.size() << " songs in your playlist" << endl;
                break;

            case 5:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid selection" << endl;
        }
    } while (choice != 5);

    return 0;
}

void play(){
    if (PlaySound(TEXT("FEIN.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
        std::cout << "Sound is playing!" << std::endl;
    } else {
        std::cout << "Failed to play sound." << std::endl;
    }
    
    // Add a pause to keep the program running while sound plays
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();
}
