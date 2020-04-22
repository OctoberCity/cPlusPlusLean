#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writefile()
{
    ofstream ofs;
    ofs.open("./hjw.txt", ios::out);
    ofs << "护甲问呢" << endl;
    ofs << "护甲问呢你" << endl;
    ofs.close();
}
void readfile()
{
    ifstream ifs;
    ifs.open("./hjw.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    char buf[1024] = {0};
    // while (ifs>>buf)
    // {
    //    cout<<buf<<endl;
    // }

    // while (ifs.getline(buf,sizeof(buf)))
    // {
    //    cout<<buf<<endl;
    // }
    // string str ;
    // while (getline(ifs, str))
    // {
    //     cout << str << endl;
    // }

    char chr;
    while ((chr = ifs.get()) != EOF)
    {
        cout << chr ;
    }

    ifs.close();
}

int main()
{
    writefile();
    readfile();
}

// 写入文件==》out to file
