#ifndef FSMSTATE_H
#define FSMSTATE_H

#include <iostream>
#include <string>

using namespace std;

/** Represents a FSM State**/
template <typename T>
class FSMState
{
    public:
        /** Default constr **/
        FSMState():
        m_selfName()
        {}

        /** Default constructor */
        FSMState(T stateName):
            m_selfName(stateName)
        {};

        /** Default destructor */
        ~FSMState(){};

        /** CopyConstructor **/
        FSMState(const FSMState& rhs):
        m_selfName(rhs.m_selfName)
        {}

    private:
        /** internal repre of the Name **/
        T m_selfName;

    /** Operator Overloading**/
    public:

    //Assignment Operator, returns a copy of the rhs
    FSMState<T> operator=(const FSMState& rhs)
    {
        if (this != &rhs)//We copy the current transition
            return FSMState<T>(rhs);
        else
            return &this;
    }

    bool operator==(const FSMState& rhs) const
    {
        return m_selfName == rhs.m_selfName;
    }

    bool operator!=(const FSMState& rhs) const
    {
        return !(this == rhs);
    }

    friend ostream& operator<<(ostream& stream,const FSMState& obj)
    {
        //DEbugging Cout
        //stream << "Sym-Addr:"<< &obj.m_sym << " ["<< obj.m_sym << "], State-Addr:"<< &obj.m_targetState << " [" << obj.m_targetState << "]";
        //Dot Ausgabe
        stream << obj.m_selfName;
    }

};

#endif // FSMSTATE_H
