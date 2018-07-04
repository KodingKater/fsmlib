#ifndef FSMTRANSITION_H
#define FSMTRANSITION_H

#include <iostream>

using namespace std;

template<typename T_STATE, typename T_SYM>
class FSMTransition
{
    public:
        /** Default Construtor**/
        FSMTransition():
            m_transSymbol(),
            m_targetState()
        {}

        /** Default Constructor **/
        FSMTransition(T_STATE targetState , T_SYM symbol):
            m_transSymbol(symbol),
            m_targetState(targetState)
        {}

        /** Default destructor */
        ~FSMTransition()
        {}

        /** Copy constructor **/
        FSMTransition(const FSMTransition& rhs):
            m_transSymbol(rhs.m_transSymbol),
            m_targetState(rhs.m_targetState)
        {}


    private:
        T_STATE     m_targetState;//represents the State
        T_SYM       m_transSymbol;//represents the transstion Symbol

    /** Operator Overloading**/
    public:
    //Assignment Operator, returns a copy of the rhs
    FSMTransition<T_STATE, T_SYM> operator=(const FSMTransition& rhs)
    {
        //We copy the current transition
        if (this != &rhs)
            return FSMTransition<T_STATE, T_SYM>(rhs);
        else
            return &this;//if it is the same obj
    }

    friend ostream& operator<<(ostream& stream, const FSMTransition& obj)
    {
        //DEbugging Cout
        //stream << "Sym-Addr:"<< &obj.m_sym << " ["<< obj.m_sym << "], State-Addr:"<< &obj.m_targetState << " [" << obj.m_targetState << "]";
        //Dot Ausgabe
        stream << " -> " << obj.m_targetState << "[Label=\"" << obj.m_transSymbol << "\"];";
    }
};

#endif // FSMTRANSITION_H
