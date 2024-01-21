#include "Card.h"

Card::Card(const CardSuits &suit, const CardRanks &rank)
    : m_suit{suit},
    m_rank{rank}
{

}

CardSuits Card::suit() const
{
    return m_suit;
}

CardRanks Card::rank() const
{
    return m_rank;
}
