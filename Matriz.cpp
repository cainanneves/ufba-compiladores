
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct{
    string tipo;
    string info;
}token;

int main(){
    vector<string> tokens;
    vector<string> oqresta;
    char digito;
    string aux = "";
    bool table = false;
    while(scanf("%c" , &digito) != EOF){
        while(!table){
            if((digito == ' '|| digito == '\t' || digito == '\n')&& aux != ""){
                tokens.push_back(aux);
                aux = "";
                if(digito == '\n') table = true;
            }else if(digito != ' '&& digito != '\t'){
                aux += digito;
            }scanf("%c" , &digito);
        }
        if(table){
            if(digito == '<'){
                if(aux == "");
                else if(aux != "s" && aux != "r"){
                    oqresta.push_back(aux);
                    aux = "";
                }
                while(digito != '>'){
                    scanf("%c" , &digito);
                }
            }else if(digito == '&'){
                oqresta.push_back(" ");
                while(digito != ';'){
                    scanf("%c" , &digito);
                }
            }else{
                if(digito!='\n')
                    aux += digito;
            }
        }
    }
    cout<<"\nacabou\n";

    for(int i = 0; i < tokens.size(); i++){
        if(i==0){
            cout<<"{{"<<'\"'<<tokens[i]<<'\"'<<",";;
        }else if(i == tokens.size()-1){
            cout<<'\"'<<tokens[i]<<'\"'<<"},";
        }else{
            cout<<'"'<<tokens[i]<<'"'<<",";
        }
    }

    int tamanhotokens = tokens.size()+1;
    
    for(int i = 1; i <= oqresta.size(); i++){
            if(i==1){
                cout<<"\n{";
            }else if(i%tamanhotokens == 1){
            }else if(i == oqresta.size()){
                cout<<'\"'<<oqresta[i-1]<<'\"'<<"}}\n";
            }else if(i%tamanhotokens == 0){
                cout<<'\"'<<oqresta[i-1]<<'"'<<"},\n{";
            }else{
                cout<<'"'<<oqresta[i-1]<<'"'<<",";
            }
    }
    cout<<endl<<endl<<"tokens: "<<tokens.size()<<endl;
}
