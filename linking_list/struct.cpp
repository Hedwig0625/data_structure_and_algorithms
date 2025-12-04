#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct tfield{
    char name[20];
    char tel[20];
    struct tfield *pointer;
}*head;

struct tfield *tallloc(void){
    return(struct tfield *)malloc(sizeof(struct tfield));
}

void genlist(void){
    struct tfield *p;
    head = NULL;
    while(p = talloc (),scanf("%s%s",p->name,p->tel)!=EOF){
        p->pointer=head;
        head=p;
    }
}

void displist(void){
    struct tfield *p;
    p=head;
    while(p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
int _tmain(int argc,_TCHAR* argv[ ]){
    char key[32];
    genlist();
    displist();
    while(printf("KEY NAME"),scanf("%s",key)!=EOF){
        link(key);
    }
    displist();
    system("pause");
    
    return 0;
}
