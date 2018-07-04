#include <iostream>
#include <string>

#include "include/FSM.h"
#include "include/FSMState.h"
#include "include/FSMTransition.h"

using namespace std;

typedef FSMState<int>                   FSMSTATE;
typedef FSMAlphabet<string>             FSMALPHA;
typedef FSM<FSMSTATE, FSMALPHA>         AUTOMATON;



typedef FSMTransition<FSMSTATE, string>           TRANS;

int main()
{
    cout << "Testing the FSM Lib!" << endl;

    /** Testing ALphabet Stuff **/
    FSMALPHA sigma =  FSMALPHA("ERROR");

    /** Testing Automaton Class **/
    AUTOMATON a = AUTOMATON(sigma);

    //TRANS a = TRANS(FSMSTATE(21),"Knaller");
    //cout << "Test:" << a << endl;

    FSMSTATE b = FSMSTATE(200);
    cout << "T:" << b << endl;


    return 0;
}
