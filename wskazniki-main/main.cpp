#include <iostream>
#include <list>
#include <string>


class IObject {
public:
    virtual ~IObject() {};
    virtual void Update(const std::string &message_from_Mapa) = 0;
    virtual std::string GetType() const = 0;
};


class IMapa {
public:
    virtual ~IMapa() {};
    virtual void DodajObiekt(IObject *Object) = 0;
    virtual void UsuńObiekt(IObject *Object) = 0;
    virtual void Notify() = 0;
    virtual void ShowSummary() const = 0;
};

/**
 * The Mapa owns some important state and notifies Objects when the state
 * changes.
 */
class Mapa : public IMapa {
public:
    virtual ~Mapa() {
        std::cout << "Goodbye, I was the Mapa.\n";
    }

    void DodajObiekt(IObject *Object) override {
        list_Object_.push_back(Object);
    }

    void UsuńObiekt(IObject *Object) override {
        list_Object_.remove(Object);
    }

    void Notify() override {
        for (IObject* obj : list_Object_) {
            obj->Update(message_);
        }
    }

    void CreateMessage(const std::string& message = "Empty") {
        this->message_ = message;
        Notify();
    }

    void ShowSummary() const override {
        std::cout << "Summary of objects in the map:\n";
        for (IObject* obj : list_Object_) {
            std::cout << "- " << obj->GetType() << "\n";
        }
    }

private:
    std::list<IObject *> list_Object_;
    std::string message_;
};

class Object : public IObject {
public:
    Object(Mapa &Mapa, const std::string& type) : Mapa_(Mapa), type_(type) {
        this->Mapa_.DodajObiekt(this);
        std::cout << "Hi, I'm the Object \"" << ++Object::static_number_ << "\" of type " << type_ << ".\n";
        this->number_ = Object::static_number_;
    }
    virtual ~Object() {
        std::cout << "Goodbye, I was the Object \"" << this->number_ << "\" of type " << type_ << ".\n";
    }

    void Update(const std::string &message_from_Mapa) override {
        message_from_Mapa_ = message_from_Mapa;
        PrintInfo();
    }

    void RemoveMeFromTheList() {
        Mapa_.UsuńObiekt(this);
        std::cout << "Object \"" << number_ << "\" of type " << type_ << " removed from the list.\n";
    }

    void PrintInfo() {
        std::cout << "Object \"" << this->number_ << "\" of type " << this->type_ << ": a new message is available --> " << this->message_from_Mapa_ << "\n";
    }

    std::string GetType() const override {
        return type_;
    }

private:
    std::string message_from_Mapa_;
    Mapa &Mapa_;
    static int static_number_;
    int number_;
    std::string type_;
};

int Object::static_number_ = 0;

class Drzewo : public Object {
public:
    Drzewo(Mapa& mapa) : Object(mapa, "Drzewo") {}
};

class Budynek : public Object {
public:
    Budynek(Mapa& mapa) : Object(mapa, "Budynek") {}
};

class jeziorko : public Object {
public:
    jeziorko(Mapa& mapa) : Object(mapa, "jeziorko") {}
};

class droga : public Object {
public:
    droga(Mapa& mapa) : Object(mapa, "droga") {}
};

class gora : public Object {
public:
    gora(Mapa& mapa) : Object(mapa, "gora") {}
};

int main() {
    Mapa* mapa = new Mapa;

    Drzewo* tree1 = new Drzewo(*mapa);
    Budynek* building1 = new Budynek(*mapa);
    jeziorko* lake1 = new jeziorko(*mapa);
    droga* road1 = new droga(*mapa);
    gora* mountain1 = new gora(*mapa);

    mapa->CreateMessage("Hello World! :D");
    mapa->ShowSummary();

    building1->RemoveMeFromTheList();
    tree1->RemoveMeFromTheList();

    mapa->CreateMessage("The weather is hot today! :p");
    mapa->ShowSummary();


    delete mapa;
    return 0;
}