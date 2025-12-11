#include <iostream>
using namespace std;

class chain;

//nodes
class node{
    friend class chain;
    
private:
    int coef;
    int Exp;
    node *link;
    
public:
    node (int a = 0,int b = 0,node *next =0 ){
        coef=a;
        Exp=b;
        link = next;
    }
    
    //get something
    int getExp() const { return Exp; }
    
    int getCoef() const { return coef; }
    
    node* getLink() const { return link; }
    
    void setCoef(int c) { coef = c; }

};

//chain
class chain{
private:
    node *first;

public:
    int terms;
    
    chain() {
        first = NULL;
        terms=0;
    }
    
    //push(插入最前面)
    void push(int coef,int Exp){
        
        node *newnode = new node(coef,Exp);
    
        if(first == NULL){
            first = newnode;
            
        }else{
            
            node *currently = first;
            
            while(currently->link != NULL){
                currently = currently->link;
            }
            
            currently->link = newnode;
        }
        
        this->terms++;
    
    }
    
    //print
    void print(){
        
        node *currently = first;
        
        if(currently == NULL){
            cout <<"Empty!"<<endl;
            return;
        }
        
        bool firstprinted= false;
        
        while(currently !=NULL){
        
            if(currently->coef != 0){
                
                if(firstprinted){
                    cout<<"+";
                }
                cout<<currently->coef;

                if(currently->Exp != 0){
                    cout<<"x^"<<currently->Exp;
                }
                
                firstprinted =true;
                
            }
            
            currently= currently->link;
        }    
        
        if (!firstprinted){
            cout << "0";
        }
        cout<<endl;
        
    }    
    
    //get first
    node* get_first(){return first;}
    
    //add term(中間插入)
    void addTerm(int coef, int Exp) {
        node* cur = first;
        node* prev = nullptr;
        
        // 次方大->小
        while (cur && cur->Exp > Exp) {  
            prev = cur;
            cur = cur->link;
        }
        
        if (cur && cur->Exp == Exp) {
            cur->coef += coef;  // 同次方累加
            
        } else {
            node* newnode = new node(coef, Exp);
            
            if (!prev) {  // 插入到最前面
            
                newnode->link = first;
                first = newnode;
                
            } else {
                
                newnode->link = prev->link;
                prev->link = newnode;
                
            }
        }
    }
    
};

//a poly into a chain(dense)
void into_poly(chain &poly,char name){
    
    int term;
    int top_exp;
    
    cout<<"Poly '"<< name <<"' :"<<endl;
    
    //term
    cout<<"plz enter the number of term:";
    cin >> term;
    
    while(term <=0 ||cin.fail()){
        cin.clear();
        cin.ignore(10000000,'\n');
        
        cout<<"Error,plz try again:";
        cin >> term;
    }
    
    poly.terms = term;
    
    //Exp
    cout<<"plz enter the highest exponent (first exponent):";
    cin >> top_exp;
    
    while(top_exp < term-1 ||cin.fail()){
        cin.clear();
        cin.ignore(10000000,'\n');
        
        cout<<"Error,plz try again:";
        cin >> top_exp;
    }
    
    
    int curr_coef;
    int curr_exp=top_exp;
    
    //push into the poly
    for(int i=1;i<=term;i++){
        
        cout<<"plz enter the coef of the '"<< i <<"' term: ";
        cin >> curr_coef;
        
            while(cin.fail()){
                cin.clear();
                cin.ignore(10000000,'\n');
        
                cout<<"Error,plz try again:";
                cin >> curr_coef;
        }
        
        
        poly.push(curr_coef,curr_exp);
        
        curr_exp--;
        
    }

}

//a poly into a chain(non-dense)
void non_dense_poly(chain &poly,char name){
    
    int term;
    
    cout<<"Poly '"<< name <<"' :"<<endl;
    
    //term
    cout<<"plz enter the number of term:";
    cin >> term;
    
    while(term <=0 ||cin.fail()){
        cin.clear();
        cin.ignore(10000000,'\n');
        
        cout<<"Error,plz try again:";
        cin >> term;
    }
    
    poly.terms = term;
    
    
    
    //Exp & coef push
    
    int currently_exp;
    int currently_coef;
    int prev=0;
    
    for(int i =1;i<=term;i++){
    
    cout<<"plz enter the exponent of "<<i<<" element:";
    
    cin >> currently_exp;
    
    if(i==1){
        
        while( currently_exp < term -1 ||cin.fail()){
        cin.clear();
        cin.ignore(10000000,'\n');
        
        cout<<"Error,plz try again:";
        cin >>currently_exp;
        }
    
        
    }else{   
    
        while( currently_exp > prev ||cin.fail()){
            cin.clear();
            cin.ignore(10000000,'\n');
        
            cout<<"Error,plz try again:";
            cin >>currently_exp;
        }
    }
    
    cout<<"plz enter the coeficient of "<<i<<" element:";
    
    cin >> currently_coef;
    while(cin.fail()){
        cin.clear();
        cin.ignore(10000000,'\n');
        
        cout<<"Error,plz try again:";
        cin >>currently_coef;
    }
    
    poly.push(currently_coef,currently_exp);
    prev=currently_exp;
    
    }

    

}


//muti
chain muti(chain &poly1,chain &poly2){
    chain result;
    
    for (node* a = poly1.get_first(); a; a = a->getLink()) {
        
        for (node* b = poly2.get_first(); b; b = b->getLink()) {
            
            int newCoef = a->getCoef() * b->getCoef();
            int newExp = a->getExp() + b->getExp();
            
            result.addTerm(newCoef, newExp); 
        }
    }
    
    return result;
}

int main(){
    chain poly1;
    chain poly2;
    non_dense_poly(poly1,'1');
    non_dense_poly(poly2,'2');
    
    poly1.print();
    poly2.print();
    
    chain result=muti(poly1,poly2);
    result.print();
    
    
    

return 0;
}
