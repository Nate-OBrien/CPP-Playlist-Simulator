#include <windows.h>
#include <iostream>
#include <MMsystem.h>
#include <vector>
#include <string>
#include <ctime> 
#pragma comment(lib, "winmm.lib" )

using namespace std;
//portaudio
void play(pair<string, string> songData);
wstring s2ws(const string& s);

int main() {
    // pairs allow for 2 objects to be combined together, arrays did not work.
    vector<pair<string, string>> playlist {{"Fein", "musicFiles/FEIN.wav"}, 
                                {"Carnival", "musicFiles\\carnival.wav"},
                                {"Magic Johnson", "musicFiles/magic johnson.wav"}, 
                                {"Thick Of It", "musicFiles/thick of it.wav"}};
    int choice;
    string song, file;
    play(playlist[1]);
    do {
        cout << "\nMenu:\n";
        cout << "1. Play a song\n";
        cout << "2. Add a song\n";
        cout << "3. Delete a song\n";
        cout << "4. Open playlist\n";
        cout << "5. How Many Songs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nThese are the songs you have on your playlist: \n";
                for (size_t i = 0; i < playlist.size(); i++) {
                        cout << i + 1 << ". " << playlist[i].first << endl;
                    }
                cout << "\nEnter the number of song that u want to play: ";
                    int play;
                    cin >> play;
                    

                    if (play > 0 && play <= playlist.size()) {
                        cout << playlist[play - 1].first << " has been selected" << endl;
                        //code to play the selected song goes here 
                    } else {
                        cout << "\nInvalid song number" << endl;
                    }
            case 2:
                cout << "Enter a song to add: ";
                cin.ignore(); 
                getline(cin, song);
                cout << "Enter the song's file: ";
                cin.ignore(); 
                getline(cin, file); 
                playlist.push_back({song, file});
                cout << song << " has been added" << endl;
                break;

            case 3:
                if (playlist.empty()) {
                    cout << "Playlist is empty" << endl;
                } else {
                    cout << "\nYour playlist contains the following songs:\n";
                    for (size_t i = 0; i < playlist.size(); i++) {
                        cout << i + 1 << ". " << playlist[i].first << endl;
                    }

                    cout << "\nEnter the number of the song to delete: ";
                    int index;
                    cin >> index;

                    if (index > 0 && index <= playlist.size()) {
                        cout << playlist[index - 1].first << " has been deleted" << endl;
                        playlist.erase(playlist.begin() + index - 1); 
                    } else {
                        cout << "\nInvalid song number" << endl;
                    }
                }
                break;

            case 4:
                cout << "\nYour playlist contains the following songs:\n";
                for (const auto s : playlist) {
                    cout << s.first << endl;
                }
                break;

            case 5:
                cout << "\nThere are " << playlist.size() << " songs in your playlist" << endl;
                break;

            case 6:
                cout << "\nExiting program" << endl;
                break;

            default:
                cout << "\nInvalid selection" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void play(pair <string, string> songData){
    string song = songData.first;
    string file = songData.second;
    cout << song << "\n" << file << endl;
    if (PlaySoundA(file.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Playing " << songData.first << "!" << std::endl;
    } else {
        std::cout << "Failed to play." << std::endl;
    }
    
    // Add a pause to keep the program running while sound plays
    std::cout << "Press any key to stop the music..." << std::endl;
    std::cin.get();

    //Stop the sound
    PlaySound(NULL, 0, 0);
}

