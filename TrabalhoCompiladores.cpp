
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct{
    int linha;
    int coluna;
}errado;

int main(){
    char digito;
    string id = "";
    int estadoatual = 0, kont = 0, coluna = 0, colunab = 0, linha = 1;
    vector<errado> erros;
    vector<char> dig;
    errado aux;
    bool erro = false, valido=true;
    while(scanf("%c", &digito)!= EOF){
        dig.push_back(digito);
        if((digito!='\n')&&(digito!='\t')&&(digito<' '||digito>'~')){
            valido=false;
            break;
        }else{
            coluna++;
            //cout<<"estadoatual "<<estadoatual<<endl;
            naoconsumido:                                                             //label para quando um char não for consumido, reinicio antes de ler mais chars
            switch(estadoatual){

                case 0:       //caso o estado atual seja o zero
                    if((digito >= 'a' && digito <= 'z')||(digito>='A'&&digito<='Z')){ //Se o digito lido for uma letra maiuscula ou minuscula comeco um id
                        id+=digito;                                                   //adiciono o digito na string identificação pra saber qual é(nao precisa na analize lexica)
                        kont++;                                                       //contador de caracteres pois o maximo num id é 512
                        estadoatual=1;                                                //vai pro estado onde vou fazer a leitura dos caracteres seguintes se houverem
                    }
                    else if(digito>='0'&&digito<='9'){                                //Se o digito lido for um numero, comeco um numero
                        id+=digito;
                        kont++;
                        estadoatual=2;
                    }else if(digito=='<'){
                        estadoatual=4;
                        //vejo o proximo char no estado 4
                    }else if(digito=='>'){
                        estadoatual=5;
                        //vejo o proximo char no estado 5
                    }else if(digito=='*'){
                        estadoatual=6;
                        //vejo o proximo char no estado 6
                    }else if(digito=='"'){
                        estadoatual=7;
                        //comeco uma string no estado 7
                    }else if(digito=='.'){
                        //cria token PONTO
                        //consome e continua no estado 0
                    }else if(digito==':'){
                        //cria token DOISPONTOS
                        //consome e continua no estado 0
                    }else if(digito==';'){
                        //cria token PONTOVIRGULA
                        //consome e continua no estado 0
                    }else if(digito=='+'){
                        //cria token SOMA
                        //consome e continua no estado 0
                    }else if(digito=='-'){
                        //cria token SUB
                        //consome e continua no estado 0
                    }else if(digito=='/'){
                        //cria token DIV
                        //consome e continua no estado 0
                    }else if(digito=='%'){
                        //cria token RESTO
                        //consome e continua no estado 0
                    }else if(digito=='('){
                        //cria token ABREPARENTESES
                        //consome e continua no estado 0
                    }else if(digito==')'){
                        //cria token FECHAPARENTESES
                        //consome e continua no estado 0
                    }else if(digito=='['){
                        //cria token ABRECOLCHETE
                        //consome e continua no estado 0
                    }else if(digito==']'){
                        //cria token FECHACOLCHETE
                        //consome e continua no estado 0
                    }else if(digito=='&'){
                        //cria token AND
                        //consome e continua no estado 0
                    }else if(digito=='='){
                        //cria token IGUAL
                        //consome e continua no estado 0
                    }else if(digito=='|'){
                        //cria token OR
                        //consome e continua no estado 0
                    }else if(digito=='!'){
                        //cria token NOT
                    }else if(digito==' '||digito=='\t'||digito=='\n'){
                        if(digito=='\n'){
                            linha++;
                            colunab=coluna;
                            coluna=0;
                        }
                        //consome
                    }else{
                        //trata como erro e consome continua no estado 0
                        erro=true;
                        aux.linha=linha;
                        aux.coluna=coluna;
                        erros.push_back(aux);
                    }
                    break;

                case 1:       //caso o estado atual seja 1, continuacao da leitura de id's
                    if((digito >= 'a' && digito <= 'z')||(digito>='A'&&digito<='Z')||(digito>='0'&&digito<='9')){   //caso o digito seja outra letra ou numero, pode fazer parte da id
                        if(kont == 512){                                                                            //erro se kont for igual a 512 e eu tento colocar mais letras ou numeros
                            //trato como erro, zero id e kont e recomeco
                            erro=true;
                            aux.linha=linha;
                            aux.coluna=coluna-1;
                            erros.push_back(aux);
                            id="";
                            kont=0;
                            estadoatual=0;
                            goto naoconsumido;
                        }else{                                                                                      //ainda pode colocar mais digitos
                            id+=digito;                                                                             //adiciono na string
                            kont++;
                            //estadoatual = 1;                                                                      //estado continua 1
                        }
                    }else{
                        //gera token IDENTIFICADOR
                        //recomeca sem consumir
                        id="";
                        kont=0;
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 2:
                    if((digito>='0'&&digito<='9')||digito==','){                                                                   //caso o digito seja outro numero, pode fazer parte do numero
                        if(kont == 512){
                            //trato como erro, zero id e kont e recomeco
                            erro=true;
                            aux.linha=linha;
                            aux.coluna=coluna-1;
                            erros.push_back(aux);
                            id="";
                            kont=0;
                            estadoatual=0;
                            goto naoconsumido;
                        }else if (digito==','){
                            estadoatual = 3;
                        }
                        id+=digito;
                        kont++;
                    }else if((digito>='a'&&digito<='z')||(digito>='A'&&digito<='Z')){
                        //trato como erro, zero id e kont e recomeco se for qualquer outro char nao aceito por numeros
                        erro=true;
                        aux.linha=linha;
                        aux.coluna=coluna-1;
                        erros.push_back(aux);
                        id="";
                        kont=0;
                        estadoatual=0;
                        goto naoconsumido;
                    }else{
                        //gera token NUMEROINTEIRO
                        //recomeca sem consumir
                        id="";
                        kont=0;
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 3:
                    if(digito>='0'&&digito<='9'){                                                                   //se quero adicionar um nemero depois da virgula
                        if(kont == 512){
                            //trato como erro, zero id e kont e recomeco
                            erro=true;
                            aux.linha=linha;
                            aux.coluna=coluna-1;
                            erros.push_back(aux);
                            id="";
                            kont=0;
                            estadoatual=0;
                            goto naoconsumido;
                        }else{
                            id+=digito;
                            kont++;
                            //estadoatual=3;
                        }
                    }else if((digito>='a'&&digito<='z')||(digito>='A'&&digito<='Z')||digito==','){

                            if(kont==512){                  //
                                id="";                      //
                                kont=0;                     // nao sei se é necessario mas nao alterou os 10pts nem passed
                                estadoatual=0;              //
                                goto naoconsumido;          //
                            }

                        //trato como erro, zero id e kont e recomeco se for qualquer outro char imprimivel nao aceito por numeros
                        erro=true;
                        aux.linha=linha;
                        aux.coluna=coluna-1;
                        erros.push_back(aux);
                        id="";
                        kont=0;
                        estadoatual=0;
                        goto naoconsumido;
                    }else{
                        //gero token NUMEROREAL
                        //recomeco sem consumir
                        id="";
                        kont=0;
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 4:
                    if(digito=='-'){
                        //gera token ATRIBUICAO
                        //consome e vai pro estado 0
                        estadoatual=0;
                    }else if(digito=='>'){
                        //gera token DIFERENTE
                        //consome e vai pro estado 0
                        estadoatual=0;
                    }else if(digito=='='){
                        //gera token MENORIGUAL
                        //consome e vai pro estado 0
                        estadoatual=0;
                    }else{
                        //gera token MENORQUE
                        //recomeca com o mesmo digito pra ver aonde vai
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 5:
                    if(digito=='='){
                        //gera token MAIORIGUAL
                        //consome e vai pro estado 0
                        estadoatual=0;
                    }else{
                        //gera token MAIORQUE
                        //recomeca com o mesmo digito pra ver aonde vai
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 6:
                    if(digito=='*'){
                        //gera token POTENCIA
                        //consome e vai pro estado 0
                        estadoatual=0;
                    }else{
                        //gera token MULTI
                        //recomeca com o mesmo digito pra ver aonde vai
                        estadoatual=0;
                        goto naoconsumido;
                    }
                    break;

                case 7:
                    if((digito>=' '&&digito<='~')||digito=='\t'||digito=='\n'){
                        if(kont==512){
                            if(digito=='"'){
                                //gero token da STRING
                                //cout<<id<<endl;
                                id="";
                                kont=0;
                                estadoatual=0;
                            }else if(coluna==1){
                                //cout<<"string termina em \n no meio do arquivo"<<endl;
                                erro=true;
                                aux.linha=linha-1;
                                aux.coluna=colunab;
                                erros.push_back(aux);
                                id="";
                                kont=0;
                                estadoatual=0;
                                goto naoconsumido;
                            }else{
                                //trato como erro e recomeco sem consumir
                                erro=true;
                                aux.linha=linha;
                                aux.coluna=coluna-1;
                                erros.push_back(aux);
                                id="";
                                kont=0;
                                estadoatual=0;
                                goto naoconsumido;
                            }
                        }else if(digito == '"'){
                            //gero token da STRING
                            //cout<<id<<endl;
                            id="";
                            kont=0;
                            estadoatual=0;
                        }else if(digito=='\n'){
                            id+=digito;
                            kont++;
                            linha++;
                            colunab=coluna;
                            coluna=0;
                        }else{
                            id+=digito;
                            kont++;
                            //estadoatual=7;
                        }
                    }
                    break;
            }
        }
    }
    if(estadoatual==7){
        //trato como erro pois terminou dentro de uma string
        erro=true;
        if(coluna==0){              //se o estado = 7 e coluna = 0 significa que o ultimo digito lido foi uma quebra de linha
            aux.linha=linha-1;
            aux.coluna=colunab;
        }else{
            aux.coluna=coluna;
            aux.linha=linha;
        }
        erros.push_back(aux);
    }

    ///////////////////////////////////////
    // IMPRESSOES DE ERRO, OK E INVALIDO //
    ///////////////////////////////////////
    if(valido){
        if(!erro){
            printf("OK\n");
        }else{
            for(vector<errado>::iterator it=erros.begin(); it!=erros.end(); it++)
                printf("%d %d\n", (*it).linha, (*it).coluna);

        }
    }else{
        printf("ARQUIVO INVALIDO\n");
    }
    /*for(vector<char>::iterator it=dig.begin(); it!=dig.end(); it++){
        if(*it=='\n') printf("quebradelinha\n");
        else if(*it=='\t') printf("tab\n");
        else printf("%c\n", *it);
    }*/

}
