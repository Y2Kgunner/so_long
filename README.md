# so_long

The objective of this project is to create a maze-solving game where the player's goal is to collect every collectible on the map and escape by choosing a route to the exit. The theme I chose for this game is that of a scuba diver diving for gold, and exiting via a boat on the map.

![Screenshot from 2024-04-25 01-36-18](https://github.com/Y2Kgunner/so_long/assets/84834112/00938c16-6982-48db-b107-2244293637c0)

## Key Features

- Use the MiniLibX graphical library for window management and image display
- Parse a map description file in the `.ber` format as a parameter
- Implement a maze game where the player navigates using the arrow keys
- Display the current number of movements in the shell
- Ensure smooth window management and clean program exit on user actions
- Construct the map with walls, collectibles, and free space according to specified characters
- Check for valid paths in the map to ensure solvability
- Parse any valid map format while handling errors gracefully

## Knowledge Gained

- Game development concepts and techniques
- Graphical management using MiniLibX
- File parsing and data validation in C programming
- Error handling and clean program exit strategies
- Implementation of maze-solving algorithms for pathfinding
- Understanding of game mechanics such as player movement and collectibles
- User interface design and feedback mechanisms

## Usage

To compile your project, use the provided Makefile:

```sh
make
```

Run your program with a map description file as a parameter:

```sh
./so_long map/map1.ber
```
