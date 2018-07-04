#ifndef FSM_H
#define FSM_H

#include <set>
#include "FSMTransition.h"
#include "FSMAlphabet.h"

#define ARRAY_INIT  64


template<typename T_STATE, typename T_SYM>
class FSM
{
    public:

        typedef FSMTransition<T_STATE, T_SYM>               TRANSITION;
        typedef std::set<FSMTransition<T_STATE, T_SYM>>     DELTA;

        typedef T_STATE                         FSMSTATE;
        typedef std::set<T_STATE>               FSMSTATES;

        typedef FSMAlphabet<T_SYM>              ALPHABET;
        typedef unsigned int                    UINT;

    public:

        /** Default constructor **/
        FSM():
            m_c_states(0), //stateCounter
            m_c_symbols(0), //AlphabetCounter (symbols)
            m_c_transitions(0), //m_stateArraySizeTransition Counter
            m_freeStates(ARRAY_INIT), //Availe States
            m_stateArraySize(ARRAY_INIT) //Size of the current transition array
        {
            m_delta = new TRANS*[ARRAY_INIT];
            for(int i = 0;i<ARRAY_INIT;i++)
                m_delta[i] = NULL;
        }

        /** FSM Constructor **/
        //A = <States, Alphabet, StartState, Delta, FinalStates>
        FSM(FSMSTATES& pSet, ALPHABET& pAlpha, FSMSTATE& pStart, DELTA& pDelta, FSMSTATES& pFinalsStates)

        /** Default destructor **/
        ~FSM()
        {
            if (m_delta != NULL)
            {
                //remember we may have resized the internal array
                for(int i = 0; i<m_stateArraySize;i++)
                    if (m_delta[i] != NULL)
                        delete m_delta[i];
                //iterate over the cells
                delete m_delta;
            }
        }

        /** Copy constructor **/
        FSM(const FSM& other)
        {
        }

    private:

        //FSM Stuff
        //<Q,Sigma,delta,S,F>
        //Q = repr TRANS**
        FSMSTATES   m_states;
        ALPHABET    m_sigma;
        DELTA       m_delta;
        FSMSTATE    m_startState;         //startstate atm only one
        FSMSTATES   m_finalStates;      //Hashset of endstates


        //Statistics
        UINT m_c_states;
        UINT m_c_transitions;
        UINT m_c_symbols;
        UINT m_c_words; //eg. nr. of Final States in acyclig else NaN

        //Internal data strukture
        UINT    m_freeStates;
        UINT    m_stateArraySize;

};

#endif // FSM_H
