#include<iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

enum TokenType {
    KEYWORD,
    OPERATOR,
    DELIMITER,
    ID,
    NUM
};

unordered_map<string, TokenType> keywords = {
        {"if", KEYWORD},
        {"else", KEYWORD},
        {"while", KEYWORD},
        // 其他关键字...
};

unordered_map<char, TokenType> operators = {
        {'=', OPERATOR},
        {'<', OPERATOR},
        {'>', OPERATOR},
        {'+', OPERATOR},
        {'-', OPERATOR},
        {'*', OPERATOR},
        {'/', OPERATOR},
        {'!', OPERATOR}
        // 其他运算符...
};

unordered_map<char, TokenType> delimiters = {
        {',', DELIMITER},
        {';', DELIMITER},
        {':', DELIMITER},
        {'{', DELIMITER},
        {'}', DELIMITER},
        {'[', DELIMITER},
        {']', DELIMITER},
        {'(', DELIMITER},
        {')', DELIMITER}
        // 其他分隔符...
};

TokenType getTokenType(const string& token) {
    if (keywords.count(token)) {
        return keywords[token];
    } else if (token.find_first_not_of("0123456789") == string::npos) {
        return NUM;
    } else {
        return ID;
    }
}

void lexicalAnalysis(const string& sourceCode) {
    string token;
    int state = 0;

    for (char c : sourceCode) {
        current_char_loop:
        switch (state) {
            case 0:
                if (isalpha(c)) {
                    token += c;
                    state = 4;
                } else if (isdigit(c)) {
                    token += c;
                    state = 5;
                } else if (operators.count(c)) {
                    cout << "Operator: " << c << endl;
                } else if (delimiters.count(c)) {
                    cout << "Delimiter: " << c << endl;
                }
                break;
            case 4:
                if (isalnum(c)) {
                    token += c;
                } else {
                    TokenType type = getTokenType(token);
                    if (type == ID) {
                        cout << "ID: " << token << endl;
                    } else {
                        cout << "Keyword: " << token << endl;
                    }
                    token.clear();
                    state = 0;
                    goto current_char_loop;  // 继续处理当前字符
                }
                break;
            case 5:
                if (isdigit(c)) {
                    token += c;
                } else {
                    cout << "NUM: " << token << endl;
                    token.clear();
                    state = 0;
                    goto current_char_loop;  // 继续处理当前字符
                }
                break;
        }
    }

    // 最后一个如果是标识符的话，不要忘记处理
    if (!token.empty()) {
        TokenType type = getTokenType(token);
        if (type == ID) {
            cout << "ID: " << token << endl;
        } else {
            cout << "Keyword: " << token << endl;
        }
    }
}

int main() {
    string filename;
    cout<<"please input the file name: ";
    cin>>filename;
    ifstream fin(filename);
    if (!fin) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        lexicalAnalysis(line);
    }

    fin.close();
    return 0;
}

