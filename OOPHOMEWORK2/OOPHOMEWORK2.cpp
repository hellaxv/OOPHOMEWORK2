#include <iostream>
#include <string>

using namespace std;

void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
    cout << "\n\n//======================================END======================================//\n\n";
}

/*HOMEWORK1
Создать класс Person (человек) с полями: имя, возраст, пол и вес.
Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student (студент), имеющий поле года обучения.
Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов.
В функции main() создать несколько студентов.
По запросу вывести определенного человека.
*/
class Person
{
private:
    static int count; //счетчик!
protected:
    string n_name;
    int n_age;
    string n_gender;
    int n_wight;
public:
    static int GetCount() { return count; } //колл-во студентов.
    //Person();
    Person(const string& name, const int& age, const string& gender, const int& wight)
        : n_name(name), n_age(age), n_wight(wight), n_gender(gender)
    {
        count++; //увеличение колл-ва студентов.
    }

    string GetName() { return n_name; } //переназначения имени, изменения возраста и веса
    int GetAge() { return n_age; }
    int GetWighr() { return n_wight; }
    virtual void Print()   //  виртуальная функция перегружаемая в классе Student
    {
        cout << n_name << ' ' << n_age << ' ' << n_gender << ' ' << n_wight << endl;
    }
};

class Student : public Person //Создали производный класс Student (студент).
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& gender, const int wight)
        :Person(name, age, gender, wight), n_year(year) {}

    int GetYear() { return n_year; } //поле года обучения.
    void AddYear(int addValue) //следующий год обучения.(добавляем год).
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++; //перемещение по году.(и все это: Определить методы переназначения и увеличения этого значения).
    }
    void Print() //команда для вывода на экран определенную подноготную нашего кода. в данном случае год выводим.(КОМАНДА ВЫВОДИТ НА ЭКРАН).(примечание: текст).
    {
        cout << n_year << ' ';
        Person::Print();
    }
};

/*HOMEWORK2
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет).
Добавить новый класс GrannySmith, который наследует класс Apple.
*/
class Fruit
{
public:
    string name;
    string color;

    Fruit(string name, string color) : name(name), color(color) {}
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
};

class Banana : public Fruit
{
public:
    Banana(string name = "Banana", string color = "Yellow") : Fruit(name, color) {}

};

class Apple : public Fruit
{
public:
    Apple(string name = "Apple", string color = "Red") : Fruit(name, color) {}

};

class GrannySmith : public Apple
{
public:
    GrannySmith(string name = "Granny Smith", string color = "Green") : Apple(name, color) {}
};


/*HOMEWORK3
Изучить правила игры в Blackjack.
Подумать, как написать данную игру на С++,
используя объектно-ориентированное программирование.
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
Продумать реализацию игры с помощью классов и записать результаты.
*/
void Blackjack()
{
    cout << "\nСоздаем классы: Dealer, Player, Hands(Руки), Deck(Колода), Deckpile(Раздача карт).";
    cout << "\nDealer, Player классы базовые, остальные производные.";
}




int Person::count = 0;
int main()
{
    setlocale(LC_ALL, "Rus");
    {
        //HOMEWORK1
        obzac();

        auto student1 = new Student(6, "Smith", 24, "male", 60);
        auto student2 = new Student(4, "Oleg", 25, "female", 63);
        auto student3 = new Student(4, "Dmitry", 25, "male", 70);
        auto student4 = new Student(1, "Danya", 15, "female", 56);
        auto student5 = new Student(2, "Volodya", 36, "male", 53.300);
        student1->Print();
        student2->Print();
        student3->Print();
        student4->Print();
        student5->Print();
        delete student1;
        delete student2;
        delete student3;
        delete student4;
        delete student5;


        obzac1();
    }

    {
        //HOMEWORK2
        obzac();
        Apple a("red");
        Banana b;
        GrannySmith c;

        cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


        obzac1();
    }

    {
        //HOMEWORK3
        obzac();
        Blackjack();
        obzac1();
    }

    return 0;
};