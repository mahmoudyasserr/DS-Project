#include "helperForGraph.h"

void usersVector(string xml_file, vector<vector<int>>* ids) {
    //vector<vector<int>> ids(n);
    string prev_opening_tag = "";
    int user_id = 0;
    for (int i = 0; i < xml_file.length(); i++)
    {
        string opening_tag_name = "";
        if (xml_file[i] == '<')
        {
            switch (xml_file[i + 1])
            {

            case'!':
                continue;
                break;
            case'?':
                continue;
                break;
            case'/':
            {
                continue;
                break;
            }
            default:
            {
                int k;
                int id_int;
                string id_str = "";
                for (k = i + 1; xml_file[k] != '>'; k++)
                {
                    opening_tag_name = opening_tag_name + xml_file[k];
                }
                /*cout << "OPENING: " << opening_tag_name << endl;
                cout << "PREV: " << prev_opening_tag << endl;
                cout << opening_tag_name << endl;*/
                if (opening_tag_name.compare("id")==0 && prev_opening_tag.compare("user")==0) {

                    for (int j = k + 1; xml_file[j] != '<'; j++) {
                        id_str += xml_file[j];

                    }
                    id_int = stoi(id_str);
                    user_id = id_int;
                    (*ids)[user_id - 1].push_back(id_int);


                }
                else if (opening_tag_name.compare("id") == 0 && prev_opening_tag.compare("follower") == 0) {
                    for (int j = k + 1; xml_file[j] != '<'; j++) {
                        id_str += xml_file[j];
                    }
                    id_int = stoi(id_str);
                    (*ids)[user_id - 1].push_back(id_int);

                }
                prev_opening_tag = opening_tag_name;
                //s.push(opening_tag_name);
                break;
            }
            }
            continue;
        }

        else
            continue;
    }
    for (int i = 0; i < (*ids).size(); i++) {
        for (int j = 0; j < (*ids)[i].size(); j++) {
            //cout << (*ids)[i][j] << " ";
        }
        //cout << endl;
    }

}


void countNoOfUsers(string xml_file, int* n) {
    *n = 0;
    //vector<vector<int>> ids(150);
    string prev_opening_tag = "";
    //int user_id = 0;
    for (int i = 0; i < xml_file.length(); i++)
    {
        string opening_tag_name = "";
        if (xml_file[i] == '<')
        {
            switch (xml_file[i + 1])
            {

            case'!':
                continue;
                break;
            case'?':
                continue;
                break;
            case'/':
            {
                continue;
                break;
            }
            default:
            {
                int k;
                //int id_int;
                string id_str = "";
                for (k = i + 1; xml_file[k] != '>'; k++)
                {
                    opening_tag_name = opening_tag_name + xml_file[k];
                }
                //cout << "OPENING: " << opening_tag_name << endl;
                //cout << "PREV: " << prev_opening_tag << endl;
                //cout << opening_tag_name << endl;
                if (opening_tag_name.compare("id") == 0 && prev_opening_tag.compare("user") == 0) {
                    (*n)++;
                }
                prev_opening_tag = opening_tag_name;
                //s.push(opening_tag_name);
                break;
            }
            }
            continue;
        }

        else
            continue;
    }
}


void qstringToFile(QString s_q) {
    QString filename = "nodes.txt";
    QFile file(filename);
    QFile::remove(filename);
    if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << s_q;
    }
}

QString vectorToQString(vector<vector<int>> v) {
    string s_str = "";
    for (int i = 0; i<v.size(); i++) {
        for (int j = 1; j<v[i].size(); j++) {
            s_str += to_string(v[i][0]);
            s_str += ' ';
            s_str += to_string(v[i][j]);
            s_str += '\n';
        }
    }
    QString s_q = QString::fromStdString(s_str);
    return s_q;
}

