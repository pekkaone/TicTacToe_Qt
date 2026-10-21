#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <QQmlEngine>
#include "tile.h"

class TileManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int currentPlayer READ currentPlayer WRITE setCurrentPlayer NOTIFY currentPlayerChanged FINAL);
    Q_PROPERTY(QString win READ win WRITE setWin NOTIFY winChanged FINAL)

public:
    explicit TileManager(QObject *parent = nullptr);
    void getTile(int tile);
    int currentPlayer() const;
    void setCurrentPlayer(int newCurrentPlayer);
    void isWin();
    void setWin(const QString &newWin);
    QString win() const;

public slots:
    void tileClicked(int tile);
    void changeCurrentPlayer();
    void addTiles(Tile* t);
    void restart();

signals:
    void currentPlayerChanged();
    void winChanged();

private:
    QList<Tile*> Tiles;
    void genereteTiles();
    int m_currentPlayer = 0;
    QString m_win = "";
};

#endif // TILEMANAGER_H
