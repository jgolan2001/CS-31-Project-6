//
//  Bank.cpp
//  SlotMachine
//
//

#include "Bank.h"


// The purpose of this class is to implement a bank of funds and a wager than can be won or lost
Bank::Bank( int amount )
{
    bankAmount = amount;
    wager = 0;
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::win( int amount )
{
    // add to the balance and set the wager to zero
    bankAmount = balance() + amount;
    wager = 0;
}
    
// TODO: adjust the bank balance for the amount won or lost
void Bank::lose( int amount )
{
    // subtract from the balance and set the wager to zero
    bankAmount = balance() - amount;
    wager = 0;
}

// TODO: adjust the bank balance for the amount being added to the bank
void Bank::deposit( int amount )
{
    // add to the balance
    bankAmount = bankAmount + amount;
}
 
// trivial getter
int Bank::balance() const
{
    return( bankAmount );
}
    
// TODO: return the bank balance and set it bank to zero
int Bank::cashOut( )
{
    // return the balance
    // set both the wager and the balance to zero
    // for now...
    int finalamount = bankAmount;
    bankAmount = 0;
    wager = 0;
    return( finalamount );
}

// TODO: can the amount be wagered??
bool Bank::canWager( int amount ) const
{
    // can the bank balance allow this amount to be wagered??
    // for now...
    
    bool validwager = false;
    
    if (amount < 0)
    {
        return (false);
    }
    
    if (amount <= bankAmount)
    {
        validwager = true;
    }
    else
    {
        validwager = false;
    }
    
    return( validwager );
}
    
// trivial setter
void Bank::setWager( int amount )
{
    wager = amount;
}
 
// trivial getter
int Bank::getWager() const
{
    return( wager );
}
