#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h"
#include "transformacoes.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Armazena o ponteiro da área promovida
    areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    // Menu
    connect(ui->actionAbrir, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Abrir", "Funcionalidade ainda não implementada.");
    });

    connect(ui->actionSalvar, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Salvar e Sair", "Ainda não implementado.");
    });

    connect(ui->actionSobre, &QAction::triggered, this, &MainWindow::mostrarSobre);

    // Checkboxes
    areaDesenho->configurarCheckboxes(ui->checkPonto, ui->checkReta, ui->checkTriangulo);

    connect(ui->checkPonto, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkReta, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkTriangulo, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));

    // Sliders e ComboBox para translação
    connect(ui->sliderTransX, &QSlider::valueChanged, this, &MainWindow::aplicarTranslacao);
    connect(ui->sliderTransY, &QSlider::valueChanged, this, &MainWindow::aplicarTranslacao);
    connect(ui->comboObjetos, &QComboBox::currentTextChanged, this, &MainWindow::aplicarTranslacao);

    // Preenche a combo com os nomes dos objetos
    atualizarComboObjetos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarSobre() {
    QMessageBox::about(this, "Sobre", "teste");
}

void MainWindow::atualizarComboObjetos() {
    ui->comboObjetos->clear();
    DisplayFile::No* atual = areaDesenho->getDisplayFile()->inicio;

    while (atual) {
        ui->comboObjetos->addItem(atual->obj->nome);
        atual = atual->proximo;
    }
}

void MainWindow::aplicarTranslacao() {
    QString nomeSelecionado = ui->comboObjetos->currentText();
    if (nomeSelecionado.isEmpty()) return;

    Objeto* obj = areaDesenho->getDisplayFile()->buscarPorNome(nomeSelecionado);

    if (!obj) return;

    float dx = ui->sliderTransX->value();
    float dy = ui->sliderTransY->value();

    auto matrizTranslacao = Transformacoes::translacao(dx, dy);
    obj->aplicarTransformacao(matrizTranslacao);

    areaDesenho->update();
}
