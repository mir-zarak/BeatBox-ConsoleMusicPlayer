#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

// Function to display menu
void displayMenu() {
    
    cout << "\n========== BEATBOX ==========\n";
    cout << "1. Display Playlist\n";
    cout << "2. Play Song\n";
    cout << "3. Stop Song\n";
    cout << "4. Play Next Song\n";
    cout << "5. Play Previous Song\n";
    cout << "6. Exit\n";
    cout << "=============================\n";
    cout << "Enter your choice: ";
}

// Function to read songs from file
int loadPlaylist(string songs[], int maxSize) {
    ifstream file("SongsPlaylist.txt");
    
    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Error: Could not open playlist file!\n";
        return 0;
    }
    
    int count = 0;
    string line;
    
    // Read file line by line
    while (getline(file, line) && count < maxSize) {
        // Only add non-empty lines
        if (!line.empty()) {
            songs[count] = line;
            count++;
        }
    }
    
    file.close();
    return count;
}


// Function to display all songs
void displayPlaylist(string songs[], int totalSongs) {
    cout << "\n----- YOUR PLAYLIST -----\n";
    
    for (int i = 0; i < totalSongs; i++) {
        // Extract song name from full path
        int pos = songs[i].find_last_of("\\");
        string songName = songs[i].substr(pos + 1);
        
        // Display song number and name
        cout << i + 1 << ". " << songName << "\n";
    }
    
    cout << "-------------------------\n";
}


// Function to play a song
void playSong(string songPath) {
    // Stop any currently playing music
    system("taskkill /IM vlc.exe /F >nul 2>&1");
    system("taskkill /IM wmplayer.exe /F >nul 2>&1");
    
    // Open the song with default media player
    string command = "start \"\" \"" + songPath + "\"";
    system(command.c_str());
    
    cout << "\nPlaying song...\n";
    cout << "Note: Use your media player's controls to pause/resume\n";
}

// Function to stop the song
void stopSong() {
    system("taskkill /IM vlc.exe /F >nul 2>&1");
    system("taskkill /IM wmplayer.exe /F >nul 2>&1");
    cout << "\nSong stopped!\n";
}

int main() {
    string songs[100];
    int totalSongs = 0;
    int currentSong = -1;
    int choice;
    
    // Load the playlist at start
    system("cls");
    cout << "Loading playlist...\n";
    totalSongs = loadPlaylist(songs, 100);
    
    if (totalSongs == 0) {
        cout << "No songs found in playlist!\n";
        return 1;
    }
    
    cout << "Playlist loaded successfully! Total songs: " << totalSongs << "\n";
    system("pause");
    
    // Main menu loop
    while (true) {
        system("cls");
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:  // Display Playlist
                system("cls");
                displayPlaylist(songs, totalSongs);
                system("pause");
                break;
                
            case 2:  // Play a Song
                system("cls");
                displayPlaylist(songs, totalSongs);
                cout << "\nEnter song number to play: ";
                int songNum;
                cin >> songNum;
                
                if (songNum >= 1 && songNum <= totalSongs) {
                    currentSong = songNum - 1;
                    playSong(songs[currentSong]);
                } else {
                    cout << "Invalid song number!\n";
                }
                system("pause");
                break;
                
            case 3:  // Stop Song
                system("cls");
                stopSong();
                currentSong = -1;
                system("pause");
                break;
                
            case 4:  // Next Song
                system("cls");
                
                if (currentSong == -1) {
                    cout << "\nNo song is currently playing. Starting from first song...\n";
                    currentSong = 0;
                } else {
                    currentSong = (currentSong + 1) % totalSongs;
                }
                
                playSong(songs[currentSong]);
                system("pause");
                break;
                
            case 5:  // Previous Song
                system("cls");
                
                if (currentSong == -1) {
                    cout << "\nNo song is currently playing. Starting from last song...\n";
                    currentSong = totalSongs - 1;
                } else if (currentSong == 0) {
                    currentSong = totalSongs - 1;
                } else {
                    currentSong = currentSong - 1;
                }
                
                playSong(songs[currentSong]);
                system("pause");
                break;
                
            case 6:  // Exit
                system("cls");
                stopSong();
                cout << "\nThank you for using BeatBox!\n";
                return 0;
                
            default:  // Invalid choice
                cout << "Invalid choice! Please try again.\n";
                system("pause");
                break;
        }
    }
    
    return 0;
}