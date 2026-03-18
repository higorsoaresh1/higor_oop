#include <iostream>
#include <string>

using namespace std;

class SensorLT {
private:
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

public:
    explicit SensorLT(string TagNova)
        : SensorLT(TagNova, 0.0, 100.0, 0.0) {}

    SensorLT(string TagNova, double MinimoNovo, double MaximoNovo, double valorAtualNovo)
        : tag(TagNova), minimo(MinimoNovo), maximo(MaximoNovo), valorAtual(valorAtualNovo) {}

    void Resumo() const {
        cout << "[SensorLT] " << tag
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};

class BombaLT {
private:
    string tag;
    double velocidade;

public:
    explicit BombaLT(string TagNova)
        : BombaLT(TagNova, 0.0) {} 

    BombaLT(string TagNova, double VelocidadeInicial)
        : tag(TagNova), velocidade(VelocidadeInicial) {}

    void Resumo() const {
        cout << "[BombaLT] " << tag
             << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque {
private:
    string tag;
    double setpoint;
    double kp;

public:
    explicit ControladorTanque(string TagNova)
        : ControladorTanque(TagNova, 0.0, 1.0) {}

    ControladorTanque(string TagNova, double SetpointInicial, double KpInicial)
        : tag(TagNova), setpoint(SetpointInicial), kp(KpInicial) {}

    void Resumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    SensorLT SentorL1("LT-401");
    SensorLT SentorL2("LT-402", 0.0, 100.0, 73.2);

    BombaLT B1("B-101");
    BombaLT B2("B-102", 75.0);

    ControladorTanque Ctrl1("CT-201");
    ControladorTanque Ctrl2("CT-202", 50.0, 1.5);

    SentorL1.Resumo();
    SentorL2.Resumo();
    B1.Resumo();
    B2.Resumo();
    Ctrl1.Resumo();
    Ctrl2.Resumo();

    return 0;
}