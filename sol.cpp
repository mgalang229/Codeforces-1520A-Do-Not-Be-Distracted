#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		string s;
		cin >> n >> s;
		bool suspicious = false;
		for (int i = 0; i < n; i++) {
			// create two checkers: 'first_checker' and 'second_checker'
			bool first_checker = false;
			bool second_checker = false;
			for (int j = i - 1; j >= 0; j--) {
				if (s[i] != s[j]) {
					// the 'first_checker' is to check if a different letter
					// occurs before the appearance of the same letter that 
					// is being currently iterated upon
					first_checker = true;
				} else if (s[i] == s[j] && first_checker) {
					// the 'second_checker' is to check if the current letter
					// appeared already previously with the fact that a different
					// letter occurred after that letter
					second_checker = true;
					break;
				}
			}
			if (second_checker) {
				suspicious = true;
				break;
			}
		}
		cout << (!suspicious ? "YES" : "NO") << '\n';
	}
	return 0;
}
