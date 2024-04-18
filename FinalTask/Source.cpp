//#include <iostream>
//#include <windows.h>
//#include <mmsystem.h>
//#include <string>
//
//using namespace std;
//
//class Base {
//public:
//    Base(string name, int health, int armor, int damage) : name(name), health(health), armor(armor), damage(damage) {}
//
//    void attack_target(Base& target) {
//        cout << "\nBom-boom\n" << endl;
//        target.health -= max(0, damage - target.armor);
//        PlaySoundA((LPCSTR)"SoundFire", NULL, SND_FILENAME | SND_ASYNC);
//        getchar();
//    }
//
//    bool is_alive() {
//        return health > 0;
//    }
//
//    void get_hp() {
//        cout << "\nObject: " << name;
//        cout << "\nThe health is: " << health;
//        cout << "\nThe armor is: " << armor;
//    }
//
//    string name;
//    int health;
//    int armor;
//    int damage;
//};
//
//void displayUnits(const Base& red, const Base& blue) {
//    cout << "\n\n";
//    cout << "      RED UNIT       BLUE UNIT" << endl;
//    cout << "     ______________      ______________" << endl;
//    cout << "    /              \\   /               \\" << endl;
//    cout << "   /                \\ /                 \\" << endl;
//    cout << "  |                  ||                  ||" << endl;
//    cout << "  |      " << red.name << "            " << blue.name << "      " << endl;
//    cout << "  |      HP: " << red.health << "            HP: " << blue.health << "     " << endl;
//    cout << "  |__________________||__________________||" << endl;
//}
//
//int main() {
//    int health_red, health_blue, armor_red, armor_blue, damage_red, damage_blue;
//    string name_red, name_blue;
//
//    cout << "Put the name of vehicle of RED team unit: " << endl;
//    PlaySoundA((LPCSTR)"Launch", NULL, SND_FILENAME | SND_ASYNC);
//
//    cin >> name_red;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the " << name_red << " health: " << endl;
//    cin >> health_red;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the " << name_red << " armor: " << endl;
//    cin >> armor_red;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the damage of " << name_red << endl;
//    cin >> damage_red;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//
//    //The first unit
//
//    cout << "\nPut the name of vehicle of BLUE team unit: " << endl;
//    PlaySoundA((LPCSTR)"Launch", NULL, SND_FILENAME | SND_ASYNC);
//
//    cin >> name_blue;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the " << name_blue << " health: " << endl;
//    cin >> health_blue;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the " << name_blue << " armor: " << endl;
//    cin >> armor_blue;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    cout << "\nPut the damage  of " << name_blue << endl;
//    cin >> damage_blue;
//    PlaySoundA((LPCSTR)"Ok", NULL, SND_FILENAME | SND_ASYNC);
//
//    //The second unit
//
//    cout << "\n\n";
//
//    Base red_team(name_red, health_red, armor_red, damage_red);
//    Base blue_team(name_blue, health_blue, armor_blue, damage_blue);
//
//    bool redTurn = true;
//    int choice;
//
//    while (red_team.is_alive() && blue_team.is_alive()) {
//        if (redTurn) {
//            cout << "\n\n\nThe " << name_red << " moving is now\n\n";
//            cout << "\nChoose the option:\n";
//            cout << "1. Attack the opponent\n";
//            cout << "2. Show stats\n";
//            cout << "3. Pass\n";
//            cout << "\n\n\n\n\n\n\n\nYour choice is: ";
//            cin >> choice;
//            cout << "\n";
//
//            switch (choice) {
//            case 1:
//                red_team.attack_target(blue_team);
//                redTurn = false;
//                break;
//            case 2:
//                cout << " The stats of RED unit is: " << endl;
//                red_team.get_hp();
//                cout << "\n\n The stats of BLUE unit is: " << endl;
//                blue_team.get_hp();
//                break;
//            case 3:
//                cout << "\n\n\n Pass.\n\n\n" << endl;
//                redTurn = false;
//                break;
//            default:
//                cout << "\n\n\n ERROR \n\n\n" << endl;
//                break;
//            }
//            displayUnits(red_team, blue_team); // Отображаем юнитов после хода красного
//        }
//        else {
//            cout << "\n\n\nThe " << name_blue << " moving is now\n\n";
//            cout << "\nChoose the option:\n";
//            cout << "1. Attack the opponent\n";
//            cout << "2. Show stats\n";
//            cout << "3. Pass\n";
//            cout << "\n\n\n\n\n\n\n\nyour choice is: ";
//            cin >> choice;
//            cout << "\n";
//
//            switch (choice) {
//            case 1:
//                blue_team.attack_target(red_team);
//                redTurn = true;
//                break;
//            case 2:
//                cout << " The stats of RED unit is: " << endl;
//                red_team.get_hp();
//                cout << "\n\n The stats of BLUE unit is: " << endl;
//                blue_team.get_hp();
//                break;
//            case 3:
//                cout << "\n\n\n Pass.\n\n\n" << endl;
//                redTurn = true;
//                break;
//            default:
//                cout << "\n\n\n ERROR\n\n\n" << endl;
//                break;
//            }
//            displayUnits(red_team, blue_team); // Отображаем юнитов после хода синего
//        }
//    }
//
//    if (!red_team.is_alive()) {
//        PlaySoundA((LPCSTR)"Loser", NULL, SND_FILENAME | SND_ASYNC);
//        cout << "\n";
//        cout << name_blue << " deafeat " << name_red << "\n\n\n" << endl;
//        cout << "The " << name_blue << " is WON!" << endl;
//    }
//    else {
//        PlaySoundA((LPCSTR)"Winner", NULL, SND_FILENAME | SND_ASYNC);
//        cout << "\n";
//        cout << name_red << " deafeat " << name_blue << "\n\n\n" << endl;
//        cout << "The " << name_red << " is WON!" << endl;
//    }
//
//    cout << "\nPress Enter to exit..." << endl;
//    cin.get();
//}








