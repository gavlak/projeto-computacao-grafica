#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h" // necessário para acessar o método configurarCheckboxes

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Estilo completo para deixar texto e caixinhas visíveis
    QString estiloCheckbox = R"(
        QCheckBox {
            color: black;
        }
        QCheckBox::indicator {
            width: 13px;
            height: 13px;
        }
        QCheckBox::indicator:unchecked {
            border: 1px solid black;
            background-color: white;
        }
        QCheckBox::indicator:checked {
            border: 1px solid black;
            background-color: black;
        }
    )";

    ui->checkPonto->setStyleSheet(estiloCheckbox);
    ui->checkReta->setStyleSheet(estiloCheckbox);
    ui->checkTriangulo->setStyleSheet(estiloCheckbox);

    // Pega o ponteiro para a área promovida (área de desenho)
    AreaDesenho* areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    // Passa os ponteiros das checkboxes para a área de desenho
    areaDesenho->configurarCheckboxes(ui->checkPonto, ui->checkReta, ui->checkTriangulo);

    // Conecta os checkboxes ao update da área de desenho
    connect(ui->checkPonto, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkReta, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkTriangulo, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));

    // [Opcional] Conectar botões para adicionar objetos
    /*
    connect(ui->btnCriarPonto, &QPushButton::clicked, this, &MainWindow::criarPonto);
    connect(ui->btnCriarReta, &QPushButton::clicked, this, &MainWindow::criarReta);
    connect(ui->btnCriarTriangulo, &QPushButton::clicked, this, &MainWindow::criarTriangulo);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
