Escape The Labyrinth
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

This C++ implementation generates two unique mazes based on the user's ID. The Regular maze follows the structure of a grid and twisty maze follows a non grid pattern adding complexity and fun for the user. 
Both mazes contains 3 items Wand, Potion, SpellBook. The user has to find path to collect all items to escape the labyrinth.

Features:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  Regular Maze: A grid based maze where movement is restricted to North, South, West, and East.

  Twisty Maze: A non grid like maze where movement is still restricted to North, South, West, and East but if you move north and then south it doesnt mean that you will be at the same location.

  Path Valid: A function is provided to warn user if they enter a wrong string of moves containing any other character the N, E, W, and S and it also checks and warns the user if the moves leads to no where.
  
  Memory: The memory is properly managed ensuring any allocated memory is freed before the end of the program.

Requirements:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  C++11 or more

  GNU

  Valgrind

How To Run:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  Regular Maze: 
    make build_reg
    make run_reg
    gdb ExploreTheRegularLabyrinth.exe
    (gdb) b ExploreTheRegularLabyrinth.cpp:15
    (gdb) r
    (gdb) i locals
    (gdb) p *start // your start point, from here its upto you where you want to move
    (gdb) p * (start->North)// if you want to move North

  Twisty Maze:
    make build_twisty
    make run_twisty
    gdb ExploreTheTwistyLabyrinth.exe
    (gdb) b ExploreTheTwistyLabyrinth.cpp:16
    (gdb) r
    (gdb) i locals
    (gdb) p *start // your start point, from here its upto you where you want to move
    (gdb) p * (start->North)// if you want to move North

Customization:
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  ID: Add an ID (Example: jdoe for John Doe) in kYourNetID (in EscapeTheLabyrinth.h) with your own ID to generate a unique maze. 

  Paths: Modify kPathOutOfRegularMaze and kPathOutOfTwistyMaze in EscapeTheLabyrinth.h to test different paths.
