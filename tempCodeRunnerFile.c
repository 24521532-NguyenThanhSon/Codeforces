#include <iostream>
#include <cstring>
using namespace std;
#define MAX 300
int myStrlen(char s[], int k) {
    int length = 0;
    for (int i = k; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}
int myStrcmp(char s1[], char s2[]) {
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);
    
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    }

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i]) return 1;
        else if (s1[i] < s2[i]) return -1;
    }
    return 0;
}
void myStrcpy(char s[], int vt, char s1[], int k) {
    for (int i = 0; i < k; i++) {
        s[vt + i] = s1[i];
    }
    s[vt + k] = '\0'; 
}
void StringReverse(char st[]) {
    char result[300];
    int count = 0;
    char* word[300]; 
    int wordcount = 0;
    char* token = strtok(st, " ");
    while (token != nullptr) {
        word[wordcount] = token;
        wordcount++;
        token = strtok(nullptr, " ");
    }
    for (int i = wordcount - 1; i >= 0; i--) {
        int j = 0;
        while (word[i][j] != '\0') {
            result[count++] = word[i][j++];
        }
        if (i > 0) {
            result[count++] = ' '; 
        }
    }
    result[count] = '\0';
    myStrcpy(st, 0, result, count);
}

int main() {
    char s[MAX];
    cin.getline(s, MAX);  // Đọc chuỗi từ người dùng

    // Kiểm tra nếu chuỗi rỗng
    if (myStrcmp(s, "") == 0) {
        cout << "Chuoi rong." << endl;
    } else {
        // Đảo ngược chuỗi theo từng từ
        StringReverse(s);
        cout << s << endl;  // In chuỗi đã đảo ngược
    }

    return 0;
}