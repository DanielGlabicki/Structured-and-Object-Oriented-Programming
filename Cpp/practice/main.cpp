#include <iostream>
#include <vector>


///ZAD 3
class Instrument{
private:

public:
    virtual void make_sound() const = 0;
};

class Piano : public Instrument{
private:
public:
    void make_sound() const override { std::cout << "Piano Sound"; }
};
class Guitar : public Instrument{
private:
public:
    void make_sound() const override { std::cout << "Guitar Sound"; }
};

class Orchestra{
private:
    std::vector<Instrument*> instruments_;
public:
    Orchestra(std::vector<Instrument*> instruments) : instruments_(instruments) {}
    ///????????????????????????????????????????
    void play_music() const {
        for (const auto& e : instruments_){
            e->make_sound();
        }
    }
};


///ZAD