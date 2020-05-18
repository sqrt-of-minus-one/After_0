    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#include <string>

const float SQRT2 = 0.7071; //������ �� ����

const float CHANGE_FRAME = 250.0; //����� � �������������, ����� ������� ����������� ���� ��������
const float FRAMES_COUNT = 4; //���������� ������ � ��������
const int HEIGHT = 64; //������ ����� ������
const int WIDTH = 64; //������ ����� ������
const int AREA_HEIGHT = 16; //������ ����
const int AREA_WIDTH = 16; //������ ����
const int WORLD_HEIGHT = 64; //������ ����
const int LOAD_DISTANCE = 3; //��������� �������� ����
const float ZOOM_STEP = 1.25; //��� ����������� ��� ��������� ������
const int MIN_ZOOM = 1; //����������� ���������
const int MAX_ZOOM = 10; //������������ ���������

const int STAY_ANIM = 0; //����� �������� ��� ����������� ��������
const int WALK_ANIM = 1; //����� �������� ������
const int RUN_AMIN = 2; //����� �������� ����
const int SWIM_ANIM = 3; //����� �������� ��������
const int ATTACK_ANIM = 4; //����� �������� �����
const int ATTACK_LONG_ANIM = 5; //����� �������� ������� �����
const int DEATH_ANIM = 6; //����� �������� ������
const int DAMAGE_ANIM = 7; //����� �������� ��������� �����
const int STONE_ANIM = 8; //����� �������� ����������
const int WEB_ANIM = 9; //����� �������� ���������������
const int SPECIAL_ANIM = 10; //����� ������ ��������

const std::string INFO = "Information: "; //����������
const std::string WARNING = "Warning: "; //��������������
const std::string ERROR = "An error occured: "; //������
const std::string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com"; //��������� �� ������
const std::string I_START = "program is run"; //������ ���������
const std::string I_CLOSE = "program is closed"; //����� ���������
const std::string I_WORLD_CREATE = "a world is created"; //������ ���
const std::string W_NO_FILE = "couldn`t find file: "; //���� �� ������
const std::string W_ENTITY_NOT_UNL_FROM_AREA = "Entity doesn`t unload from area"; //�������� �� ��������� �� ����

const std::string LOG = "log"; //���
const std::string DEBUG = "debug"; //���������� ����

const std::string DATA_PATH = "res\\data\\"; //���� � ������
const std::string SOUNDS_PATH = "res\\sounds\\"; //���� � ������
const std::string TEXTURES_PATH = "res\\textures\\"; //���� � ���������
const std::string OPTIONS_PATH = "res\\options\\"; //���� � ����������

const std::string CONTROLS = "controls"; //����������

const std::string ENTITY = "entity\\"; //��������
const std::string MOB = "mob\\"; //���
const std::string ANIMAL = "animal\\"; //��������
const std::string EXTRA = "extra\\"; //�������������
const std::string OBJECT = "object\\"; //������

const int ENTITY_COUNT = 2; //���������� ���������
const int MOB_COUNT = 1; //���������� �����
const int ANIMAL_COUNT = 1; //���������� ��������
const int OBJECT_COUNT = 1; //���������� ��������

const std::string TEXT_EXT = ".txt"; //���������� ��������� ������
const std::string DATA_EXT = ".dat"; //���������� ������ ������
const std::string SOUNDS_EXT = ".wav"; //���������� �������� ������
const std::string TEXTURES_EXT = ".png"; //���������� ������ �������