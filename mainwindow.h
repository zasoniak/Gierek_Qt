#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0, Game *_game = 0);
    ~MainWindow();

private slots:
    void on_actionNew_game_triggered();


    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    Game *game=NULL;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H