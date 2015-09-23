/*
    othello.cpp
*/
#include "othello.h"

void printb(BOARD* b)
{
    int x,y;
    printf("=======================================\n");
    if(b->turn==BLACK) printf(" TURN : BLACK\n"); else printf(" TURN : WHITE\n");
    if(b->ispassed!=0) printf(" PREVIOUS TURN was Passed.\n"); else printf("\n");

    for(y=0;y<8;y++)
    {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("  ");
        for(x=0;x<8;x++)
        {
            switch(b->piece[y][x])
            {
                case WHITE:
                    printf("| O ");break;
                case BLACK:
                    printf("| $ ");break;
                default:
                    printf("|   ");break;
            };
        };
        printf("|\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
}

int resolve(char* path)
{
    return 0;
}

int main(int argc, char** argv)
{
    BOARD b;

    if( argc < 2 ) {
        memcpy(&b, &Initial_Board, sizeof(BOARD));
    } else {
        printf("currently, resume function is not implemented.\n");
        return 0;
    }

    printb(&b);
}

