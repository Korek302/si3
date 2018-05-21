#ifndef GAMEWINDOWPVE_H
#define GAMEWINDOWPVE_H

#include "gamewindow.h"
#include "node.h"

#include <limits>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>


namespace Ui
{
    class GameWindowPvE;
}

class GameWindowPvE : public GameWindow
{
    Q_OBJECT

public:
    explicit GameWindowPvE(QWidget *parent);
    explicit GameWindowPvE(QWidget *parent, int dim, bool aiStart, int depth, bool alfabeta);
    ~GameWindowPvE();

private:
    Ui::GameWindowPvE *ui;
    int _depth;
    bool _alfabeta;

    void computerTurn(QPair<int, int> move);
    Node minimax(Node currNode, int depth, bool maximizingPlayer);
    Node alfabeta(Node currNode, int depth, int alfa, int beta, bool maximizingPlayer);
    void initBoard();

private slots:
    void onPushButtonClick();
};

#endif // GAMEWINDOWPVE_H
