    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#include <string>

using std::string;

const float SQRT2 = 0.7071;

const float CHANGE_FRAME = 250.0;
const float FRAMES_COUNT = 4;
const int HEIGHT = 64;
const int WIDTH = 64;
const float ZOOM_STEP = 1.25;
const int MIN_ZOOM = 1;
const int MAX_ZOOM = 10;

const int STAY = 0;
const int WALK = 1;
const int RUN = 2;
const int SWIM = 3;
const int ATTACK = 4;
const int ATTACK_LONG = 5;
const int DEATH = 6;
const int DAMAGE = 7;
const int STONE = 8;
const int WEB = 9;
const int SPECIAL = 10;

const string INFO = "Information: ";
const string WARNING = "Warning: ";
const string ERROR = "An error occured: ";
const string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com";
const string START = "program is run";
const string CLOSE = "program is closed";
const string NO_FILE = "couldn`t find file: ";

const string LOG = "log";
const string DEBUG = "debug";

const string DATA_PATH = "res\\data\\";
const string SOUNDS_PATH = "res\\sounds\\";
const string TEXTURES_PATH = "res\\textures\\";
const string OPTIONS_PATH = "res\\options\\";

const string CONTROLS = "controls";

const string ENTITY = "entity\\";
const string MOB = "mob\\";
const string ANIMAL = "animal\\";
const string EXTRA = "extra\\";

const int ENTITY_COUNT = 2;
const int MOB_COUNT = 1;
const int ANIMAL_COUNT = 1;

const string TEXT_EXT = ".txt";
const string DATA_EXT = ".dat";
const string SOUNDS_EXT = ".wav";
const string TEXTURES_EXT = ".png";