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

class Medico {
    private:
    string crm;
    string especialidade;

    public:
    string nome;

    Medico (){
        crm = "Vazio";
        especialidade ="Vazio";
        nome = "Vazio";
    }

    Medico (string _crm, string _especialidade, string _nome){
        this-> nome = _nome;
        this-> setCrm(_crm);
        this-> setEspecialidade(_especialidade);
    }

    string getCrm (){
        return this-> crm;
    }
    string getEspecialidade(){
        return this-> especialidade;
    }
    string getNome(){
        return this-> nome;
    }
    void setCrm (string _crm){
        this-> crm = _crm;
    }
    void setEspecialidade(string _especialidade){
        this-> especialidade = _especialidade;
    }
    void setNome(string _nome){
        this-> nome = _nome;
    }

    void imprimir(){
        cout << "Nome: "<< nome << endl;
        cout <<  "CRM: " << crm << endl;
        cout <<  "Especialidade: " << especialidade << endl;
    }
};

class CrudPaciente {
public:
    int op;
    vector<Paciente*> pacientes;

    int localizaPaciente(string _cpf) {
        int i = 0;
        for (auto it : pacientes) {
            if (it->getCpf() == _cpf) {
                return i;
            }
            i++;
        }
        return -1;
    }

    void menu() {
        do {
            string auxNome, auxCpf, auxDtNascimento;
            int posicao = 0;
            string auxResposta = "0";
            Paciente* paciente = new Paciente();

            cout << "--Cadastro de Pacientes-- " << endl << endl;
            cout << "1. Incluir" << endl;
            cout << "2. Excluir" << endl;
            cout << "3. Alterar" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar" << endl;
            cout << "0. Voltar" << endl;
            cin >> op;

            switch (op) {
                case 1:
                    cout << "Informe o nome: ";
                    getline(cin >> ws, auxNome);

                    cout << "Informe o CPF: ";
                    getline(cin >> ws, auxCpf);

                    cout << "Informe a Data de Nascimento: ";
                    getline(cin >> ws, auxDtNascimento);

                    paciente->setNome(auxNome);
                    paciente->setCpf(auxCpf);
                    paciente->setDtNascimento(auxDtNascimento);

                    pacientes.push_back(paciente);
                    break;

                case 2:
                    cout << "Informe o CPF do paciente que deseja excluir: ";
                    getline(cin >> ws, auxCpf);
                    posicao = localizaPaciente(auxCpf);
                    if (posicao != -1) {
                        cout << "Cadastro de paciente " << pacientes[posicao]->getNome() << " excluído com sucesso!" << endl;
                        delete pacientes[posicao];
                        pacientes.erase(pacientes.begin() + posicao);
                    } else {
                        cout << "Paciente com CPF " << auxCpf << " não encontrado." << endl;
                    }
                    break;

                case 3:
                    cout << "Digite o CPF do paciente: ";
                    getline(cin >> ws, auxCpf);
                    posicao = localizaPaciente(auxCpf);
                    if (posicao != -1) {
                        cout << "Paciente " << pacientes[posicao]->getNome() << " encontrado." << endl;
                        pacientes[posicao]->imprimir();
                        cout << "Deseja alterar o nome? (S/N): ";
                        getline(cin >> ws, auxResposta);
                                                
                        if ((auxResposta == "S")||(auxResposta == "s")){
                            cout << "Informe o novo nome: ";
                            getline(cin >> ws, auxNome);
                            cout << "Paciente " << pacientes[posicao]->getNome() <<" nome alterado para: " << auxNome << endl;
                            pacientes[posicao]->setNome(auxNome);
                        }
                        cout << "Deseja alterar a Data de Nascimento? (S/N): ";
                        getline(cin >> ws, auxResposta);

                        if ((auxResposta == "S")||(auxResposta == "s")){
                            cout << "Informe a nova Data de Nascimento: ";
                            getline(cin >> ws, auxDtNascimento);
                            cout << "Paciente " << pacientes[posicao]->getDtNascimento() <<" com data de nascimento alterada para: " << auxDtNascimento << endl;
                            pacientes[posicao]->setDtNascimento(auxDtNascimento);
                        }
                        
                    } else {
                        cout << "CPF não encontrado! Digitação incorreta ou usuario não cadastrado" << endl;
                    }
                    break;

                case 4:
                    if (!pacientes.empty()) {
                        for (auto el : pacientes) {
                            cout << endl;
                            cout << "Nome: " << el->getNome() << endl;
                            cout << "CPF: " << el->getCpf() << endl;
                            cout << "Data de nascimento: " << el->getDtNascimento() << endl;
                            cout << endl;
                        }
                    } else {
                        cout << endl << "Nenhum paciente encontrado!" << endl;
                        cout << "Utilize a opção 1 para incluir um novo" << endl << endl;
                    }
                    break;

                case 5:
                    cout << "Informe o CPF do paciente: ";
                    getline(cin >> ws, auxCpf);
                    posicao = localizaPaciente(auxCpf);
                    if (posicao != -1) {
                        cout << "Paciente encontrado:" << endl;
                        cout << "Nome: " << pacientes[posicao]->getNome() << endl;
                        cout << "CPF: " << pacientes[posicao]->getCpf() << endl;
                        cout << "Data de Nascimento: " << pacientes[posicao]->getDtNascimento() << endl;
                    } else {
                        cout << "Paciente com CPF " << auxCpf << " não encontrado." << endl;
                    }
                    break;

                case 0:
                    return;

                default:
                    cout << "Informe uma das opções disponíveis. Numerais entre 0 e 5." << endl;
            }
        } while (op != 0);
    }
};

