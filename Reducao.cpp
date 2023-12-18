#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
    string c = "", simb, vazio;
    int tamanho;
    vector<int> reducao;
    vector<string> simbo;
    cin.ignore();
    while(getline(cin,c)){
        simb = "";
        simbo.clear();
        for(int i = 0; i < c.size(); i++){
            if(c[i]==' '){
                simbo.push_back(simb);
                simb = "";
            }else{
                simb+=c[i];
            }  
        }
        if(simb!=""){
            simbo.push_back(simb);
            simb = "";
        }
        cout<<c<<endl;
        cout<<"Simbolos lidos nessa linha:"<<endl;
        for(int i = 0; i < simbo.size(); i++){
            cout<<simbo[i]<<",";
        }
        cout<<endl<<endl;
        
    }
    /*
     for(int i = 0; i < simbo.size(); i++){
        if(i==0){
            cout<<"{{\""<<simbo[i]<<"\", \"";
        }else if(i == simbo.size()-1){
            cout<<simbo[i]<<"\"},\n";
        }else{
            cout<<simbo[i]<<"\", \"";
        }
    }
    for(int i = 0; i < reducao.size(); i++){
        if(i==0){
            cout<<"{\""<<reducao[i]<<"\", \"";
        }else if(i == reducao.size()-1){
            cout<<reducao[i]<<"\"}}";
        }else{
            cout<<reducao[i]<<"\", \"";
        }
    }
    */
}
