# [Versija v0.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1)
Programa nuskaito studentų vardus ir pavardes ir tada leidžia įvesti 
arba sugeneruoti atsitiktinai namų darbų ir egzaminų rezultatus, po to program
apskaičiuoja vidurkį arba medianą (pasirinktinai) ir išveda rezultatus.
# [Versija v0.1.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.1)
Programa atlaisvina dinamiškai paskirtą atmintį.
# [Versija v0.1.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.2)
Programa atnaujinta pakeičiant užsilikusius C masyvus į vektorius.
# [Versija v0.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.2)
Programa gali nuskaityti duomenis ne tik iš įvesties, bet ir iš failo, arba juos sugeneruoti. Rezultatai surikiuojami pagal studentų vardus ir pavardes ir išvedami į failą.
# [Versija v0.3](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.3)
Programa pertvarkyta į daug mažesnių kodo bei antraščių failų ir pradėtos naudoti išimtys.
# [Versija v0.4](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.4)
Programa dabar gali pati sugeneruoti pradinių duomenų failus ir rezultatus dalina į dvi grupes: tuos kurių vidurkis >= 5 ir likusius.

## Programos veikimo laiko analizė:
Studentų kiekis | Failų generavimas | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas | Jų surašymas į failus
--------------- | ----------------- | ------------------- | ------------------------------------- | ---------------------
1000 | 10.1487s | 0.106562s | 0.0106751s | 0.0914507s
10000 | 11.457s | 0.535841s | 0.0920975s | 0.795783s
100000 | 23.498s | 11.6074s | 1.06327s | 20.0915s
1000000 | 172.587s | 59.3968s | 11.5389s | 91.4407s
10000000 | 798.283s | 520.644s | 208.69s | 1510.09s

# [Versija v0.5](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.5)
Programa dabar suskirstyta į 3 versijas, su skirtingomis duomenų struktūromis: std::vector, std::list ir std::deque.

## Programos veikimo laiko analizė, su skirtingomis duomenų struktūromis:

### std::vector:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.164573s | 0.0178654s
10000 | 0.843864s | 0.152695s
100000 | 20.0737s | 1.73136s
1000000 | 87.6163s | 18.1514s
10000000 | 535.361s | 193.838s

### std::list:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.173245s | 0.0367772s
10000 | 0.795647s | 0.194006s
100000 | 19.6674s | 3.69981s
1000000 | 88.6772s | 20.79s
10000000 | 427.472s | 169.605s

### std::deque:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.199052s | 0.0743446s
10000 | 0.934598s | 0.35277s
100000 | 21.9512s | 7.51762s
1000000 | 99.7644s | 38.7584s
10000000 | 461.06s | 240.721s

### Kompiuterio parametrai
CPU | RAM | SSD
--- | --- | ---
Intel CORE i5 8th Gen | 8GB | 256GB
