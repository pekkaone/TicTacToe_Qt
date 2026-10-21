#include "tilemanager.h"

TileManager::TileManager(QObject *parent) : QObject{parent} {
    changeCurrentPlayer();
}

void TileManager::tileClicked(int tileNum)
{
    for (int i = 0; i <= Tiles.size() - 1; ++i) {
        if(Tiles[i]->gridNum() == tileNum){
            if(Tiles[i]->Symbol() != "X" && Tiles[i]->Symbol() != "O"){
                if(m_currentPlayer == 1){
                    Tiles[i]->setSymbol("X");
                }
                else if(m_currentPlayer == 0){
                    Tiles[i]->setSymbol("O");
                }

                changeCurrentPlayer();
            }
            else{

            }
        }
    }

    isWin();
}

void TileManager::changeCurrentPlayer()
{
    if(m_currentPlayer) {
        if (m_currentPlayer == 1) {
            m_currentPlayer = 0;
        }
        else if (m_currentPlayer == 0) {
            m_currentPlayer = 1;
        }
    }
    else{
        m_currentPlayer = 1;
    }
}

void TileManager::genereteTiles()
{
    /*
    QList<Tile*> TEMPTiles;

    Tile* t1 = new Tile();
    Tile* t2 = new Tile();
    Tile* t3 = new Tile();
    Tile* t4 = new Tile();
    Tile* t5 = new Tile();
    Tile* t6 = new Tile();
    Tile* t7 = new Tile();
    Tile* t8 = new Tile();
    Tile* t9 = new Tile();

    TEMPTiles.append(t1);
    TEMPTiles.append(t2);
    TEMPTiles.append(t3);
    TEMPTiles.append(t4);
    TEMPTiles.append(t5);
    TEMPTiles.append(t6);
    TEMPTiles.append(t7);
    TEMPTiles.append(t8);
    TEMPTiles.append(t9);

    std::cout << TEMPTiles.size();

    int i = 1;
    for (auto& x : TEMPTiles) {
        x->setGridNum(i);
        i++;
        Tiles.append(x);
    }
*/
}

int TileManager::currentPlayer() const
{
    return m_currentPlayer;
}

void TileManager::setCurrentPlayer(int newCurrentPlayer)
{
    if (m_currentPlayer == newCurrentPlayer)
        return;
    m_currentPlayer = newCurrentPlayer;
    emit currentPlayerChanged();
}

void TileManager::isWin()
{
    for (int i = 0; i < 2; ++i) {
        QString sym;
        if(i == 1){
            sym = "O";
        }
        else{
            sym = "X";
        }

        for(auto& x : Tiles) {

            //Column
            if((x->gridNum() == 1 && x->Symbol() == sym) &&
                (Tiles[3]->Symbol() == sym) &&
                (Tiles[6]->Symbol() == sym)){
                setWin(sym + " - WON");
            }
            else if((x->gridNum() == 2 && x->Symbol() == sym) &&
                (Tiles[4]->Symbol() == sym) &&
                (Tiles[7]->Symbol() == sym)){
                setWin(sym + " - WON");
            }
            else if((x->gridNum() == 3 && x->Symbol() == sym) &&
                     (Tiles[5]->Symbol() == sym) &&
                     (Tiles[8]->Symbol() == sym)){
                setWin(sym + " - WON");
            }

            //Row
            else if((x->gridNum() == 1 && x->Symbol() == sym) &&
                (Tiles[1]->Symbol() == sym) &&
                (Tiles[2]->Symbol() == sym)){
                setWin(sym + " - WON");
            }
            else if((x->gridNum() == 4 && x->Symbol() == sym) &&
                     (Tiles[4]->Symbol() == sym) &&
                     (Tiles[5]->Symbol() == sym)){
                setWin(sym + " - WON");
            }
            else if((x->gridNum() == 7 && x->Symbol() == sym) &&
                     (Tiles[7]->Symbol() == sym) &&
                     (Tiles[8]->Symbol() == sym)){
                setWin(sym + " - WON");
            }

            //Cross
            else if((x->gridNum() == 1 && x->Symbol() == sym) &&
                     (Tiles[4]->Symbol() == sym) &&
                     (Tiles[8]->Symbol() == sym)){
                setWin(sym + " - WON");
            }
            else if((x->gridNum() == 3 && x->Symbol() == sym) &&
                     (Tiles[4]->Symbol() == sym) &&
                     (Tiles[6]->Symbol() == sym)){
                setWin(sym + " - WON");
            }

            else {
                m_win = " ";
            }
        }
    }
}

void TileManager::addTiles(Tile *t)
{
    Tiles.append(t);
}

void TileManager::restart()
{
    for(auto& x : Tiles){
        x->setSymbol("");
    }
    setWin("");
    setCurrentPlayer(1);
}

void TileManager::setWin(const QString &newWin)
{
    if (m_win == newWin)
        return;
    m_win = newWin;
    emit winChanged();
}

QString TileManager::win() const
{
    return m_win;
}
