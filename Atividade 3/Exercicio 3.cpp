#include <iostream>



using namespace std;

class celula
{
private:
	
	string nome;
	string sexo;
	string beber;
	int id;
	celula * proxima;
	
public:
	celula()
	{
		proxima = NULL;
	}
	
	celula(string n)
	{
		nome = n;
	}
	
	celula(string n, celula *p)
	{
		nome = n;
		proxima = p;
	}

	
	string getNome()
	{
		return nome;
	}
	
	string getSexo()
	{
		return sexo;
	}
	
	int getid()
	{
		return id;
	}
	
	string getbeber()
	{
		return beber;
	}
	
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	
	celula (string nomenovo, string sexonovo, int idnova, string al, celula *p)
	{
		nome = nomenovo;
		sexo = sexonovo;
		id = idnova;
		beber = al;
		proxima = p;   	
	}
	
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string nome, string sexo, int id, string beber)
	{
		celula *nova = new celula(nome, sexo, id, beber, inicio);
		inicio = nova;
	}

	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << " - " << aux->getSexo() << " - " << aux->getid()<< " - " << aux->getbeber() <<endl; 

				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{	
	
	lista l1;
	
	l1.inserirInicio("Vinicius","masculinah",25,"claro mo");
	
	l1.imprimir();
	
	return 0;
}