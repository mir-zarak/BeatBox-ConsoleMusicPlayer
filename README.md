BeatBox Music Player
A simple console-based music player built in C++ for Windows, featuring playlist management, playback controls, and a user-friendly menu interface. Designed as a student project to demonstrate file I/O, system commands, and program flow in C++.

Features
Playlist Loading: Reads song paths from SongsPlaylist.txt and displays them numbered.
Play Song: Launches selected song using the default Windows media player.
Stop Song: Terminates common players like VLC and Windows Media Player.
Next/Previous Song: Cycles through the playlist seamlessly.
Menu-Driven Interface: Clear console menu with BEATBOX branding.

Implementation Details
1.	File Handling (loadPlaylist())
 
The function reads song paths from SongsPlaylist.txt:
Key Features:
•	Opens file stream for reading
•	Validates file existence
•	Reads line by line into array
•	Filters empty lines
•	Returns total song count
Error Handling:
•	File not found detection
•	Array overflow prevention
•	Empty file handling


2.	Display Functions displayMenu()
Creates the main user interface with formatted menu options.
 
 
displayPlaylist()
Displays all songs with numbering.
Key Operations:
•	Extracts filename from full path using find_last_of("\\")
•	Formats output with song numbers
•	Presents clean, readable list


3.	Playback Control Functions playSong()
Handles music playback through system media player.
Process:
1.	Terminates any running media player processes
 
2.	Constructs system command with song path
3.	Launches default media player
4.	Provides user feedback
Technical Details:
•	Uses Windows taskkill command
•	Supports VLC and Windows Media Player
•	Uses system() function for process control

stopSong()
Terminates media player processes to stop playback.


4.	Navigation System
The application maintains a currentSong index to track playback position:
Next Song Logic:
•	If no song playing → Start from first song
•	If at end of playlist → Wrap to first song
•	Otherwise → Move to next index
Previous Song Logic:
 
•	If no song playing → Start from last song
•	If at first song → Wrap to last song
•	Otherwise → Move to previous index


NEXT SONG:

PREVIOUS SONG:


Code Structure Main Components:
// Global Constants
const int MAX_SONGS = 100;


// Data Storage
 
string songs[MAX_SONGS];	// Stores song paths int totalSongs;	// Total songs loaded
int currentSong;	// Currently playing index


// Function Modules
void displayMenu()		// UI Component int loadPlaylist()	// Data Layer
void displayPlaylist()		// UI Component void playSong()	// Control Layer
void stopSong()		// Control Layer int main()	// Program Entry Point Control Flow:
1.	Initialization Phase:
o	Clear screen
o	Load playlist
o	Validate songs exist
o	Initialize variables
2.	Main Loop:
o	Display menu
o	Accept input
o	Validate choice
o	Execute function
o	Return to menu
3.	Termination:
o	Stop any playing music
o	Display exit message
 
o	Clean exit

How to Use
Setup Instructions:
1.	Create Playlist File:
o	Create SongsPlaylist.txt in the same directory
o	Add full paths to your music files (one per line)
Example format:
C:\Music\Song1.mp3 C:\Music\Song2.mp3
D:\MyMusic\FavoriteSong.mp3
2.	Compile the Program:
3.	g++ MusicPlayer.cpp -o BeatBox.exe
4.	Run the Application:
5.	BeatBox.exe


User Guide:
Menu Options:
1.	Display Playlist (Option 1)
o	Shows all available songs with numbers
o	Use this to see what songs are available
2.	Play Song (Option 2)
o	Displays playlist
o	Prompts for song number
o	Starts playback of selected song
3.	Stop Song (Option 3)
 
o	Stops currently playing music
o	Closes media player
4.	Play Next Song (Option 4)
o	Advances to next song in playlist
o	Automatically wraps to first song after last
5.	Play Previous Song (Option 5)
o	Returns to previous song
o	Wraps to last song if at beginning
6.	Exit (Option 6)
o	Stops any playing music
o	Closes the application



How It Works
Program loads playlist from SongsPlaylist.txt (format: one full song path per line).
User selects options via numbered menu.
Songs play asynchronously via system("start <path>"), returning control immediately.
Exit (option 6) stops playback and terminates cleanly with return 0;.

Note: Music files have been removed from this repository due to copyright restrictions. Create your own SongsPlaylist.txt with paths to legally owned MP3/WAV files on your system.

Prerequisites
Windows OS (uses windows.h and system commands like taskkill/start).
C++ compiler (e.g., g++ via MinGW or Visual Studio).
Text editor/IDE like VS Code.

Installation
Create SongsPlaylist.txt in the project root with song paths, e.g.:
C:\Music\song1.mp3
C:\Music\song2.wav
Compile: g++ MusicPlayer.cpp -o BeatBox.exe
Run: ./BeatBox.exe





Limitations
Windows-only due to system commands.
Asynchronous playback; songs may continue after exit unless stopped.
Kills specific players (VLC, WMPlayer); adjust stopSong for others.

References
Deitel, P. J., & Deitel, H. M. (2016). C++ How to Program, 10th Edition. Pearson.​
MusicPlayer.cpp source code.​

License
MIT License - feel free to use/modify for educational purposes. Respect music copyrights!
