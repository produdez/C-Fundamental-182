#include "abstract.h"



//...................Main function.....................
void process(ChampionA& a, ChampionB& b, int* skillSequence, int numberOfSkills);

int main()
{
    ChampionA a(1,1500,50,50,0,0);
    ChampionB b(2,2000,50,50,0,0);
    int* i= new int[6];
    i[0]=1;
  //  i[1]=2;
   // i[2]=3;
    i[3]=0;
    i[4]=1;
  //  i[5]=3;
    process(a,b,i,3);
a.printStatus();
    b.printStatus();
    return 0;
}

//.........................global function.................
void process(ChampionA& a, ChampionB& b, int* skillSequence, int numberOfSkills) {
    for (int i = 0; i < numberOfSkills; i++) {

        switch (skillSequence[i]) {
            case 0:
                if (a.skill1(b)) return;
                break;
            case 1:
                if (a.skill2(b)) return;
                break;
            case 2:
                if (b.skill1(a)) return;
                break;
            case 3:
                if (b.skill2(a)) return;
                break;
            default:
                break;

        }

            a.printStatus();
    b.printStatus();
    }
}
