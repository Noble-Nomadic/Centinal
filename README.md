# Centinal
C based sentinal is a simple CLI system for managing a files, tracking device peformance, encrytion, and a simple antivirus.
This is a fun project for an old linux laptop.

More features may be implemented over time, but I am casually working on this in my free time so I don't want to commit to a bunch of features now.

Please note that this project is being developed on and for my old linux Toshiba satellite a300 from 2003
If you are not using linux, some features will not be compatible, and all users may find that some hardware is incompatible with certain commands

## Current features planned
- File multitool: Basics complete
- Encryption for files: Basics complete
- File scanning antivirus: Basics complete
- System peformance tracking: Basics complete
- Logging system: Basics complete
- Unit based memory system: Not started
- Interpretor for commands: Currently developing

## How it Works
When the main file is run, it presents a simple CLI system to the user.
Entering a command here will take the user to another section.
The section the user enters is the main loop that is in each header file
From that header files CLI, the user can run commands within that header file.
EG from within the *files* section, the user can run the command for creating files
Currently I am planning to add a logging system where each header is also linked to another header which logs each function called from the other headers.
This will not be added until the main header files and CLI systems are created.