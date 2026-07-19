#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "linkedlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertBeginBtn_clicked();
    void on_insertEndBtn_clicked();
    void on_insertPosBtn_clicked();
    void on_deleteBeginBtn_clicked();
    void on_deleteEndBtn_clicked();
    void on_deletePosBtn_clicked();
    void on_searchBtn_clicked();
    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;
    LinkedList *list;
    QGraphicsScene *scene;

    void drawList();
};

#endif // MAINWINDOW_H
