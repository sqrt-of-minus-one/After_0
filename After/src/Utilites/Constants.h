    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#include <string>

const float SQRT2 = 0.7071; //Корень из двух

const float CHANGE_FRAME = 250.0; //Время в миллисекундах, через которое обновляется кадр анимации
const float FRAMES_COUNT = 4; //Количество кадров в анимации
const int HEIGHT = 64; //Высота одной клетки
const int WIDTH = 64; //Ширина одной клетки
const int AREA_HEIGHT = 16; //Высота зоны
const int AREA_WIDTH = 16; //Ширина зоны
const int WORLD_HEIGHT = 64; //Высота мира
const int LOAD_DISTANCE = 3; //Дальность загрузки мира
const float ZOOM_STEP = 1.25; //Шаг приближения или отдаления камеры
const int MIN_ZOOM = 1; //Минимальное отдаление
const int MAX_ZOOM = 10; //Максимальное отдаление

const int STAY_ANIM = 0; //Номер анимации для неподвижной сущности
const int WALK_ANIM = 1; //Номер анимации ходьбы
const int RUN_AMIN = 2; //Номер анимации бега
const int SWIM_ANIM = 3; //Номер анимации плаванья
const int ATTACK_ANIM = 4; //Номер анимации атаки
const int ATTACK_LONG_ANIM = 5; //Номер анимации дальней атаки
const int DEATH_ANIM = 6; //Номер анимации смерти
const int DAMAGE_ANIM = 7; //Номер анимации получения урона
const int STONE_ANIM = 8; //Номер анимации окаменения
const int WEB_ANIM = 9; //Номер анимации «опаутинивания»
const int SPECIAL_ANIM = 10; //Номер особой анимации

const std::string INFO = "Information: "; //Информация
const std::string WARNING = "Warning: "; //Предупреждения
const std::string ERROR = "An error occured: "; //Ошибка
const std::string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com"; //Сообщение об ошибке
const std::string I_START = "program is run"; //Начало программы
const std::string I_CLOSE = "program is closed"; //Конец программы
const std::string I_WORLD_CREATE = "a world is created"; //Создан мир
const std::string W_NO_FILE = "couldn`t find file: "; //Файл не найден
const std::string W_ENTITY_NOT_UNL_FROM_AREA = "Entity doesn`t unload from area"; //Сущность не удаляется из зоны

const std::string LOG = "log"; //Лог
const std::string DEBUG = "debug"; //Отладочный файл

const std::string DATA_PATH = "res\\data\\"; //Путь к данным
const std::string SOUNDS_PATH = "res\\sounds\\"; //Путь к звукам
const std::string TEXTURES_PATH = "res\\textures\\"; //Путь к текстурам
const std::string OPTIONS_PATH = "res\\options\\"; //Путь к настройкам

const std::string CONTROLS = "controls"; //Управление

const std::string ENTITY = "entity\\"; //Сущность
const std::string MOB = "mob\\"; //Моб
const std::string ANIMAL = "animal\\"; //Животное
const std::string EXTRA = "extra\\"; //Дополнительно
const std::string OBJECT = "object\\"; //Объект

const int ENTITY_COUNT = 2; //Количество сущностей
const int MOB_COUNT = 1; //Количество мобов
const int ANIMAL_COUNT = 1; //Количество животных
const int OBJECT_COUNT = 1; //Количество объектов

const std::string TEXT_EXT = ".txt"; //Расширение текстовых файлов
const std::string DATA_EXT = ".dat"; //Расширение файлов данных
const std::string SOUNDS_EXT = ".wav"; //Расширение звуковых файлов
const std::string TEXTURES_EXT = ".png"; //Расширение файлов текстур