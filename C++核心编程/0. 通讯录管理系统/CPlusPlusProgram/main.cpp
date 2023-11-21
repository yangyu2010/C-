//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//  https://github.com/Blitzer207/C-Resource/blob/master/README.md

#include <iostream>
#include <string>
using namespace std;


struct Person {
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

const int MAX_PERSON_COUNT = 1000;

struct AddressBooks {
    struct Person personArray[MAX_PERSON_COUNT];
    int size;
};



void addPerson(AddressBooks *books) {
    if (books->size >= MAX_PERSON_COUNT) {
        cout << "通讯录已满, 无法添加" << endl;
        return;
    }
    
    string name;
    cout << "请输入姓名: " << endl;
    cin >> name;
    books->personArray[books->size].name = name;

    cout << "请输入性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;

    //性别
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            books->personArray[books->size].sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    //年龄
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    books->personArray[books->size].age = age;

    //联系电话
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    books->personArray[books->size].phone = phone;

    //家庭住址
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    books->personArray[books->size].address = address;

    //更新通讯录人数
    books->size++;

    cout << "添加成功\n" << endl;
}


void showPerson(AddressBooks *books) {
    if (books->size == 0) {
        cout << "当前记录为空\n" << endl;
        return;
    }
    for (int i = 0; i < books->size; i++) {
        cout << "姓名:" << books->personArray[i].name << "\t";
        cout << "性别:" << (books->personArray[i].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄:" << books->personArray[i].age << "\t";
        cout << "电话:" << books->personArray[i].phone << "\t";
        cout << "住址:" << books->personArray[i].address << endl;
    }
}



//3、删除指定联系人信息

//判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
int isExist(AddressBooks *books, string name)
{
    for (int i = 0; i < books->size; i++)
    {
        if (books->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}


void deletePerson(AddressBooks *books) {
    cout << "请输入您要删除的联系人的姓名" << endl;
    string name;
    cin >> name;

    int ret = isExist(books, name);
    if (ret != -1)
    {
        for (int i = ret; i < books->size; i++)
        {
            books->personArray[i] = books->personArray[i + 1];
        }
        books->size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

}



//查找联系人
void findPerson(AddressBooks *books) {
    cout << "请输入您要查找的联系人的姓名" << endl;
    string name;
    cin >> name;

    int ret = isExist(books, name);
    if (ret != -1)
    {
        cout << "姓名:" << books->personArray[ret].name << "\t";
        cout << "性别:" << (books->personArray[ret].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄:" << books->personArray[ret].age << "\t";
        cout << "电话:" << books->personArray[ret].phone << "\t";
        cout << "住址:" << books->personArray[ret].address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

}




// 修改联系人
void modifyPerson(AddressBooks *books) {
    cout << "请输入您要修改的联系人的姓名" << endl;
    string find_name;
    cin >> find_name;
    
    int ret = isExist(books, find_name);
    if (ret == -1) {
        cout << "查无此人" << endl;
        return;
    }
    
    //姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    books->personArray[ret].name = name;

    //性别
    cout << "请输入性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;

    //性别
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            books->personArray[ret].sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    //年龄
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    books->personArray[ret].age = age;

    //联系电话
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    books->personArray[ret].phone = phone;

    //家庭住址
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    books->personArray[ret].address = address;

    cout << "修改成功" << endl;

}


//6、清空所有联系人
void cleanPerson(AddressBooks *books) {
    books->size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}






void showMenu() {
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}




int main() {
    
    AddressBooks books;
    books.size = 0;
    
    int select = 0;
    
    while (true) {
        showMenu();
        
        cin >> select;
        
        switch (select) {
            case 1:  //添加联系人
                addPerson(&books);
                break;
            case 2:  //显示联系人
                showPerson(&books);
                break;
            case 3:  //删除联系人
                deletePerson(&books);
                break;
            case 4:  //查找联系人
                findPerson(&books);
                break;
            case 5:  //修改联系人
                modifyPerson(&books);
                break;
            case 6:  //清空联系人
                cleanPerson(&books);
                break;
            case 0:  //退出通讯录
                cout << "欢迎下次使用" << endl;
                return EXIT_SUCCESS;
            default:
                break;
        }
    }
    
    return EXIT_SUCCESS;
}

