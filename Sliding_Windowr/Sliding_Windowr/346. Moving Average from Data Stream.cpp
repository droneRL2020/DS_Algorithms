#include <iostream>
#include <vector>
#include <numeric>   
using namespace std;

class MovingAverage {
public:
    int count = 0;
    double average;
    vector<int> vec;
    int length;
    MovingAverage(int size) 
    {
        vector<int> vec(size);
        length = size;
    }

    double next(int val) {
        int init_sum = 0;
        count += 1;
        if (count <= length) {
            vec.push_back(val);
            double total = accumulate(vec.begin(), vec.end(), init_sum);
            average = total / count;
            return average;
        }
        else{
            int idx;
            if (count % length == 0) {
                idx = length-1;
            }
            else {
                idx = count % length - 1;
            }
            vec[idx] = val;
            double total = accumulate(vec.begin(), vec.end(), init_sum);
            average = total / length;
            return average;
        }
    }
};

int main() {
    MovingAverage* m = new MovingAverage(5);
    cout << m->next(12009);
    cout << m->next(1965);
    cout << m->next(-940);
    cout << m->next(-8516);
    cout << m->next(-16446);
    cout << m->next(7870);

    cout << m->next(25545);
    cout << m->next(-21028);
    cout << m->next(18430);
    cout << m->next(-23464);

    return 0;
}