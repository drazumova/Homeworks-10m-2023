# Homeworks-10m-2023
<<<<<<< refs/remotes/origin/hw2-2-mult
## Домашнее задание 3

1. Напишите программу, создающую три дополнительных потока. Каждый из потоков выводит числа от 1 до 1000000, после каждого числа также выводится id потока. id можно получить с помощью функции `get_id`. \
Посмотрите, перемешиваются ли у вас строчки вывода из разных потоков. Если нет, попробуйте добиться этого с помощью функций `sleep` и `yield`. Кроме того проверьте, очищается ли у вас буфер вывода.
2. Напишите программу, создающую два новых потока. Первый из них занимается тем, что читает числа из входных данных и добавляет их к общей переменной `A`, либо в вектор `vector<int> A`. Второй поток после изменений в `A` выводит новую сумму (необязательно после каждого добавления), изначально сумма считается равной 0.
3. Добавьте в предыдущей задаче `n` потоков, читающих данные из входных данных. Для простоты число `n` задается константой.  

## Заметки с пары

С точки зрения пользователя: \
Процесс — экземпляр программы во время выполнения. \
Потоки — ветви кода, выполняющиеся «параллельно», то есть без предписанного порядка во времени. 

С точки зрения операционной системы процессы разделены по ресурсам, изолированы друг от друга. Потоки же находятся внутри одного процесса и делят все ресурсы, это быстрее и проще в случае использование для единых вычислений.

По сути поток — это просто контейнер, в котором находятся:
* Счётчик команд
* Регистры
* Стек

Использование нескольких потоков в программе позволяет ускорить выполнение и в некоторых случаях упростить код (выделение отдельных задач в отдельные потоки). \
Однако это создает и дополнительные трудности, так как потоки (при отсутствии синхронизации) могут выполняться в любом порядке. Кроме того не все они даже теоретически могут это сделать. Если число потоков больше, чем допустимое на устройстве для параллельного выполнения, планировщик потоков переключается между ними. То есть некоторые потоки находятся в состоянии ожидания, пока работают другие. На эту часть выполнения повлиять невозможно, нужно всегда помнить, что работа потока может быть приостановлена в любой момент в пользу другого. 

### Потоки в C++

Для работы с потока необходима библиотека `thread` \
Отдельный поток создается с помощью класса `std::thread` . Новый поток запускается сразу после создания объекта. При создании в качестве аргумента конструктора передается функция, которая и будет выполняться в отдельном потоке. \
`std::thread my_thread(do_some_work);` \
Если в функцию требуется передать аргументы, это можно сделать так же \
``
void f(int i, int j);
std::thread my_thread(f, 3, 4);
``

В качестве исполняемой функции для потока можно передать любой вызывающийся объект. Например, класс с определенным оператором `()` или лямбда функцию.

