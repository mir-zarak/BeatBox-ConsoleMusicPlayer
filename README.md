BeatBox Music Player
A simple console-based music player built in C++ for Windows, featuring playlist management, playback controls, and a user-friendly menu interface. Designed as a student project to demonstrate file I/O, system commands, and program flow in C++.

Features
Playlist Loading: Reads song paths from SongsPlaylist.txt and displays them numbered.

Play Song: Launches selected song using the default Windows media player.

Stop Song: Terminates common players like VLC and Windows Media Player.

Next/Previous Song: Cycles through the playlist seamlessly.

Menu-Driven Interface: Clear console menu with BEATBOX branding.

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
Clone the repo: git clone <your-repo-url>

Create SongsPlaylist.txt in the project root with song paths, e.g.:

text
C:\Music\song1.mp3
C:\Music\song2.wav
Compile: g++ MusicPlayer.cpp -o BeatBox.exe

Run: ./BeatBox.exe

Screenshots
<img width="455" height="291" alt="Screenshot 2025-12-09 235119" src="https://github.com/user-attachments/assets/c292570c-3c48-4caa-99a6-cdb248431859" />

<img width="1547" height="480" alt="image" src="https://github.com/user-attachments/assets/4f38ea41-8ee0-4475-b84d-c8f47d2fb215" />



Limitations
Windows-only due to system commands.

Asynchronous playback; songs may continue after exit unless stopped.

Kills specific players (VLC, WMPlayer); adjust stopSong for others.

References
Deitel, P. J., & Deitel, H. M. (2016). C++ How to Program, 10th Edition. Pearson.​

MusicPlayer.cpp source code.​

License
MIT License - feel free to use/modify for educational purposes. Respect music copyrights!
