
#include "stack.h"
#include <string.h>
#include <stdio.h>

using namespace std;

//void addToken (int x,int &t) {
//    token[t]=x;
//    t++;
//}
int main()
{
    int i;
    bool stats=true;
    char x[99];
    int token[99];
    cout<<"input  : ";
    cin.getline(x, sizeof(x));
    i=0;
    int t=-1;
    cout<<"Token Lexic : ";
    while ((i<=strlen(x))&&(stats!=false))
    {
        if((x[i]=='p')||(x[i]=='q')||(x[i]=='r')||(x[i]=='s')){
            cout<<"1 ";
            t++;
            token[t]=1;
        }

        else if(x[i]=='n')
        {
            i=i+1;
            if(x[i]=='o')
            {
                i=i+1;
                if(x[i]=='t')
                {
                    cout<<"2 ";
                    t++;
                    token[t]=2;
                }
                else
                {
                    stats=false;
                    cout<<"error ";
                }
            }
            else
            {
                stats=false;
                cout<<"error ";
            }
        }
        else if(x[i]=='a')
        {
            i=i+1;
            if(x[i]=='n')
            {
                i=i+1;
                if(x[i]=='d')
                {
                    t++;
                    token[t]=3;
                    cout<<"3 ";
                }
                else
                {
                    stats=false;
                    cout<<"error ";
                }
            }
            else
            {
                i=i+2;
                stats=false;
                cout<<"error ";
            }
        }
        else if(x[i]=='o')
        {
            i=i+1;
            if(x[i]=='r')
            {
                t++;
                token[t]=4;
                cout<<"4 ";
            }
            else
            {
                stats=false;
                cout<<"error ";
            }
        }
        else if(x[i]=='x')
        {
            i=i+1;
            if(x[i]=='o')
            {
                i=i+1;
                if(x[i]=='r')
                {
                    t++;
                    token[t]=5;
                    cout<<"5 ";
                }
                else
                {
                    stats=false;
                    cout<<"error ";
                }
            }
            else
            {
                stats=false;
                cout<<"error ";
            }
        }
        else if(x[i]=='i')
        {
            i=i+1;
            if(x[i]=='f')
            {
                i=i+1;
                if(x[i]=='f')
                {
                    t++;
                    token[t]=8;
                    cout<<"8 ";
                    stats=true;
                }
                else if ((x[i]==NULL)||(x[i]==' '))
                {
                    t++;
                    token[t]=6;
                    cout<<"6 ";
                    stats=true;
                }
                else if(x[i]!='f')
                {
                    stats=false;
                    cout<<"error ";
                }

            }
            else
            {
                stats=false;
                cout<<"error ";
            }
        }


        else if(x[i]=='t')
        {
            i=i+1;
            if(x[i]=='h')
            {
                i=i+1;
                if(x[i]=='e')
                {
                    i=i+1;
                    if(x[i]=='n'){
                        t++;
                        token[t]=7;
                        cout<<"7 ";}
                    else{
                        stats=false;
                        cout<<"error";
                    };
                }
                else
                {
                    stats=false;
                    cout<<"error ";
                }
            }
            else
            {
                stats=false;
                cout<<"error ";
            }
        }
        else if(x[i]=='(')
        {
            t++;
            token[t]=9;
            cout<<"9 ";
        }
        else if(x[i]==')')
        {
            t++;
            token[t]=10;
            cout<<"10 ";
        }

        else if((x[i]==' ')||(x[i]==0)){
            stats=true;
        }
        else{
            stats=false;
            cout<<"error ";
        }


        i=i+1;
    };
    int *p;
    int q=0;///sebagai penunjuk indeks dari pointer p
    char tmp;///buat nyimpen hasil pop
    Stack val;///Validity
    createstack(val);
    push(val,'#');
    push(val,'S');
    p = &token[q];///pointer p nunjuk ke token[0]
    bool B=true; ///rencananya buat tau kapan validity nya bernilai salah. tp kapan dipakenya?
    char cad[10];///array ini berfungsi sebagai penyimpan 6&9 untuk ditentukan pasangannya nanti
    int c=-1;///penunjuk indeks cad
    //========MUNGKIN NANTI BUTUH LOOPING DARI SINI=================
    while ((val.top!=0)&&B) {
        if (val.info[val.top]=='S') {
            if (*p==1) {
                if (token[*p+1]==8) {
                    tmp=pop(val);
                    push(val,'I');
                    push(val,'8');
                    push(val,'I');
                }
                else if (token[*p+1]==5) {
                    tmp=pop(val);
                    push(val,'I');
                    push(val,'5');
                    push(val,'I');
                }
                else if (token[*p+1]==4){
                    tmp=pop(val);
                    push(val,'I');
                    push(val,'4');
                    push(val,'I');
                }
                else if (token[*p+1]==3) {
                    tmp=pop(val);
                    push(val,'I');
                    push(val,'3');
                    push(val,'I');
                }
            }
            else if (*p==9) {
                tmp=pop(val);
                push(val,'10');
                push(val,'I');
                push(val,'9');
            }
            else if (*p=='2') {
                tmp=pop(val);
                push(val,'2');
                push(val,'I');
            }
            else if (*p=='6') {
                tmp=pop(val);
                push(val,'I');
                push(val,'7');
                push(val,'I');
                push(val,'6');
            }
        }
        else if (val.info[val.top]=='I') {
            ///[??????????????????]
        }

        else if ((val.info[val.top]=='1') || (val.info[val.top]=='2') || (val.info[val.top]=='3') || (val.info[val.top]=='5') || (val.info[val.top]=='8') || (val.info[val.top]=='4')) {
            tmp=pop(val);
            q++;
            *p=token[q];
        }
        else if ((val.info[val.top]=='6') || (val.info[val.top]=='9')) {
            c++;
            cad[c]=pop(val);
        }

    }//end of while



//    if (t>0) { //berarti inputan lebih dari 1 char
//        //==================ATAU LOOPINGNYA DARI SINI?===============
//        if (*p==2) { ///not___
//
//
//        }
//        else if ()
//    }
//    else if (t==2) {
//        if ()
//    }




    return 0;
}