//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Family
//{
//public:
//    string name;
//    int cleaningSkill;
//    int cookingSkill;
//    int relaxingSkill;
//
//    Family(string name, int cleaningSkill, int cookingSkill, int relaxingSkill)
//    {
//        this->name = name;
//        this->cleaningSkill = cleaningSkill;
//        this->cookingSkill = cookingSkill;
//        this->relaxingSkill = relaxingSkill;
//    }
//
//    void cleaning()
//    {
//        cout << name << ", а также " << cleaningSkill << " уборки... ";
//        if (cleaningSkill > 80)
//        {
//            cout << " поздравляю ты молодец, возьми с полки пирожок. " << endl;
//
//        }
//        else if (cleaningSkill > 50)
//        {
//            cout << "50 на 50 короче..." << endl;
//        }
//        else
//        {
//            cout << "Че то как то.. не так то..." << endl;
//        }
//    }
//
//    void cooking()
//    {
//        cout << name << " и " << cookingSkill << " готовки это кагда... ";
//        if (cookingSkill > 80)
//        {
//            cout << "- ДАЙ ЕЩЁ!" << endl;
//            cout << "- нет." << endl;
//        }
//        else if (cookingSkill > 50)
//        {
//            cout << "Норм." << endl;
//        }
//        else
//        {
//            cout << "'Мда... где дошык?'" << endl;
//        }
//    }
//
//    void relaxing()
//    {
//        cout << name << ", что там по " << relaxingSkill << " отдыха? ";
//        if (relaxingSkill > 80)
//        {
//            cout << "'Учись, студент!'" << endl;
//        }
//        else if (relaxingSkill > 50)
//        {
//            cout << "отдыхать надо уметь, а я сплю." << endl;
//        }
//        else
//        {
//            cout << "Не, не маё." << endl;
//        }
//    }
//};
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    vector<Family> family;
//    string name;
//    int cleaningSkill, cookingSkill, relaxingSkill;
//
//    cout << "Введите информацию о четырех членах семьи: " << endl;
//    for (int i = 0; i < 4; i++)
//    {
//        cout << "\nИмя: ";
//        cin >> name;
//        cout << "Уровень навыка уборки (0-100): ";
//        cin >> cleaningSkill;
//        cout << "Уровень навыка готовки (0-100): ";
//        cin >> cookingSkill;
//        cout << "Уровень навыка отдыха (0-100): ";
//        cin >> relaxingSkill;
//        family.push_back(Family(name, cleaningSkill, cookingSkill, relaxingSkill));
//    }
//
//    int choice, memberChoice;
//    while (true)
//    {
//        cout << "\nВыберите члена семьи (1, 2, 3 или 4): ";
//        cin >> memberChoice;
//        if (memberChoice < 1 || memberChoice > 4)
//        {
//            cout << "Неверный выбор члена семьи. Попробуйте снова." << endl;
//            continue;
//        }
//
//        cout << "Выберите задачу для " << family[memberChoice - 1].name << ":" << endl;
//        cout << "1. Уборка" << endl;
//        cout << "2. Готовка" << endl;
//        cout << "3. Отдых" << endl;
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            family[memberChoice].cleaning();
//            break;
//        case 2:
//            family[memberChoice].cooking();
//            break;
//        case 3:
//            family[memberChoice].relaxing();
//            break;
//        default:
//            cout << "Неверный выбор. Попробуйте снова." << endl;
//            break;
//        }
//
//        cout << "Продолжить? (0 - выход, 1 - продолжить) ";
//        cin >> choice;
//        if (choice == 0)
//        {
//            break;
//        }
//    }
//    return 0;
//}












