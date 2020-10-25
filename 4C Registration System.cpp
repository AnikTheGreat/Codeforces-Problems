#include <bits/stdc++.h>
using namespace std;

struct Trie_Node{
    map < char, struct Trie_Node* > character;
    bool endofword = false ;
    int cnt=0;
};

struct Trie_Node root;

void insertWord(string str);
struct Trie_Node* Get_newNode();
bool searchWord(string str);

int c;

int main(){
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;

        if(searchWord(str)){
            str = str + to_string(c);
            cout<<str<<endl;
            insertWord(str);
        }
        else{
            cout<<"OK"<<endl;
            insertWord(str);
        }
    }
}


//Creating New Node
struct Trie_Node * Get_newNode(){
    struct Trie_Node *newNode;
    newNode = new struct Trie_Node;
    newNode->endofword = false ;
    return newNode;
}



//Inserting on The Trie Tree
void insertWord(string str){
    struct Trie_Node *temp ;
    temp = &root ;

    for(int i=0;i<str.size();i++){
        char ch = str[i];

        if(temp->character.find(ch) == temp->character.end()){
                temp->character[ch];
                temp->character[ch] = Get_newNode();
        }

        temp = temp->character[ch];
    }

    temp->endofword = true;
}




//Searching a Word in the Trie Tree
bool searchWord(string str){
    struct Trie_Node *temp;
    temp = &root ;

    for(int i=0;i<str.size();i++){
        char ch = str[i];

        if(temp == nullptr){
            return false;
        }
        if(temp->character.find(ch) == temp->character.end()){
            return false ;
        }

        temp = temp->character[ch];
    }
    if(temp->endofword){
        temp->cnt++;
        c = temp->cnt;
        return true;
    }
    else{
        return temp->endofword;
    }
}
