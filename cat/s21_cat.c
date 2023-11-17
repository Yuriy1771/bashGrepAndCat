#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#include "headers.h"

int main(int argc, char* argv[]) {
    Flags flags = readFlags(argc, argv);
    const char *table[256];
    catSetTable(table);
    if(flags.markEndStr) {
        catSetEndl(table);
    }
    if(flags.tabStr) {
        catSetTab(table);
    }
    if(flags.printNonPrintable) {
        catSetNonPrintable(table);
    }
    catOpen(argc, argv, flags, table);
return 0;
}

void catRead(FILE *file, Flags flags, const char *table[static 256]) {
    int currentSymbol = 0;
    int lastSymbol;
    bool isSqueeze = false;
    int lineNo = 0;
    lastSymbol = '\n';
    (void)flags;

    while(fread(&currentSymbol, 1, 1, file) > 0) {
        if(lastSymbol == '\n') {
            if(flags.squeezeStr && currentSymbol == '\n') {
                if(isSqueeze) {
                    continue;
                }
                isSqueeze = true;
            }else {
                isSqueeze = false;
            }
            if(flags.numberNonBlank) {
                if(currentSymbol != '\n') {
                    printf("%6d\t", ++lineNo);
                }
            }
            else if(flags.numberAll) {
                printf("%6d\t",  ++lineNo);
            }
        }
        if (!currentSymbol && !flags.printNonPrintable) {
      printf("%c", '\0');
    } else {
      printf("%s", table[currentSymbol]);
    }
        lastSymbol = currentSymbol;
    }
}

void catOpen(int argc, char* argv[], Flags flags, const char* table[static 256]) {
    for(char** filename = &argv[1], **end = &argv[argc]; filename != end; ++filename) {
        if(**filename == '-') {
            continue;
        }
        FILE* file = fopen(*filename, "rb");
        if(errno) {
            fprintf(stderr, "%s", argv[0]);
            perror(*filename);
            continue;
        }
    catRead(file, flags, table);
    fclose(file);
    }
}