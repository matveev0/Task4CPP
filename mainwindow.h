#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QtGui>
#include <QMdiArea>
#include <QString>
#include <QFileDialog>
#include <iostream>
#include "utils.h"
#include <QVector>
#include <QFile>
#include <QMdiSubWindow>
#include <QErrorMessage>
#include <vector>
#include <regex>
#include <string>
#include <QFileInfo>
#include <sstream>
#include <QStringListModel>
#include <QStringList>
#include <dictionary.h>
#include "filesubwindow.h"
#include "QTextEdit"
#include <map>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    Dictionary *d;
    void showFileSubWindow(const QString &text = nullptr, const QString &title = nullptr);
    void showErrorDialog(const QString &text);
    void showDictionary(const QString &text, const QString &title);

private slots:
    void actionNewDoc();
    void actionOpen();
    void actionSave_as();
    void actionOpenDictionary();
    void on_sortByFreq_clicked();
    void on_addToDict_clicked();
    void on_sortByAlphabet_clicked();
};

#endif // MAINWINDOW_H
