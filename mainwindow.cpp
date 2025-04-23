#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbrir, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Abrir", "Funcionalidade ainda não implementada.");
    });

    connect(ui->actionSalvar, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Salvar e Sair", "Ainda não implementado.");
    });

    connect(ui->actionSobre, &QAction::triggered, this, &MainWindow::mostrarSobre);

    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");
    areaDesenho->configurarCheckboxes(ui->checkPonto, ui->checkReta, ui->checkTriangulo);

    connect(ui->checkPonto, &QCheckBox::toggled, areaDesenho, QOverload<>::of(&AreaDesenho::update));
    connect(ui->checkReta, &QCheckBox::toggled, areaDesenho, QOverload<>::of(&AreaDesenho::update));
    connect(ui->checkTriangulo, &QCheckBox::toggled, areaDesenho, QOverload<>::of(&AreaDesenho::update));

    connect(ui->botaoTransladar, &QPushButton::clicked, this, &MainWindow::aplicarTranslacao);
    connect(ui->botaoEscalar, &QPushButton::clicked, this, &MainWindow::aplicarEscala);
    connect(ui->botaoRotacionar, &QPushButton::clicked, this, &MainWindow::aplicarRotacao);

    ui->botaoTransladar->setStyleSheet("color: red;");
    ui->botaoEscalar->setStyleSheet("color: green;");
    ui->botaoRotacionar->setStyleSheet("color: blue;");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarSobre()
{
    QMessageBox::information(this, "Sobre", "Visualizador 2D - Computação Gráfica\nAluno: Seu Nome\nProfessor: Erikson Morais");
}

void MainWindow::aplicarTranslacao() {
    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");
    areaDesenho->aplicarTranslacao(50, 30); // move todos os objetos
    areaDesenho->update();
}

void MainWindow::aplicarEscala() {
    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");
    areaDesenho->aplicarEscala(1.2, 1.2); // aumenta 20%
    areaDesenho->update();
}

void MainWindow::aplicarRotacao() {
    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");
    areaDesenho->aplicarRotacao(30, QPointF(300, 300)); // gira em torno de (300, 300)
    areaDesenho->update();
}

