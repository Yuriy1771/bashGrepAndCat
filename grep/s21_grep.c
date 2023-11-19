#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

typedef struct {
//-------------------------------------------ВАЖНО-------------------------------------------
    bool flagE; //Шаблон
    bool flagI; //Выводит все совпадающие строки игнорируя различия регистра. (я - Я)
    bool flagV; //Показывает только несовпавшие строки.
    bool flagC; //Выводит только количество совпадающих строк.
    bool flagL; //Выводит только совпадающие файлы.
    bool flagN; //Выводит номера строк где есть совпадения.
//-------------------------------------------ДОПОЛНИТЕЛЬНО-------------------------------------------
    bool flagH; //Выводит совпадающие строки, не предваряя их именами файлов.
    bool flagS; //Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах.
    bool flagF; //Получает регулярные выражения из файла.
    bool flagO; //Печатает только совпадающие (непустые) части совпавшей строки.
}Flags;
    Flags flags;


Flags readFlags(int argc, char* argv[]) {
    int currentFlag = getopt(argc, argv, "eivclnhsfo");


    Flags flags = {false, false, false, false, false, false, false, false, false, false};

    for(;currentFlag != -1; currentFlag = getopt(argc, argv, "eivclnhsfo")) {
        switch (currentFlag) {
            case 'e':
                flags.flagE = true;
                break;
        }
 }
return flags;

}

int main(int argc, char* argv[]) {

    Flags flags = readFlags(argc, argv);
    printf("%d", flags.flagE);
    return 0;
}