//#include <iostream>
//
//using namespace std;
//
//class journal
//{
//private:
//    int* array;
//    int size;
//
//public:
//    journal(int _size) : size(_size)
//    {
//        array = new int[size];
//    }
//
//    ~journal()
//    {
//        delete[] array;
//    }
//
//    void fill_journal()
//    {
//        cout << "Введите " << size << " каких то цифорок-чиселок:" << endl;
//        for (int i = 0; i < size; i++)
//        {
//            cout << "Сюда " << i + 1 << ": ";
//            cin >> array[i];
//        }
//    }
//
//    void shuffle_journal()
//    {
//        for (int i = size - 1; i > 0; i--)
//        {
//            int j = rand() % (i + 1);
//            swap(array[i], array[j]);
//        }
//    }
//
//    int c_d_elements()
//    {
//        int count = 1;
//        for (int i = 1; i < size; i++)
//        {
//            bool is_d = true;
//            for (int j = 0; j < i; j++)
//            {
//                if (array[i] == array[j])
//                {
//                    is_d = false;
//                    break;
//                }
//            }
//            if (is_d)
//            {
//                count++;
//            }
//        }
//        return count;
//    }
//
//    void show_journal()
//    {
//        for (int i = 0; i < size; i++)
//        {
//            cout << array[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    int size;
//    cout << "Каким будет размер массива: ";
//    cin >> size;
//
//    journal arr(size);
//    arr.fill_journal();
//
//    cout << "\nМассив на старте: ";
//    arr.show_journal();
//
//    arr.shuffle_journal();
//    cout << "\nВаш помешанный массив: ";
//    arr.show_journal();
//
//    int d_count = arr.c_d_elements();
//    cout << "\nРазных элементов: " << d_count << endl;
//
//    return 0;
//}













//#include <iostream>
//using namespace std;
//class gym_chisla
//{ private:
//    int* arr;
//    int size;
//public:
//    gym_chisla()
//    {
//        cout << "Сколько качков в тиме? - ";
//        cin >> size;
//        arr = new int[size];
//        cout << "Вводи их в виде чиселок:" << endl;
//        for (int i = 0; i < size; i++)
//        {
//            cin >> arr[i];
//        }
//    }
//    ~gym_chisla()
//    {
//        delete[] arr; //типо пример дуструктора(он в коде)
//    } void pokazhi_kachkov()
//    {
//        cout << "\nвот твои качки в виде цифорок: ";
//        for (int i = 0; i < size; i++)
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    } void chisla_podkachalis()
//    {
//        for (int i = 0; i < size; i++)
//        {
//            arr[i]++;
//        }
//        cout << "\nТвои цифорки + 1 это: " << endl;
//        pokazhi_kachkov();
//    } void chisla_v_zapoe()
//    {
//        for (int i = 0; i < size; i++)
//        {
//            arr[i]--;
//        }
//        cout << "\nТвои цифорки - 1 это:" << endl;
//        pokazhi_kachkov();
//    }
//}; int main()
//{
//    setlocale(LC_ALL, "RU");
//    gym_chisla thing;
//    thing.pokazhi_kachkov();
//
//    int vibor;
//    cout << "\nШта делаем? напиши 1 или 2:" << endl;
//    cout << "1) твои числа треняться и увеличивают мышечную массу на + 1" << endl;
//    cout << "2) они решили уйти в запой, а это - 1 каждому из собутыльников " << endl;
//    cout << "\nБатя выбрал: ";
//    cin >> vibor;
//
//    switch (vibor)
//    {
//    case 1:
//        thing.chisla_podkachalis();
//        break;
//    case 2:
//        thing.chisla_v_zapoe();
//        break;
//    default:
//        cout << "Тебе норм?" << endl;
//        break;
//    } return 0;
//}









#include <iostream>
#include <vector>
using namespace std;

class soldiers {
private:
    vector<int> arr;
public:
    soldiers() {
        int size, num;
        cout << "Сколько бойцов у вас будет?: ";
        cin >> size;

        cout << "Дайте их силу в очках: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> num;
            arr.push_back(num);
        }
    }

    ~soldiers() {
        cout << "вот пример деструктора. " << endl;
    }

    void numbers_s() {
        cout << "\nНомера бойцов: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void numbers_new_s() {
        int choice;
        cout << "\nЧто делать товарисч?:" << endl;
        cout << "1) Всем солдатам дать по одному рожку " << endl;
        cout << "2) Пусть съедят по 1 патрону" << endl;
        cout << "3) Дать им всем по ящику фугасов" << endl;
        cout << "4) Забрать у них бронежелеты и одежду " << endl;
        cout << "\nВаш выбор: ";
        cin >> choice;

        for (int& num : arr) {
            if (choice == 1) {
                num++;
            }
            else if (choice == 2) {
                num--;
            }
            else if (choice == 3) {
                num*=2;
            }
            else if (choice == 4) {
                num/=2;
            }
            else {
                cout << "Товарисч вы компетентны?" << endl;
                return;
            }
        }

        cout << "Ваши боцы теперь выглядят так... " << endl;
        numbers_s();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    soldiers obj;
    obj.numbers_s();
    obj.numbers_new_s();
    return 0;
}