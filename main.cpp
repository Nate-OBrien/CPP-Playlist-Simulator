#include <windows.h>
#include <iostream>
#include <MMsystem.h>
#include <vector>
#include <string>
#include <ctime> 
#include <algorithm>
#include <random>
#pragma comment(lib, "winmm.lib" )

using namespace std;

void play(pair<string, string> songData);

int main() {
    // pairs allow for 2 objects to be combined together, arrays did not work.
    vector<pair<string, string>> playlist {
                                {"Fein", "musicFiles\\FEIN.wav"}, 
                                {"Carnival", "musicFiles\\carnival.wav"},
                                {"Magic Johnson", "musicFiles\\magic johnson.wav"}, 
                                {"Thick Of It", "musicFiles\\thick of it.wav"}};
    int choice;
    string song, file;
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
                cout << "\nEnter Playmode (1=Single Song, 2=In order, 3=Shuffle): ";
                    int playMode;
                    cin >> playMode;
                //plays correct mode
                if (playMode == 1){
                    play(playlist[0]);
                } else if (playMode == 2){
                    // plays in order
                    string next = "";
                    for (size_t i = 0; i < playlist.size(); i++){
                        cout << "\nPlaying " << playlist[i].first << "!" << endl;
                        cout << "Type anything to go to the next song. ";
                        cin >> next;
                    }
                } else if (playMode == 3){
                    // creates a copy of the playlist before shuffling and playing
                    string next = "";
                    vector <pair <string, string>> placeholder = {};
                    auto rng = default_random_engine {};

                    copy(playlist.begin(), playlist.end(), back_inserter(placeholder));
                    shuffle(begin(placeholder), end(placeholder), rng);
                    for (size_t i = 0; i < placeholder.size(); i++){
                        cout << "\nPlaying " << placeholder[i].first << "!" << endl;
                        cout << "Type anything to go to the next song. ";
                        cin >> next;
                    }
                }
                break;
            case 2:
                // gets the name and filepath before adding
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
                //checks if empty
                if (playlist.empty()) {
                    cout << "Playlist is empty" << endl;
                } else {
                    // deletes a entry
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
            //prints number of songs
            case 4:
                cout << "\nThere are " << playlist.size() << " songs in your playlist" << endl;
                break;
            
            case 5:
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
    cin.clear();
    string song = songData.first;
    string file = songData.second;
    // no other files work so make it play fein
    if (PlaySound(TEXT("musicFiles/FEIN.wav"), NULL, SND_FILENAME | SND_ASYNC)) {
        cout << "Playing Fein!" << endl;
    } else {
        cout << "Failed to play." << endl;
    }
    
    // Add a pause to keep the program running while sound plays
    cout << "Press any key to stop the music..." << endl;
    cin.get();

    //Stop the sound
    PlaySound(NULL, 0, 0);
}

