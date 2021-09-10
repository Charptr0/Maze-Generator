#include "./Text/text.cpp"

enum Axis
{
    x, y
};

//600x600
//smallest resolution
const int RESOLUTIONS_SMALL[2] = {600,600};

//800x800 
//default resolution | Medium resolution
const int RESOLUTIONS_MEDIUM[2] = {800,800};

//1000x1000
//biggest resolution
const int RESOLUTIONS_LARGE[2] = {1000,1000};

//square will have a length of 8 and the wall will have the length of 2, in total combined will be 10px
const int SIDE_LENGTH_SMALL = 8;
const int WALL_LENGTH_SMALL = 2;

//square will have a length of 40 and the wall will have the length of 10, in total combined will be 50px
const int SIDE_LENGTH_MEDIUM = 40;
const int WALL_LENGTH_MEDIUM= 10;

//square will have a length of 80 and the wall will have the length of 20, in total combined will be 100px
const int SIDE_LENGTH_LARGE = 80;
const int WALL_LENGTH_LARGE = 20;

const int MAX_FRAMERATE = 80;
const char TITLE[] = "Maze Generator";

const Text RESTART_INSRUCTION_TXT("Press any key to restart");
const Text ELAPSED_TIME_TXT("Elapsed Time: ");
const Text CURRENT_CELL_TXT("Current Cell: ");