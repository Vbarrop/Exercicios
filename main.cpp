#include <iostream>
#include <list>

using namespace std;

class Alunos
{
private:
    string nome;
    float nota;
    float pontoExtra;

public:
    Alunos()
    {
    }

    Alunos(string nom, float n)
    {
        nome = nom;
        nota = n;
    }

    bool operator==(const Alunos &p) const
    {
        return nome == p.nome;
    }

    void AlteraPontoExtra(int posicao)
    {
        if (posicao == 1)
        {
            pontoExtra = 0.1;
        }
        else if (posicao == 2)
        {
            pontoExtra = 0.75;
        }
        else if (posicao == 3)
        {
            pontoExtra = 0.5;
        }
        else
        {
            pontoExtra = 0;
        }
    }

    void Imprimir()
    {
        cout << "Nome: " << nome << endl;
        cout << "Nota: " << nota << endl;
        cout << "Percentual Pontos Extras: " << pontoExtra * 100 << "%" << endl;
        cout << "Nota Final: " << (1 + pontoExtra) * nota << endl;
    }
};

void atualizaLista(list<Alunos> &alunos)
{

    int contador = alunos.size();
    for (auto &item : alunos)
    {
        item.AlteraPontoExtra(contador);
        contador--;
    }
}

int main()
{
    list<Alunos> sala;
    Alunos aluno;
    double nota;

    string nome;
    char op;

    do
    {
        cout << "\t\tAvaliação Mailson" << endl << endl;
        cout << "1 adicionar alunos" << endl;
        cout << "2 remover Alunos" << endl;
        cout << "3 imprimir alunos" << endl;
        cout << "4 sair";
        cin >> op;
        switch (op)
        {
        case '1':
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite a nota";
            cin >> nota;
            aluno = Alunos(nome, nota);
            sala.push_back(aluno);
            atualizaLista(sala);

            break;
        case '2':
            cout << "Digite o nome que deseja remover : ";
            cin >> nome;
            aluno = Alunos(nome, 0);
            for (auto &item : sala)
            {
                if (item == aluno)
                {
                    sala.remove(aluno);
                    atualizaLista(sala);
                    break;
                }
            }

            break;
        case '3':
            for (auto item : sala)
            {
                item.Imprimir();
            }

            break;
        }
    } while (op != '4');
}
