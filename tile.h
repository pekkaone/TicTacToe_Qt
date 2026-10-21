#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QQmlEngine>

class Tile : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString Symbol READ Symbol WRITE setSymbol NOTIFY SymbolChanged FINAL)
    Q_PROPERTY(int gridNum READ gridNum WRITE setgridNum MEMBER m_gridNum FINAL)

public:
    explicit Tile(QObject *parent = nullptr);
    QString Symbol() const{
        return m_Symbol;
    }

signals:
    void SymbolChanged(QString symbol);
    void GridNumChanged();

public:
    void setSymbol(const QString &newSymbol);
    int gridNum() const;
    void setgridNum(int newgridNum);

private:
    int m_gridNum;
    QString m_Symbol;
};

#endif // TILE_H
