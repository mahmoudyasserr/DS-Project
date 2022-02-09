#ifndef HELPERFORGRAPH_H
#define HELPERFORGRAPH_H
#include <vector>
#include <string>
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
using namespace std;
QString vectorToQString(vector<vector<int>> v);
void qstringToFile(QString s_q);
void countNoOfUsers(string xml_file, int* n);
void usersVector(string xml_file, vector<vector<int>>* ids);
#endif // HELPERFORGRAPH_H
