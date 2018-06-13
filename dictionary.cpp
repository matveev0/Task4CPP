#include "dictionary.h"

Dictionary::Dictionary(){

}

Dictionary::Dictionary(QVector<QString> fromLines)
{
    QVector<QString> l;
    for (int i = 0; i < fromLines.length(); i++){
        qDebug () << fromLines[i];
        l = fromLines[i].split(' ', QString::SkipEmptyParts).toVector();
        dictionary.insert(l[0], l[1].toInt());
    }
}

QStringList Dictionary::getDictionary(){
    QStringList List;
    QMap<QString, int>::iterator i;
    for (i = dictionary.begin(); i != dictionary.end(); ++i)
         List << i.key() + "         :       " + QString::number(i.value());
    return List;
}

QStringList Dictionary::getOrderedByFreqDict(){
    sortByFreq();
    QStringList List;
    for (pair<int,QString> &p : vect)
        List << p.second + "         :       " + QString::number(p.first);
    return List;
}

void Dictionary::addWordsToDictionary(QString str){
    QVector<QString> l;
    l = str.split(' ', QString::SkipEmptyParts).toVector();
    for (int i = 0; i < l.length(); i++){
        qDebug () << l[i];
        dictionary.insert(l[i], dictionary.value(l[i])+1);
     }
}

QString Dictionary::getTextForSave(){
    QString res;
    QMap<QString, int>::iterator i;
    for (i = dictionary.begin(); i != dictionary.end(); ++i)
    res.append(i.key()).append(' ').append(QString::number(i.value())).append('\n');
    return res;
}

void Dictionary::sortByFreq(){
        vect.clear();
        QMap<QString, int>::iterator i;
        for (i = dictionary.begin(); i != dictionary.end(); ++i)
            vect.push_back( make_pair(i.value(),i.key()) );
        sort(vect.begin(), vect.end());
}
