#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>
#include "Game.h"

namespace Ui {
class NewGame;
}
/*!
 * \brief The NewGame class okno kreatora nowej gry
 */
class NewGame : public QDialog
{
    Q_OBJECT

public:
    explicit NewGame(QWidget *parent = 0);
    ~NewGame();
    Game *game;

private slots:
    void on_buttonBox_accepted();

    void on_playerComboBox_activated(const QString &arg1);

private:
    Ui::NewGame *ui;
    QList<QString> players;

};

#endif // NEWGAME_H
