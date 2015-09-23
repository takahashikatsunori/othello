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

int move(BOARD* b, char* pos)
{
    int x,y,cx,cy;
    int sts;
    int cur,nxt;
    int moveto[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

    cx=atoi(pos)/10;
    cy=atoi(pos)%10;
    if((cx<0)||(cx>7)||(cy<0)||(cy>7)) return -1;
    if(b->piece[cy][cx]!=-1) return -1;

    cur=b->turn;
    nxt=(b->turn)+1;
    if(nxt>1)nxt=0;
 printf("nxt[%d]\n",nxt);   
    b->piece[cy][cx]=cur;

    for(int i=0;i<8;i++) {
      sts=0;
      y=cy;
      x=cx;
      while(1) {
        switch(sts) {
          case 0:sts=1;break;
          case 1:
            if(b->piece[y][x]==nxt)sts=2;else sts=100;
            break;
          case 2:
            if(b->piece[y][x]==nxt)sts=2; else if(b->piece[y][x]==cur)sts=3; else sts=100;
          default:break;
        };
        x+=moveto[i][0];
        y+=moveto[i][1];
        if((x<0)||(x>7)||(y<0)||(y>7))break;
      }
      if(sts==3) {
        x=cx+moveto[i][0];
        y=cy+moveto[i][1];
        while(1) {
            if(b->piece[y][x]==nxt)b->piece[y][x]=cur;else break;
            x+=moveto[i][0];
            y+=moveto[i][1];
        }
      }
    };

    b->turn=nxt;
    return 0;
}

int decodepath(char* path, BOARD* b)
{
    if(strncmp(path,"top",3)!=0) return -1;

    memcpy(b,&Initial_Board,sizeof(BOARD));

    char* p = strtok(path,"/");

    while(p!=NULL)
    {
printf("path[%s]\n",p);
        if(strcmp(p,"top")!=0)
            if(move(b,p)!=0) return -1;
        p=strtok(NULL,"/");
    };

    return 0;
}

int resolve(char* path)
{
    BOARD b;

    // decode path
    decodepath(path,&b);
    printb(&b);
    // check status

    // analyze next

    // resolve next

    // resolve current

    return 0;
}

int main(int argc, char** argv)
{
    BOARD b;
    char path[1024];

    if( argc < 2 ) {
        memcpy(&b, &Initial_Board, sizeof(BOARD));
        sprintf(path,"top/32/22");

        struct stat st;
        if(stat("top",&st)!=0) {
            mkdir("top",775);
        };
    } else {
        printf("currently, resume function is not implemented.\n");
        return 0;
    }

    printb(&b);

    resolve(path);
}

