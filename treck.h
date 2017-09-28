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
 bool operator <(const Pointer_Area& a){return a.point->ret_name()<this->point->ret_name();}
 bool operator >(const Pointer_Area& a){return a.point->ret_name()>this->point->ret_name();}
 bool operator ==(const QString& a){return a==this->point->ret_name();}
 bool operator <(const QString& a){return a<this->point->ret_name();}
 bool operator >(const QString& a){return a>this->point->ret_name();}
};

class Albom;
class Group
{
private:
    QString name_Group;
    QSet<Area*> set_Area;
    QList<Albom*> List;

public:
    virtual QString ret_Name(){return name_Group;}
    Group(const QString& Name){name_Group=Name;}
    void add_Area(Area* pointer_area){set_Area.insert(pointer_area);}


};
class Albom : public Group
{
private:
QString name_Albom;
Group* group;
public:
Albom(const QString& Name, Group* parent){name_Albom=Name; name_Group=parent->ret_Name(); group=parent;}
Albom(const QString &Name, const QString& ggroup ){name_Albom=Mame; name_Group=ggroup;group=new Group(ggroup)/*надо зделать свой аалокатор груп*/;}
virtual QString ret_Name(){return name_Albom;}
virtual QString retFullName(){return "<a>="+ret_Name()+"<g>="+Group::ret_Name();}


};

class Treck : public Albom
{
public:
    Treck(const QString nname, Albom* parent);
};

#endif // TRECK_H
