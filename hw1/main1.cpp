//malloc version
#include <iostream>
#include <limits>
#include <cstdlib> 
#include <cstring> 
using namespace std;

int main() {
  
    int n, m;
  
    cout << "請輸入學生人數n: ";
    cin >> n;
    cout << "請輸入姓名最大長度m: ";
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char** names = (char**)malloc(n * sizeof(char*));
  
    for (int i = 0; i < n; ++i) {
        names[i] = (char*)malloc((m + 1) * sizeof(char)); 
    }

    for (int i = 0; i < n; ++i) {
      
        int ture = 1; 
      
        while (ture) {
            cout << "請輸入第 " << i + 1 << " 位學生的姓名 (長度不超過 " << m << " 個字元): ";
            cin.getline(names[i], m + 1); 

            if (strlen(names[i]) <= m) {
                ture = 0;  
            } else {
                cout << "超出長度，請重新輸入"<<endl;
            }
        }
    }

   
    cout << "輸入的學生姓名如下:";
  
    for (int i = 0; i < n; ++i) {
        cout << "第 " << i + 1 << " 位學生: " << names[i] << endl;
    }

    for(int i =0;i<n;++i){
      free(names[i]);
    }
  free(names);

    return 0;
}
