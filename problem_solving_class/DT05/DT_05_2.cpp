#include <iostream>
#include<string>
// getline(istream, str); -> istream getur verið cin eða ifstream
// str.find_first_of(str2)
// str.find_first_not_of(str2)
// str.find(str2)
// str.insert(pos, str2)
// str.erase(pos, n)
// str.length()

#include <cctype>
// isalpha(character)
// tolower(character)

#include<fstream>
// ifstream
// ofstream
// stream.open()
// stream.close()
// stream.fail()

#include<cstdlib>
// exit

using namespace std;

// Föll til að opna straum/skrá
void openInFile(ifstream& fin, string filename);
void openOutFile(ofstream& fout, string filename);

// Fall sem les í fylki
void readData(string array[], int size, istream& in );
// Fall sem prentar út öll stök í fylki
void printArray(string array[], int size, ostream& out);

// Föll til að laga strenginn
void fixNumber( string &line);
void downBarToSpace(string &line);
void dashForDot(string &line);
void bigFirstLetter(string &line);
void smallMP3(string &line);
void smallMP3_2(string &line);

// Fall sem athuga hvort eigi að breyta streng eða ekki
bool fixLine(string &line);

// Skilgreini stærðina á fylkinu sem fasta þar sem ekki má breyta henni á keyrslutíma.
// skráin okkar inniheldur 10 línur svo við skilgreinum stærðina sem 10
const int SIZE = 10;

int main()
{
    // staðsetning á skránni
    string filename = "C:\\Users\\sarakri13\\Desktop\\songlist.txt";

    // straumur sem við munum tengja við skránna
    ifstream fin;

    openInFile(fin, filename);

    // Skilgreinum strengja fylki af stærð SIZE
    string fylki[SIZE];

    // Fall sem les úr skránni í fylkið.
    // Hver lína í skránni verður eitt stak í fylkinu
    readData(fylki, SIZE, fin);

    // þar sem við erum búin að sækja gögnin þá getum við lokað straumnum/skránni aftur
    fin.close();

    // ítrum okkur í gegnum fylkið og eitt stak í einu -> þ.e eina línu í einu
    // og lögum hana ef það á að gera það
    for( int i = 0; i < SIZE; i++)
    {
        // athugum hvort það eigi að laga stak númer i í fylkinu
        if(fixLine(fylki[i]))
        {
            // lögum tölustafina úr 1.texti í 01.texti
            fixNumber(fylki[i]);
            // breytum öllum "_" í bil
            downBarToSpace(fylki[i]);
            // breytum 01.texti í 01 - texti
            dashForDot(fylki[i]);
            // breytum fyrsta staf í hverju orði í hástaf
            bigFirstLetter(fylki[i]);
            // breytum "MP3" í "mp3"
            smallMP3(fylki[i]);
        }
    }

    // Skilgreinum straum sem verður notaður til að skrifa í skrá
    ofstream fout;

    // skilgreinum skránna sem á að skrifa í
    // ef hún er ekki til þá býr forritið hana til. Ef hún er til þá er hún yfirskrifuð
    string outputFileName = "C:\\Users\\sarakri13\\Desktop\\prettysonglist.txt";

    // Opnum skránna sem við ætlum að skrifa í
    openOutFile(fout, outputFileName);

    // Skrifum gildin úr fylkinu okkar í skránna
    printArray(fylki, SIZE, fout);

    // lokum skránni
    fout.close();

    return 0;
}

// Fall sem opnar ifstream þ.e inntaksskrá
void openInFile(ifstream& fin, string filename)
{
    fin.open(filename.c_str());

    if(fin.fail())
    {
        cout << " gat ekki opnað skrá" << endl;
        exit(1);
    }
}

// Fall sem opnar ofstream þ.e úttaksskrá
void openOutFile(ofstream& fout, string filename)
{
    fout.open(filename.c_str());

    if(fout.fail())
    {
        cout << " gat ekki opnað skrá " << endl;
        exit(2);
    }
}

