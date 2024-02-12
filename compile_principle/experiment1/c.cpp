#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

enum TokenType {
    ID,
    NUM,
//    KEYWORD
    KEYWORD,
    VOID,
    IF,
    ELSE,
    WHILE,
    FOR,
    DO,
    INT, FLOAT, DOUBLE, STRING,
    GOTO,
    CIN, COUT,
    SWITCH,
    BREAK,
    MAIN,
    USING, NAMESPACE, IOSTREAM, STD,
    RETURN,
    INCLUDE,
    ENDL,
    THEN,
    REPEAT,
    UNTIL,
    FROM, TO, STEP,
    OF, CASE, DEFAULT,
    INTEGER, REAL, CHAR, BOOL,
    AND, OR, _NOT, MOD,
    READ, WRITE,

//    OPERATOR
    OPERATOR,
    EQUAL,
    PLUS,
    MINUS,
    MUL,
    DIV,
    SMALL,
    BIG,
    NOT_SMALL,
    NOT_BIG,
    IN,
    OUT,
    NOT,
    NOT_EQUAL,

//    DELIMITER
    DELIMITER,
    COMMA, //,
    SEMICOLON, //;
    COLCOLONS, //:
    BRACES_L, //{
    BRACES_R, //}
    BRACKETS_L, //[
    BRACKETS_R, //]
    PARENTHESS_L, //(
    PARENTHESS_R, //)
    HEADER_BIG //#include<map>的这个‘>’
};

// 利用这个数组和函数，判断得到的字母（字母数字）串是不是关键字
// 其中的顺序需要和上面定义的TokenType中的关键字顺序一致，这样可以利用设置的标签KEYWORD+1+遍历序号，找到起对应的值
vector<string> keywords = {"void", "if", "else", "while", "for", "do",
                           "int", "float", "double", "string", "goto",
                           "cin", "cout", "switch", "break", "main",
                           "using", "namespace", "iostream", "std", "return",
                           "include", "endl", "then", "repeat", "until",
                           "from", "to", "step", "of", "case",
                           "default", "integer", "real", "char", "bool",
                           "and", "or", "not", "mod", "read", "write",};

int is_keyword(string token) {
    for (int i = 0; i < keywords.size(); i++) {
        if (keywords[i] == token)
            return KEYWORD + 1 + i;
    }
    return -1;
}

// 判断当前字符是否为分隔符
int is_delimiter(char c) {
    switch (c) {
        case ',':
            return COMMA;
        case ';':
            return SEMICOLON;
        case ':':
            return COLCOLONS;
        case '{':
            return BRACES_L;
        case '}':
            return BRACES_R;
        case '[':
            return BRACKETS_L;
        case ']':
            return BRACKETS_R;
        case '(':
            return PARENTHESS_L;
        case ')':
            return PARENTHESS_R;
        default:
            return -1;
    }
}

// 判断当前字符是否为运算符，
// 这里需要注意的是如果某个字符既是运算符，又是某个运算符的前缀，应把它放在了自动机里去判断
int is_operator(char c) {
    switch (c) {
        case '=':
            return EQUAL;
        case '+':
            return PLUS;
        case '-':
            return MINUS;
        case '*':
            return MUL;
        case '/':
            return DIV;
        default:
            return -1;
    }
}


void lexicalAnalysis(const string &sourceCode) {
    string token;
    int state = 0;

    for (char c: sourceCode) {
        // 在这里加了这个，是为了方便会退，比如遇到标识符结束了，但是这个字符还没有被分析，则处理完token之后跳回这里
        current_char_loop:
        switch (state) {
            case 0:
                if (isalpha(c)) {
                    token += c;
                    state = 1;
                } else if (isdigit(c)) {
                    token += c;
                    state = 3;
                } else if (is_delimiter(c) != -1) {
                    cout << "(" << is_delimiter(c) << ",-)" << endl;
                } else if (is_operator(c) != -1) {
                    cout << "(" << is_operator(c) << ",-)" << endl;
                } else if (c == '<') {
                    token += c;
                    state = 10;
                } else if (c == '>') {
                    token += c;
                    state = 14;
                } else if (c == '!') {
                    token += c;
                    state = 18;
                }
                break;

            case 1:
                if (isalnum(c)) {
                    token += c;
                } else {
                    int iskeyword = is_keyword(token);
                    if (iskeyword != -1) {
                        cout << "(" << iskeyword << ",-)" << endl;
                    } else {
                        cout << "(" << ID << "," << token << ")" << endl;
                    }

                    token.clear();
                    state = 0;
                    goto current_char_loop;  // 继续处理当前字符
                }
                break;

            case 3:
                if (isdigit(c)) {
                    token += c;
                } else {
                    cout << "(" << NUM << "," << bitset<32>(stoi(token)) << ")" << endl;
                    token.clear();
                    state = 0;
                    goto current_char_loop;  // 继续处理当前字符
                }
                break;

            case 10:
                if (c == '=') {
                    cout << "(" << NOT_BIG << ",-)" << endl;
                    token.clear();
                    state = 0;
                } else if (c == '<') {
                    cout << "(" << OUT << ",-)" << endl;
                    token.clear();
                    state = 0;
                } else {
                    cout << "(" << SMALL << ",-)" << endl;
                    token.clear();
                    state = 0;
                    goto current_char_loop;
                }
                break;

            case 14:
                if (c == '=') {
                    cout << "(" << NOT_SMALL << ",-)" << endl;
                    token.clear();
                    state = 0;
                } else if (c == '<') {
                    cout << "(" << IN << ",-)" << endl;
                    token.clear();
                    state = 0;
                } else {
                    cout << "(" << BIG << ",-)" << endl;
                    token.clear();
                    state = 0;
                    goto current_char_loop;
                }
                break;

            case 18:
                if (c == '=') {
                    cout << "(" << NOT_EQUAL << ",-)" << endl;
                    token.clear();
                    state = 0;
                } else {
                    cout << "(" << NOT << ",-)" << endl;
                    token.clear();
                    state = 0;
                    goto current_char_loop;
                }
                break;
        }
    }

    // 最后一个不要忘记处理
    if (!token.empty()) {
        if(token == ">"){
            cout << "(" << HEADER_BIG << ",-)" << endl;
            return;
        }
        int iskeyword = is_keyword(token);
        if (iskeyword != -1) {
            cout << "(" << iskeyword << ",-)" << endl;
        } else {
            cout << "(" << ID << "," << token << ")" << endl;
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