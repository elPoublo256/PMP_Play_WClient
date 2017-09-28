#ifndef TRECK_H
#define TRECK_H
#include <QString>
#include <QSet>
class Area
{
private:
    QString name_Area;
public:
    Area(const QString& name){name_Area=name;}
    QString ret_name(){return name_Area;}

};

class Pointer_Area
{
public:
    Area* point;
 Pointer_Area(Area* p){point=p;}
 bool operator ==(const Pointer_Area& a){return a.point->ret_name()==this->point->ret_name();}
};

class Group
{
private:
    QString name_Group;
    QSet<Area*> set_Area;

public:
    virtual QString ret_Name(){return name_Group;}
    Group(const QString& Name){name_Group=Name;}
    void add_Area(Area* pointer_area){set_Area.insert(pointer_area);}
};
class Albom : public Group
{


};

class Treck: public Treg_reg
{
public:
    Treck();
};

#endif // TRECK_H
