#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

char read_name() {
    char n, e;
    cin >> n >> e;
    return n;
}

int read_value(map<char, vector<int>> m) {
    int v;
    char c;
    cin >> c;
    if (isdigit(c)) {
        v = c - '0';
    } else {
        v = m[c].at(0);
    }
    return v;
}

int calc_value(map<char, vector<int>> m) {
    int value = read_value(m);
    char c;
    while (true) {
        int v;
        cin >> c;
        if (c == '+') {
            v = read_value(m);
            value += v;
        } else if (c == '-') {
            v = read_value(m);
            value -= v;
        } else if (c == ';') {
            break;
        }
    }
    return value;
}

string print_int(map<char, vector<int>> m) {
    string ans;
    int v = calc_value(m);
    ans = to_string(v);
    return ans;
}

vector<int> read_vec(map<char, vector<int>> m) {
    vector<int> vec;
    int v;
    char c;
    cin >> c;
    if (c == '[') {
        while (c != ']') {
            v = read_value(m);
            cin >> c;
            vec.push_back(v);
        }
    } else {
        vec = m[c];
    }
    return vec;
}

vector<int> add_vec(vector<int> vec1, vector<int> vec2) {
    vector<int> vec(vec1.size());
    rep(i, 0, vec1.size()) {
        vec.at(i) = vec1.at(i) + vec2.at(i);
    }
    return vec;
}

vector<int> sub_vec(vector<int> vec1, vector<int> vec2) {
    vector<int> vec(vec1.size());
    rep(i, 0, vec1.size()) {
        vec.at(i) = vec1.at(i) - vec2.at(i);
    }
    return vec;
}

vector<int> calc_vec(map<char, vector<int>> m) {
    vector<int> vec = read_vec(m);
    char c;
    while (true) {
        vector<int> v;
        cin >> c;
        if (c == '+') {
            v = read_vec(m);
            vec = add_vec(vec, v);
        } else if (c == '-') {
            v = read_vec(m);
            vec = sub_vec(vec, v);
        } else if (c == ';') {
            break;
        }
    }
    return vec;    
}

string print_vec(map<char, vector<int>> m) {
    string ans;
    vector<int> vec = calc_vec(m);
    ans += "[ ";
    for (int i = 0; i < vec.size(); i++) {
        ans += to_string(vec.at(i)) + " ";
    }
    ans += "]";
    return ans;
}

void print_ans(vector<string> ans) {
    rep(i, 0, ans.size()) {
        cout << ans.at(i) << endl;
    }
}

int main() {
    int N;
    cin >> N;
    map<char, vector<int>> variable;
    vector<string> ans;
    rep(i, 0, N) {
        string s;
        cin >> s;
        if (s == "int") {
            char name = read_name();
            int value = calc_value(variable);
            variable[name] = {value};
        } else if (s == "print_int") {
            ans.push_back(print_int(variable));
        } else if (s == "vec") {
            char name = read_name();
            vector<int> vec = calc_vec(variable);
            variable[name] = vec;
        } else if (s == "print_vec") {
            ans.push_back(print_vec(variable));
        }
    }
    print_ans(ans);
}