// Fall sem les inní fylki þar sem stökin eru strengir.
// Hægt er að nota fallið bæði með skrá og cin
// Dæmi um hvernig fallið væri notað með skrá
//
//  ifstream fin;
//  openInFile(fin, filename);
//  readData(fylki, SIZE, fin);
//
// Dæmi um hvernig væri kallað á fallið með cin
//  Hér þarf notandinn sjálfur að skrifa inn gögnin af lyklaborði
//
//  readData(fylki, SIZE, cin);
void readData(string array[], int size, istream& in )
{
    for( int i = 0; i < size; i++)
    {
        // nota getline því ég vil fá eina línu í hvert stak
        getline(in, array[i]);
    }
}

// Fall sem prentar út öll stökin í fylkinu
// Hægt er að nota fallið bæði með skrá og cout
// Dæmi um hvernig fallið væri notað með skrá
//      Hér myndu stökin í fylkinu skrifast í skrá
//
//  ofstream fout;
//  openOutFile(fout, output_filename);
//  printArray(fylki, SIZE, fout);
//
// Dæmi um hvernig væri kallað á fallið með cout
//      Hér myndu stökin í fylkinu skrifast á skjáinn
//
//  printArray(fylki, SIZE, cout);

void printArray(string array[], int size, ostream& out)
{
    for( int i = 0; i < size; i++)
    {
        out << array[i] << endl;
    }
}

// Fall sem breytir streng þannig að ef hann lítur svona út í byrjun
// 1.þetta er strengur
// Verður hann að
// 01.þetta er strengur
void fixNumber( string &line)
{
    unsigned int pos = 0;

    // Við viljum finna staðsetninguna á fyrsta stakinu sem er ekki tölustafur
    pos = line.find_first_not_of("0123456789"); //  hefðum líka getað gert -> pos = line.find_first_of(".");
    // Erum að ganga úr skugga um að fyrsta punkturinn sé stak númer 1, þ.e að strengurinn líti svona út
    // 1.þetta er strengur
    if( pos == 1)
    {
        // insert skipunin virkar svona
        // line.insert(pos, str) -> bætum við strengnum str í staðsetningu pos
        // bætum strengnum "0" inn í stak númer 0 í line.
        // öll hin stökin færast þá eitt sæti til hægri.
        line.insert(0,"0");
    }
}
// Fall sem tekur inn streng og breytir öllum niðurstrikum _ í bil
void downBarToSpace(string &line)
{
    unsigned int pos = 0;
    // Finnum staðsetningu á fyrsta "_"
    pos = line.find_first_of("_");

    // Ef það er ekkert "_" í strengnum þá skilar fallið line.find_first_of("_")
    // gildi sem er miklu stærra en lengt strengsins.
    // While lykkjan keyrir þá þangað til strengurinn inniheldur ekkert "_"
    while(pos < line.length())
    {
        // erase skipunin virkar svona
        // line.erase(pos, n) -> byrjum að eyða úr strengnum á staðsetningu pos og eyðum n stökum
        // stakið sem er í staðsetningu pos er "_". Við viljum því byrja að eyða í pos og viljum eyða einu staki.
        line.erase(pos,1);
        // pos er staðsetningin þar sem "_" var og við viljum því bæta við bili í þá staðsetningu í staðin
        line.insert(pos," ");
        // uppfærum pos breytuna og finnum næsta "_"
        // ef við værum ekki að eyða út "_" þá þyrftum við að gera
        // pos = line.find_first_of("_", pos + 1);
        // þ.e finna næsta niðurstrik sem er á eftir staðsetningu pos + 1
        pos = line.find_first_of("_");
    }
}

// Fall sem tekur inn streng og eyðir skiptir út fyrsta punktinum fyrir bandstrik eða " - "
void dashForDot(string &line)
{
    unsigned int pos = 0;

    // Finnum staðsetningu á fyrsta punktinum
    pos = line.find_first_of(".");

    // Ef strengurinn inniheldur punkt þá skilar line.find_first_of(".")
    // gildi sem er minni heldur en lengd strensins.
    // Ef strengurinn inniheldur punkt þá ætlum við að skipta honum út
    if( pos < line.length())
    {
        // stakið sem er í staðsetningu pos er ".". Við viljum því byrja að eyða í pos og viljum eyða einu staki.
        line.erase(pos,1);
        // pos er stasetningin þar sem punkturinn var.
        // við viljum því bæta við " - " í þá staðsetningu
        line.insert(pos, " - ");
    }

}

