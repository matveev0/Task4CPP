#include "mainwindow.h"
#include <QApplication>


//5. Разработать структуру данных «словарь, пополняемый словами из файлов».
//В словаре хранить слово и количество его повторений. Словарь должен уметь
//себя сохранять в файл, восстанавливать себя из файла и выдавать на экран слова,
//упорядоченные по алфавиту и по встречаемости.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
