#include <iostream>
#include <string>

using namespace std;

int qtdTimes = 1;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Localizacao {
    string estado;
    string cidade;
};

struct TimeNBA {
    string nome;
    Data dataFundacao;
    Localizacao localizacao;
    int conferencia;
    struct Titulos {
        int quantidade;
        int ultimo;
    } titulos;
};

TimeNBA vetorTimes[100];

void preencherTimeNBA(TimeNBA &time) {
    system("cls");
    cout << "Digite o nome do time: ";
    cin.ignore();
    getline(cin, time.nome);

    cout << "Digite o dia de fundacao do time: ";
    cin >> time.dataFundacao.dia;
    cin.ignore(); // Limpa o buffer

    cout << "Digite o mes de fundacao do time: ";
    cin >> time.dataFundacao.mes;
    cin.ignore(); // Limpa o buffer

    cout << "Digite o ano de fundacao do time: ";
    cin >> time.dataFundacao.ano;
    cin.ignore(); // Limpa o buffer

    cout << "Digite o estado do time: ";
    getline(cin, time.localizacao.estado);

    cout << "Digite a cidade do time: ";
    getline(cin, time.localizacao.cidade);

    cout << "Digite a conferencia do time: (0 para Leste. 1 para Oeste) ";
    cin >> time.conferencia;
    cin.ignore(); // Limpa o buffer

    cout << "Digite a quantidade de titulos do time: ";
    cin >> time.titulos.quantidade;
    cin.ignore(); // Limpa o buffer

    if (time.titulos.quantidade > 0) {
        cout << "Digite o ano do ultimo titulo do time: ";
        cin >> time.titulos.ultimo;
        cin.ignore(); // Limpa o buffer
    }

    // Assumindo que 'qtdTimes' é uma variável global ou está definida de alguma forma acessível aqui.
    qtdTimes++;
}



void exibirInfo(TimeNBA indexTime) {
    system("cls");
    cout << "Nome: " << indexTime.nome << endl;
    cout << "Data de Fundacao: " << indexTime.dataFundacao.dia << "/" << indexTime.dataFundacao.mes << "/" << indexTime.dataFundacao.ano << endl;
    cout << "Localizacao: " << indexTime.localizacao.cidade << ", " << indexTime.localizacao.estado << endl;
    if(indexTime.conferencia == 0){
      cout << "Conferencia: Leste"<< endl;
    } else {
      cout << "Conferencia: Oeste"<< endl;
    }
    cout << "Quantidade de Titulos: " << indexTime.titulos.quantidade << endl;
    cout << "Ultimo Titulo: " << indexTime.titulos.ultimo << endl;
}

void diretorio(){
    system("cls");
    for(int i = 0; i<qtdTimes; i++){
        cout << i + 1 << ": " << vetorTimes[i].nome << endl; 
    }
}

int acessarDiretorio(){
    //system("cls");
    int x;
    cout << "Qual time voce deseja acessar? " << endl;
    cout << "Digite o numero do indice" << endl;
    cin >> x;
    return x;
}

void menu(){
    int x;
    do{
    cout << "Digite 1 para acessar o diretorio, digite 2 para adicionar um time e 3 para sair." << endl;
    cin >> x;
    if(x == 1){
        diretorio();
        exibirInfo(vetorTimes[(acessarDiretorio()-1)]);
    } else if(x == 2){
        preencherTimeNBA(vetorTimes[qtdTimes]);
    }
    } while(x!=3);
    
}

int main() {

    cout << "Bem vindo ao aplicativo: TIMES DA NBA (e os seus)." << endl;
    // Exemplo de uso da estrutura TimeNBA
    TimeNBA a01;
    a01.nome = "Golden State Warriors";
    a01.dataFundacao.dia = 15;
    a01.dataFundacao.mes = 7;
    a01.dataFundacao.ano = 1946;
    a01.localizacao.estado = "California";
    a01.localizacao.cidade = "San Francisco";
    a01.conferencia = 1;
    a01.titulos.quantidade = 6;
    a01.titulos.ultimo = 2018;
    vetorTimes[0] = a01;

    //exibirInfo(vetorTimes[0]);
    //TimeNBA a01;
    //exibirInfo(a01);
    //preencherTimeNBA(vetorTimes[qtdTimes]);
    //diretorio();
    //exibirInfo(vetorTimes[acessarDiretorio()-1]);

    menu();

    return 0;
}