// Fall sem tekur inn streng og breytir fyrsta staf í hverju orði í hástaf
// Gert er ráð fyrir að orð séu aðskilin með bili
void bigFirstLetter(string &line)
{
    unsigned int pos = 0;

    // finnum staðsetningu á fyrsta bilinu
    pos = line.find_first_of(" ");

    // Til að koma í veg fyrir að við vísum út fyrir strenginn
    while( pos < ( line.length()-1 ) )
    {
        // athugum hvort að næsta stak á eftir bilinu sé bókstafur
        // ef þetta er ekki bókstafur þá viljum við ekkert gera viðs takið
        if(isalpha(line[pos + 1]))
        {
            // breytir næsta staki á eftir bilinu í hástaf
            // toupper er innbyggð skipun sem tekur inn char
            line[pos + 1] = toupper(line[pos + 1]);
        }

        // Finnum næsta bil á eftir bilinu okkar í strengnum.
        // bilið okkar var staðsett í pos, þá viljum við byrja að leita af bili í pos+1
        pos = line.find_first_of(" ", pos + 1);
    }
}

// Fall sem tekur inn streng. Ef strengurinn inniheldur MP3 þá breytir fallið
// því í mp3
void smallMP3(string &line)
{
    unsigned int pos = 0;

    //find skipunin virkar svona
    // pos = line.find(str) -> ef line inniheldur strenginn str þá verður pos staðsetninginn á fyrsta skainu í str
    pos = line.find("MP3");
    // Ef line inniheldur "MP3" þá er pos staðsetning á M í line. Ef line inniheldur ekki "MP3"
    // þá verður pos stærri en lengdin á line
    if(pos < line.length())
    {
        // eyðum út 3 sökum úr staðsetningu pos
        line.erase(pos,3);
        // bætum "mp3" inn í staðsetningu pos í staðin
        line.insert(pos, "mp3");
    }
}

// ÖNNUR AÐFERÐ
// Fall sem tekur inn streng. Ef strengurinn inniheldur MP3 þá breytir fallið
// því í mp3
// Fallið notar skipunina tolower
void smallMP3_2(string &line)
{
    unsigned int pos = 0;

    string str = "MP3";

    // finnum staðsetningu á str í line, þ.e finnum staðsetningu á "MP3" í line
    pos = line.find(str);

    // ef line inniheldur strenginn str þá ætlum viljum breytum við str í lástafi
    if(pos < line.length())
    {
        // látum forlykkjuna byrja í pos þar sem pos er staðsetningin á fyrsta stakinu í str
        // þ.e pos er staðsetning á M
        // Ef line lítur svona út
        // stutt.MP3
        // 012345678
        // þá er pos = 6
        // við viljum breyta öllum strengnum "MP3" í lástafi þannig stöðvunarskilyrði er
        // i < pos + str.length()
        // ->  str.length() = 3,
        //     pos + str.length() = 9
        //     seinasta stak í str er stak númer 8 í line svo i < pos + str.length()
        for( unsigned int i = pos; i < pos + str.length(); i++ )
        {
            line[i] = tolower(line[i]);
        }
        // Það hefði verið hægt að sleppa forlykkjunni og gera þetta í staðinn
        // Ef strenguinn okkar hefði verið langur þá er miklu hendtugara að kunna forlykkjuna
        //line[pos] = tolower(line[pos]);
        //line[pos+1] = tolower(line[pos+1]);
        //line[pos+2] = tolower(line[pos+2]);
    }
}

// Fall sem athugar hvort það eigi að breyta streng eða ekki
// það á að breyta streng ef hann byrjar á "//"
bool fixLine(string &line)
{
    // Við viljum athuga hvort line[0]=='/' og line[1] == '/'.
    // Með því að gera line.length() > 1, þá er ég að fullvissa mig um að line innihaldi amk 2 stök
    // Ef line væri tómur strengur eða bara eitt stak, þá værum færum við út fyrir strenginn
    // þegar við getum line[1] == '/'
    if(line.length() > 1 && line[0] == '/' && line[1] == '/')
    {
        // Ef fyrstu 2 stökin eru // þá á ekki að laga strenginn
        return false;
    }
    return true;
}
