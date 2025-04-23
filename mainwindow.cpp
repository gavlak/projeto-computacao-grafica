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

    // Transformações
    connect(ui->sliderTransX, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderTransY, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderEscalaX, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderEscalaY, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);

    connect(ui->comboObjetos, &QComboBox::currentTextChanged, this, [=]() {
        resetarSliders();
        aplicarTransformacoes();
    });

    atualizarComboObjetos();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mostrarSobre() {
    QMessageBox::about(this, "Sobre", "Projeto de Computação Gráfica\n"
                                      "Grupo: Paulo Henrique e equipe\n"
                                      "Disciplina: Computação Gráfica\n"
                                      "Ano: 2025");
}

void MainWindow::atualizarComboObjetos() {
    ui->comboObjetos->clear();
    DisplayFile::No* atual = areaDesenho->getDisplayFile()->inicio;

    while (atual) {
        ui->comboObjetos->addItem(atual->obj->nome);
        atual = atual->proximo;
    }
}

void MainWindow::aplicarTransformacoes() {
    QString nomeSelecionado = ui->comboObjetos->currentText();
    if (nomeSelecionado.isEmpty()) return;

    Objeto* obj = areaDesenho->getDisplayFile()->buscarPorNome(nomeSelecionado);
    if (!obj) return;

    float dx = ui->sliderTransX->value();
    float dy = ui->sliderTransY->value();

    float sx = ui->sliderEscalaX->value() / 10.0f;
    float sy = ui->sliderEscalaY->value() / 10.0f;

    QPointF centro = obj->centro();

    // Matriz composta: T(dx,dy) * T(cx,cy) * S(sx,sy) * T(-cx,-cy)
    auto T1 = Transformacoes::translacao(-centro.x(), -centro.y());
    auto S = Transformacoes::escala(sx, sy);
    auto T2 = Transformacoes::translacao(centro.x(), centro.y());
    auto T3 = Transformacoes::translacao(dx, dy);

    auto composta = Transformacoes::multiplicar(T3, Transformacoes::multiplicar(T2, Transformacoes::multiplicar(S, T1)));
    obj->aplicarTransformacao(composta);

    areaDesenho->update();
}

void MainWindow::resetarSliders() {
    ui->sliderTransX->setValue(0);
    ui->sliderTransY->setValue(0);
    ui->sliderEscalaX->setValue(10);  // 10 = fator 1.0
    ui->sliderEscalaY->setValue(10);
}
