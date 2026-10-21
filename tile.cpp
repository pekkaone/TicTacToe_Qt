#include "tile.h"

Tile::Tile(QObject *parent)
    : QObject{parent}
{}

void Tile::setSymbol(const QString &newSymbol)
{
    if (m_Symbol == newSymbol)
        return;
    m_Symbol = newSymbol;
    emit SymbolChanged(m_Symbol);
}

int Tile::gridNum() const
{
    return m_gridNum;
}

void Tile::setgridNum(int newgridNum)
{
    if (m_gridNum == newgridNum)
        return;
    m_gridNum = newgridNum;
}
