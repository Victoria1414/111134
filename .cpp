#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

//  алгоритм Евкліда
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    if (b == 0)
        
     return {a, 1, 0};
    
    auto [g, x1, y1] = extended_gcd(b, a % b);
     long long x = y1;
      long long y = x1 - (a / b) * y1;
    
       return {g, x, y};
}

int main() {
    int t;
     cin >> t;
    
    vector<pair<long long, long long>> tests(t);
    
    for (int i = 0; i < t; ++i) {
      cin >> tests[i].first >> tests[i].second;
    }

    for (auto [a, b] : tests) {
      if (a == 0 && b == 0) {
        cout << "No Solution" << endl;
         continue;
        }
        
        if (a == 0) {
          if (b == 1) {
            cout << "0 1" << endl;
            } else {
            cout << "No Solution" << endl;
            }
             continue;
        }
        
        if (b == 0) {
          if (a == 1) {
            cout << "1 0" << endl;
            } else {
            cout << "No Solution" << endl;
            }
             continue;
        }

        auto [g, x, y] = extended_gcd(a, b);
        
        if (g != 1) {
          cout << "No Solution" << endl;
        } else {
            // Приводим x до невід'ємного значення
            long long k = (x < 0) ? (-x + b - 1) / b : 0;
            x += k * b;
            y -= k * a;

            if (x < 0) {
              cout << "No Solution" << endl;
              } else {
              cout << x << " " << y << endl;
            }
        }
    }

    return 0;
}