#### Лямбды
Также мы кратко обсудили лямбда выражения, про них можно почитать [тут](https://learn.microsoft.com/ru-ru/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

Результат выполнения функции игнорируется, так что если он нужен, возвращаемое значение требуется сохранить в глобальные переменные.

Потоки нельзя копировать. 

Чтобы дождаться завершения работы потока используется функция `join`. После завершения работы объект очищается, то есть невозможно вызвать `join` больше одного раза. Для проверки возможности ожидания существует метод `joinable()`.

Если же поток выполняет фоновую задачу и его выполнение может продолжаться в течении всей жизни программы, необходимо вызвать метод `detach`. Однако открепить поток тоже можно только в случае, если есть откуда, то есть метод `joinable` возвращает `true`.

После создания потока нужно выбрать один из вышеперечисленных вариантов его существования. Если этого не произошло, то на моменте уничтожения объект вызовется `terminate`, то есть программа аварийно завершится.

При редактировании одних и тех же данных в нескольких потоках легко получить коллизии. 

### Проблемы при использовании параллельных вычислений

**Состояние гонки (race condition)** -- это ситуация в которой два поток одновременно редактируют данные, и результат будет зависеть от того, в каком порядке они выполнятся.

Пример получения гонки, для гарантии прерывания увеличим количество изменений. В случае корректной работы программы мы увидим 2000000 после завершения работы потоков. 
``
int main()
{
    unsigned long long cnt = 0;

    std::thread t1([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            ++cnt;
    });
    
    std::thread t2([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            ++cnt;
    });
    
    t1.join();
    t2.join();
    
    std::cout << cnt;

    return 0;
}
``

Рассмотрим простой пример, в котором два потока сначала считывают, а потом записывают в переменную новое значение на основе старого. То есть по сути каждый из потоков состоит из шагов 
1. `read`
2. `write`

В идеале сначала выполнится первый поток, то есть `read_1`, `write_1`, а потом второй `read_2`, `write_2`. Но вполне возможна ситуация, в которой первый поток прервет выполнение и мы получим порядок `read_1, read_2, write_1, write_2` или `read_1, read_2, write_2, write_1`. В обоих случаях часть изменений теряется. Это можно исправить двумя способами

1. mutex -- блокировка, которая может быть взята только одним потоком. Примитивы синхронизации могут быть и более сложными, но пока рассмотрим только обычный мютекс.
Для того чтобы взять блокировку используется метод `lock`, чтобы отдать `unlock`. \
Классы лежат в библиотеке `mutex`


``
int main()
{
    unsigned long long cnt = 0;
    std::mutex cnt_mutex;

    std::thread t1([&]()
    {
        for(auto i = 0; i < 1000000; ++i) {
            cnt_mutex.lock();
            cnt += 1;
            cnt_mutex.unlock();
        }
    });
    
    std::thread t2([&]()
    {
        for(auto i = 0; i < 1000000; ++i) {
            cnt_mutex.lock();
            cnt += 1;
            cnt_mutex.unlock();
        }
    });
    
    t1.join();
    t2.join();
    
    std::cout << cnt;

    return 0;
}
``

Полезной может быть обертка над взятием блокировки `std::lock_guard`, автоматически освобождающая блокировку при удалении объекта. При создании в нее передается сам мютекс `const std::lock_guard<std::mutex> lock(g_i_mutex);`

2. atomic . Атомарными называют операции, которые невозможно застать в промежуточном состоянии, то есть гарантируется, что при прерывании потока операция завершилась. В примере выше оператор ++ делает два шага, которые потенциально могут быть разделены прерыванием. \
    В C++ есть возможность создания атомик переменных с набором простых операций. `std::atomic<int>` . Чтобы записать значение используется метод `store`, чтобы получить -- `load`. `fetch_add` увеличивает значение и обновляет его, аналогичные методы есть и для других бинарных операций. Того же эффекта можно достичь используя обычные операторы арифметических операций. 
Пример использования, не забудьте подключить библиотеку `atomic`

`` 
#include <iostream>
#include <thread>
#include <atomic>

int main()
{
    std::atomic<unsigned long long> cnt = 0;

    std::thread t1([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            cnt.fetch_add(1);
    });
    
    std::thread t2([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            cnt.fetch_add(1);
    });
    
    t1.join();
    t2.join();
    
    std::cout << cnt;

    return 0;
}
``

Полезна может быть функция yield, позволяющая подсказать приостановить этот поток и переключиться на другой, но никаких гарантий на использование подсказки нет. Также существует функция `sleep_for(<time_>milliseconds)` позволяющая потоку явно заснуть на указанное время. Обе функции работают для текущего потока, то есть вызываются в коде как `std::this_thread::yield()`.

**Deadlock** -- состояние пробки, в котором два или несколько потоков ожидают взятия блокировки другого. 

Пример

`` 
#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>

int main()
{
    std::mutex m1;
    std::mutex m2;
    
    auto f1 = [&m1, &m2]() {
        std::lock_guard<std::mutex> lg1(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m2);
    };
    
    auto f2 = [&m1, &m2]() {
        std::lock_guard<std::mutex> lg1(m2);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m1);
    };
    
    std::thread thread1([&f1, &f2]() {
        f1();
    });
    
    std::thread thread2([&f1, &f2]() {
        f2();
    });
    
    thread1.join();
    thread2.join();

    return 0;
} 
``

Классический способ борьбы с такими ситуациями -- взятие мютексов в одинаковом порядке, то есть для взятия мютекса также понадобится взять и все предыдущие. \
Можно также посмотреть на `std::scoped_lock` это улучшенная версия `lock_guard`, позволяющая брать несколько мютексов со встроенным алгоритмом для избежания дедлоков. Однако 100% гарантий, конечно, получить нельзя 
=======
Базовый репозиторий для домашних заданий 10м

1. Первое домашнее задание и заметки в ветке `hw-1-git` срок сдачи 28.01
>>>>>>> Update README.md
