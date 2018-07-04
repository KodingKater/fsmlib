#ifndef FSMALPHABET_H
#define FSMALPHABET_H

#include <map>

/**
FSAMAlphabet takes care of the mapping between symbols and internal representation of
those symbols.

ATM the internal repr is only provided by integers
**/
template<typename SYM>
class FSMAlphabet
{
    public:
        typedef std::map<int,SYM> MAP_INT2SYM;
        typedef std::map<SYM,int> MAP_SYM2INT;
        typedef std::set<SYM> SET_SYM;
        typedef std::set<int> SET_INT;

    public:
    /** Default constructor */
        FSMAlphabet():
        m_errorSYM()
        {
            m_errorId  = -1;

            m_sigmaIds = SET_INT();
            m_sigmaSym = SET_SYM();

            m_id2sym = MAP_INT2SYM();
            m_sym2id = MAP_SYM2INT();

            m_IdCounter = 0;
        }

        /** Default constructor */
        FSMAlphabet(const SYM& pErrorSymbol)
        {
            m_errorSYM = pErrorSymbol;
            m_errorId  = -1;

            m_sigmaIds = SET_INT();
            m_sigmaSym = SET_SYM();

            m_id2sym = MAP_INT2SYM();
            m_sym2id = MAP_SYM2INT();

            m_IdCounter = 0;
        }

        /** Default destructor */
        ~FSMAlphabet()
        {
        }

        /** Copy constructor
         *  \param other Object to copy from
         */
        FSMAlphabet(const FSMAlphabet& other) {}

    public:

    //get a pointer to the SigmaSet
    const SET_SYM* getSigma() const
    {
        //TODO: what if this class is destroyed?
    }

    //get a copy of the sigmaSet
    SET_SYM getSigma()
    {
        //return copy
        return m_sigmaSym;
    }


    //get all ids
    const SET_INT* getSigmaIds()
    {
        //TODO - see getSigma()
    }

    SET_INT getSigmaIds() const
    {
        return m_sigmaIds;
    }

    //returns true if pSym is in the set
    bool contains(SYM pSym) const
    {
        return m_sigmaSym.find(pSym) != m_sigmaSym.end();
    }

    //lookup a internal id - mostly for debug reasons
    bool contains(int pId) const
    {
        return m_sigmaIds.find(pId) != m_sigmaIds.end();
    }

    //get a copy of symbol
    SYM id2sym(int pId) const
    {
        if(contains(pId))
            return m_id2sym.find(pId)->second;

        return m_errorSYM;
    }

    //get the id of a symbol
    int sym2id(SYM pSym) const
    {
        if(contains(pSym))
            return m_sym2id.find(pSym)->second;

        return m_errorId;
    }

    //insert a symbol
    int addSym(SYM pSym)
    {
        if (contains(pSym))
            return m_sym2id.find(pSym)->second;

        int newId = getNewId();

        m_id2sym[newId] = pSym;
        m_sym2id[pSym] = newId;
        m_sigmaIds.insert(newId);
        m_sigmaSym.insert(pSym);

        return newId;
    }


    private:

    int getNewId()
    {
        return m_IdCounter++;
    }


    private:

    int                     m_errorId;
    SET_INT                 m_sigmaIds;
    MAP_INT2SYM             m_id2sym;

    SYM                     m_errorSYM;
    SET_SYM                 m_sigmaSym;
    MAP_SYM2INT             m_sym2id;

    //keep trac of the symbols
    int                     m_IdCounter;


};

#endif // FSMALPHABET_H
