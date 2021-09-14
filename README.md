# Maze-Generator <img src="https://i.imgur.com/0ZhDDz4.gif" width="10%" align="right">

Generate a randomized maze using depth-first search.


## Demonstration Video
[![MAZE](https://img.youtube.com/vi/IZkIYlHzFvg/0.jpg)](https://www.youtube.com/watch?v=IZkIYlHzFvg)


## Installation
You will need to install the **SFML library** to run this program.

1. Clone this repository

3. Install SFML

5. Run these commands to compile

```
g++ -c main.cpp
g++ main.o -o maze-gen -lsfml-graphics -lsfml-window -lsfml-system
```

4. Run the program

```
./maze-gen
```


## Tips and Instructions
* Once the maze has finished generating, **press any key on your keyboard to restart the generation**
* At the beginning the `CURRENT_RESOLUTION[2]` can be changed to either of the three supported resolutions
```c++
//600x600
//smallest resolution
const int RESOLUTIONS_SMALL[2] = {600,600};

//800x800 
//default resolution | Medium resolution
const int RESOLUTIONS_MEDIUM[2] = {800,800};

//1000x1000
//biggest resolution
const int RESOLUTIONS_LARGE[2] = {1000,1000};
```
* Similar to `CURRENT_RESOLUTION[2]`, the `SIDE_LENGTH` and the `WALL_LENGTH` can also be changed
```c++
//square will have a length of 8 and the wall will have the length of 2, combined in total will have a size of 10px
const int SIDE_LENGTH_SMALL = 8;
const int WALL_LENGTH_SMALL = 2;

//square will have a length of 40 and the wall will have the length of 10, combined in total will have a size of 50px
const int SIDE_LENGTH_MEDIUM = 40;
const int WALL_LENGTH_MEDIUM= 10;

//square will have a length of 80 and the wall will have the length of 20, combined in total will have a size of 100px
const int SIDE_LENGTH_LARGE = 80;
const int WALL_LENGTH_LARGE = 20;
```
* The `MAX_FRAMERATE` can be changed in the `config.cpp` file. The higher the framerate, the faster the generation. (It is not recommanded to go above 100+ fps)
  
