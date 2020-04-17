# Įdiegimo instrukcija:
1. Atsisiųskite norimą programos versiją iš „Releases“ skilties arba naudodami `git clone https://github.com/mxstrong/2-uzduotis-2.git` nusikopijuokite kodą į pasirinktą aplanką (senesnėms programos versijoms gauti eikite į [repozitoriją](https://github.com/mxstrong/2-uzduotis) arba naudokite `git clone https://github.com/mxstrong/2-uzduotis.git`).
2. Pasirinkite aplanką, kuriame yra jūsų norima versija ir jį atsidarykite komandinėje eilutėje.
3. Unix sistemoje Paleiskite Makefile naudodami komandą `make` (Reikalingas clang kompiliatorius, jei jo neturite, atsisiųskite iš https://releases.llvm.org/download.html arba nurodykite kitą kompiliatorių: `make CC='[Kompiliatoriaus pavadinimas]'`(pvz. `make CC='g++'`)).
4. Pasileiskite programą naudodami komandą: `./[Paleidžiamojo failo vardas]` (Students, Deque, Deque-2, List, List-2, Vector arba Vector-2).

# Naudojimo instrukcija:
* Pasirinkite ar daryti programos veikimo laiko analizę.
  * Jei pasirinkote Taip: 
    * Įveskite kiek failų generuoti.
    * Įveskite kiek studentų turi buti kiekviename faile.
    * Įveskite failų vardus.
    * Pasirinkite ką naudosite galutinio balo skaičiavimui - vidurkį ar medianą.
  * Jei pasirinkote Ne:
    * Pasirinkite iš kur gauti pradinius duomenis.
      * Jei pasirinkote įvesti:
        * Pasirinkite kelių studentų duomenis norite įvesti.
        * Įveskite kiekvieno studento vardą, pavardę, namų darbų rezultatus ir egzamino pažymį.
        * Pasirinkite ką naudoti galutinio balo skaičiavimui (vidurkį ar medianą).
      \
     * Jei pasirinkote generuoti:
        * Pasirinkite kiek studentų sugeneruoti.
        * Įveskite norimo sugeneruoti failo vardą.
        * Pasirinkite ką naudoti galutinio balo skaičiavimui (vidurkį ar medianą).
      \
     * Jei pasirinkote skaityti iš failo:
        * Įveskite duomenų failo vardą.
        * Pasirinkite ką naudoti galutinio balo skaičiavimui (vidurkį ar medianą).
        
# Versijų istorija:
# [Versija v1.1](https://github.com/mxstrong/2-uzduotis-2/releases/tag/v1.1)
Programa buvo pertvarkyta, kad vietoj struktūtų būtų naudojamos klasės. Makefile buvo atnaujintas, kad būtų galima pasirinkti kitą kompiliatorių, o ne tik Clang, kuris naudojamas pagal nutylėjimą ir taip pridėta galimybė perduoti kompiliatoriui vėliavėles. Atitinkamai atnaujinta įdiegimo intrukcija. Pertvarkytas README.md failas, kad būtų patogiau jį skaityti.

## Realizacijų su struktūromis ir klasėmis spartos palyginimas naudojant skirtingas optimizavimo vėlevėles:

### Realizacija su struktūromis
Optimizavimo lygis | Studentų kiekis | Studentų generavimas | Failų generavimas | Studentų rikiavimas | Studentų dalijimas | Pažangių studentų surašymas į failą | Nepažangių studentų surašymas į failą | Visas programos veikimo laikas
------------------ | --------------- | -------------------- | ----------------- | ------------------- | ------------------ | ------------------------------------- | ------------------------------------- | ------------------------------
O0 | 100000 | 8.79207s | 1.8715s | 0.539056s | 0.075302s | 0.529118s | 0.516372s | 12.3711s
O0 | 1000000 | 99.8932s | 23.5658s | 36.126s | 4.724s | 9.27253s | 9.1843s | 183.434s
O1 | 100000 | 2.5265s | 0.580496s | 0.534772s | 0.0681022s | 0.506144s | 0.496437s | 4.75348s
O1 | 1000000 | 54.0644s | 12.2552s | 6.50643s | 0.73036s | 6.34312s | 6.27112s | 86.5149s
O2 | 100000 | 2.53614s | 0.55653s | 0.527959s | 0.065899s | 0.502331s | 0.490639s | 4.71863s
O2 | 1000000 | 47.3382s | 10.823s | 7.01431s | 1.41166s | 5.13762s | 5.13161s | 77.2176s
O3 | 100000 | 9.23115s | 2.13202s | 0.53676s | 0.0755792s | 0.536876s | 0.542889s | 13.1272s
O3 | 1000000 | 26.8457s | 6.41903s | 51.6167s | 6.9785s | 9.39205s | 10.1993s | 111.758s

### Realizacija su klasėmis
Optimizavimo lygis | Studentų kiekis | Studentų generavimas | Failų generavimas | Studentų rikiavimas | Studentų dalijimas | Pažangių studentų surašymas į failą | Nepažangių studentų surašymas į failą | Visas programos veikimo laikas
------------------ | --------------- | -------------------- | ----------------- | ------------------- | ------------------ | ------------------------------------- | ------------------------------------- | ------------------------------
O0 | 100000 | 2.97253s | 0.693766s | 0.702667s | 0.0724155s | 0.506103s | 0.495282s | 5.48166s
O0 | 1000000 | 55.219s | 15.2347s | 8.82869s | 0.969558s | 5.90437s | 6.45459s | 92.9973s
O1 | 100000 | 6.58311s | 1.34273s | 1.04617s | 0.200828s | 1.15753s | 0.624s | 10.9985s
O1 | 1000000 | 29.8749s | 7.23805s | 9.06979s | 0.727013s | 6.26406s | 6.86356s | 60.3589s
O2 | 100000 | 4.25523s | 0.95603s | 0.66821s | 0.08555s | 0.524508s | 0.517556s | 7.04778s
O2 | 1000000 | 27.4779s | 7.14568s | 8.59512s | 0.738729s | 6.36322s | 6.22027s | 56.9681s
O3 | 100000 | 3.40846s | 0.787401s | 0.709763s | 0.0746906s | 0.509482s | 0.505135s | 6.03558s
O3 | 1000000 | 34.6857s | 7.00862s | 9.2618s | 0.754081s | 5.7023s | 5.79412s | 63.5294s

# [Versija v1.0.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v1.0.1)
Buvo atnaujinta programos sąsaja su vartotoju komandinėje eilutėje, taip pat minimaliai atnaujinta programos veikimo laiko analizė. Buvo sukurti nauji Makefile tam, kad programa veiktų Unix tipo sistemose. Sukūrus Makefile ir atnaujinus vartotojo sąsają atitinkamai buvo atnaujintos programos įdiegimo ir naudojimo instrukcijos.

# [Versija v1.0](https://github.com/mxstrong/2-uzduotis/releases/tag/v1.0)
Programa buvo pertvarkyta ir ženkliai optimizuota ir todėl atnaujintos programos spartos analizės. Programa dabar taiko 2 skirtingas strategijas studentams surūšiuoti į dvi grupes.

## Studentų rūšiavimo strategijų palyginimas:
1 strategija - studentų konteinerį padalinti į du konteinerius\
2 strategija - iš studentų konteinerio perkelti kriterijų atitinkančius studentus į naują konteinerį

Studentų kiekis | std::vector 1 strategija | std::vector 2 strategija | std::list 1 strategija | std::list 2 strategija | std::deque 1 strategija | std::deque 2 strategija
--------------- | ------------------------ | ------------------------ | ---------------------- | ---------------------- | ---------------------- | -----------------------
1000 | 0.0003923s | 0.0001764 | 0.0007535s | 0.0005547s | 0.0006412s |  0.0004933s
10000 | 0.0027093s | 0.0016226s | 0.0063385s | 0.0077404s | 0.0069454s | 0.0070327s
100000 | 0.0382856s | 0.0184986s | 0.146764s | 0.102567s | 0.0954378s | 0.0729289s
1000000 | 0.469434s | 0.241298s | 1.09972s | 1.14836s | 0.83865s | 0.769068s
10000000 | 4.23923s | 2.44195s | 9.35601s | 9.33468s | 11.5791s | 7.82477s

2 strategija daugeliu atvejų yra greitesnė, išskyrus su std::list, kur vykdymo laikas panašus ir su std::deque naudojant apie 10000 įrašų, bet su mažiau arba daugiau įrašų std::deque programos implementacija veikia šiek tiek greičiau naudojant 2 strategiją. Ženkliausi skirtumai pastebimi su std::vector, kur 2 strategija beveik du kartus greitesnė.

# [Versija v0.5](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.5)
Programa dabar suskirstyta į 3 versijas, su skirtingomis duomenų struktūromis: std::vector, std::list ir std::deque.

## Programos veikimo laiko analizė, su skirtingomis duomenų struktūromis:

### std::vector:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas | Visas laikas
--------------- | ------------------- | ------------------------------------- | ------------
1000 | 0.0056261s | 0.0003923s | 0.0060184s
10000 | 0.0460614s | 0.0027093s | 0.0487707s
100000 | 1.1548s | 0.0382856s | 1.1930856s
1000000 | 5.41935s | 0.469434s | 5.888784s
10000000 | 44.3545s | 4.23923s | 48.59373s

### std::list:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas | Visas laikas
--------------- | ------------------- | ------------------------------------- | ------------
1000 | 0.0089173s | 0.0007535s | 0.0096708s
10000 | 0.0467701s | 0.0063385s | 0.0531086s
100000 | 1.22308s | 0.146764s | 1.369844s
1000000 | 6.05603s | 1.09972s | 7.15575s
10000000 | 47.787s | 9.35601s | 57.14301s

### std::deque:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas | Visas laikas
--------------- | ------------------- | ------------------------------------- | ------------
1000 | 0.0102834s | 0.0006412s | 0.0109246s
10000 | 0.049512s | 0.0069454s | 0.0564574s
100000 | 1.20976s | 0.0954378s | 1.3051978s
1000000 | 5.60804s | 0.83865s | 6.44669s
10000000 | 50.1963s | 11.5791s | 61.7754s

Greičiausiai šioje programoje veikia std::vector duomenų struktūra, kitos duomenų struktūros šias užduotis atlieka lėčiau, o programos veikimo laiko augimas tarp struktūrų panašus.

# [Versija v0.4](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.4)
Programa dabar gali pati sugeneruoti pradinių duomenų failus ir rezultatus dalina į dvi grupes: tuos kurių vidurkis >= 5 ir likusius.

## Programos veikimo laiko analizė:
Studentų kiekis | Studentų generavimas | Failų generavimas | Duomenų nuskaitymas | Studentų rikiavimas | Studentų rūšiavimas į dvi kategorijas | Pažangių studentų surašymas į failą | Nepažangių studentų surašymas į failą | Visas programos veikimo laikas
--------------- | -------------------- | ----------------- | ------------------- | ------------------- | ------------------------------------- | ----------------------------------- | ------------------------------------- | ------------------------------
1000 | 3.79208s | 0.0055796s | 0.0056261s | 0.0015246s | 0.0003923s | 0.0051052s | 0.00039824s | 17.2514s
10000 | 3.21854s | 0.0365878s | 0.0460614s | 0.0152302s | 0.0027093s | 0.0355636s | 0.0372222s | 13.7339s
100000 | 9.52402s | 0.786247s | 1.1548s | 0.421733s | 0.0382856s | 0.414563s | 0.307117s | 27.857s
1000000 | 29.3251s | 4.1484s | 5.41935s | 1.69674s | 0.469434s | 3.55203s | 3.61551s | 32.1945s
10000000 | 165.339s | 36.2581s | 44.3545s | 17.6408s | 4.23923s | 36.4908s | 42.16s | 164.168s

Bendras programos veikimo laikas auga šiek tiek mažiau kartų nei duomenų kiekis, todėl šis augimas yra logaritminis. Galima išskirti studentų rikiavimą ir rašymą į failus kaip greičiausiai augančias operacijas veikimo laiko prasme.

# [Versija v0.3](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.3)
Programa pertvarkyta į daug mažesnių kodo bei antraščių failų ir pradėtos naudoti išimtys.

# [Versija v0.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.2)
Programa gali nuskaityti duomenis ne tik iš įvesties, bet ir iš failo, arba juos sugeneruoti. Rezultatai surikiuojami pagal studentų vardus ir pavardes ir išvedami į failą.

# [Versija v0.1.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.2)
Programa atnaujinta pakeičiant užsilikusius C masyvus į vektorius.

# [Versija v0.1.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.1)
Programa atlaisvina dinamiškai paskirtą atmintį.

# [Versija v0.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1)
Programa nuskaito studentų vardus ir pavardes ir tada leidžia įvesti 
arba sugeneruoti atsitiktinai namų darbų ir egzaminų rezultatus, po to program
apskaičiuoja vidurkį arba medianą (pasirinktinai) ir išveda rezultatus.

# Spartos analizėms naudoto kompiuterio parametrai
CPU | RAM | SSD
--- | --- | ---
Intel CORE i5 8th Gen | 8GB | 256GB



