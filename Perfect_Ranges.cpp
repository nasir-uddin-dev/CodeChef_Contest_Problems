#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(const vector<int>& A, const vector<int>& B, int L, int R) {
    int prev = min(A[L], B[L]);
    for (int i = L + 1; i <= R; ++i) {
        int current = -1;
        if (A[i] > prev) {
            current = A[i];
        }
        if (B[i] > prev && (current == -1 || B[i] < current)) {
            current = B[i];
        }
        if (current == -1) {
            return false;
        }
        prev = current;
    }
    return true;
}

int countPerfectPairs(const vector<int>& A, const vector<int>& B, int N) {
    int count = 0;
    for (int L = 0; L < N; ++L) {
        for (int R = L; R < N; ++R) {
            if (isPerfect(A, B, L, R)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    cout << countPerfectPairs(A, B, N) << endl;
    return 0;
}