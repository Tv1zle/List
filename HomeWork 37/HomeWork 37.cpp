#include <iostream>
using namespace std;

struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
    int GetCount();


    void insert(Element *value, int index);
    void removeAt(int index);
    int Search(Element* value, int index);
};

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}


void List::insert(Element *value, int index)
{
    Element* prev = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        prev = prev->Next;
    }

    Element* newElement = new Element;
    newElement->data = index;
    newElement->Next = value;

    prev->Next = newElement;
    Count++;
}


void List::removeAt(int index)
{
    Element* prev = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        prev = prev->Next;
    }

    Element* delElement = prev->Next;
    prev->Next = delElement->Next;
   
    delete delElement;
    Count--;
}

int List::Search(Element* value, int index)
{
    Element* prev = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        if (value->data == prev->data && value->Next == prev->Next)
        {
            return i;
        }
        prev = prev->Next;
    }

    return NULL;
}


void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}

// Тестовый пример
void main()
{
    // Создаем объект класса List
    List lst;

    // Тестовая строка
    char s[] = "Hello, World !!!\n";
    // Выводим строку
    cout << s << "\n\n";
    // Определяем длину строки
    int len = strlen(s);
    // Загоняем строку в список
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    // Распечатываем содержимое списка
    lst.Print();
    // Удаляем три элемента списка
    lst.Del();
    lst.Del();
    lst.Del();
    //Распечатываем содержимое списка
    lst.Print();
}