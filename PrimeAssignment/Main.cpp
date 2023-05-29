#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <atomic>
#include <vector>
using namespace std;
using namespace std::chrono;

atomic<int> counterser= 0;
atomic<int> counter = 0;// global variabel så den kan användas både i och utanför funktioner.
bool isPrime(int num) // funktionen som kollar ifall ett tal är primtal
{

    bool prime = true; // standardvärdet sätter jag som true. Så ska funktionen motbevisa ifall det inte är ett primtal.

    if (num == 0 || num == 1) { // om talet är 0 eller 1 är det falskt då det inte är primtal.
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            prime = false; // icke ett primtal.
            break;

        }
    }
    return prime; // har talet nått ända hit så är det ett primtal
}


void seriellt(int st, int ed)
{
    
    for (st; st <= ed; st++) { 
        counterser++;
        
        if (isPrime(st) == true) {
            counter++; // om det är ett primtal så ökar räknaren med 1
        }
    }
 

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
