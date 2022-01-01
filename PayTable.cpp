//
//  PayTable.cpp
//  SlotMachine
//
//

#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

// TODO:  For the wheel combination, determine the pay multiplier
PayTable::Multiplier PayTable::calculateMultiplier( )
{
    // For now...
    Multiplier result = ZERO;
    
    // three aces
    if (mWheel1 == 'A' && mWheel2 == 'A' && mWheel3 == 'A')
    {
        result = TENTIME;
    }
    
    // two aces
    if ((mWheel1 == 'A' && mWheel2 == 'A' && mWheel3 != 'A') || (mWheel2 == 'A' && mWheel3 == 'A' && mWheel1 != 'A') || (mWheel1 == 'A' && mWheel3 == 'A' && mWheel2 != 'A'))
    {
        result = FIVETIME;
    }
    
    // three of a kind other than aces
    if ((mWheel1 == mWheel2 && mWheel1 == mWheel3 && mWheel1 != 'A') || (mWheel2 == mWheel1 && mWheel2 == mWheel3 && mWheel1 != 'A') || (mWheel3 == mWheel1 && mWheel3 == mWheel2 && mWheel1 != 'A'))
    {
        result = SEVENTIME;
    }
    
    // any pair other than aces
    if ((mWheel1 == mWheel2 && mWheel1 != mWheel3 && mWheel1 != 'A' && mWheel2 != 'A') || (mWheel2 == mWheel3 && mWheel2 != mWheel1 && mWheel2 != 'A' && mWheel3 != 'A') || (mWheel1 == mWheel3 && mWheel1 != mWheel2 && mWheel1 != 'A' && mWheel3 != 'A'))
    {
        result = THREETIME;
    }
    
    // A single ace
    if ((mWheel1 == 'A' && mWheel2 != 'A' && mWheel3 != 'A') ||(mWheel1 != 'A' && mWheel2 == 'A' && mWheel3 != 'A') || (mWheel1 != 'A' && mWheel2 != 'A' && mWheel3 == 'A'))
    {
        result = ONETIME;
    }
    
    // having a A, K and Q
    if ((mWheel1 == 'A' && mWheel2 == 'K' && mWheel3 == 'Q') || (mWheel1 == 'K' && mWheel2 == 'A' && mWheel3 == 'Q') || (mWheel1 == 'Q' && mWheel2 == 'K' && mWheel3 == 'A') || (mWheel1 == 'K' && mWheel2 == 'Q' && mWheel3 == 'A') || (mWheel1 == 'Q' && mWheel2 == 'A' && mWheel3 == 'K') || (mWheel1 == 'A' && mWheel2 == 'Q' && mWheel3 == 'K'))
    {
        result = FIVETIME;
    }
    
    // any pair other than aces + ace
    if ((mWheel1 == mWheel2 && mWheel1 != mWheel3 && mWheel3 == 'A') || (mWheel2 == mWheel3 && mWheel2 != mWheel1 && mWheel1 == 'A') || (mWheel1 == mWheel3 && mWheel1 != mWheel2 && mWheel2 == 'A'))
    {
        result = FOURTIME;
    }
    return( result );
}

// TODO: For the wheel combination and wager of the passed Bank, update the Bank's balance
void PayTable::manageWager( Bank & bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier
    double amount = bank.getWager();
    Multiplier multiplier = calculateMultiplier();

    // TODO: adjust the bank balance accordingly...
    
    if (calculateMultiplier() == ZERO)
    {
        bank.lose(amount);
    }
    
    else
    {
        bank.win(amount*multiplier);
    }
}
