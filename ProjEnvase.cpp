#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AtuadorLinha {
  private:
    string tag;
    string area;

  protected:
    double limitarPercentual(double percentual) const {
        if (percentual < 0.0) {
            return 0.0;
        } else if (percentual > 100.0) {
            return 100.0;
        } else {
            return percentual;
        }
    }

  public:
    AtuadorLinha(string tagNova, string areaNova)
        : tag(tagNova), area(areaNova) {}

    virtual ~AtuadorLinha() = default;
    /* O virtual permite que o ponteiro manipule o mesmo construtor e os mesmos métodos em diferentes objetos durante tempo de compilação. */
    /*Além disso garante que as informações da base fiquem "ocultas" para que as informações dos objetos sejam manipuladas, permitindo assim, o polimorfismo.*/

    string getTag() const {
        return tag;
    }

    string getArea() const {
        return area;
    }

    virtual void aplicarReferencialPercentual(double percentual) = 0;
    virtual void exibirResumo() const = 0;
};

class MotorEsteira : public AtuadorLinha {
    double frequenciaHz;

  public:
    MotorEsteira(string tagNova, string areaNova, double frequenciaHzNova)
        : AtuadorLinha(tagNova, areaNova), frequenciaHz(frequenciaHzNova) {}

    void aplicarReferencialPercentual(double percentual) override {
        percentual = limitarPercentual(percentual);
        frequenciaHz = (percentual / 100.0) * 60.0;
    }

    void exibirResumo() const override {
        cout << "Tag: " << getTag() << " | Area: " << getArea() << " | Frequencia: " << frequenciaHz << "Hz\n";
    }
};

class ValvulaDosagem : public AtuadorLinha {
  private:
    double aberturaPercentual;

  public:
    ValvulaDosagem(string tagNova, string areaNova, double aberturaPercentualNova)
        : AtuadorLinha(tagNova, areaNova), aberturaPercentual(aberturaPercentualNova) {}

    void aplicarReferencialPercentual(double percentual) override {
        percentual = limitarPercentual(percentual);
    }

    void exibirResumo() const override {
        cout << "Tag: " << getTag() << " | Area: " << getArea() << " | Abertura: " << aberturaPercentual << "%\n";
    }
};

int main() {
    int i;
    MotorEsteira E1("E100", "Planta1", 50.0);
    ValvulaDosagem V1("V100", "Planta1", 25.0);

    vector<AtuadorLinha *> atuadores = {&E1, &V1};
    const double referencia = 60.0;

    for (i = 0; i < atuadores.size(); i++) {
        AtuadorLinha *atuador = atuadores[i];
        atuador->aplicarReferencialPercentual(referencia);
    }

    for (i = 0; i < atuadores.size(); i++) {
        AtuadorLinha *atuador = atuadores[i];
        atuador->exibirResumo();
    }
}