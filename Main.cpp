#include <string>
#include <iostream>

using namespace std;

struct Student {
    string Name;
    string Gender;
    string Major;
    long long Phone = 0;//定义一个int时最好赋一个安全值，否则会报警C26495
    string Email;
    int BirthYear = 0;
    int BirthMonth = 0;
    int BirthDay = 0;

    void print() const {
        cout << "Name:" << Name << endl;
        cout << "Gender:" << Gender << endl;
        cout << "Major:" << Major << endl;
        cout << "Phone:" << Phone << endl;
        cout << "Email:" << Email << endl;
        cout << "BirthYear:" << BirthYear << endl;
        cout << "BirthMonth:" << BirthMonth << endl;
        cout << "BirthDay:" << BirthDay << endl;
    }
};

int main() {
    string str;
    struct Student A;
    int now = 0, last = 0;

    cout << "请输入内容：";
    cin >> str;

    for (int section = 0; section < 5; section = (now != 0) ? (section + 1) : 0)  //字符串分为五大段
    {
        last = now;//上次的位置和这次的位置
        now = str.find(',', last + 1);//用,作为分隔符
        if ((now >= 0) || (section == 4)) {
            switch (section) {
                case 0:
                    A.Name = str.substr(last, now - last);//名字在第一大段，长度为now - last
                    break;
                case 1:
                    A.BirthYear = stoi(str.substr((last + 7), 4));//生日、性别在第二大段，长度都是固定的
                    A.BirthMonth = stoi(str.substr((last + 11), 2));
                    A.BirthDay = stoi(str.substr((last + 13), 2));
                    if (stoi(str.substr((last + 17), 1)) % 2 == 0)
                        A.Gender = "Female";
                    else
                        A.Gender = "Male";
                    break;
                case 2:
                    A.Major = str.substr(last + 1, now - last - 1);//专业在第三大段，长度为now - last
                    break;
                case 3:
                    A.Phone = stoll(str.substr(last + 1, 11));//电话在第四大段，共11位，因此使用long long类型
                    break;
                case 4:
                    A.Email = str.substr(last + 1, (str.length() - now));//邮件在第五大段，长度为字符串长度减去现在的位置
                    break;
            }
        } else {
            cout << "错误输入，请重新输入！" << endl;//粗略清除错误格式
            now = last = 0;
            cin >> str;
        }
    }

    A.print();//打印

    return 0;
}
