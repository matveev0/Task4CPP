#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QStringList>
#include "qdebug.h"
#include <vector>

using namespace std;

class Dictionary
{
public:
    Dictionary(QVector<QString> fromLines);
    Dictionary();
    QStringList getDictionary();
    QStringList getOrderedByFreqDict();
    QString getTextForSave();
    void addWordsToDictionary(QString str);

private:
    void sortByFreq();
    QMap<QString,int> dictionary;
    vector<pair <int,QString> > vect;
};

#endif // DICTIONARY_H