class CrudMedico {
public:
    int op;
    vector<Medico*> medicos;

    int localizaMedico(string _crm) {
        int i = 0;
        for (auto it : medicos) {
            if (it->getCrm() == _crm) {
                return i;
            }
            i++;
        }
        return -1;
    }

    void menu() {
        do {
            string auxCrm, auxEspecialidade, auxNome;
            int posicao = 0;
            string auxResposta = "0";
            Medico* medico = new Medico();

            cout << "--Cadastro de Medicos-- " << endl << endl;
            cout << "1. Incluir" << endl;
            cout << "2. Excluir" << endl;
            cout << "3. Alterar" << endl;
            cout << "4. Listar" << endl;
            cout << "5. Localizar" << endl;
            cout << "0. Voltar" << endl << endl;
            cin >> op;

            switch (op) {
                case 1:
                cout << "Informe o nome: ";
                getline(cin >> ws, auxNome);

                cout << "Informe o CRM: ";
                getline(cin >> ws, auxCrm);

                cout << "Informe a Especialidade: ";
                getline(cin >> ws, auxEspecialidade);

                medico->setNome(auxNome);
                medico->setCrm(auxCrm);
                medico->setEspecialidade(auxEspecialidade);
                medicos.push_back(medico);
                break;

                case 2:
                    cout << "Informe o CRM do Médico que deseja excluir: ";
                    getline(cin >> ws, auxCrm);
                    posicao = localizaMedico(auxCrm);
                    if (posicao != -1) {
                        cout << "Cadastro de paciente " << medicos[posicao]->getNome() << " excluído com sucesso!" << endl;
                        delete medicos[posicao];
                        medicos.erase(medicos.begin() + posicao);
                    } else {
                        cout << "Medico com CRM " << auxCrm << " não encontrado." << endl;
                    }
                    break;

                case 3:
                    cout << "Digite o CRM do Medico: ";
                    getline(cin >> ws, auxCrm);
                    posicao = localizaMedico(auxCrm);
                    if (posicao != -1) {
                        cout << "Medico " << medicos[posicao]->getNome() << " encontrado." << endl;
                        medicos[posicao]->imprimir();
                        cout << "Deseja alterar o nome? (S/N): ";
                        getline(cin >> ws, auxResposta);

                        if ((auxResposta == "S")||(auxResposta == "s")){

                            cout << "Informe o novo nome: ";
                            getline(cin >> ws, auxNome);
                            cout << "Paciente " << medicos[posicao]->getNome() <<" nome alterado para: " << auxNome << endl;
                            medicos[posicao]->setNome(auxNome);
                        }
                        cout << "Deseja alterar a especialidade? (S/N): ";
                        getline(cin >> ws, auxResposta);
                        if ((auxResposta == "S")||(auxResposta == "s")){
                            cout << "Informe a nova especialidade: ";
                            getline(cin >> ws, auxEspecialidade);
                            cout << "Medico " << medicos[posicao]->getNome() <<" alterado especialidade para: ";
                            medicos[posicao]->setEspecialidade(auxEspecialidade);
                            cout << medicos[posicao]->getEspecialidade() << endl;
                        }
                    } else {
                        cout << "CRM não encontrado! Digitação incorreta ou usuario não cadastrado" << endl;
                    }
                    break;

                case 4:
                    if (!medicos.empty()) {
                        for (auto el : medicos) {
                            cout << endl;
                            cout << "Nome: " << el->getNome() << endl;
                            cout << "CRM: " << el->getCrm() << endl;
                            cout << "Especialidade: " << el->getEspecialidade() << endl;
                            cout << endl;
                        }
                    } else {
                        cout << endl << "Nenhum medico encontrado!" << endl;
                        cout << "Utilize a opção 1 para incluir um novo" << endl << endl;
                    }
                    break;

                case 5:
                    cout << "Informe o CRM do medico: ";
                    getline(cin >> ws, auxCrm);
                    posicao = localizaMedico(auxCrm);
                    if (posicao != -1) {
                        cout << "Medico encontrado:" << endl;
                        cout << "Nome: " << medicos[posicao]->getNome() << endl;
                        cout << "CRM: " << medicos[posicao]->getCrm() << endl;
                        cout << "Especialidade: " << medicos[posicao]->getEspecialidade() << endl;
                    } else {
                        cout << "Medico com CPF " << auxCrm << " não encontrado." << endl;
                    }
                    break;

                case 0:
                    return;

                default:
                    cout << "Informe uma das opções disponíveis. Numerais entre 0 e 5." << endl;
            }
        } while (op != 0);
    }
};

int main() {
    CrudPaciente crudPaciente;
    CrudMedico crudMedico;

    int op;
    do {
        cout << "Seja bem ao Sistema de Gestão" << endl << "Clinica Médica Sem Dodói Ltda." << endl << endl;
        cout << "Escolha uma opção de gerenciamento" << endl << endl;
        cout << "1- Pacientes"<<endl;
        cout <<"2- Medicos"<< endl;
        cout <<"0- Sair" << endl;
        cin >> op;

        if (op == 1) {
            crudPaciente.menu();
        } else if (op == 2) {
            crudMedico.menu();
        }
        else if (op != 0) {
            cout << "Por favor escolha uma das opções válidas" << endl << endl;
        }
    } while (op != 0);

    cout << "Encerrando programa" << endl;
    
    return 0;
}
