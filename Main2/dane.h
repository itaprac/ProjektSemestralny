#include <iostream>
#include <string>

const size_t nImiona = 22;
const size_t nNazwiska = 17;
const size_t nUlice = 22;
const size_t nEmaile = 12;
const size_t nWydawnictwa = 12;
const size_t nTytuly = 20;
const size_t nDzialy = 10;
std::string_view Imiona[nImiona]{"Adam",   "Bartek", "Cezary", "Dawid",  "Emil",   "Filip",   "Grzegorz", "Henryk",
                                 "Igor",   "Janusz", "Kamil",  "Lukasz", "Marek",  "Norbert", "Oskar",    "Pawel",
                                 "Robert", "Stefan", "Tomasz", "Wiktor", "Szymon", "Jan"};

std::string_view Nazwiska[nNazwiska]{"Nowak",      "Kowalski",  "Wisniewski", "Dabrowski",     "Lewandowski",
                                     "Wojcik",     "Kaminski",  "Kowalczyk",  "Zielinski",     "Szymanski",
                                     "Wozniak",    "Kozlowski", "Jankowski",  "Wojciechowski", "Kwiatkowski",
                                     "Malinowski", "Zawadzki"};

std::string_view Ulice[nUlice]{"Mickiewicza", "Slowackiego",  "Sienkiewicza",  "Konopnickiej",   "Reymonta",
                               "Lelewela",    "Moniuszki",    "Pilsudskiego",  "Sobieskiego",    "Kosciuszki",
                               "Piastowska",  "Jagiellonska", "Wyspianskiego", "Matejki",        "Krasickiego",
                               "Orzeszkowej", "Kasprowicza",  "Staszica",      "Kochanowskiego", "Malczewskiego",
                               "Roosevelta",  "Churchilla"};

std::string_view Emaile[nEmaile]{"@gmail.com",  "@mail.com",   "@yahoo.com",    "@outlook.com",
                                 "@icloud.com", "@aol.com",    "@zoho.com",     "@protonmail.com",
                                 "@gmx.com",    "@yandex.com", "@fastmail.com", "@hotmail.com"};

std::string_view Wydawnictwa[nWydawnictwa]{
    "Wydawnictwo Literackie", "Wydawnictwo Naukowe PWN", "Wydawnictwo Znak",      "Wydawnictwo Ossolineum",
    "Wydawnictwo Czarne",     "Wydawnictwo WAB",         "Wydawnictwo Iskry",     "Wydawnictwo Zysk",
    "Wydawnictwo Otwarte",    "Wydawnictwo Agora",       "Wydawnictwo Marginesy", "Wydawnictwo Noir sur Blanc"};

std::string_view Dzialy[nDzialy]{"Literatura Polska", "Literatura Obca", "Fantastyka",      "Kryminał",
                                 "Sensacja",          "Horror",          "Science Fiction", "Biografia",
                                 "Historyczna",       "Popularnonaukowa"};

std::string_view Tytuly1[nTytuly]{"Cicha",      "Wieczna",  "Złota",    "Ostatnia",   "Zaginiona",
                                  "Tajemnicza", "Stara",    "Pierwsza", "Zimowa",     "Letnia",
                                  "Wiosenna",   "Jesienna", "Północna", "Południowa", "Wschodnia",
                                  "Zachodnia",  "Czarna",   "Biała",    "Szara",      "Czerwona"};

std::string_view Tytuly2[nTytuly]{"Noc",      "Wieża",     "Róża",    "Księga",  "Droga",    "Przepaść", "Łąka",
                                  "Pustynia", "Tajemnica", "Burza",   "Rzeka",   "Światło",  "Cisza",    "Gwiazda",
                                  "Kraina",   "Pieśń",     "Ścieżka", "Forteca", "Przystań", "Opowieść"};