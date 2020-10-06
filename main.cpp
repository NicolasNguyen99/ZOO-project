#include <iostream>
using namespace std;

class Auto{
	float m_najeto;
	float m_cenaZaDen;
	float m_vydelalo;

public:
	Auto(float najeto, float cenaZaDen, float vydelalo){
		m_najeto = najeto;
		m_cenaZaDen = cenaZaDen;
		m_vydelalo = vydelalo;
	}
}

int main(){
	Auto* ford = new Auto(10000, 500, 0);

	delete ford;
	return 0;
}