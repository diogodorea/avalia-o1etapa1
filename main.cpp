#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente {
private:
    string cpf;
    string dtNascimento;

public:
    string nome;

    Paciente() {
        nome = "Vazio";
        cpf = "Vazio";
        dtNascimento = "Vazio";
    }

    Paciente(string _nome, string _cpf, string _dtNascimento) {
        this->nome = _nome;
        this->setCpf(_cpf);
        this->setDtNascimento(_dtNascimento);
    }

    string getCpf() {
        return this->cpf;
    }

    string getDtNascimento() {
        return this->dtNascimento;
    }

    string getNome() {
        return this->nome;
    }

    
    void setCpf(string _cpf) {
        this->cpf = _cpf;
    }
        
    void setDtNascimento(string _data_nascimento) {
        this->dtNascimento = _data_nascimento;
    }

    void setNome(string _nome) {
        this->nome = _nome;
    }

    void imprimir(){
        cout << "Nome: "<< nome << endl;
        cout <<  "CPF: " << cpf << endl;
        cout <<  "Nascimento: " << dtNascimento << endl;
    }
};

int main(){
  return 0;
}
