#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "areadesenho.h"  // Necessário para usar AreaDesenho*
#include "objeto.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mostrarSobre();
    void aplicarTranslacao();
    void atualizarComboObjetos();

private:
    Ui::MainWindow *ui;
    AreaDesenho* areaDesenho;  // Ponteiro para a área de desenho promovida
};

#endif // MAINWINDOW_H
