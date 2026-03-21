#include <iostream>
#include <string>

using namespace std;

class AtivoCampo { /*Classe para representar um ativo de campo.*/
  private:
    string tag;
    bool bloqueado;

  protected: /*Área do ativo que pode ser herdada por outras classes.*/
    string area;

    void redefinirArea(string novaArea) { /* Método para redefinir a área do ativo.*/
        area = novaArea;
    }

  public:
    AtivoCampo(string TagNova, string AreaNova) : tag(TagNova), bloqueado(false), area(AreaNova) {} /*Construtor da classe.*/

    string getTag() const {
        return tag;
    }

    bool estaBloqueado() const {
        return bloqueado;
    }

    void bloquear() {
        bloqueado = true;
    }

    void liberar() {
        bloqueado = false;
    }
};

class SensorNivel : public AtivoCampo { /*Classe para representar um sensor de nível, que herda de AtivoCampo.*/
  private:
    double nivelAtual;
    double limiteAlto;

  public:
    explicit SensorNivel(string Tagnova, string AreaNova)                      /*Construtor da classe SensorNivel.*/
        : AtivoCampo(Tagnova, AreaNova), nivelAtual(0.0), limiteAlto(100.0) {} /*Lista de inicialização.*/

    SensorNivel(string Tagnova, string AreaNova, double NivelAtualNovo, double LimiteAltoNovo)     /*Construtor completo.*/
        : AtivoCampo(Tagnova, AreaNova), nivelAtual(NivelAtualNovo), limiteAlto(LimiteAltoNovo) {} /*Lista de inicialização.*/

    void atualizarNivel(double novoNivel) { /*Método para atualizar o nível, com verificação de bloqueio.*/
        if (estaBloqueado()) {
            return;
        }
        if (novoNivel < 0.0) {
            nivelAtual = 0.0;
        } else if (novoNivel > limiteAlto) {
            nivelAtual = limiteAlto;
        } else {
            nivelAtual = novoNivel;
        }
    }
    void Resumo() const { /*Método para imprimir o resumo das informações do sensor.*/
        cout << "Tag: " << getTag() << " | Área: " << area << " | Nível: " << nivelAtual << " | Limite Alto: " << limiteAlto << "\n";
    }

    friend void verificarNivel(const SensorNivel &sensor) {
        /*Função amiga para verificar o nível do sensor, que pode acessar os membros privados da classe, porem sem modificar.*/
        if (sensor.nivelAtual > sensor.limiteAlto) {
            cout << "Alerta: Nível acima do limite!\n";
            cout << "Nível atual: " << sensor.nivelAtual << "\n"
                 << "Limite alto: " << sensor.limiteAlto << "\n";

        } else {
            cout << "Nível dentro do limite.\n"
                 << "Nível atual: " << sensor.nivelAtual << "\n";
        }
    }
};

class BombaDosadora : public AtivoCampo { /*Classe para representar uma bomba dosadora, que herda de AtivoCampo.*/
  private:
    double vazaoPercentual;

  public:
    explicit BombaDosadora(string Tagnova, string AreaNova, double novaVazao) /*Construtor da classe BombaDosadora.*/
        : AtivoCampo(Tagnova, AreaNova), vazaoPercentual(novaVazao) {}        /*Lista de inicialização.*/

    void ajustarVazao(double novaVazao) { /*Método para ajustar a vazão da bomba, com verificação de bloqueio.*/
        if (estaBloqueado()) {
            return;
        }
        if (novaVazao < 0.0) {
            novaVazao = 0.0;
        } else if (novaVazao > 100.0) {
            novaVazao = 100.0;
        } else {
            vazaoPercentual = novaVazao;
        }
    }
    void moverParaArea(string novaArea) { /*Método para mover a bomba para uma nova área, com verificação de bloqueio.*/
        if (estaBloqueado()) {
            return;
        }
        redefinirArea(novaArea); /*Chama o método protegido da classe base para redefinir a área.*/
    }

    void Resumo() const { /*Método para imprimir o resumo das informações da bomba.*/
        cout << "Tag: " << getTag() << " | Área: " << area << " | Vazão: " << vazaoPercentual << "%\n\n";
    }
};

int main() {
    SensorNivel S1("S200", "Tanque A", 45.0, 100.0); /*Objeto da classe SensorNivel com valores iniciais.*/
    BombaDosadora B1("B127", "Tanque A", 55.0);      /*Objeto da classe BombaDosadora com valores iniciais.*/

    S1.Resumo(); /*Resumos.*/
    B1.Resumo();

    verificarNivel(S1); /*Verificação do nível do sensor usando a função friend.*/

    return 0;
};