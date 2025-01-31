#include <windows.h>
#include <iostream>
#include <MMsystem.h>
#include <vector>
#include <string>
#pragma comment(lib, "winmm.lib" )

using namespace std;

void play(pair<string, string> songData);

int main() {
    // pairs allow for 2 objects to be combined together, arrays did not work.
    vector<pair<string, string>> playlist {{"Fein", "musicFiles/FEIN.wav"}, 
                                {"Carnival", "musicFiles/carnival.wav"},
                                {"Magic Johnson", "musicFiles/magic johnson.wav"}, 
                                {"Thick Of It", "musicFiles/thick of it.wav"}};
    int choice;
    string song, file;
    play(playlist[1]);
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
                cout << "Enter the song's file: ";
                cin.ignore(); 
                getline(cin, file); 
                playlist.push_back({song, file});
                cout << song << " has been added" << endl;
                break;

            case 2:
                if (playlist.empty()) {
                    cout << "Playlist is empty" << endl;
                } else {
                    cout << "Your playlist contains the following songs:\n";
                    for (size_t i = 0; i < playlist.size(); i++) {
                        cout << i + 1 << ". " << playlist[i].first << endl;
                    }

                    cout << "Enter the number of the song to delete: ";
                    int index;
                    cin >> index;

                    if (index > 0 && index <= playlist.size()) {
                        cout << playlist[index - 1].first << " has been deleted" << endl;
                        playlist.erase(playlist.begin() + index - 1); 
                    } else {
                        cout << "Invalid song number" << endl;
                    }
                }
                break;

            case 3:
                cout << "Your playlist contains the following songs:\n";
                for (const auto s : playlist) {
                    cout << s.first << endl;
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
                break;
        }
    } while (choice != 5);

    return 0;
}

void play(pair <string, string> songData){
    string song = songData.first;
    string file = songData.second;
    if (PlaySoundW(std::wstring(file.begin(), file.end()).c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Playing " << songData.first << "!" << std::endl;
    } else {
        std::cout << "Failed to play." << std::endl;
    }
    
    // Add a pause to keep the program running while sound plays
    std::cout << "Press any key to stop the music..." << std::endl;
    std::cin.get();

    // Stop the sound
    PlaySound(NULL, 0, 0);
}
