#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    list = new LinkedList();

    // updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
}

void MainWindow::on_insertBeginBtn_clicked()
{
    int value = ui->valueInput->text().toInt();
    list->insertAtBegin(value);
    drawList();
}

void MainWindow::on_insertEndBtn_clicked()
{
    int value = ui->valueInput->text().toInt();
    list->insertAtEnd(value);
    drawList();
}

void MainWindow::on_insertPosBtn_clicked()
{
    int value = ui->valueInput->text().toInt();
    int pos = ui->posInput->text().toInt();
    list->insertAtPos(value, pos);
    drawList();
}

void MainWindow::on_deleteBeginBtn_clicked()
{
    list->deleteAtBegin();
    drawList();
}

void MainWindow::on_deleteEndBtn_clicked()
{
    list->deleteAtEnd();
    drawList();
}

void MainWindow::on_deletePosBtn_clicked()
{
    int pos = ui->posInput->text().toInt();
    list->deleteAtPos(pos);
    drawList();
}

void MainWindow::on_searchBtn_clicked()
{
    int value = ui->valueInput->text().toInt();
    bool found = list->search(value);

    QMessageBox::information(
        this,
        "Search Result",
        found ? "Value found!" : "Value not found."
        );
}

void MainWindow::on_clearBtn_clicked()
{
    list->clear();
    scene->clear();
}

void MainWindow::drawList()
{
    scene->clear();

    auto nodes = list->getNodes();

    int x = 0;
    for (int v : nodes)
    {
        scene->addRect(x, 0, 60, 40);
        QGraphicsTextItem *text = scene->addText(QString::number(v));
        text->setPos(x + 20, 10);
        x += 80;
    }
}
