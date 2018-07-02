#include <iostream>
#include <vector>

using namespace std;



int main() {
    long long n;
    cin >> n;
    vector<bool> prime(1e6 + 5, true);
    prime[1] = false;
    prime[0] = false;
    long long ans = 0;
    int curr = 1;
    for (long long i = 0; i < prime.size(); ++i) {
        if (prime[i]) {
            int temp = 0;
            while(n % i == 0) {
                n = n / i;
                temp++;
            }
            if (temp % 2 == 1) {
                ans = ans xor curr;
            }
            curr++;
            for (long long j = i * 1ll *  i; j < prime.size(); j += i) {
                prime[j] = false;
            }
        }
    }

    if (n == 1) {
        if (ans == 0) {
            cout << "Vasya";
        } else {
            cout << "David";
        }
    } else {
        cout << "David";
    }

    return 0;
}