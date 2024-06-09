#include "group.h"

Group::Group() {}

Group::Group(int GID, QString groupname, int ownerid)
    : GID(GID), groupname(groupname), ownerID(ownerid)
{

}

int Group::getGID()
{
    return this->GID;
}

QString Group::getGroupname()
{
    return this->groupname;
}

int Group::getOwnerid()
{
    return this->ownerID;
}

void Group::setGID(int GID) {
    this->GID = GID;
}


void Group::setUsername(QString groupname) {
    this->groupname = groupname;
}


void Group::setOwnerid(int ownerid) {
    this->ownerID = ownerid;
}
