/*
1. Создать шаблонную функцию, которая принимает итераторы на начало и конец
последовательности слов, и выводящую в консоль список уникальных слов (если слово
повторяется больше 1 раза, то вывести его надо один раз). Продемонстрировать работу
функции, передав итераторы различных типов.
2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные
введенные пользователем из стандартного потока ввода и разбивать их на предложения.
Далее программа должна вывести пользователю все предложения, а также количество слов в
них, отсортировав предложения по количеству слов.
*/
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <queue>

#include <cctype>
using namespace std;

//Task #1
template<typename IT>
void print(IT it, IT end)
{
    set<string> words(it, end);
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, "; "));
}

void task1()
{
    vector<string> task1Vector{ "March", "June", "Saturday", "July", "November", "Friday", "Monday", "Wednesday", "Sunday", "Monday", "Saturday", "September" };
    cout << "Vector:" << endl;
    print(task1Vector.begin(), task1Vector.end());
    cout << "\n" << endl;
    list<string> task1List(task1Vector.begin(), task1Vector.end());
    cout << "List:" << endl;
    print(task1List.begin(), task1List.end());
    cout << "\n" << endl;
    deque<string> task1Deque(task1Vector.begin(), task1Vector.end());
    cout << "Deque:" << endl;
    print(task1Deque.begin(), task1Deque.end());
}

//Task #2


string getSentence(string& s)
{
    string stopMarks{ ".?!" };
    string temp;

    for (const char& c : s)
    {


        temp.push_back(c);
            if (stopMarks.find(c) != string::npos)
            {
                s.erase(0, temp.size());
                if (temp[0] == ' ') { temp.erase(0, 1); }
                return temp;
            }

    }


    return {};
   

}
void task2()
{
    unordered_set<string, hash<string>> sentences;
    string currentString, tempString;
    //int wordCount = 0;
    cout << "Enter your text:" << endl;
    while (getline(cin, currentString))
    {
        if (!currentString.empty())
        {
            tempString += currentString + ' ';

            while (true)
            {

                string sentence(move(getSentence(tempString)));

                if (sentence.empty())
                {
                    break;
                }

                sentences.insert(move(sentence));
            }

        }
        break;
    }

    priority_queue<pair<size_t, string>> queue;
    for (const auto& sentence : sentences)
    {
        queue.push({ sentence.size(), sentence});
    }
    while (!queue.empty())
    {
        cout << "Number of symbols in the sentence: " << queue.top().first << "! Sentence: " << queue.top().second << '\n';
        queue.pop();
    }
}

int main()
{
    //Task #1
    cout << "Task1:" << endl;
    task1();
    cout << "\n" << endl;
    //Task #2
    cout << "Task2:" << endl;
    task2();


    return 0;
}

