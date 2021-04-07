#include <bits/stdc++.h>
using namespace std;
#define Niloy
#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
 

void input() {
#ifdef Niloy
    read("input.txt");  
    write("output.txt");
#endif
}

int mt;
bool nt(int g) {
	if (g == 2359) {
		mt = 0;
		return true;
	}
	g++;
	if (g % 100 == 60)
		mt = g + 40;
	else {
		mt = g;
	}
	return true;
}

bool p(int g) {
	string a, revA;
	a = to_string(g);
    revA = a;
	reverse(a.begin(), a.end());

	if (a == revA)
		return true;
	return false;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
    // input();

	int t;
	cin >> t;

	while (t--) {
		int h = 1, m = 1;
		string str;
        cin >> str;
		string a = "", b = "";
		bool flag = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ':') {
				flag = false;
				continue;
			}
            if (flag) {
				a += str[i];
			} else {
				b += str[i];
			}
		}
        h = stoi(a);
		m = stoi(b);
		mt = h * 100 + m;
		if (mt == 2359) {
			cout << "00:00" << endl;
			continue;
		}
		while (nt(mt)) {
			if (p(mt)) {
				m = mt % 100;
				h = mt / 100;
				printf("%02d:%02d\n", h, m);
				break;
			}
		}
	}

	return 0;
}