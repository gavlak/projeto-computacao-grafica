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

    //pega o ponteiro para a area promovida
    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    //passa os ponteiros das checkboxes
    areaDesenho->configurarCheckboxes(ui->checkPonto, ui->checkReta, ui->checkTriangulo);

    //conecta checkboxes a atualizacao da area de desenho
    connect(ui->checkPonto, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkReta, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkTriangulo, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarSobre() {
    QMessageBox::about(this, "Sobre", "teste");
}
