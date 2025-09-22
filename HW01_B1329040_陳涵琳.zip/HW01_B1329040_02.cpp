//malloc version
#include <iostream>
#include <limits>
#include <cstdlib> 
#include <cstring> 
using namespace std;

void bubble(char** names, int n) {
    for (int i = 0; i < n - 1; ++i) {
      
        for (int j = 0; j < n - i - 1; ++j) {
          
            int len1 = strlen(names[j]);
            int len2 = strlen(names[j+1]);
          
            if (len1 > 0 && len2 > 0 && names[j][len1 - 1] > names[j + 1][len2 - 1]) {
              
                char temp[101];
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
}


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

    bubble(names,n);
  
    cout << "輸入的學生姓名如下:"<<endl;
  
    for (int i = 0; i < n; ++i) {
        cout << "第 " << i + 1 << " 位學生: " << names[i] << endl;
    }
  
    for(int i =0;i<n;++i){
      free(names[i]);
    }
  free(names);

    return 0;
}
