#include <bits/stdc++.h>
using namespace std;
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int t;
	string s;
	cin >> t;
	getchar();
	while (t--) {
		getline(cin, s);
		int len = s.length();
		// transform(s.begin(), s.end(), s.begin(), ::tolower);
		// cout << s << endl;
		if (len < 5) {
			cout << "OMG>.< I don't know!" << endl;
			continue;
		} else {
			string s1 = s.substr(0, 5);
			string s2 = s.substr(len - 5, len);
            
			if (s1 == "miao." && s2 == "lala.")
				cout << "OMG>.< I don't know!" << endl;
            else if (s1 == "miao." && s2 != "lala.")
				cout << "Rainbow's" << endl;
			else if (s2 == "lala." && s1 != "miao.")
				cout << "Freda's" << endl;
			else
				cout << "OMG>.< I don't know!" << endl;
		}
	}

	return 0;
}