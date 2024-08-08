#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    int result = 2 * n;
    for (int offset = -1000; offset <= 1000; offset++) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] < b[j] + offset) {
                merged.push_back(a[i++]);
            } else if (a[i] > b[j] + offset) {
                merged.push_back(b[j++] + offset);
            } else {
                merged.push_back(a[i++]);
                j++;
            }
        }
        while (i < n) merged.push_back(a[i++]);
        while (j < n) merged.push_back(b[j++] + offset);
        
        result = min(result, (int)merged.size());
    }
    
    cout << result << endl;
    return 0;
}