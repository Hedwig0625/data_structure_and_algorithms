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
    
    //push
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
        
        while(currently !=NULL){
        
        if(currently->Exp != 0){
            cout<<currently->coef<<"x^"<<currently->Exp;
        }else{
            cout<<currently->coef;
        }    
        
        
        if(currently-> link !=NULL){
            cout<<"+";
        }
        
        currently=currently->link;
        
        }
        
    }    
    
    //get first
    node* get_first(){return first;}
    
    //add term
    void addTerm(int coef, int Exp) {
        node* cur = first;
        node* prev = nullptr;
        
        while (cur && cur->Exp > Exp) {  // 保持次方由大到小
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

//a poly into a chain
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
    
    
    chain poly1, poly2;
    into_poly(poly1,'1');
    into_poly(poly2,'2');

    cout << "Poly1: ";
    poly1.print();
    cout << endl;

    cout << "Poly2: ";
    poly2.print();
    cout << endl;

    chain result = muti(poly1, poly2);
    cout << "Result: ";
    result.print();
    cout << endl;

return 0;
}



