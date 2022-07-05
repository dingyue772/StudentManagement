#include <iostream>
#include "Department.h"
using namespace std;
void Print()
{
    cout << "*************************" << endl;
    cout << "***      " << "1. 增加" << "      ***" << endl;
    cout << "***      " << "2. 删除" << "      ***" << endl;
    cout << "***      " << "3. 查询" << "      ***" << endl;
    cout << "***      " << "4. 修改" << "      ***" << endl;
    cout << "***      " << "5. 清空" << "      ***" << endl;
    cout << "***      " << "6. 退出" << "      ***" << endl;
    cout << "*************************" << endl;
}
int main()
{
    string sp;
    cout << "请输入专业：" << endl;
    cin >> sp;
    Department depart(sp);
    depart.input_fromfile();
    int flag = 0;
    do{
        Print();
        cout << "请输入你想要选择的功能" << endl;
        cin >> flag;
        system("cls");
        switch (flag) {
        case 1:
            cout << "你想要输入几名学生的信息" << endl;
            int count;
            cin >> count;
            system("cls");
            for (int i = 0; i < count; i++) {
                cout << "请输入第" << i + 1 << "名学生的信息" << endl;
                depart.Add();
                //cout << i + 1 << "名学生的信息已成功添加" << endl;
                system("pause");
                system("cls");
            }   
            depart.Sort();
            depart.output_tofile();
            break;
        case 2:
            depart.Delete();
            depart.output_tofile();
            cout << "删除完成" << endl;
            break;
        case 3:
            depart.Check();
            system("pause");
            system("cls");
            break;
        case 4:
            depart.Change();
            depart.output_tofile();
            system("cls");
            break;
        case 5:
            depart.Clear();
            depart.output_tofile();
            system("cls");
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "请输入以上整数以选择功能" << endl;
            break;
        }
    } while (1);
    return 0;
}
