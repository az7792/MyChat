#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include<qstring.h>

class Group
{
public:
    Group();
    Group(int GID,QString groupname,int ownerID);

    int getGID();
    int getOwnerid();
    QString getGroupname();
    void setGID(int GID);
    void setUsername(QString groupname);
    void setOwnerid(int ownerid);


private:
    int GID=-1;
    int ownerID = -1;
    QString groupname;
};

#endif // GROUP_H
