#include <iostream>
#include <string>

using namespace std;

class SensorNivel { /* Classe criada para representar um sensor de nível. */
  private:          /* Atributos privados que só podem ser acessados dentro da classe. */
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

  public:
    explicit SensorNivel(string TagNova)
        : SensorNivel(TagNova, 0.0, 100.0, 0.0) {} /*Construtor de inicialização, que começa com a faixa padrão
                                                    de 0 a 100, sem leitura inicial.*/

    SensorNivel(string TagNova, double MinimoNovo, double MaximoNovo, double valorAtualNovo)  /*Construtor completo.*/
        : tag(TagNova), minimo(MinimoNovo), maximo(MaximoNovo), valorAtual(valorAtualNovo) {} /*Permite configurar todas as variáveis.*/

    void Resumo() const { /*Imprime as informações do sensor.*/
        cout << "[SensorNivel] " << tag << " | faixa: " << minimo << " a " << maximo << " | valor atual: " << valorAtual << "\n";
    }
};

class Bomba { /*Classe criada para representar uma bomba de nível. */
  private:
    string tag;
    double velocidade;

  public:
    explicit Bomba(string TagNova)
        : Bomba(TagNova, 0.0) {} /*Construtor de inicialização simples, sem ação.*/

    Bomba(string TagNova, double VelocidadeInicial)
        : tag(TagNova), velocidade(VelocidadeInicial) {
    } /*Permite configurar todas as variáveis.*/

    void Resumo() const { /*Imprime as informações da bomba.*/
        cout << "[Bomba] " << tag << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque { /*Classe criada para representar um controlador de tanque. */
  private:
    string tag;
    double setpoint;
    double kp;

  public:
    explicit ControladorTanque(string TagNova)
        : ControladorTanque(TagNova, 0.0, 1.0) {} /*Inicialização simples, com SP = 0.0 e KP = 1.0.*/

    ControladorTanque(string TagNova, double SetpointInicial, double KpInicial)
        : tag(TagNova), setpoint(SetpointInicial), kp(KpInicial) {
    } /*Permite ajustar os valores de SP e KP.*/

    void Resumo() const {
        cout << "[ControladorTanque] " << tag << " | SP = " << setpoint
             << " | Kp = " << kp << "\n";
    }
};

int main() {
    /*Em resumo, a sobrecarga de construtores permite criar objetos de diferentes formas, reutilizando o código.*/

    SensorNivel SentorL1("LT-401");
    SensorNivel SentorL2("LT-402", 0.0, 100.0, 73.2);

    Bomba B1("BL-101");
    Bomba B2("BL-102", 75.0);

    ControladorTanque Ctrl1("CL-201");
    ControladorTanque Ctrl2("CL-202", 85.0, 1.5);

    SentorL1.Resumo();
    SentorL2.Resumo();
    B1.Resumo();
    B2.Resumo();
    Ctrl1.Resumo();
    Ctrl2.Resumo();

    return 0;
}