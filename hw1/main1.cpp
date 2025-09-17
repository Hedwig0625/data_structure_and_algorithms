//Part 1: 使用者可輸入學生人數n及姓名長度m
//使用new和malloc兩種方式建立二維動態陣列
//兩種動態宣告方式都要實作 (沒用動態陣列，最多僅能得15分)
//讓使用者輸入n個學生的姓名 (長度不可以超過m個字元)
//將學生姓名存入動態二維字元陣列

#include <iostream>
#include <limits>
using namespace std;

int main(){
    int n, m;
    cout << "請輸入學生人數n: ";
    cin >> n;
    cout << "請輸入姓名最大長度m: ";
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    //丟掉前一次cin留下的換行字元
    //cin.ignore(最多忽略的字元數, 遇到這個字元就停止忽略)
    //numeric_limits<streamsize>::max():代表「一個非常大的數字」，通常比緩衝區還大，確保能丟棄所有殘留字元
    //'\n',指遇到換行就停止

    string* names= new string[n];

    
    for (int i = 0; i < n; ++i) {
      
    int ture =1;
      
     while(ture){
        cout <<"請輸入 第" << i+1 << "位學生的姓名 (長度不超過 " << m << " 個字元):" <<endl;
        getline(cin,names[i]);
        
        if(names[i].length() <= m){
          ture=0;
        }else{
          cout<<"超出長度，請重新輸入"<<endl;
        }
    }
    }

    cout << "輸入的學生姓名如下:"<<endl;
      
    for (int i = 0; i < n; ++i) {
        cout << "第 " << i + 1 << " 位學生: " << names[i] << endl;
    }

    delete[] names;
}
