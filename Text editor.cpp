/*Text Editor*/

/*Input File needed*/

#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>

using namespace std;

ifstream in;
ofstream out;
ifstream fsIn;

class Stack
{
        int n;
        int top;
        string S[1000];

        public:

        Stack()
        {
                top = -1;
                n = 1000;
        }

        void push(char elt);
        string pop();
        int isstackempty();
        int isstackfull();
        int displaytop();
        void displaytopelt();
        void insertWord(string word);
        void insertCharacter(char character);
        void backspace();
        void delete_elt();
        void moveLeft(int);
        void moveRight(int);
        void replaceChar(char find_char,char replace_char);
        void file();
        void viewFile();
        void cpy(int,int);
        void cut(int ,int );
        void paste(int);
        void insertFile();

}leftStack,rightStack,cp,pste;

void Stack::insertWord(string word) {
    int i=0;

    while(word[i]!='\0')
    {
        insertCharacter(word[i]);
        i++;
    }
}
void Stack::insertFile()
{
    fsIn.open("Input File.txt");
    char ch;
    while(!fsIn.eof())
    {
        fsIn.get(ch);
        leftStack.push(ch);
    }
    leftStack.pop();
}
void Stack::insertCharacter(char character)
{
    push(character);
}
void Stack :: push(char elt)
{
        if ( isstackfull()==0)
        {
                top++;
                S[top]=elt;
        }
        else
            cout<<"Stack is full"<<endl;
}

void Stack::backspace()
{
    leftStack.pop();
}

void Stack::delete_elt()
{
    rightStack.pop();
}

void Stack::moveLeft(int position)
{
    if(top+1<position)
        cout<<"Action cannot be performed"<<endl;
    else
    {
        for(int i=0;i<position;i++)
        {
            string temp;
            temp = leftStack.pop();
            char x = temp[0];
            rightStack.push(x);
        }

    }
}

void Stack::moveRight(int position)
{
    if(top+1<position)
        cout<<"Action cannot be performed"<<endl;
    else
    {
        for(int i=0;i<position;i++)
        {
            string temp;
            temp = rightStack.pop();
            char x = temp[0];
            leftStack.push(x);
        }

    }
}

string Stack :: pop()
{
        if ( isstackempty()==0)
        {
            string item = S[top];
            top-=1;
            return item;
        }
        else
            cout<<"Stack is empty"<<endl;

}

int Stack :: isstackempty()
{
        if(top == -1)
                return 1;
        else
                return 0;
}

int Stack :: isstackfull()
{
        if(top == n)
                return 1;
        else
                return 0;
}

int Stack :: displaytop()
{
        return top+1;
}

void Stack :: displaytopelt()
{
        cout<<"Top element is "<<S[top]<<endl;
}

void Stack::replaceChar(char find_char,char replace_char)
{
    int flag = 0;
    leftStack.moveLeft(leftStack.displaytop());
    while(!rightStack.isstackempty())
    {
        string temp;
        temp = rightStack.pop();
        char t = temp[0];
        if(t == find_char)
        {
            t = replace_char;
            flag = 1;
        }
        leftStack.push(t);
    }
    if(flag == 0)
        cout<<"Letter not found"<<endl;
    rightStack.moveRight(rightStack.displaytop());
}

void Stack::file()
{
    leftStack.moveLeft(leftStack.displaytop());
    while(!rightStack.isstackempty())
    {
        string temp;
        temp = rightStack.pop();
        char t = temp[0];
        leftStack.push(t);
        out<<t;
    }
}

