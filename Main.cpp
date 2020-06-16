#include <string>
#include <iostream>

using namespace std;

struct Student {
    string Name;
    string Gender;
    string Major;
    long long Phone = 0;//����һ��intʱ��ø�һ����ȫֵ������ᱨ��C26495
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

    cout << "���������ݣ�";
    cin >> str;

    for (int section = 0; section < 5; section = (now != 0) ? (section + 1) : 0)  //�ַ�����Ϊ����
    {
        last = now;//�ϴε�λ�ú���ε�λ��
        now = str.find(',', last + 1);//��,��Ϊ�ָ���
        if ((now >= 0) || (section == 4)) {
            switch (section) {
                case 0:
                    A.Name = str.substr(last, now - last);//�����ڵ�һ��Σ�����Ϊnow - last
                    break;
                case 1:
                    A.BirthYear = stoi(str.substr((last + 7), 4));//���ա��Ա��ڵڶ���Σ����ȶ��ǹ̶���
                    A.BirthMonth = stoi(str.substr((last + 11), 2));
                    A.BirthDay = stoi(str.substr((last + 13), 2));
                    if (stoi(str.substr((last + 17), 1)) % 2 == 0)
                        A.Gender = "Female";
                    else
                        A.Gender = "Male";
                    break;
                case 2:
                    A.Major = str.substr(last + 1, now - last - 1);//רҵ�ڵ�����Σ�����Ϊnow - last
                    break;
                case 3:
                    A.Phone = stoll(str.substr(last + 1, 11));//�绰�ڵ��Ĵ�Σ���11λ�����ʹ��long long����
                    break;
                case 4:
                    A.Email = str.substr(last + 1, (str.length() - now));//�ʼ��ڵ����Σ�����Ϊ�ַ������ȼ�ȥ���ڵ�λ��
                    break;
            }
        } else {
            cout << "�������룬���������룡" << endl;//������������ʽ
            now = last = 0;
            cin >> str;
        }
    }

    A.print();//��ӡ

    return 0;
}
