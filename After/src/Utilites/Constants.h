    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#include <string>

using std::string;

const float SQRT2 = 0.7071; //Корень из двух

const float CHANGE_FRAME = 250.0; //Время в миллисекундах, через которое обновляется кадр анимации
const float FRAMES_COUNT = 4; //Количество кадров в анимации
const int HEIGHT = 64; //Высота одной клетки
const int WIDTH = 64; //Ширина одной клетки
const int AREA_HEIGHT = 16; //Высота зоны
const int AREA_WIDTH = 16; //Ширина зоны
const int WORLD_HEIGHT = 256; //Высота мира
const int LOAD_DISTANCE = 10; //Дальность загрузки мира
const float ZOOM_STEP = 1.25; //Шаг приближения или отдаления камеры
const int MIN_ZOOM = 1; //Минимальное отдаление
const int MAX_ZOOM = 10; //Максимальное отдаление

const int STAY = 0; //Номер анимации для неподвижной сущности
const int WALK = 1; //Номер анимации ходьбы
const int RUN = 2; //Номер анимации бега
const int SWIM = 3; //Номер анимации плаванья
const int ATTACK = 4; //Номер анимации атаки
const int ATTACK_LONG = 5; //Номер анимации дальней атаки
const int DEATH = 6; //Номер анимации смерти
const int DAMAGE = 7; //Номер анимации получения урона
const int STONE = 8; //Номер анимации окаменения
const int WEB = 9; //Номер анимации «опаутинивания»
const int SPECIAL = 10; //Номер особой анимации

const string INFO = "Information: "; //Информация
const string WARNING = "Warning: "; //Предупреждения
const string ERROR = "An error occured: "; //Ошибка
const string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com"; //Сообщение об ошибке
const string START = "program is run"; //Начало программы
const string CLOSE = "program is closed"; //Конец программы
const string NO_FILE = "couldn`t find file: "; //Файл не найден

const string LOG = "log"; //Лог
const string DEBUG = "debug"; //Отладочный файл

const string DATA_PATH = "res\\data\\"; //Путь к данным
const string SOUNDS_PATH = "res\\sounds\\"; //Путь к звукам
const string TEXTURES_PATH = "res\\textures\\"; //Путь к текстурам
const string OPTIONS_PATH = "res\\options\\"; //Путь к настройкам

const string CONTROLS = "controls"; //Управление

const string ENTITY = "entity\\"; //Сущность
const string MOB = "mob\\"; //Моб
const string ANIMAL = "animal\\"; //Животное
const string EXTRA = "extra\\"; //Дополнительно

const int ENTITY_COUNT = 2; //Количество сущностей
const int MOB_COUNT = 1; //Количество мобов
const int ANIMAL_COUNT = 1; //Количество животных

const string TEXT_EXT = ".txt"; //Расширение текстовых файлов
const string DATA_EXT = ".dat"; //Расширение файлов данных
const string SOUNDS_EXT = ".wav"; //Расширение звуковых файлов
const string TEXTURES_EXT = ".png"; //Расширение файлов текстур