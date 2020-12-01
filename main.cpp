#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
std::mutex mtx;
int a = 1;
void test() {
//    std::unique_lock<std::mutex> lck(mtx);
    if(a) {
        cout << a << endl;
        a--;
    }
    else
        cout << "nothing" << endl;
}
int main(void){
    std::vector<thread> v;
    int n = 10;
    while(n--)
        v.push_back(thread(test));
    for(auto &i: v)
        i.join();
}
