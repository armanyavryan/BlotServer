#pragma once

#include "SharedData.h"

class Card
{
public:
    Card(const CardSuits& suit, const CardRanks& rank);
    CardSuits suit() const;
    CardRanks rank() const;

    static QString toString(const std::vector<Card>& cards){
        QString str;

        for (int i = 0; i < cards.size(); ++i) {
            str.append(toString(cards[i])).append(" ");
        }
        return str;
    }

    static QString toString(const Card& card){
        QString suit;
        QString rank;
        switch (card.suit()) {
        case CardSuits::Clubs:
            suit = QStringLiteral("Clubs");
            break;
        case CardSuits::Spades:
            suit = QStringLiteral("Spades");
            break;
        case CardSuits::Hearts:
            suit = QStringLiteral("Spades");
            break;
        case CardSuits::Diamonds:
            suit = QStringLiteral("Diamonds");
            break;
        default:
            break;
        }
        switch (card.rank()) {
        case CardRanks::Two:
            rank = QStringLiteral("2");
            break;
        case CardRanks::Three:
            rank = QStringLiteral("3");
            break;
        case CardRanks::Four:
            rank = QStringLiteral("4");
            break;
        case CardRanks::Five:
            rank = QStringLiteral("5");
            break;
        case CardRanks::Six:
            rank = QStringLiteral("6");
            break;
        case CardRanks::Seven:
            rank = QStringLiteral("7");
            break;
        case CardRanks::Eight:
            rank = QStringLiteral("8");
            break;
        case CardRanks::Nine:
            rank = QStringLiteral("9");
            break;
        case CardRanks::Ten:
            rank = QStringLiteral("10");
            break;
        case CardRanks::Jack:
            rank = QStringLiteral("J");
            break;
        case CardRanks::Queen:
            rank = QStringLiteral("Q");
            break;
        case CardRanks::King:
            rank = QStringLiteral("K");
            break;
        case CardRanks::Ace:
            rank = QStringLiteral("A");
            break;
        default:
            break;
        }

        return QString("%0 off %1").arg(rank).arg(suit);
    }

private:

    CardSuits m_suit;
    CardRanks m_rank;
};
