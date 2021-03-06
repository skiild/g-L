#include "Catalogue.h"
vector<Capteur> Catalogue::capteur;
vector<Capteur> Catalogue::rechercherCapteursSimilaires(Capteur c, time_t debut, time_t fin)
{
	vector<Capteur> res;
	for (Capteur e : capteur)
		if (c.getId() != e.getId())
			for (Mesure m : c.getMesures()) {
				bool fini = false;
				//if (difftime(m.getTemps(), debut) > 0 && difftime(fin, m.getTemps()) > 0)
					for (Mesure n : e.getMesures())
						//if (difftime(n.getTemps(), debut) > 0 && difftime(fin, n.getTemps()) > 0)
							if (m.getValeur() == n.getValeur()) {
								res.push_back(e);
								fini = true;
								break;
							}
				if (fini)
					break;
			}
	return res;
}

int Catalogue::rechercherQualiteTerritoire(float r, float lon, float lat)
{
	return rechercherQualiteMoyenne(r, lon, lat, true);
}

int Catalogue::rechercherQualiteMoyenne(float r, float lon, float lat, bool zone)
{
	time_t limite = chrono::system_clock::to_time_t(chrono::system_clock::now() - chrono::hours(24));
	vector<CalculMoy> stats;
	for (unsigned int i = 0; i < 4; ++i) {
		CalculMoy x;
		stats.push_back(x);
	}
	for (Capteur c : capteur)
		if (!c.ChercherErreur() && (!zone || (abs(c.getLongitude() - lon) <= r && abs(c.getLattitude() - lat) <= r)))
			for (Mesure m : c.getMesures()) {
				//if (difftime(m.getTemps(), limite) > 0) {
					stats[m.getType()].valeur += m.getValeur();
					stats[m.getType()].compteur++;
				//}
			}
	return pireIndice(stats);
}

int Catalogue::pireIndice(vector<CalculMoy> &stats)
{
	stats[0].palier = { 30, 55, 80, 105, 130, 150, 180, 210, 240 };
	stats[1].palier = { 40, 80, 120, 160, 200, 250, 300, 400, 500 };
	stats[2].palier = { 30, 55, 85, 110, 135, 165, 200, 275, 400 };
	stats[3].palier = { 7, 14, 21, 28, 35, 42, 50, 65, 80 };
	for (CalculMoy &s : stats) {
		s.valeur = s.valeur / s.compteur;
		for (unsigned int i = 0; i < s.palier.size(); ++i)
			if (s.valeur < s.palier[i]) {
				s.indice = i + 1;
				break;
			}
	}
	return max({ stats[0].indice, stats[1].indice, stats[2].indice, stats[3].indice });
}

vector<Capteur> Catalogue::chercherCapteursDefectueux()
{
	vector<Capteur> res;
	for (Capteur c : capteur)
		if (c.ChercherErreur())
			res.push_back(c);
	return res;
}

vector<Mesure> Catalogue::afficherMesures(long idCapteur)
{
	vector<Mesure> res;
	for (Capteur c : capteur){
		if(c.getId() == idCapteur)
			return c.getMesures();
	}
	return res;
}

vector<Capteur> Catalogue::afficherCapteurs()
{
	return capteur;
}

void Catalogue::ajouterCapteur(Capteur c)
{
	capteur.push_back(c);
}

void Catalogue::ajouterMesure(long idCapteur, Mesure &m)
{
	for (Capteur& c : capteur) {
		if (c.getId() == idCapteur) {
			c.addMesure(m);
			break;
		}
	}
}