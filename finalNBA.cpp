#include <iostream>
#include <string>

using namespace std;

int qtdTimes = 5;

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

void definirTimes(){
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

    TimeNBA a02;
    a02.nome = "Los Angeles Lakers";
    a02.dataFundacao.dia = 16;
    a02.dataFundacao.mes = 4;
    a02.dataFundacao.ano = 1947;
    a02.localizacao.estado = "California";
    a02.localizacao.cidade = "Los Angeles";
    a02.conferencia = 1; // Lakers na conferência oeste
    a02.titulos.quantidade = 17;
    a02.titulos.ultimo = 2020;
    vetorTimes[1] = a02;

    TimeNBA a03;
    a03.nome = "San Antonio Spurs";
    a03.dataFundacao.dia = 11;
    a03.dataFundacao.mes = 7;
    a03.dataFundacao.ano = 1967;
    a03.localizacao.estado = "Texas";
    a03.localizacao.cidade = "San Antonio";
    a03.conferencia = 1; // Spurs na conferência oeste
    a03.titulos.quantidade = 5;
    a03.titulos.ultimo = 2014;
    vetorTimes[2] = a03;

    TimeNBA a04;
    a04.nome = "Boston Celtics";
    a04.dataFundacao.dia = 6;
    a04.dataFundacao.mes = 6;
    a04.dataFundacao.ano = 1946;
    a04.localizacao.estado = "Massachusetts";
    a04.localizacao.cidade = "Boston";
    a04.conferencia = 0; // Celtics na conferência leste
    a04.titulos.quantidade = 17;
    a04.titulos.ultimo = 2008;
    vetorTimes[3] = a04;

    TimeNBA a05;
    a05.nome = "Miami Heat";
    a05.dataFundacao.dia = 31;
    a05.dataFundacao.mes = 1;
    a05.dataFundacao.ano = 1988;
    a05.localizacao.estado = "Florida";
    a05.localizacao.cidade = "Miami";
    a05.conferencia = 0; // Heat na conferência leste
    a05.titulos.quantidade = 3;
    a05.titulos.ultimo = 2013;
    vetorTimes[4] = a05;
}

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

int acessarDiretorio(){
    //system("cls");
    int x;
    cout << "Qual time voce deseja acessar? " << endl;
    cout << "Digite o numero do indice" << endl;
    cin >> x;
    return x;
}

void diretorio(){
    system("cls");
    for(int i = 0; i<qtdTimes; i++){
        cout << i + 1 << ": " << vetorTimes[i].nome << endl; 
    }
}




void exibirInfo(TimeNBA indexTime) {
    system("cls");
    if(indexTime.nome.empty() == true){
        cout << "Indice invalido." << endl;
    } else {
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
}

void ordenarTimesAlfabetico(){
    TimeNBA temp;
    for (int i = 0; i < qtdTimes - 1; i++) {
        for (int j = 0; j < qtdTimes - i - 1; j++) {
            if (vetorTimes[j].nome > vetorTimes[j + 1].nome) {
                temp = vetorTimes[j];
                vetorTimes[j] = vetorTimes[j + 1];
                vetorTimes[j + 1] = temp;
            }
        }
    }
}

void ordenarTimesData() {
    TimeNBA temp;
    for (int i = 0; i < qtdTimes - 1; i++) {
        for (int j = 0; j < qtdTimes - i - 1; j++) {

            if (vetorTimes[j].dataFundacao.ano > vetorTimes[j + 1].dataFundacao.ano) {
                temp = vetorTimes[j];
                vetorTimes[j] = vetorTimes[j + 1];
                vetorTimes[j + 1] = temp;
            }

            else if (vetorTimes[j].dataFundacao.ano == vetorTimes[j + 1].dataFundacao.ano) {
                if (vetorTimes[j].dataFundacao.mes > vetorTimes[j + 1].dataFundacao.mes) {
                    temp = vetorTimes[j];
                    vetorTimes[j] = vetorTimes[j + 1];
                    vetorTimes[j + 1] = temp;
                }
            }
        }
    }
}

void ordenarTimesTitulos(){
    TimeNBA temp;
    for (int i = 0; i < qtdTimes - 1; i++) {
        for (int j = 0; j < qtdTimes - i - 1; j++) {
            if (vetorTimes[j].titulos.quantidade < vetorTimes[j + 1].titulos.quantidade) {
                temp = vetorTimes[j];
                vetorTimes[j] = vetorTimes[j + 1];
                vetorTimes[j + 1] = temp;
            }
        }
    }

}

void ordenarTimes(){
        int x;
        cout << "Digite 1 para ordenar em ordem alfabetica" << endl <<
        "digite 2 para ordenar por data de fundacao" << endl <<
        "digite 3 para ordenar por numero de titulos" << endl;
        cin >> x;
            if(x == 1){
                ordenarTimesAlfabetico();

            } else if(x == 2){
                ordenarTimesData();

            } else if(x == 3){
                ordenarTimesTitulos();

    }
}

int buscarTimes() {
    string busca;
    cout << "Digite o nome do time que deseja buscar: ";
    cin >> busca;

    for (int i = 0; i < qtdTimes; i++) {
        if (vetorTimes[i].nome == busca) {
            return i; 
        }
    }

    return 0;
}

void exibirOrdenar(){
    int x;
    cout << "Digite 1 para acessar um time, digite 2 para ordenar, digite 3 para buscar times." << endl;
    cin >> x;
    if(x == 1){
        exibirInfo(vetorTimes[(acessarDiretorio()-1)]);

    } else if(x == 2){
        ordenarTimes();
        diretorio();
    } else if(x == 3){
        exibirInfo(vetorTimes[buscarTimes()]);

    }

}

void menu(){
    int x;
    do{
    cout << "Digite 1 para acessar o diretorio, digite 2 para adicionar um time e 3 para sair." << endl;
    cin >> x;
    if(x == 1){
        diretorio();
        exibirOrdenar();
    } else if(x == 2){
        preencherTimeNBA(vetorTimes[qtdTimes]);
    }
    } while(x!=3);
    
}


int main() {
    definirTimes();
    cout << "Bem vindo ao aplicativo: TIMES DA NBA (e os seus)." << endl;
    

    //exibirInfo(vetorTimes[0]);
    //TimeNBA a01;
    //exibirInfo(a01);
    //preencherTimeNBA(vetorTimes[qtdTimes]);
    //diretorio();
    //exibirInfo(vetorTimes[acessarDiretorio()-1]);

    menu();

    return 0;
}