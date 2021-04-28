#include <bits/stdc++.h>
using namespace std;

int track[130];

class Task {
  public:
	char potion;
	int timeNeed;
	int price;
};

class sampleInput {
  public:
	char classmate;
	char potionName;
	int lastTime;
};

bool compare(Task a, Task b) {
	return (a.price / a.timeNeed) > (b.price / b.timeNeed);
}

int main() {
	Task list[] = {
        {'r', 2, 2000},
        {'s', 1, 1000},
        {'t', 1, 4000},
        {'u', 2, 3000},
        {'v', 1, 3000}
    };

	int listSize = 5;
	sort(list, list + listSize, compare);

	// sampleInput input[] = {
	// 	{'a', 'r', 4},
	// 	{'b', 's', 1},
	// 	{'c', 't', 1},
	// 	{'d', 'u', 4},
	// 	{'e', 'v', 3}
    // };

    sampleInput input[] = {
		{'a', 'r', 4},
		{'b', 's', 5},
		{'c', 't', 1},
		{'d', 'u', 4},
    };

	int inputSize = sizeof(input) / sizeof(input[0]);

	// Print the input list

    // for (int i = 0; i < inputSize; i++) {
	// 	cout << input[i].classmate << " " << input[i].potionName << " " << input[i].lastTime << endl;
	// }

	int n = 0;
    for (int i = 0; i < inputSize; i++) {
		n = max(n, input[i].lastTime);
	}

	Task a[n];
	memset(a, -1, sizeof(a));

    for (int i = 0; i < n; i++) {
		a[i].potion = '0';
	}

	for (int i = 0; i < listSize; i++) {
		Task temp = list[i];

		int cnt = 0;
		int deadline;
		for (int j = 0; j < inputSize; j++) {
            if (temp.potion == input[j].potionName) {
				deadline = input[j].lastTime;
			}
		}
		deadline--;

		if (a[deadline].potion == '0') {
			int cnt = 0;
            for (int j = deadline; j >= 0; j--) {
                if (a[j].potion == '0') {
					cnt++;
				}
                if (cnt == temp.timeNeed) {
                    break;
                }
			}
            if (cnt == temp.timeNeed) {
				int x = 0;
				for (int j = deadline; j >= 0; j--) {
                    if (a[j].potion == '0') {
                        a[j] = temp;
                        x++;
                        if (x == cnt) {
                            break;
                        }
                    }
				}
            }
		} else if (a[deadline].potion != '0') {
			bool flag = false;
			for (int j = deadline; j >= 0; j--) {
				if (a[j].potion == '0') {
					int cnt = 0;
					for (int k = j; k >= 0; k--) {
                        if (a[k].potion == '0') {
							cnt++;
						}
                        if (cnt == temp.timeNeed) {
                            break;
                        }
					}
                    if (cnt == temp.timeNeed) {
						int x = 0;
                        for (int k = j; k >= 0; k--) {
                            a[k] = temp;
                            x++;
                            if (x == cnt) {
								flag = true;
								break;
							}
                        }
                    }
				}
                if (flag) {
					break;
				}
			}
		}
	}

	int sum = 0, x = 0;

	for (int i = 0; i < n; i++) {
		if (!track[a[i].potion] && a[i].potion != '0') {
			Task ans = a[i];
			for (int j = 0; j < inputSize; j++) {
                if (a[i].potion == input[j].potionName) {
                    if (x == 0) {
                        cout << input[j].classmate;
						x = 1;
					} else {
						cout << ", " << input[j].classmate;
					}
				}
			}
			sum += a[i].price;
			track[a[i].potion] = 1;
		}
	}
	cout << endl;
	cout << sum << endl;
}
