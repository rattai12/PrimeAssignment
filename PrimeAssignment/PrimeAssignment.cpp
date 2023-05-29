#include <iostream>
/*
#include <chrono>
#include <thread>
#include <functional>
using namespace std;
using namespace std::chrono;


int counter = 0; // global variabel s� den kan anv�ndas b�de i och utanf�r funktioner. 
bool isPrime(int num) // funktionen som kollar ifall ett tal �r primtal
{

    bool prime = true; // standardv�rdet s�tter jag som true. S� ska funktionen motbevisa ifall det inte �r ett primtal.

    if (num == 0 || num == 1) { // om talet �r 0 eller 1 �r det falskt d� det inte �r primtal. 
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) { 
        if (num % i == 0) {
            prime = false; // icke ett primtal. 
            break;

        }
    }
    return prime; // har talet n�tt �nda hit s� �r det ett primtal
}


void seriellt(int st, int ed)
{       
for (st; st <= ed; st++) {
    if (isPrime(st) == true) {
        counter++;
    }
    else(isPrime(st) == false);
    {
        continue;
    }
}

}

int main()
{
    double tot_tid = 0;
    int i = 0;
    for (i; i < 5; i++) {
        auto t0 = steady_clock::now();
        thread t1(seriellt, 0, 200000);
        thread t2(seriellt, 200001, 400000);
        thread t3(seriellt, 400001, 600000);
        thread t4(seriellt, 6000001, 8000000);
        thread t5(seriellt, 8000001, 1000000);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
         t5.join();



        duration<double> duration_sec = steady_clock::now() - t0;
        cout << "Number of primes found: " << counter << endl;
        cout << "Time: " << duration_sec.count() << " sec" << endl;
        cout << endl;

        tot_tid = tot_tid + duration_sec.count();
        counter = 0;
    }
    cout << tot_tid/i;
}



// int first; int last;



   // cout << "Ange startnummer: ";
    //cin >> first;
    //cout << "Ange slutnummer: ";
   // thread my_thread(seriellt, first, last); // skapar en tr�d som k�r programmet. Dock k�rs allt endast p� 1 tr�d atm. 
    //cin >> last;
   // seriellt(first, last);

    //my_thread.join(); // kanske kan g�ra en for loop f�r att dela upp siffrorna mellan olika tr�dar. 
    */

/*
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
using namespace std;
using namespace std::chrono;


int counter = 0;// global variabel s� den kan anv�ndas b�de i och utanf�r funktioner.
bool isPrime(int num) // funktionen som kollar ifall ett tal �r primtal
{

    bool prime = true; // standardv�rdet s�tter jag som true. S� ska funktionen motbevisa ifall det inte �r ett primtal.

    if (num == 0 || num == 1) { // om talet �r 0 eller 1 �r det falskt d� det inte �r primtal.
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            prime = false; // icke ett primtal.
            break;

        }
    }
    return prime; // har talet n�tt �nda hit s� �r det ett primtal
}


void seriellt(int st, int ed)
{
    for (st; st <= ed; st++) {
        if (isPrime(st) == true) {
            counter++;
        }
        else(isPrime(st) == false);
        {
            continue;
        }
    }
   // cout << counter << endl;

}

int main()
{
    double tot_tid = 0;
    int i = 0;
    for (i; i < 5; i++) {
        auto t0 = steady_clock::now();
        thread t1(seriellt, 0, 62500);
        thread t2(seriellt, 62501, 125000);
        thread t3(seriellt, 125001, 187500);
        thread t4(seriellt, 187501, 250000);
        thread t5(seriellt, 250001, 312500);
        thread t6(seriellt, 312501, 375000);
        thread t7(seriellt, 375001, 437500);
        thread t8(seriellt, 437501, 500000);
        thread t9(seriellt, 500001, 562500);
        thread t10(seriellt, 562501, 625000);
        thread t11(seriellt, 625001, 687500);
        thread t12(seriellt, 687501, 750000);
        thread t13(seriellt, 750001, 812500);
        thread t14(seriellt, 812501, 875000);
        thread t15(seriellt, 875001, 937500);
        thread t16(seriellt, 937501, 1000000);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
        t9.join();
        t10.join();
        t11.join();
        t12.join();
        t13.join();
        t14.join();
        t15.join();
        t16.join();

        duration<double> duration_sec = steady_clock::now() - t0;
        cout << "Number of primes found: " << counter << endl;
        cout << "Time: " << duration_sec.count() << " sec" << endl;
        cout << endl;

        tot_tid = tot_tid + duration_sec.count();
        counter = 0;
    }

    cout << tot_tid / i;
}




*/

/*
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::chrono;

bool is_prime(int n)
{
    if (n < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void seriellt(int start, int end, int& counter)
{
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            counter++;
        }
    }
}

int main()
{
    int num_threads;
    cout << "Enter the number of threads: ";
    cin >> num_threads;

    int counter = 0;
    double tot_tid = 0;
    int i = 0;
    for (i; i < 5; i++) {
        auto t0 = steady_clock::now();

        vector<thread> threads;
        int range = 10000000 / num_threads;
        int start = 0;
        int end = range;

        for (int j = 0; j < num_threads; j++) {
            threads.emplace_back(seriellt, start, end, ref(counter));
            start = end + 1;
            end += range;
            if (end > 10000000) {
                end = 10000000;
            }
        }

        for (auto& t : threads) {
            t.join();
        }

        duration<double> duration_sec = steady_clock::now() - t0;
        cout << "Number of primes found: " << counter << endl;
        cout << "Time: " << duration_sec.count() << " sec" << endl;
        cout << endl;

        tot_tid += duration_sec.count();
        counter = 0;
    }

    cout << "Average time taken: " << tot_tid / i << " sec" << endl;
}



*/