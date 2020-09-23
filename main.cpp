#include <iostream>
#include <list>

using namespace std;

void pause()
{
    string temp;
    cout << "\n\n-----Aperte enter para sair-----";
    getline(cin, temp);
    cin.get();
}

class jogador
{
private:
    string nome, posicao;
    int numero;

public:
    jogador()
    {
    }
    jogador(string n, string p, int nu)
    {
        nome = n;
        posicao = p;
        numero = nu;
    }

    //sobrecarga operador ==
    bool operator==(const jogador &p) const
    {
        return nome == p.nome;
    }

    void imprimir()
    {
        cout << nome << " - " << posicao << " - " << numero << endl;
    }
};

class equipe
{
private:
    list<jogador> jogadores;
    string nome;
    string naciolidade;
    int ano;

public:
    equipe()
    {
        nome = "";
        naciolidade = "";
        ano = 0;
    }
    equipe(string n, string na, int a)
    {
        nome = n;
        naciolidade = na;
        ano = a;
    }

    //sobrecarga operador ==
    bool operator==(const equipe &p) const
    {
        return nome == p.nome;
    }

    void insereJogador()
    {
        cout << "Time a ser adicionado o jogador: " << nome << endl;
        string nomeJogador, posicaoJogador;
        int numeroJogador;
        cout << "Digite o nome do jogador: ";
        cin >> nomeJogador;
        cout << "Digite a posição do jogador: ";
        cin >> posicaoJogador;
        cout << "Digite o número do jogador: ";
        cin >> numeroJogador;
        jogador temp(nomeJogador, posicaoJogador, numeroJogador);
        jogadores.push_back(temp);
        cout << "\nJogador inserido com sucesso\n";
    }

    void imprimirEquipe()
    {
        cout << "Equipe: " << nome;
        cout << "\nJogadores da equipe:\n";
        for (auto item : jogadores)
        {
            item.imprimir();
        }
    }
    void removeJogador()
    {
        string n;
        cout << "Digite o nome do jogador a ser removido:";
        cin >> n;
        jogador temp(n, "", 0);
        jogadores.remove(temp);
    }
};

void cadastroJogador(list<equipe> &lista)
{
    cout << "Em qual time deseja adicionar um jogador? ";
    string e;
    cin >> e;
    equipe temp(e, "", 0);
    for (auto &item : lista)
    {
        if (item == temp)
        {
            item.insereJogador();
        }
    }
}

int main()
{
    list<equipe> torneio;
    string nome, nacionalidade;
    equipe equipeAux;

    int ano;
    char opcao;

    do
    {
        system("clear");
        cout << "\t\t----- Cadastro de Campeonatos 1.0 -----" << endl
             << endl;
        cout << "1 - Adicionar Time ao Torneio" << endl;
        cout << "2 - Remover Time do torneio" << endl;
        cout << "3 - Adicionar Jogador ao time" << endl;
        cout << "4 - Remover jogador do time" << endl;
        cout << "5 - Imprimir" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;
        switch (opcao)
        {
        case '1':
            cin.ignore();
            cout << "Digite o nome do time: ";
            cin >> nome;
            cin.ignore();
            cout << "Digite a nacionalidade: ";
            cin >> nacionalidade;
            cout << "Digite o ano de criação: ";
            cin >> ano;
            equipeAux = equipe(nome, nacionalidade, ano);
            torneio.push_back(equipeAux);
            break;
        case '2':

            cout << "Digite o nome do time que deseja remover: ";
            cin >> nome;
            equipeAux = equipe(nome, "", 0);
            for (auto &item : torneio)
            {
                if (item == equipeAux)
                {
                    torneio.remove(equipeAux);
                    break;
                }
            }
            break;
        case '3':
            cout << "Digite o nome do time que deseja adicionar um novo jogador: ";
            cin >> nome;
            equipeAux = equipe(nome, "", 0);
            for (auto &item : torneio)
            {
                if (item == equipeAux)
                {
                    item.insereJogador();
                    break;
                }
            }

            break;
        case '4':
            cout << "Digite o nome do time que deseja remover um jogador: ";
            cin >> nome;
            equipeAux = equipe(nome, "", 0);
            for (auto &item : torneio)
            {
                if (item == equipeAux)
                {
                    item.removeJogador();
                    break;
                }
            }
            break;
        case '5':
            for (auto item : torneio)
            {
                item.imprimirEquipe();
            }
            break;
        case '0':
            cout << "Ate mais";
            break;
        default:
            cout << "Opcao Invalida";
            break;
        }
        pause();

    } while (opcao == 0);
}
