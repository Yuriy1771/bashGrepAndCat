#include <stdio.h>
#include <stdbool.h>

typedef struct {
    // shablon, //-e
    // ignoreDifferencesReg, //-i
    // invertsSearshMatches, //-v
    // outputMatchStr, //-c
    // outputMatchFiles, //-i
    bool flagE; //Шаблон
    bool flagI; //Игнорирует различия регистра.
    bool flagV; //Инвертирует смысл поиска соответствий.
    bool flagC; //Выводит только количество совпадающих строк.
    bool flagL; //Выводит только совпадающие файлы.
    bool flagN; //Предваряет каждую строку вывода номером строки из файла ввода.
    bool flagH; //Выводит совпадающие строки, не предваряя их именами файлов.
    bool flagS; //Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах.
    bool flagFfile; //Получает регулярные выражения из файла.
    bool flagO; //Печатает только совпадающие (непустые) части совпавшей строки.
}Flags;
Flags flags;


int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}