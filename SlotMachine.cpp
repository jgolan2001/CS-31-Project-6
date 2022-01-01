//
//  SlotMachine.cpp
//  SlotMachine
//
//


#include <cstdlib>
#include <iostream>
#include <string>
#include "SlotMachine.h"
#include "RandomNumber.h"
#include "Bank.h"
#include "PayTable.h"


SlotMachine::SlotMachine( std::string seq )
   : display( true ), sequence( seq )
{

}

// TODO: force a specific set of wheels to be played and display the screen if requested to do so
void SlotMachine::play( Bank & bank, char w1, char w2, char w3 )  // cheating
{
    // TODO: update the wheel1, wheel2 and wheel3 members from the passed cheating values
    
    wheel1 = w1;
    wheel2 = w2;
    wheel3 = w3;
    
    // TODO: Draw the machine by calling spinWheels
    
    spinWheels();
    
    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay
    
    updateBankFromSpinAndDisplay(bank);
    
}

// TODO: randomly spin the wheels and display the screen if requested to do so
void SlotMachine::play( Bank & bank )
{
    // TODO: pick three random letters for the sequence of available letters on this machine
    
    char w1;
    char w2;
    char w3;
    long k = sequence.size();
    int i = (int)k;
    RandomNumber spin1(0, i, true, false);
    int num1 = spin1.random( );
    w1 = sequence.at(num1);
    RandomNumber spin2(0, i, true, false);
    int num2 = spin2.random( );
    w2 = sequence.at(num2);
    RandomNumber spin3(0, i, true, false);
    int num3 = spin3.random( );
    w3 = sequence.at(num3);
    
    
    // TODO: update the wheel1, wheel2 and wheel3 members
    
    wheel1 = w1;
    wheel2 = w2;
    wheel3 = w3;
    
    // TODO: Draw the machine by calling spinWheels
    
    spinWheels();
    
    // TODO: Update the bank and display results by calling updateBankFromSpinAndDisplay
    
    updateBankFromSpinAndDisplay(bank);
}

// spin the wheels
void SlotMachine::spinWheels( )
{
    // Draw the machine
    if (display)
    {
        Screen screen;
        screen.displayScreen(wheel1, wheel2, wheel3, sequence);
    }
}

// show the wager after one round of play
void SlotMachine::displayWager( int wager, int before, int after )
{
    // Show the wager information
    if (display)
    {
        Screen screen;
        screen.displayWager( wager, before, after );
    }
}

// update the bank for one round of play
void SlotMachine::updateBankFromSpinAndDisplay( Bank & b )
{
    int balanceBefore = b.balance();
    int wager = b.getWager( );
    
    PayTable p( wheel1, wheel2, wheel3 );
    p.manageWager( b );
    
    int balanceAfter = b.balance();
    
    // Display the wager lines
    displayWager( wager, balanceBefore, balanceAfter );
}

// trivial getter
char SlotMachine::getWheel1() const
{
    return( wheel1 );
}

// trivial getter
char SlotMachine::getWheel2() const
{
    return( wheel2 );
}

// trivial getter
char SlotMachine::getWheel3() const
{
    return( wheel3 );
}

void SlotMachine::showDisplay()
{
    display = true;
}

void SlotMachine::noDisplay()
{
    display = false;
}