void Stack::viewFile()
{
    string line;
    while(getline(in,line))
    {
        cout<<line<<endl;
    }
}
void Stack::cpy(int i1,int i2)
{
    leftStack.moveLeft(i1);
    char temp;
    for(int j=i1;j>i2;j--)
    {
        string temp;
        temp = rightStack.pop();
        char t = temp[0];
        cp.push(t);
        pste.push(t);
    }
    while(!cp.isstackempty())
    {
        string s;
        s=cp.pop();
        char a = s[0];
        rightStack.push(a);
    }
    rightStack.moveRight(rightStack.displaytop());
}
void Stack::cut(int i1,int i2)
{
    leftStack.moveLeft(i1);
    char temp;
    for(int j=i1;j>i2;j--)
    {
        string temp;
        temp = rightStack.pop();
        char t = temp[0];
        pste.push(t);
    }
    rightStack.moveRight(rightStack.displaytop());
}
void Stack::paste(int p)
{
    leftStack.moveLeft(p);
    while(!pste.isstackempty())
    {
        string s;
        s=pste.pop();
        char a = s[0];
        rightStack.push(a);
    }
    rightStack.moveRight(rightStack.displaytop());
}
int main()
{

        int j;
        cout<<"\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\n\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n";
        cout<<"\t\t\xb0                 Let's write                   \xb0\n";
        cout<<"\t\t\xb0      \xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4       \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\t\t\xb0           Making writing simple               \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\t\t\xb0                                               \xb0\n";
        cout<<"\n\n\t\t\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n\n\n";
        cout<<"\n\t\t\tLET'S MOVE ON.....\n";
        cout<<"\t\t\tPress 1 to Continue.... ";
        cin>>j;
        if (j==0)
        {
            exit(0);
        }
        L2:system("cls");
        cout<<"\n\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf 'MENU' \xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\n";
        cout<<"\n\t\t\t 1.Insertion\n";
        cout<<"\t\t\t 2.Backspace\n";
        cout<<"\t\t\t 3.Delete an element\n";
        cout<<"\t\t\t 4.Move to the left\n";
        cout<<"\t\t\t 5.Move to the right\n";
        cout<<"\t\t\t 6.Replace a character\n";
        cout<<"\t\t\t 7.Save\n";
        cout<<"\t\t\t 8.View the saved file\n";
        cout<<"\t\t\t 9.Copy\n";
        cout<<"\t\t\t 10.Cut\n";
        cout<<"\t\t\t 11.Paste\n";
        cout<<"\t\t\t 12.Clear the screen\n";
        cout<<"\t\t\t 13.Exit\n";
        cout<<"\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\xaf\n";

        int ch;
        L1:cout<<"\n\t\t\t Enter your choice : ";
        cin>>ch;
        cout<<"\n"<<endl;
        switch(ch)
        {
            case 1:
            {
                string line;

                /*Insertion using user input*/
                //cout<<"Enter the String : ";
                //cin>>line;
                //leftStack.insertWord(line);

                leftStack.insertFile();//Insertion using input file
                break;
            }
            case 2:
            {
                leftStack.backspace();
                break;
            }
            case 3:
            {
                rightStack.delete_elt();
                break;
            }
            case 4:
            {
                int cur;
                cout<<"Enter the position you want to move your cursor to : ";
                cin>>cur;
                leftStack.moveLeft(cur);
                break;
            }
            case 5:
            {
                int cur;
                cout<<"Enter the position you want to move your cursor to : ";
                cin>>cur;
                rightStack.moveRight(cur);
                break;
            }
            case 6:
            {
                char fin,rep;
                cout<<"Enter the character to be replaced : ";
                cin>>fin;
                cout<<"Enter the character to replace the above character : ";
                cin>>rep;
                leftStack.replaceChar(fin,rep);
                break;
            }
            case 7:
            {
                int choice;
                cout<<"Do you wish to append in an existing file or write in a new file(0/1 resp.) : ";
                cin>>choice;
                if(choice==0)
                {
                    out.open("Text Editor.txt",ios::app);
                }
                else if(choice==1)
                {
                    out.open("Text Editor.txt");
                }
                else
                {
                    cout<<"Invalid choice!";
                }
                leftStack.file();
                out.close();
                break;
            }
            case 8:
            {
                in.open("Text Editor.txt");
                leftStack.viewFile();
                in.close();
                break;
            }
            case 9:
            {
                //Start position > End Position
                //Position counted from current cursor position towards left
                int i1,i2;
                cout<<"Enter the start position of text to be copied : ";
                cin>>i1;
                cout<<"Enter the end position of text to be copied : ";
                cin>>i2;
                leftStack.cpy(i1,i2);
                break;
            }
            case 10:
            {
                //Start position > End Position
                //Position counted from current cursor position towards left
                int i1,i2;
                cout<<"Enter the start position of text to be cut : ";
                cin>>i1;
                cout<<"Enter the end position of text to be cut : ";
                cin>>i2;
                leftStack.cut(i1,i2);
                break;
            }
            case 11:
            {
                //Position counted from current cursor position towards left
                int p;
                cout<<"Enter the position to paste the text : ";
                cin>>p;
                leftStack.paste(p);
                break;
            }
            case 12:
            {
                goto L2;
                break;
            }
            case 13:
            {
                //exit(0);
                break;
            }
        }
        int cont;
        cout<<"Do you want to continue[0/1] ? : ";
        cin>>cont;
        if(cont == 1)
            goto L1;
        else if(cont != 0)
            cout<<"Invalid"<<endl;
        else
        {
            system("cls");
            cout<<"\n\n\n";
            cout<<"\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf           \xae\xae\xae\xae\xae\xae\xae\xae";
            cout<<"\n\t\t\t\xaf\xaf\xaf\xaf\xaf\xaf\xaf Thank You \xae\xae\xae\xae\xae\xae\xae\xae\n\n\n\n";
        }

}
