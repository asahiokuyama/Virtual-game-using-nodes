#include <stdio.h>
#include <unistd.h>

#define NODE_1 0
#define NODE_2 1
#define NODE_3 2
#define NODE_4 3
#define NODE_A 4
#define NODE_B 5
#define NODE_C 6
#define NODE_D 7
#define NODE_E 8
#define NODE_F 9
#define NODE_G 10
#define NODE_H 11
#define NODE_I 12
#define NODE_J 13
#define NODE_END 100

#define NODE_START NODE_1

#define MAXLEN 256

//構造体の設定
struct fsm_trans {
    int node;
    int up;
    int right;
    int left;

    char message[MAXLEN];
};

struct fsm_trans fsmtable[] = {
    //{node,up,right,left,message}
    {NODE_1,NODE_2,NODE_3,NODE_4,"Which way to go?1(u/r/l)"},
    {NODE_2,NODE_A,NODE_B,NODE_C,"Which way to go?2(u/r/l)"},
    {NODE_3,NODE_D,NODE_E,NODE_F,"Which way to go?3(u/r/l)"},
    {NODE_4,NODE_G,NODE_H,NODE_I,"Which way to go?4(u/r/l)"},
    {NODE_A,NODE_1,NODE_2,NODE_3,"Which way to go?5(u/r/l)"},
    {NODE_B,NODE_1,NODE_2,NODE_3,"Which way to go?6(u/r/l)"},
    {NODE_C,NODE_1,NODE_2,NODE_3,"Which way to go?7(u/r/l)"},
    {NODE_D,NODE_1,NODE_2,NODE_3,"Which way to go?8(u/r/l)"},
    {NODE_E,NODE_1,NODE_2,NODE_3,"Which way to go?9(u/r/l)"},
    {NODE_F,NODE_1,NODE_2,NODE_3,"Which way to go?10(u/r/l)"},
    {NODE_G,NODE_1,NODE_2,NODE_3,"Which way to go?11(u/r/l)"},
    {NODE_H,NODE_1,NODE_2,NODE_3,"Which way to go?12(u/r/l)"},
    {NODE_I,NODE_END,NODE_END,NODE_END,"You find Treasure!!"}
};

int main(){
    //変数宣言
    int state;
    char input[MAXLEN],*p;
    state = NODE_START;

    int count = 0;

    while(1){
        //終わりの判定
        if(fsmtable[state].up == NODE_END){
            break;
        }

        printf("Are you ready?: %s\n",fsmtable[state].message);
        //入力
        p = fgets(input,MAXLEN,stdin);

        //文字が入力されていたら処理開始
        if(p != NULL){
            if(input[0] == 'u'){//上
                state = fsmtable[state].up;
                count++;
            }else if(input[0] == 'r'){//右
                state = fsmtable[state].right;
                count++;
            }else if(input[0] == 'l'){//左
                state = fsmtable[state].left;
                count++;
            }else if (input[0] == 'f'){//終わりたいとき
                fsmtable[state].up = NODE_END;
            }else{
                //何もしない
            }
        }else{
            break;
        }
    }

    //かかったスコアの表示
    printf("%s\nyour Score is %d\n",fsmtable[state].message,count);

    return 0;
}
